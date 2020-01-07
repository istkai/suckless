/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  =  1;        /* border pixel of windows */
static const unsigned int snap      =  1;        /* snap pixel */
static const unsigned int gappx     =  2;
static const int showbar            =  1;        /* 0 means no bar */
static const int topbar             =  1;        /* 0 means bottom bar */
static const char *fonts[]          = {"SF Pro Text:size=8" };
static const char dmenufont[]       =  "SF Pro Text:size=8";
static const char col_gray1[]       =  "#222222";
static const char col_gray2[]       =  "#444444";
static const char col_gray3[]       =  "#bbbbbb";
static const char col_white[]	    =  "#FFFFFF";
static const char col_black[]	    =  "#000000";
static const char col_purple[]      =  "#BD93F9";
static const char col_green[]       =  "#50FA7B";
static const char col_yellow[]	    =  "#F1FA8C";
static const char col_magenta[]     =  "#FF79C6";
static const char col_bg_d[]        =  "#282A36";
static const char col_bg_c[]        =  "#1C1C1C";
static const char col_fg_w[]        =  "#F8F8F2";
static const char col_fg_y[]        =  "#F9CE74";
static const char col_fg_o[]        =  "#EA7217";
static const char col_gray4[]       =  "#eeeeee";
static const char col_cyan[]        =  "#8BE9FD";
static const char *colors[][3]      = {
	/*               fg        bg            border   */
	[SchemeNorm] = { col_fg_w, col_bg_c,     col_bg_c },
	[SchemeSel]  = { col_bg_c, col_fg_y,     col_bg_c  },
};
static const unsigned int baralpha = 0xcc;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
       /* class           instance    title       		tags mask     iscentered      isfloating   monitor */
	{ "Gimp",         NULL,       NULL,       		0,            1,              1,           -1 },
	{ "Firefox",      NULL,       NULL,       		1 << 8,       1,              0,           -1 },
	{ "qutebrowser",  NULL,       NULL,       		1,            1,              0,           -1 },
        { "Surf",         "surf",     NULL,       		1,            1,              0,           -1 },
	{ "Spotify",      "spotify",  NULL,                     1 << 7,	      1,              0,           -1 },
	{ "St",           "st",       "ranger",                 1 << 3,	      1,              0,           -1 },
	{ "St",           "st",       NULL,                     0,	      1,              0,           -1 },
	{ "St",           "st",       "htop",                   0,	      1,              1,           -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static const char *dmenucmd[]   = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_bg_c, "-nf", col_white, "-sb", col_fg_y, "-sf", col_bg_c, NULL };
static const char *termcmd[]    = { "st", NULL };
static const char *fibrowser[]  = { "firefox", NULL };
static const char *subrowser[]  = { "tabbed", "surf", "-pe", NULL };
static const char *qubrowser[]  = { "qutebrowser", NULL};
static const char *file[]       = { "st", "ranger", NULL };
static const char *monitor[]    = { "st", "htop", NULL };
static const char *music[]      = { "spotify", NULL };
static const char *yout[]       = { "gtk-youtube-viewer", NULL };
static const char *style[]      = { "lxappearance", NULL };
static const char *colour[]     = { "gpick", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_y,      spawn,          {.v = yout } },
	{ MODKEY,                       XK_c,      spawn,          {.v = colour } },
	{ MODKEY,                       XK_l,      spawn,          {.v = style } },
	{ MODKEY,                       XK_i,      spawn,          {.v = monitor } },
	{ MODKEY,                       XK_s,      spawn,          SHCMD("exec $HOME/.scrot.sh") },
	{ MODKEY,                       XK_r,      spawn,          {.v = file } },
	{ MODKEY,                       XK_w,      spawn,          {.v = fibrowser } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = subrowser } },
	{ MODKEY|ControlMask,           XK_w,      spawn,          {.v = qubrowser } },
	{ MODKEY|ShiftMask,             XK_j,      rotatestack,    {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      rotatestack,    {.i = -1 } },
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      spawn,          {.v = music } },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

