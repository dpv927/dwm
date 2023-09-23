#pragma once
#include <X11/keysym.h>
#include "dwm.h"
#include "objects.h"
#include "fibonacci.h"
#include "themes/catppuccin.h"

/* Patch: Vanity gaps. Gaps between windows */ 
static const unsigned int gappih    = 20;   
static const unsigned int gappiv    = 20;   
static const unsigned int gappoh    = 20;
static const unsigned int gappov    = 20;
static const int smartgaps          = 0;    

/* Patch: Statuspadding. Bar inner padding */
static const int horizpadbar        = 0;
static const int vertpadbar         = 40;

/* Some Dwm settings */
static const unsigned int borderpx  = 8;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;

/* In the fonts[] array you can define several fonts if you want.
 * This can be used to be able to put more than one type of font 
 * at the statusbar tags or text.
 *
 * At the fonts[] array, you can define various fonts  
 * you want to have some backup fonts
 * * * * */
static const char* fonts[]          = { "Jetbrains Mono Nerd Font:size=12" };
static const char  dmenufont[]      = "Jetbrains Mono Nerd Font:size=12";

/* Bar color theme. Defines the color of the bar and windows colors.
 * The order is the following one: {foreground, background, border}.
 *
 * - <SchemeNorm>: Scheme to apply to non-focused windows.
 * - <SchemeSel>: Scheme to apply to focused windows.
 *
 *  Be aware that this colors will also be applied at the dwm status
 *  bar and its items.
 * * * * */
static const char* colors[][3] = {
	[SchemeNorm] = { white,   black, border },
	[SchemeSel]  = { title,   black, border },
};

/* Bar tag colors. Defines the foreground and background colors
 * of the statusbar tags when they are selected, overwriting those
 * colors from colors[SchemeSel].
 *
 * Each pair { "#col1", "#col2" } of the array indicates that
 * the foreground of the tag will be #col1 and the background #col2.
 * * * * */
static const char *tagsel[][2] = {
	{ magenta,  active },
    { yellow,   active },
    { green,    active },
    { red,      active },
    { blue,     active },
    { cyan,     active },
    { magenta,  active }
};

/* The tags[] array defines the icons or characters that will
 * represent each of the Dwm workspaces in the statusbar. 
 * * * * */
static const char *tags[] = { "  ", "  ", "  ", "  ", "  ", "  ", "  " };

/* This array defines the rules for behavior different from
 * the usual behavior of certain applications. 
 *
 * An example can be to make an application open in tiled 
 * (normal) or floating mode. 
 * * * * */
static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* Layout(s) constants */
static const float mfact     = 0.5;  // factor of master area size [0.05..0.95]
static const int nmaster     = 1;    // number of clients in master area
static const int resizehints = 1;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1; // 1 will force focus on the fullscreen window

/* The array layouts[] defines the possible layouts that can be applied 
 * to a Dwm desktop. 
 *
 * The pairs { "rep", func} define a layout with a "rep" representation in the 
 * statusbar and func will be the function to invoke to organize the windows. 
 * * * * */
static const Layout layouts[] = {
    { "[]=",      tile },
	{ "><>",      NULL },
    { "[\\]",     dwindle },
    { "[@]",      spiral },
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* Define a shell command helper */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Definition of keybidings. With these key combinations you
 * open and close applications, adjust window gaps and restart
 * or kill Dwm. 
 * * * * */
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_d,      spawn,          SHCMD("dmenu_run") },
	{ MODKEY,	                    XK_Return, spawn,          SHCMD("st") },
	{ MODKEY|ShiftMask,   		    XK_f,	   spawn,          SHCMD("firefox") },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,   		            XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("killall dwm") },
    { MODKEY|ShiftMask,             XK_r,      restart,        {0} },

    /* Vanity gaps: modify window gaps */
    { MODKEY,                       XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY,                       XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|ControlMask,           XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|ControlMask,           XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },  

    /* Tag keys */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* Definition of events that are executed when clicking in
 * different ways. 
 * * * * */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          SHCMD("st") },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
