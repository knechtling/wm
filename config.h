/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

#define TERMINAL "st"
#define TERMCLASS "St"
#define BROWSER "firefox"
#define MUSICPLAYER "feishin"
#define EMAILCLIENT "thunderbird"

/* appearance */
static const unsigned int borderpx       = 3;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int swallowfloating         = 0;   /* 1 means swallow floating windows by default */
static int nomodbuttons                  = 1;   /* allow client mouse button bindings that have no modifier */
static const unsigned int gappih         = 20;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 30;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int focusonwheel            = 0;
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
static const char *fonts[]               = { "monospace:size=14", "NotoColorEmoji:pixelsize=10:antialias=true:autohint=true" };
static const char dmenufont[]            = "monospace:size=14";
static const char font[]                 = "monospace 10";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#3a0000";
static char selbordercolor[]             = "#3a0000";
static char selfloatcolor[]              = "#3a0000";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#444444";
static char titleselbordercolor[]        = "#444444";
static char titleselfloatcolor[]         = "#444444";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#444444";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#444444";
static char tagsselbordercolor[]         = "#444444";
static char tagsselfloatcolor[]          = "#444444";

static char hidnormfgcolor[]             = "#894B9F";
static char hidselfgcolor[]              = "#894B9F";
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

static const Launcher launchers[] = {
	/* icon to display      command        */
	{ "surf",               CMD("surf", "duckduckgo.com") },
};

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
[DEFAULT_TAGS]    = { "", "", "", "", "", "", "", "🇩🇪", "" },
[ALTERNATIVE_TAGS]        = { "1", "2", "3", "4", "5", "6", "7", "8", "9" },
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
	RULE(.class = "help-window", .isfloating = 1)
	RULE(.class = EMAILCLIENT, .tags = 1 << 1)
	RULE(.title = "tmux", .tags= 1 << 2)
	RULE(.class = "discord", .tags = 1 << 7)
	RULE(.class = MUSICPLAYER, .tags = 1 << 8)
	RULE(.class = "org.gnome.Nautilus", .isfloating = 1)
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
	{ -1,        0,     BAR_ALIGN_LEFT,   width_launcher,           draw_launcher,          click_launcher,          NULL,                    "launcher" },
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

