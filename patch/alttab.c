int alttabn;          /* move that many clients forward */
int alttabnc;		  /* move that many clients forward when using tab for same class */
int ntabs;            /* number of active clients in tag */
int nctabs;			  /* number of active clients under same class in tag */
int isalt;
Client **altsnext;    /* array of all clients in the tag */
Client **altsnextclass;	/* array of all clients under same class in the tag */
Window alttabwin;

void
alttab()
{
	Monitor *m = selmon;

	/* move to next window */
	if (m->sel && m->sel->snext) {
		alttabn++;
		if (alttabn >= ntabs)
			alttabn = 0; /* reset alttabn */

		focus(altsnext[alttabn]);
		/* restack(m); */
	}

	/* redraw tab */
	XRaiseWindow(dpy, alttabwin);
	drawtab(ntabs, 0, m);
}

alttabclass()
{
	/* move to next window */
	if (sel != NULL) {
		alttabnc++;
		if (alttabnc >= nctabs)
			alttabnc = 0; /* reset alttabnc */

		focus(altsnextclass[alttabnc]);
	}

	/* redraw tab */
	XRaiseWindow(dpy, tabwin);
	drawtab(nctabs, 0, selmon);
}

void
alttabshift()
{
	/* move to prev window */
	if (sel != NULL) {
		alttabn--;
		if (alttabn < 0)
			alttabn = ntabs - 1; /* reset alttabn */

		if (altsnext[alttabn]) {
			focus(altsnext[alttabn]);
		}
 	}
 
	/* redraw tab */
	XRaiseWindow(dpy, tabwin);
	drawtab(ntabs, 0, selmon);
}
 
void
alttabshiftclass()
{
	/* move to prev window */
	if (sel != NULL) {
		alttabnc--;
		if (alttabnc < 0)
			alttabnc = nctabs - 1; /* reset alttabnc */

		if (altsnextclass[alttabnc]) {
			focus(altsnextclass[alttabnc]);
		}
	}

	/* redraw tab */
	XRaiseWindow(dpy, tabwin);
	drawtab(nctabs, 0, selmon);
}

