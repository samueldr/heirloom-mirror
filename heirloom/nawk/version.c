#include "awk.h"
#ifndef	SUS
const char version[] = "@(#)nawk.sl  1.38 (gritter) 12/4/04";
int	posix = 0;
#include "pfmt.h"
#include <ctype.h>
int
vpfmt(FILE *stream, long flags, const char *fmt, va_list ap)
{
	extern char	*pfmt_label__;
	int	n = 0;

	if ((flags & MM_NOGET) == 0) {
		if (*fmt == ':') {
			do
				fmt++;
			while (*fmt != ':');
			fmt++;
		}
	}
	if ((flags & MM_NOSTD) == 0)
		n += fprintf(stream, "%s: ", pfmt_label__);
	if ((flags & MM_ACTION) == 0 && isupper(*fmt&0377))
		n += fprintf(stream, "%c", tolower(*fmt++&0377));
	n += vfprintf(stream, fmt, ap);
	return n;
}
#else
const char version[] = "@(#)awk_sus.sl  1.38 (gritter) 12/4/04";
int	posix = 1;
#endif
/*
awk.g.y:
	awk.g.y	1.8 (gritter) 12/4/04
awk.h:
	awk.h	1.22 (gritter) 12/4/04
awk.lx.l:
	awk.lx.l	1.10 (gritter) 12/4/04
b.c:
	b.c	1.6 (gritter) 5/15/04
lib.c:
	lib.c	1.22 (gritter) 12/4/04
main.c:
	main.c	1.13 (gritter) 12/4/04
maketab.c:
	maketab.c	1.11 (gritter) 12/4/04
nawk.1:
	nawk.1	1.19 (gritter) 5/15/04
parse.c:
	parse.c	1.7 (gritter) 12/4/04
run.c:
	run.c	1.27 (gritter) 12/4/04
tran.c:
	tran.c	1.14 (gritter) 12/4/04
*/