#define FORCE_VSPLIT 1

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "|||",      col },
	{ "[D]",      deck },
	{ "[\\]",     dwindle },
	{ "HHH",      grid },
	{ ":::",      gaplessgrid },
	{ "###",      nrowgrid },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ShiftMask,    KEY,      swaptags,       {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask,              KEY,      tagnextmon,     {.ui = 1 << TAG} }, \
	{ MODKEY|Mod1Mask|ControlMask,  KEY,      tagprevmon,     {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *termcmd[]  = { TERMINAL, NULL };
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	topbar ? NULL : "-b",
	NULL
};

/* This defines the name of the executable that handles the bar (used for signalling purposes) */
#define STATUSBAR "dwmblocks"

#include <X11/XF86keysym.h>
static const Key keys[] = {
{ MODKEY,			XK_BackSpace,	spawn,		{.v = (const char*[]){ "sysact", NULL } } },
{ MODKEY,			XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-; kill -44 $(pidof dwmblocks)") },
{ MODKEY|ShiftMask,		XK_minus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%-; kill -44 $(pidof dwmblocks)") },
{ MODKEY,			XK_plus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+; kill -44 $(pidof dwmblocks)") },
{ MODKEY|ShiftMask,		XK_plus,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 15%+; kill -44 $(pidof dwmblocks)") },
{ MODKEY,			XK_Tab,		view,		{0} },
{ MODKEY,			XK_w,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
{ MODKEY|ShiftMask,		XK_w,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "sudo", "nmtui", NULL } } },
{ MODKEY,			XK_e,		spawn,		{.v = (const char*[]){ EMAILCLIENT, NULL } } },
{ MODKEY|ShiftMask,		XK_e,		spawn,		SHCMD(TERMINAL " -e abook -C ~/.config/abook/abookrc --datafile ~/.config/abook/addressbook") },
{ MODKEY,			XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "lfub", NULL } } },
{ MODKEY|ShiftMask,		XK_r,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
{ MODKEY|ShiftMask,		XK_y,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ytfzf", "-t", NULL } } },
{ MODKEY,			XK_n,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "nvim", "-c", "WikiIndex", NULL } } },

{ MODKEY|ShiftMask,		XK_m,		spawn,		SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },

{ MODKEY,			XK_Page_Up,	shiftview,	{ .i = -1 } },
{ MODKEY|ShiftMask,		XK_Page_Up,	shifttag,	{ .i = -1 } },
{ MODKEY,			XK_Page_Down,	shiftview,	{ .i = +1 } },
{ MODKEY|ShiftMask,		XK_Page_Down,	shifttag,	{ .i = +1 } },

{ MODKEY,			XK_F1,		spawn,		SHCMD("zathura /home/anton/Nextcloud/dox/important/tud-indexed-secret.pdf") },
{ MODKEY,			XK_F2,		spawn,		{.v = (const char*[]){ "displayselect", NULL } } },
{ MODKEY,			XK_F3,		spawn,		SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
{ MODKEY,			XK_F4,		spawn,		{.v = (const char*[]){ "maimpick", NULL } } },
{ MODKEY|ShiftMask,		XK_F4,		spawn,		SHCMD("maim -s | xclip -selection clipboard -t image/png") },
{ MODKEY,			XK_F5,		spawn,		{.v = (const char*[]){ "clipmenu", NULL } } },
{ MODKEY,			XK_F7,		spawn,		{.v = (const char*[]){ "dmenuunicode", NULL } } },
{ MODKEY,			XK_F9,		spawn,		{.v = (const char*[]){ "mounter", NULL } } },
{ MODKEY,			XK_F10,		spawn,		{.v = (const char*[]){ "unmounter", NULL } } },
{ MODKEY,			XK_F11,		spawn,		SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
{ MODKEY,			XK_F12,		spawn,		SHCMD("remaps") },

{ 0,				XK_Print,	spawn,		SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png && notify-send 'screenshot taken'") },
{ MODKEY,			XK_Print,	spawn,		{.v = (const char*[]){ "maimpick", NULL } } },
{ MODKEY,			XK_Print,	spawn,		{.v = (const char*[]){ "dmenurecord", NULL } } },
{ MODKEY|ShiftMask,		XK_Print,	spawn,		{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
{ MODKEY,			XK_Delete,	spawn,		{.v = (const char*[]){ "dmenurecord", "kill", NULL } } },
{ MODKEY,			XK_Scroll_Lock,	spawn,		SHCMD("killall screenkey || screenkey &") },

{ 0, XF86XK_AudioMute,		spawn,		SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle; kill -44 $(pidof dwmblocks)") },
{ 0, XF86XK_AudioRaiseVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%+; kill -44 $(pidof dwmblocks)") },
{ 0, XF86XK_AudioLowerVolume,	spawn,		SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 3%-; kill -44 $(pidof dwmblocks)") },
{ 0, XF86XK_AudioPrev,		spawn,		{.v = (const char*[]){ "mpc", "prev", NULL } } },
{ 0, XF86XK_AudioNext,		spawn,		{.v = (const char*[]){ "mpc",  "next", NULL } } },
{ 0, XF86XK_AudioPause,		spawn,		{.v = (const char*[]){ "mpc", "pause", NULL } } },
{ 0, XF86XK_AudioPlay,		spawn,		{.v = (const char*[]){ "mpc", "play", NULL } } },
{ 0, XF86XK_AudioStop,		spawn,		{.v = (const char*[]){ "mpc", "stop", NULL } } },
{ 0, XF86XK_AudioRewind,	spawn,		{.v = (const char*[]){ "mpc", "seek", "-10", NULL } } },
{ 0, XF86XK_AudioForward,	spawn,		{.v = (const char*[]){ "mpc", "seek", "+10", NULL } } },
{ 0, XF86XK_AudioMedia,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "ncmpcpp", NULL } } },
{ 0, XF86XK_AudioMicMute,	spawn,		SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
{ 0, XF86XK_PowerOff,		spawn,		{.v = (const char*[]){ "sysact", NULL } } },
{ 0, XF86XK_Calculator,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "bc", "-l", NULL } } },
{ 0, XF86XK_Sleep,		spawn,		{.v = (const char*[]){ "sudo", "-A", "zzz", NULL } } },
{ 0, XF86XK_WWW,		spawn,		{.v = (const char*[]){ BROWSER, NULL } } },
{ 0, XF86XK_DOS,		spawn,		{.v = termcmd } },
{ 0, XF86XK_ScreenSaver,	spawn,		SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
{ 0, XF86XK_TaskPane,		spawn,		{.v = (const char*[]){ TERMINAL, "-e", "htop", NULL } } },
{ 0, XF86XK_Mail,		spawn,		SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
{ 0, XF86XK_MyComputer,		spawn,		{.v = (const char*[]){ TERMINAL, "-e",  "lfub",  "/", NULL } } },
/* { 0, XF86XK_Battery,		spawn,		SHCMD("") }, */
{ 0, XF86XK_Launch1,		spawn,		{.v = (const char*[]){ "xset", "dpms", "force", "off", NULL } } },
{ 0, XF86XK_TouchpadToggle,	spawn,		SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
{ 0, XF86XK_TouchpadOff,	spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=1", NULL } } },
{ 0, XF86XK_TouchpadOn,		spawn,		{.v = (const char*[]){ "synclient", "TouchpadOff=0", NULL } } },
{ 0, XF86XK_MonBrightnessUp,	spawn,		{.v = (const char*[]){ "brightnessctl", "set", "+15%", NULL } } },
{ 0, XF86XK_MonBrightnessDown,	spawn,		{.v = (const char*[]){ "brightnessctl", "set", "15%-", NULL } } },
{ MODKEY,			XK_d,		spawn,          {.v = (const char*[]){ "dmenu_run", NULL } } },
{ MODKEY,		        XK_Return,     spawn,                  {.v = termcmd } },
{ MODKEY|ControlMask,           XK_p,          riospawnsync,           {.v = dmenucmd } },
{ MODKEY|ControlMask,           XK_Return,     riospawn,               {.v = termcmd } },
{ MODKEY,                       XK_s,          rioresize,              {0} },
{ MODKEY,                       XK_b,          togglebar,              {0} },
{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
{ MODKEY,                       XK_space,          swapfocus,              {.i = -1 } },
{ MODKEY,                       XK_v,          switchcol,              {0} },
{ MODKEY|ShiftMask,             XK_i,          incnmaster,             {.i = +1 } },
{ MODKEY|ShiftMask,             XK_d,          incnmaster,             {.i = -1 } },
{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
{ MODKEY|ShiftMask,             XK_h,          setcfact,               {.f = +0.25} },
{ MODKEY|ShiftMask,             XK_l,          setcfact,               {.f = -0.25} },
{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
{ MODKEY,                       XK_x,          transfer,               {0} },
{ MODKEY|ShiftMask, 	        XK_x,          transferall,            {0} },
{ MODKEY|ControlMask,           XK_d,          distributetags,         {0} },
{ MODKEY|ShiftMask,             XK_space,     	zoom,                   {0} },
{ MODKEY,              		XK_g,          togglegaps,             {0} },
{ MODKEY|ShiftMask, 		XK_g, 		incrgaps, 		{.i = 5} },    // Increment gaps by 5
{ MODKEY|ControlMask|ShiftMask, XK_g, 		defaultgaps, 		{0} },    // Increment gaps by 5
{ Mod1Mask,                     XK_Tab,        alttabstart,            {0} },
{ MODKEY,             		XK_q,          killclient,             {0} },
{ MODKEY|ShiftMask,             XK_q,          killunsel,              {0} },
{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
{ MODKEY, 			XK_o, 		winview,		{0} },
{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
{ MODKEY,                       XK_c,          setlayout,              {.v = &layouts[3]} },
{ MODKEY|ShiftMask,             XK_f, 		togglefloating,         {0} },
{ MODKEY|ShiftMask, 	        XK_Return,	togglescratch,     		        {.v = scratchpadcmd } },
{ MODKEY, 	        	XK_dead_circumflex,      	setscratch,             {.v = scratchpadcmd } },
{ MODKEY|ShiftMask,         	XK_dead_circumflex,      	removescratch,          {.v = scratchpadcmd } },
{ MODKEY|ControlMask,           XK_f,  	 	unfloatvisible,         {0} },
{ MODKEY,                       XK_y,          togglefullscreen,       {0} },
{ MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
{ MODKEY,                       XK_period,      focusmon,               {.i = 1 } },
{ MODKEY|ControlMask|ShiftMask,  XK_comma,      tagallmon,              {.i = +1 } },
{ MODKEY|ControlMask|ShiftMask,  XK_period,     tagallmon,              {.i = -1 } },
{ MODKEY|ControlMask,  		XK_comma,      tagswapmon,             {.i = +1 } },
{ MODKEY|ControlMask,  		XK_period,     tagswapmon,             {.i = -1 } },
{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
{ MODKEY|ShiftMask,           XK_F1,         tagall,                 {.v = "1"} },
{ MODKEY|ShiftMask,           XK_F2,         tagall,                 {.v = "2"} },
{ MODKEY|ShiftMask,           XK_F3,         tagall,                 {.v = "3"} },
{ MODKEY|ControlMask,         XK_F4,         tagall,                 {.v = "4"} },
{ MODKEY|ShiftMask,           XK_F5,         tagall,                 {.v = "5"} },
{ MODKEY|ShiftMask,           XK_F6,         tagall,                 {.v = "6"} },
{ MODKEY|ShiftMask,           XK_F7,         tagall,                 {.v = "7"} },
{ MODKEY|ShiftMask,           XK_F8,         tagall,                 {.v = "8"} },
{ MODKEY|ShiftMask,           XK_F9,         tagall,                 {.v = "9"} },
{ MODKEY|ShiftMask,             XK_b,          togglealttag,           {0} },
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
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

