#pragma once
#include <X11/Xlib.h>

/* Enumerations definition */
enum CursorTypes { CurNormal, CurResize, CurMove, CurLast };
enum ColorScheme { SchemeNorm, SchemeSel };

enum EwmhAtoms { 
    NetSupported, NetWMName, NetWMState, NetWMCheck,
    NetWMFullscreen, NetActiveWindow, NetWMWindowType,
    NetWMWindowTypeDialog, NetClientList, NetClientInfo, 
    NetLast
};

enum DefaultAtoms { 
    WMProtocols, WMDelete, WMState,
    WMTakeFocus, WMLast 
};

enum Clicks { 
    ClkTagBar, ClkLtSymbol, ClkStatusText, 
    ClkClientWin, ClkRootWin, ClkLast 
};

/* Structs definition */
typedef union Arg Arg;
typedef struct Button Button;
typedef struct Client Client;
typedef struct Key Key;
typedef struct Layout Layout;
typedef struct Monitor Monitor;
typedef struct Rule Rule ;

union Arg {
	int i;
	unsigned int ui;
	float f;
	const void *v;
};

struct Button {
	unsigned int click;
	unsigned int mask;
	unsigned int button;
	void (*func)(const Arg *arg);
	const Arg arg;
};

struct Client {
	char name[256];
	float mina, maxa;
	int x, y, w, h;
	int oldx, oldy, oldw, oldh;
	int basew, baseh, incw, inch, maxw, maxh, minw, minh, hintsvalid;
	int bw, oldbw;
	unsigned int tags;
	int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
	Client *next;
	Client *snext;
	Monitor *mon;
	Window win;
};

struct Key {
	unsigned int mod;
	KeySym keysym;
	void (*func)(const Arg *);
	const Arg arg;
};

struct Layout {
	const char *symbol;
	void (*arrange)(Monitor *);
};

struct Monitor {
	char ltsymbol[16];
	float mfact;
	int nmaster;
	int num;
	int by;               /* bar geometry */
	int mx, my, mw, mh;   /* screen size */
	int wx, wy, ww, wh;   /* window area  */
    int gappih;           /* horizontal gap between windows */
	int gappiv;           /* vertical gap between windows */
	int gappoh;           /* horizontal outer gaps */
	int gappov;           /* vertical outer gaps */
	unsigned int seltags;
	unsigned int sellt;
	unsigned int tagset[2];
	int showbar;
	int topbar;
	Client *clients;
	Client *sel;
	Client *stack;
	Monitor *next;
	Window barwin;
	const Layout *lt[2];
    int currlt; // current Layout
};

struct Rule {
	const char *clss;
	const char *instance;
	const char *title;
	unsigned int tags;
	int isfloating;
	int monitor;
};
