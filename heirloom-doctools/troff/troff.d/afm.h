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
 * Sccsid @(#)afm.h	1.4 (gritter) 8/17/05
 */

extern struct afmtab {
	struct Font	Font;
	char	*path;
	char	*file;
	char	*fontname;
	char	*fontab;
	char	*kerntab;
	char	*codetab;
	char	*fitab;
	char	**nametab;
	int	rq;
	int	lineno;
	int	nchars;
	int	capheight;
} **afmtab;
extern int nafm;

extern int	afmget(struct afmtab *, char *, size_t);