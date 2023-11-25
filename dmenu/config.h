#include "themes/onedark_pro.h"

/* Patch: bar height */
static const int user_bt = 20;

/* Default variables */ 
static unsigned int lines   = 0;
static int topbar           = 1;
static const char worddelimiters[] = " ";
static const char* prompt = NULL;

/* Color scheme */
static const char *colors[SchemeLast][2] = {
	[SchemeNorm] = { NormForeground, NormBackground },
	[SchemeSel]  = { SelForeground,  SelBackground  },
	[SchemeOut]  = { OutForeground,  OutBackground  },
};
