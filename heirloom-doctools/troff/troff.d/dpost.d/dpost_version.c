#if __GNUC__ >= 3 && __GNUC_MINOR__ >= 4 || __GNUC__ >= 4
#define	USED	__attribute__ ((used))
#elif defined __GNUC__
#define	USED	__attribute__ ((unused))
#else
#define	USED
#endif
static const char sccsid[] USED = "@(#)dpost.sl	4.22 (gritter) 10/1/05";
const char creator[] = "Heirloom Documentation Tools - dpost 4.22 (gritter) 10/1/05";
/* SLIST */
/*
asciitype.c:	Sccsid @(#)asciitype.c	1.4 (gritter) 4/17/03	
asciitype.h:	Sccsid @(#)asciitype.h	1.6 (gritter) 9/9/05	
color.c: * Sccsid @(#)color.c	1.3 (gritter) 8/9/05
comments.h: * Sccsid @(#)comments.h	1.5 (gritter) 8/23/05
dpost.c: * Sccsid @(#)dpost.c	1.93 (gritter) 10/1/05
dpost.h: * Sccsid @(#)dpost.h	1.6 (gritter) 10/1/05
dpost_afm.c: * Sccsid @(#)dpost_afm.c	1.2 (gritter) 9/29/05
dpost_draw.c: * Sccsid @(#)draw.c	1.3 (gritter) 8/9/05
dpost_makedev.c: * Sccsid @(#)dpost_makedev.c	1.1 (gritter) 9/4/05
dpost_otf.c: * Sccsid @(#)dpost_otf.c	1.2 (gritter) 9/29/05
ext.h: * Sccsid @(#)ext.h	1.3 (gritter) 8/9/05
gen.h: * Sccsid @(#)gen.h	1.9 (gritter) 9/8/05
getopt.c: * Sccsid @(#)getopt.c	1.8 (gritter) 8/2/05
glob.c: * Sccsid @(#)glob.c	1.3 (gritter) 8/9/05
misc.c: * Sccsid @(#)misc.c	1.6 (gritter) 9/27/05
path.h: * Sccsid @(#)path.h	1.3 (gritter) 8/9/05
pictures.c: * Sccsid @(#)pictures.c	1.4 (gritter) 9/9/05
ps_include.c: * Sccsid @(#)ps_include.c	1.5 (gritter) 8/13/05
request.c: * Sccsid @(#)request.c	1.3 (gritter) 8/9/05
request.h: * Sccsid @(#)request.h	1.3 (gritter) 8/9/05
../afm.c: * Sccsid @(#)afm.c	1.35 (gritter) 9/30/05
../afm.h: * Sccsid @(#)afm.h	1.15 (gritter) 9/30/05
../otf.c: * Sccsid @(#)otf.c	1.10 (gritter) 10/1/05
../makedev.c: * Sccsid @(#)makedev.c	1.10 (gritter) 9/8/05
../dev.h: * Sccsid @(#)dev.h	1.8 (gritter) 9/30/05
*/
