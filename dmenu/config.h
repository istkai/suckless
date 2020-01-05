/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static int topbar = 0;                      /* -b  option; if 0, dmenu appears at bottom     */
/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"SF Pro Text:size=10"
};
static const char *prompt      = NULL;      /* -p  option; prompt to the left of input field */

static const char col_gray1[]       =  "#222222";
static const char col_gray2[]       =  "#444444";
static const char col_gray3[]       =  "#bbbbbb";
static const char col_white[]	    =  "#FFFFFF";
static const char col_black[]	    =  "#000000";
static const char col_out_b[]       =  "#00FFFF";
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

static const char *colors[SchemeLast][2] = {
	/*               fg         bg        */
	[SchemeNorm] = { col_white, col_bg_c  },
	[SchemeSel] =  { col_bg_c,  col_fg_y  },
	[SchemeOut] =  { col_black, col_out_b },
};
/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines      = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
