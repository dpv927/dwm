#pragma once
#include <X11/X.h>
#include <X11/XF86keysym.h>
#include <X11/keysym.h>
#include "dwm.h"
#include "objects.h"
#include "fibonacci.h"
#include "themes/catppuccin.h"

/* Patch: Custom rate. Sets the fps to a fixed number.
 * Warning: Its not recomendable to use a number above your
 * screen refresh rate. */
static const unsigned int fps       = 60;

/* Patch: Follow window. If the value is 1, when you send
 * a window to a different workspace, you will also go to
 * that workspace. */
static const unsigned int followwin = 1;

/* Patch: Underline tags */
static const unsigned int ulinepad      = 0;
static const unsigned int ulinestroke   = 3;
static const unsigned int ulinevoffset  = 0;
static const int ulineall               = 0;

/* Patch: Vanity gaps. Gaps between windows */ 
static const unsigned int gappih    = 5;   
static const unsigned int gappiv    = 5;   
static const unsigned int gappoh    = 5;
static const unsigned int gappov    = 5;
static const int smartgaps          = 0;    

/* Patch: Statuspadding. Bar inner padding */
static const int horizpadbar        = 0;
static const int vertpadbar         = 20;

/* Some Dwm settings */
static const unsigned int borderpx  = 0;
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
static const char* fonts[] = { "Cascadia Code:size=12" };

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
	[SchemeNorm] = { foreground, background, background },
	[SchemeSel]  = { foreground, background, background },
};

/* Bar tag colors. Defines the foreground and background colors
 * of the statusbar tags when they are selected, overwriting those
 * colors from colors[SchemeSel].
 *
 * Each pair { "#col1", "#col2" } of the array indicates that
 * the foreground of the tag will be #col1 and the background #col2.
 * * * * */
static const char *tagsel[][2] = {
  { tagfg,  background },
  { tagfg,  background },
  { tagfg,  background },
  { tagfg,  background },
  { tagfg,  background },
  { tagfg,  background },
  { tagfg,  background },
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
static const float mfact        = 0.5;  // factor of master area size [0.05..0.95]
static const int nmaster        = 1;    // number of clients in master area
static const int resizehints    = 1;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1;    // 1 will force focus on the fullscreen window

/* The array layouts[] defines the possible layouts that can be applied 
 * to a Dwm desktop. 
 *
 * The pairs { "rep", func} define a layout with a "rep" representation in the 
 * statusbar and func will be the function to invoke to organize the windows. 
 * * * * */
static const Layout layouts[] = {
    { "<@>",      tile },
    { "><>",      NULL },
    { "[\\]",     dwindle },
    { "[@]",      spiral },
    { "[M]",      monocle },
};

/* Key definitions. 
 * The MODKEY variable tells what key must be pressed first in  keybinding
 * to spawn a dwm 'command'. If MODKEY is defined to Mod4Mask, the first key
 * of that keybinding must be the Win key.
 * 
 * The TAGKEYS macro will be usefull later on. It defines the basic keybidings
 * to operate with the dwm workspaces.
 * * * * */
#define NONKEY 0
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* Shell command helper.
 * It is used to execute commands that someone would usually do in a shell in order
 * to run programs with specific arguments. 
 *
 * In this way it is possible to run programs external to dwm such as a terminal,
 * a browser...Everything is possible,
 * * * * */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* Shell commands definition. In the previous macro commentary it was explained what
 * SHCMD was for. Well, the following macros define default applications or specific
 * commands to be executed later with SHCMD 
 * * * * */
#define launcher    "dmenu_run"
#define terminal    "st"
#define navigator   "firefox"
#define printScreen "scrot"
#define screenshot  "flameshot gui"
#define colorPicker "xcolor | tr -d '\n' | xclip -selection clipboard"
#define upvolume    "pactl set-sink-volume @DEFAULT_SINK@ +5%"
#define downvolume  "pactl set-sink-volume @DEFAULT_SINK@ -5%"
#define mutevolume  "pactl set-sink-mute @DEFAULT_SINK@ toggle"
#define upbright    "brightnessctl set 10%+"
#define downbright  "brightnessctl set 10%-"
#define shutdown    "systemctl poweroff"
#define hibernate   "systemctl hibernate"
#define reboot      "systemctl reboot"
#define killDwn     "killall dwm"

/* Definition of keybidings. With these key combinations you
 * open and close applications, adjust window gaps and restart
 * or kill Dwm. 
 * * * * */
static const Key keys[] = {

    /* --- Favourite applications ---*/
    { MODKEY,                       XK_d,       spawn,          SHCMD(launcher)},
    { MODKEY,                       XK_Return,  spawn,          SHCMD(terminal)},
    { MODKEY,                       XK_f,       spawn,          SHCMD(navigator)},
    
    /* --- Tools - Utils ---*/
    { MODKEY,                       XK_s,       spawn,          SHCMD(printScreen)}, 
    { MODKEY|ShiftMask,             XK_s,       spawn,          SHCMD(screenshot)}, 
    { MODKEY,                       XK_p,       spawn,          SHCMD(colorPicker)}, 
   
     /* Hardware control */
    {NONKEY, XF86XK_AudioLowerVolume,           spawn,          SHCMD(downvolume)},
    {NONKEY, XF86XK_AudioRaiseVolume,           spawn,          SHCMD(upvolume)},
    {NONKEY, XF86XK_AudioMute,                  spawn,          SHCMD(mutevolume)},
    {NONKEY, XF86XK_MonBrightnessUp,            spawn,          SHCMD(upbright)},
    {NONKEY, XF86XK_MonBrightnessDown,          spawn,          SHCMD(upbright)},

    /* --- System bindings --- */
    { MODKEY|ControlMask,           XK_s,       spawn,          SHCMD(shutdown)},
    { MODKEY|ControlMask,           XK_h,       spawn,          SHCMD(hibernate)},
    { MODKEY|ControlMask,           XK_r,       spawn,          SHCMD(reboot)},
    { MODKEY|ShiftMask,             XK_q,       spawn,          SHCMD(killDwn) },
    { MODKEY|ShiftMask,             XK_r,       restart,        {0} },

    /* --- Window bindings --- */
    { MODKEY,                       XK_b,       togglebar,      {0} },
    { MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
    { MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
    { MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
    { MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
    { MODKEY,                       XK_Tab,     view,           {0} },
    { MODKEY,   		            XK_q,       killclient,     {0} },
    { MODKEY,                       XK_t,       setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_r,       setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,       setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_space,   setlayout,      {0} },
    { MODKEY,                       XK_comma,   focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period,  focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_i,       incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,             XK_d,       incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,             XK_Return,  zoom,           {0} },
    { MODKEY|ShiftMask,             XK_space,   togglefloating, {0} },
    { MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_f,       fullscreen,     {0} },
	{ MODKEY|ShiftMask,             XK_l,       layoutscroll,   {.i = +1 } },

    /* --- Tag keys ---*/
    TAGKEYS(                        XK_1,                       0)
    TAGKEYS(                        XK_2,                       1)
    TAGKEYS(                        XK_3,                       2)
    TAGKEYS(                        XK_4,                       3)
    TAGKEYS(                        XK_5,                       4)
    TAGKEYS(                        XK_6,                       5)
    TAGKEYS(                        XK_7,                       6)
    TAGKEYS(                        XK_8,                       7)
    TAGKEYS(                        XK_9,                       8)
};

/* Definition of events that are executed when clicking in
 * different ways. 
 * * * * */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    //{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          SHCMD(terminal) },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
