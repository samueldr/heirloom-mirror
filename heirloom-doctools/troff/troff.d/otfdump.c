/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */

/*
 * Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)otfdump.c	1.1 (gritter) 9/30/05
 */

static enum {
	SHOW_CHARS		= 001,
	SHOW_KERNPAIRS		= 002,
	SHOW_SUBSTITUTIONS	= 004,
	SHOW_NAME		= 010
} show;

#define	DUMP
#include <stdio.h>
#undef	stderr
#define	stderr	troff_stderr
#include "otf.c"
#include "afm.c"
#undef	stderr
#include "dpost.d/getopt.c"
#include "../version.c"

#include <libgen.h>

static const char	*progname;
struct dev	dev;
char	*chname;
short	*chtab;
int	nchtab;

void
verrprint(const char *s, va_list ap)
{
	fprintf(stderr, "%s: ", progname);
	if (filename)
		fprintf(stderr, "%s: ", filename);
	vfprintf(stderr, s, ap);
	putc('\n', stderr);
}

void
errprint(const char *s, ...)
{
	va_list	ap;

	va_start(ap, s);
	verrprint(s, ap);
	va_end(ap);
}

static void
devinit(void)
{
	dev.res = 72000;
	dev.hor = dev.vert = 1;
	dev.unitwidth = 1;
	dev.afmfonts = 1;
}

static void
usage(void)
{
	errprint("usage: %s [-ckns] font", progname);
	exit(2);
}

int
main(int argc, char **argv)
{
	static struct afmtab	A;
	struct stat	st;
	int	i;
	FILE	*fp;

	progname = basename(argv[0]);
	devinit();
	while ((i = getopt(argc, argv, "ckns")) != EOF) {
		switch (i) {
		case 'c':
			show |= SHOW_CHARS;
			break;
		case 'k':
			show |= SHOW_KERNPAIRS;
			break;
		case 'n':
			show |= SHOW_NAME;
			break;
		case 's':
			show |= SHOW_SUBSTITUTIONS;
			break;
		default:
			usage();
		}
	}
	if (show == 0)
		show = 0xFFFFFFFF;
	if (argc != optind + 1)
		usage();
	if ((fp = fopen(filename = argv[optind], "r")) == NULL) {
		errprint("cannot open");
		return 1;
	}
	a = &A;
	a->file = a->path = (char *)filename;
	if (fstat(fileno(fp), &st) < 0) {
		errprint("cannot stat");
		return 1;
	}
	size = st.st_size;
	contents = malloc(size);
	if (fread(contents, 1, size, fp) != size) {
		errprint("cannot read");
		return 1;
	}
	fclose(fp);
	return otfget(a, contents, size) != 0;
}

void
afmaddchar(struct afmtab *a, int C, int tp, int cl, int WX, int B[4], char *N,
		int isS, int isS1, int gid)
{
	if (show & SHOW_CHARS)
		printf("char %s width %d\n", N, WX);
}

void
afmalloc(struct afmtab *a, int n)
{
}

struct kernpair *
afmkernlook(struct afmtab *a, int ch1, int ch2)
{
	static struct kernpair	k;

	return &k;
}

static void
kernpair(int first, int second, int x)
{
	char	*s1, *s2;

	if (x && show & SHOW_KERNPAIRS) {
		s1 = GID2SID(first);
		s2 = GID2SID(second);
		if (s1 && s2)
			printf("kernpair %s %s width %d\n",
				s1, s2, unitconv(x));
	}
}

static void
kernfinish(void)
{
}