void
alttabend()
{
	Monitor *m = selmon;
	Client *buff;
	int i;

	Client *buff = NULL;
	if (!isalt)
		return;

	/* Move all clients between first and choosen position,
	 * one down in stack and put choosen client to the first position
	 * so they remain in right order for the next time that alt-tab is used
	 */
	if (ntabs > 1) {
		if (alttabn != 0) { /* if user picked original client do nothing */
       		buff = altsnext[alttabn];
		else if (alttabnc != 0) {
			buff = altsnextclass[alttabnc];
			for (; alttabn < ntabs; alttabn++)
				if (altsnext[alttabn] == altsnextclass[alttabnc])
					break;
		}
		if (buff) { /* if user picked original client do nothing */

			if (alttabn > 1)
				for (i = alttabn; i > 0; i--)
					altsnext[i] = altsnext[i - 1];
			else /* swap them if there are just 2 clients */
				altsnext[alttabn] = altsnext[0];
			altsnext[0] = buff;
		}

		/* restack clients */
		for (i = ntabs - 1; i >= 0; i--) {
		    focus(altsnext[i]);
		    restack(m);
		}

		free(altsnext); /* free list of clients */
		free(altsnextclass); /* free list of clients */
	}

	/* destroy the window */
	isalt = 0;
	ntabs = 0;
	XUnmapWindow(dpy, alttabwin);
	XDestroyWindow(dpy, alttabwin);
}

void
drawtab(int nwins, int first, Monitor *m)
{
	Client *c;
	int i, h;
	int y = 0;
	int px = m->mx;
	int py = m->my;

	if (first) {
		XSetWindowAttributes wa = {
			.override_redirect = True,
			.background_pixmap = ParentRelative,
			.event_mask = ButtonPressMask|ExposureMask
		};

		/* decide position of tabwin */
		if (tabposx == 1)
			px = m->mx + (m->mw / 2) - (maxwtab / 2);
		else if (tabposx == 2)
			px = m->mx + m->mw - maxwtab;

		if (tabposy == 1)
			py = m->my + (m->mh / 2) - (maxhtab / 2);
		else if (tabposy == 2)
			py = m->my + m->mh - maxhtab;

		h = maxhtab;

		alttabwin = XCreateWindow(dpy, root, px, py, maxwtab, maxhtab, 2, DefaultDepth(dpy, screen),
		                             CopyFromParent, DefaultVisual(dpy, screen),
		                             CWOverrideRedirect|CWBackPixmap|CWEventMask, &wa);

		XDefineCursor(dpy, alttabwin, cursor[CurNormal]->cursor);
		XMapRaised(dpy, alttabwin);
	}

	h = maxhtab / nwins;
	for (int i = 0; i < nwins; i++) { /* draw all clients into tabwin */
		if (nwins == m->ntabs)
			c = m->altsnext[i];
		else
			c = m->altsnextclass[i];
		if (!ISVISIBLE(c))
			continue;
		if (HIDDEN(c))
			continue;

		drw_setscheme(drw, scheme[c == m->sel ? SchemeSel : SchemeNorm]);
		drw_text(drw, 0, y, maxwtab, h, 0, c->name, 0, 0);
		y += h;
	}

	drw_setscheme(drw, scheme[SchemeNorm]);
	drw_map(drw, alttabwin, 0, 0, maxwtab, maxhtab);
}

void
alttabstart(const Arg *arg)
{
	Client *c;
	Monitor *m = selmon;
	int grabbed;
	int i;

	if (alttabwin)
		alttabend();

	if (isalt == 1) {
		alttabend();
		return;
	}

	char tempclass[256] = {'\0'};
	if (selmon->sel)
		strncpy(tempclass, selmon->sel->class, 256);


	isalt = 1;
	alttabn = 0;
	alttabnc = 0;
	ntabs = 0;
	nctabs = 0;

	for (c = m->clients; c; c = c->next) {
		if (!ISVISIBLE(c))
			continue;
		if (HIDDEN(c))
			continue;

		++ntabs;
		if (!strcmp(c->class, tempclass))
			++m->ncTabs;
	}

	if (!ntabs) {
		alttabend();
		return;
	}

	altsnext = (Client **) malloc(ntabs * sizeof(Client *));
	altsnextclass = (Client **) malloc(ncTabs * sizeof(Client *));

	int listIndexc = 0;

	for (i = 0, c = m->stack; c; c = c->snext) {
		if (!ISVISIBLE(c))
			continue;
		if (HIDDEN(c))
			continue;

		altsnext[i] = c;
		i++;

		if (!strcmp(c->class, tempclass))
			m->altsnextclass[listIndexc++] = c;
	}

	if (arg->i)
		drawtab(ntabs, 1, m);
	else
		drawtab(nctabs, 1, m);

	struct timespec ts = { .tv_sec = 0, .tv_nsec = 1000000 };

	/* grab keyboard (take all input from keyboard) */
	grabbed = 1;
	for (i = 0; i < 1000; i++) {
		if (XGrabKeyboard(dpy, root, True, GrabModeAsync, GrabModeAsync, CurrentTime) == GrabSuccess)
			break;
		nanosleep(&ts, NULL);
		if (i == 1000 - 1)
			grabbed = 0;
	}

	XEvent event;
	alttab();
	if (arg->i)
		altTab();
	else
		altTabClass();

	if (grabbed == 0) {
		alttabend();
		return;
	}

	while (grabbed) {
		XNextEvent(dpy, &event);
		if (event.type == KeyPress || event.type == KeyRelease) {
			if (event.type == KeyRelease && event.xkey.keycode == tabmodkey) /* if mod key is released break cycle */
				break;

			if (event.type == KeyPress) {
				if (event.xkey.keycode == tabcyclekey || event.xkey.keycode == tabcyclekey2 ) { /* if xk_s is pressed move to the next window */
					if (arg->i) {
						if (CLEANMASK((Mod1Mask|ShiftMask)) == CLEANMASK(event.xkey.state))
							alttabshift();
						else
							alttab();
					} else {
						if (CLEANMASK((Mod1Mask|ShiftMask)) == CLEANMASK(event.xkey.state))
							alttabshiftclass();
						else
							alttabclass();
					}

				}
			}
		}
	}

	c = m->sel;
	alttabend();

	XUngrabKeyboard(dpy, CurrentTime);
	focus(c);
	restack(m);
}
