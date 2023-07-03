/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMCLASS "St"
#define BROWSER "vivaldi"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const int corner_radius           = 10;
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int focusonwheel            = 0;
static int floatposgrid_x                = 5;  /* float grid columns */
static int floatposgrid_y                = 5;  /* float grid rows */
static const char slopspawnstyle[]       = "-t 0 -c 0.92,0.85,0.69,0.3 -o"; /* do NOT define -f (format) here */
static const char slopresizestyle[]      = "-t 0 -c 0.92,0.85,0.69,0.3"; /* do NOT define -f (format) here */
static const int riodraw_borders         = 0;  /* 0 or 1, indicates whether the area drawn using slop includes the window borders */
static const int riodraw_matchpid        = 1;  /* 0 or 1, indicates whether to match the PID of the client that was spawned with riospawn */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const char buttonbar[]            = "<O>";
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */


/* alt-tab configuration */
static const unsigned int tabmodkey        = 0x40; /* (Alt) when this key is held down the alt-tab functionality stays active. Must be the same modifier as used to run alttabstart */
static const unsigned int tabcyclekey      = 0x17; /* (Tab) when this key is hit the menu moves one position forward in client stack. Must be the same key as used to run alttabstart */
static const unsigned int tabposy          = 1;    /* tab position on Y axis, 0 = top, 1 = center, 2 = bottom */
static const unsigned int tabposx          = 1;    /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxwtab          = 600;  /* tab menu width */
static const unsigned int maxhtab          = 200;  /* tab menu height */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static int fakefsindicatortype           = INDICATOR_PLUS;
static int floatfakefsindicatortype      = INDICATOR_PLUS_AND_LARGER_SQUARE;
static const char *fonts[]               = { "monospace:size=10", "NotoColorEmoji:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]            = "monospace:size=10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static char scratchselfgcolor[]          = "#FFF7D4";
static char scratchselbgcolor[]          = "#77547E";
static char scratchselbordercolor[]      = "#894B9F";
static char scratchselfloatcolor[]       = "#894B9F";

static char scratchnormfgcolor[]         = "#FFF7D4";
static char scratchnormbgcolor[]         = "#664C67";
static char scratchnormbordercolor[]     = "#77547E";
static char scratchnormfloatcolor[]      = "#77547E";



static char *colors[][ColCount] = {
/*                       fg                bg                border                float */
[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
[SchemeScratchSel]  = { scratchselfgcolor, scratchselbgcolor, scratchselbordercolor, scratchselfloatcolor },
[SchemeScratchNorm] = { scratchnormfgcolor, scratchnormbgcolor, scratchnormbordercolor, scratchnormfloatcolor },
};


static const char *layoutmenu_cmd = "layoutmenu.sh";


static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};

/* Tags
* In a traditional dwm the number of tags in use can be changed simply by changing the number
* of strings in the tags array. This build does things a bit different which has some added
* benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
*
* Examples:
*
*  1) static char *tagicons[][NUMTAGS*2] = {
*         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
*     }
*
*  2) static char *tagicons[][1] = {
*         [DEFAULT_TAGS] = { "•" },
*     }
*
* The first example would result in the tags on the first monitor to be 1 through 9, while the
* tags for the second monitor would be named A through I. A third monitor would start again at
* 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
* count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
* the array. This can be changed to *3 to add separate icons for a third monitor.
*
* For the second example each tag would be represented as a bullet point. Both cases work the
* same from a technical standpoint - the icon index is derived from the tag index and the monitor
* index. If the icon index is is greater than the number of tag icons then it will wrap around
* until it an icon matches. Similarly if there are two tag icons then it would alternate between
* them. This works seamlessly with alternative tags and alttagsdecoration patches.
*/
static char *tagicons[][NUMTAGS] =
{
[DEFAULT_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};


/* There are two options when it comes to per-client rules:
*  - a typical struct table or
*  - using the RULE macro
*
* A traditional struct table looks like this:
*    // class      instance  title  wintype  tags mask  isfloating  monitor
*    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
*    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
*
* The RULE macro has the default values set for each field allowing you to only
* specify the values that are relevant for your rule, e.g.
*
*    RULE(.class = "Gimp", .tags = 1 << 4)
*    RULE(.class = "Firefox", .tags = 1 << 7)
*
* Refer to the Rule struct definition for the list of available fields depending on
* the patches you enable.
*/
static const Rule rules[] = {
/* xprop(1):
 *	WM_CLASS(STRING) = instance, class
 *	WM_NAME(STRING) = title
 *	WM_WINDOW_ROLE(STRING) = role
 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
 */
RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
RULE(.class = "Gimp", .tags = 1 << 4)
RULE(.class = "$BROWSER", .tags = 1 << 7)
RULE(.instance = "spterm", .scratchkey = 's', .isfloating = 1)
};



/* Bar rules allow you to configure what is shown where on the bar, as well as
* introducing your own bar modules.
*
*    monitor:
*      -1  show on all monitors
*       0  show on monitor 0
*      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
*    bar - bar index, 0 is default, 1 is extrabar
*    alignment - how the module is aligned compared to other modules
*    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
*    name - does nothing, intended for visual clue and for logging / debugging
*/
static const BarRule barrules[] = {
/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
{ -1,        0,     BAR_ALIGN_LEFT,   width_stbutton,           draw_stbutton,          click_stbutton,          NULL,                    "statusbutton" },
{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_statuscmd,         NULL,                    "status" },
{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */



static const Layout layouts[] = {
/* symbol     arrange function */
{ "[]=",      tile },    /* first entry is default */
{ "><>",      NULL },    /* no layout function means floating behavior */
{ "[M]",      monocle },
{ "|||",      col },
{ "[D]",      deck },
{ "[\\]",     dwindle },
{ ":::",      gaplessgrid },
};


/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]  = { "st", NULL };
static const char *dmenucmd[] = {
"dmenu_run",
"-m", dmenumon,
"-fn", dmenufont,
"-nb", normbgcolor,
"-nf", normfgcolor,
"-sb", selbgcolor,
"-sf", selfgcolor,
NULL
};

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"


static const Key keys[] = {
/* modifier                     key            function                argument */
{ MODKEY,			XK_grave,	spawn,			{.v = (const char*[]){ "dmenuunicode", NULL } } },
{ MODKEY,			XK_BackSpace,	spawn,			{.v = (const char*[]){ "sysact", NULL } } },
/* { MODKEY,                       XK_d,          spawn,                  {.v = dmenucmd } }, */
{ MODKEY,			XK_d,		spawn,          {.v = (const char*[]){ "dmenu_run", NULL } } },
{ MODKEY,		        XK_Return,     spawn,                  {.v = termcmd } },
{ MODKEY|ControlMask,           XK_p,          riospawnsync,           {.v = dmenucmd } },
{ MODKEY|ControlMask,           XK_Return,     riospawn,               {.v = termcmd } },
{ MODKEY,                       XK_s,          rioresize,              {0} },
{ MODKEY,                       XK_b,          togglebar,              {0} },
{ MODKEY|ControlMask,           XK_space,      focusmaster,            {0} },
{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
{ MODKEY|Mod1Mask,              XK_j,          rotatestack,            {.i = +1 } },
{ MODKEY|Mod1Mask,              XK_k,          rotatestack,            {.i = -1 } },
{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
{ MODKEY|ShiftMask,             XK_o,          setcfact,               {0} },
{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
{ MODKEY,                       XK_x,          transfer,               {0} },
{ MODKEY|ControlMask,           XK_d,          distributetags,         {0} },
{ MODKEY,                       XK_Return,     zoom,                   {0} },
{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
{ MODKEY,             		XK_q,          killclient,             {0} },
{ MODKEY|ShiftMask,             XK_x,          killunsel,              {0} },
{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
{ MODKEY,                       XK_o,          winview,                {0} },
{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
{ MODKEY,                       XK_c,          setlayout,              {.v = &layouts[3]} },
{ MODKEY,                       XK_space,      setlayout,              {0} },
{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
{ MODKEY|ShiftMask,             XK_Escape,     togglenomodbuttons,     {0} },
{ MODKEY|ShiftMask,             XK_Return,     togglescratch,          {.v = scratchpadcmd } },
{ MODKEY|ControlMask,           XK_grave,      setscratch,             {.v = scratchpadcmd } },
{ MODKEY|ShiftMask,             XK_grave,      removescratch,          {.v = scratchpadcmd } },
{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
{ MODKEY|ShiftMask,             XK_y,          togglefakefullscreen,   {0} },
{ MODKEY|ShiftMask,             XK_f,          fullscreen,             {0} },
{ MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_comma,      tagallmon,              {.i = +1 } },
{ MODKEY|Mod1Mask|ShiftMask,    XK_period,     tagallmon,              {.i = -1 } },
/* Note that due to key limitations the below example kybindings are defined with a Mod3Mask,
 * which is not always readily available. Refer to the patch wiki for more details. */
/* Client position is limited to monitor window area */
{ Mod3Mask,                     XK_u,            floatpos,               {.v = "-26x -26y" } }, // ↖
{ Mod3Mask,                     XK_i,            floatpos,               {.v = "  0x -26y" } }, // ↑
{ Mod3Mask,                     XK_o,            floatpos,               {.v = " 26x -26y" } }, // ↗
{ Mod3Mask,                     XK_j,            floatpos,               {.v = "-26x   0y" } }, // ←
{ Mod3Mask,                     XK_l,            floatpos,               {.v = " 26x   0y" } }, // →
{ Mod3Mask,                     XK_m,            floatpos,               {.v = "-26x  26y" } }, // ↙
{ Mod3Mask,                     XK_comma,        floatpos,               {.v = "  0x  26y" } }, // ↓
{ Mod3Mask,                     XK_period,       floatpos,               {.v = " 26x  26y" } }, // ↘
/* Absolute positioning (allows moving windows between monitors) */
{ Mod3Mask|ControlMask,         XK_u,            floatpos,               {.v = "-26a -26a" } }, // ↖
{ Mod3Mask|ControlMask,         XK_i,            floatpos,               {.v = "  0a -26a" } }, // ↑
{ Mod3Mask|ControlMask,         XK_o,            floatpos,               {.v = " 26a -26a" } }, // ↗
{ Mod3Mask|ControlMask,         XK_j,            floatpos,               {.v = "-26a   0a" } }, // ←
{ Mod3Mask|ControlMask,         XK_l,            floatpos,               {.v = " 26a   0a" } }, // →
{ Mod3Mask|ControlMask,         XK_m,            floatpos,               {.v = "-26a  26a" } }, // ↙
{ Mod3Mask|ControlMask,         XK_comma,        floatpos,               {.v = "  0a  26a" } }, // ↓
{ Mod3Mask|ControlMask,         XK_period,       floatpos,               {.v = " 26a  26a" } }, // ↘
/* Resize client, client center position is fixed which means that client expands in all directions */
{ Mod3Mask|ShiftMask,           XK_u,            floatpos,               {.v = "-26w -26h" } }, // ↖
{ Mod3Mask|ShiftMask,           XK_i,            floatpos,               {.v = "  0w -26h" } }, // ↑
{ Mod3Mask|ShiftMask,           XK_o,            floatpos,               {.v = " 26w -26h" } }, // ↗
{ Mod3Mask|ShiftMask,           XK_j,            floatpos,               {.v = "-26w   0h" } }, // ←
{ Mod3Mask|ShiftMask,           XK_k,            floatpos,               {.v = "800W 800H" } }, // ·
{ Mod3Mask|ShiftMask,           XK_l,            floatpos,               {.v = " 26w   0h" } }, // →
{ Mod3Mask|ShiftMask,           XK_m,            floatpos,               {.v = "-26w  26h" } }, // ↙
{ Mod3Mask|ShiftMask,           XK_comma,        floatpos,               {.v = "  0w  26h" } }, // ↓
{ Mod3Mask|ShiftMask,           XK_period,       floatpos,               {.v = " 26w  26h" } }, // ↘
/* Client is positioned in a floating grid, movement is relative to client's current position */
{ Mod3Mask|Mod1Mask,            XK_u,            floatpos,               {.v = "-1p -1p" } }, // ↖
{ Mod3Mask|Mod1Mask,            XK_i,            floatpos,               {.v = " 0p -1p" } }, // ↑
{ Mod3Mask|Mod1Mask,            XK_o,            floatpos,               {.v = " 1p -1p" } }, // ↗
{ Mod3Mask|Mod1Mask,            XK_j,            floatpos,               {.v = "-1p  0p" } }, // ←
{ Mod3Mask|Mod1Mask,            XK_k,            floatpos,               {.v = " 0p  0p" } }, // ·
{ Mod3Mask|Mod1Mask,            XK_l,            floatpos,               {.v = " 1p  0p" } }, // →
{ Mod3Mask|Mod1Mask,            XK_m,            floatpos,               {.v = "-1p  1p" } }, // ↙
{ Mod3Mask|Mod1Mask,            XK_comma,        floatpos,               {.v = " 0p  1p" } }, // ↓
{ Mod3Mask|Mod1Mask,            XK_period,       floatpos,               {.v = " 1p  1p" } }, // ↘
{ MODKEY|ControlMask,           XK_comma,      cyclelayout,            {.i = -1 } },
{ MODKEY|ControlMask,           XK_period,     cyclelayout,            {.i = +1 } },
TAGKEYS(                        XK_1,                                  0)
TAGKEYS(                        XK_2,                                  1)
TAGKEYS(                        XK_3,                                  2)
TAGKEYS(                        XK_4,                                  3)
TAGKEYS(                        XK_5,                                  4)
TAGKEYS(                        XK_6,                                  5)
TAGKEYS(                        XK_7,                                  6)
TAGKEYS(                        XK_8,                                  7)
TAGKEYS(                        XK_9,                                  8)
};


/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
/* click                event mask           button          function        argument */
{ ClkButton,            0,                   Button1,        spawn,          {.v = dmenucmd } },
{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
{ ClkLtSymbol,          0,                   Button3,        layoutmenu,     {0} },
{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
{ ClkStatusText,        0,                   Button1,        sigstatusbar,   {.i = 1 } },
{ ClkStatusText,        0,                   Button2,        sigstatusbar,   {.i = 2 } },
{ ClkStatusText,        0,                   Button3,        sigstatusbar,   {.i = 3 } },
{ ClkStatusText,        0,                   Button4,        sigstatusbar,   {.i = 4 } },
{ ClkStatusText,        0,                   Button5,        sigstatusbar,   {.i = 5 } },
{ ClkStatusText,        0,                   Button6,        sigstatusbar,   {.i = 6 } },
{ ClkStatusText,        ShiftMask,           Button1,        sigstatusbar,   {.i = 7 } },
/* placemouse options, choose which feels more natural:
 *    0 - tiled position is relative to mouse cursor
 *    1 - tiled postiion is relative to window center
 *    2 - mouse pointer warps to window center
 *
 * The moveorplace uses movemouse or placemouse depending on the floating state
 * of the selected client. Set up individual keybindings for the two if you want
 * to control these separately (i.e. to retain the feature to move a tiled window
 * into a floating position).
 */
{ ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
{ ClkClientWin,         MODKEY|ShiftMask,    Button3,        dragcfact,      {0} },
{ ClkTagBar,            0,                   Button1,        view,           {0} },
{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
/* signum       function        argument  */
{ 1,            setlayout,      {.v = 0} },
};

