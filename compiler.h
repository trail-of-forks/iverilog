#ifndef __compiler_H
#define __compiler_H
/*
 * Copyright (c) 1999-2000 Stephen Williams (steve@icarus.com)
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#ifdef HAVE_CVS_IDENT
#ident "$Id: compiler.h,v 1.18 2003/11/08 20:06:21 steve Exp $"
#endif

# include  <list>
# include  <map>
# include  <string>
# include  "StringHeap.h"

/*
 * This defines constants and defaults for the compiler in general.
 */


/* The INTEGER_WIDTH is the default width of integer variables, and
   the presumed width of unsigned literal numbers. */
#ifndef INTEGER_WIDTH
# define INTEGER_WIDTH 32
#endif

/* The TIME_WIDTH is the width of time variables. */
#ifndef TIME_WIDTH
# define TIME_WIDTH 64
#endif

/*
 * When doing dynamic linking, we need a uniform way to identify the
 * symbol. Some compilers put leading _, some trailing _. The
 * configure script figures out which is the local convention and
 * defines NEED_LU and NEED_TU as required.
 */
#ifdef NEED_LU
#define LU "_"
#else
#define LU ""
#endif

#ifdef NEED_TU
#define TU "_"
#else
#define TU ""
#endif


/*
 * These are flags to enable various sorts of warnings. By default all
 * the warnings are off, the -W<list> parameter arranges for each to be
 * enabled. 
 */

/* Implicit definitions of wires. */
extern bool warn_implicit;
extern bool error_implicit;

/* inherit timescales across files. */
extern bool warn_timescale;

/* Warn about legal but questionable module port bindings. */
extern bool warn_portbinding;

/* This is true if verbose output is requested. */
extern bool verbose_flag;

/* This is an ordered list of library suffixes to search. */
extern list<const char*>library_suff;
extern int build_library_index(const char*path, bool key_case_sensitive);

/* This is the generation of Verilog that the compiler is asked to
   support. */
enum generation_t {
      GN_VER1995  = 1,
      GN_VER2001  = 2,
      GN_SYSVER30 = 3,
      GN_DEFAULT  = 3
};

extern generation_t generation_flag;

  /* This is the string to use to invoke the preprocessor. */
extern char*ivlpp_string;

extern map<string,unsigned> missing_modules;

extern StringHeapLex lex_strings;

/*
 * $Log: compiler.h,v $
 * Revision 1.18  2003/11/08 20:06:21  steve
 *  Spelling fixes in comments.
 *
 * Revision 1.17  2003/09/25 00:25:14  steve
 *  Summary list of missing modules.
 *
 * Revision 1.16  2003/03/01 06:25:30  steve
 *  Add the lex_strings string handler, and put
 *  scope names and system task/function names
 *  into this table. Also, permallocate event
 *  names from the beginning.
 *
 * Revision 1.15  2003/02/22 04:12:49  steve
 *  Add the portbind warning.
 *
 * Revision 1.14  2003/01/30 16:23:07  steve
 *  Spelling fixes.
 *
 * Revision 1.13  2002/08/12 01:34:58  steve
 *  conditional ident string using autoconfig.
 *
 * Revision 1.12  2002/05/28 20:40:37  steve
 *  ivl indexes the search path for libraries, and
 *  supports case insensitive module-to-file lookup.
 *
 * Revision 1.11  2002/05/28 00:50:39  steve
 *  Add the ivl -C flag for bulk configuration
 *  from the driver, and use that to run library
 *  modules through the preprocessor.
 *
 * Revision 1.10  2002/05/24 01:13:00  steve
 *  Support language generation flag -g.
 *
 * Revision 1.9  2002/04/22 00:53:39  steve
 *  Do not allow implicit wires in sensitivity lists.
 *
 * Revision 1.8  2002/04/15 00:04:22  steve
 *  Timescale warnings.
 *
 * Revision 1.7  2001/11/16 05:07:19  steve
 *  Add support for +libext+ in command files.
 */
#endif
