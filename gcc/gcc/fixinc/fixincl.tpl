[= autogen template -*- Mode: C -*-
x =]
/*
 *  DO NOT EDIT THIS FILE - it has been generated
 *
 * Install modified versions of certain ANSI-incompatible system header
 * files which are fixed to work correctly with ANSI C and placed in a
 * directory that GNU C will search.
 *
 * This file contains [=_eval fix _count =] fixup descriptions.
 *
 * See README-fixinc for more information.
 *
 *  inclhack copyright (c) [=_eval "date +%Y" _shell
                                =] The Free Software Foundation, Inc.
 *
[=_eval inclhack "# *  " _gpl=]
 *[=_EVAL "re_ct=0" _shell=][=

_FOR fix =]
 *
 *  Description [=_eval _index 1 + "#%3d -" _printf=] [=hackname _Cap=] fix
 */
tSCC z[=hackname _cap=]Name[] =
     [=hackname _cap _krstr=];
/*
 *  File name selection pattern
 */[=

  _IF files _exist=]
tSCC z[=hackname _cap=]List[] =
  "[=_FOR files =]|[=files=][=/files=]|";[=

  _ELSE =]
#define z[=hackname _cap=]List (char*)NULL[=
  _ENDIF "files _exist" =]
/*
 *  Machine/OS name selection pattern
 */[=

  _IF mach _exist=]
tSCC* apz[=hackname _cap=]Machs[] = {[=
    _FOR mach =]
        [=mach _krstr=],[=
    /mach=]
        (const char*)NULL };[=

  _ELSE =]
#define apz[=hackname _cap=]Machs (const char**)NULL[=
  _ENDIF "files _exist" =][=

  _IF exesel _exist=]

/*
 *  content selection pattern - do fix if pattern found
 *  This is a special pattern that not all egrep commands
 *  are capable of coping with.  We use the GNU library, tho :)
 */[=
    _FOR exesel =]
tSCC z[=hackname _cap=]Select[=_eval _index=][] =
       [=exesel _krstr=];[=
    /exesel =][=

  _ELIF select _exist=]

/*
 *  content selection pattern - do fix if pattern found
 */[=
    _FOR select =]
tSCC z[=hackname _cap=]Select[=_eval _index=][] =
       [=select _krstr=];[=
    /select =][=
  _ENDIF =][=

  _IF bypass _exist=]

/*
 *  content bypass pattern - skip fix if pattern found
 */[=
    _FOR bypass =]
tSCC z[=hackname _cap=]Bypass[=_eval _index=][] =
       [=bypass _krstr=];[=
    /bypass =][=
  _ENDIF =][=

  _IF test _exist=]

/*
 *  perform the 'test' shell command - do fix on success
 */[=
    _FOR test =]
tSCC z[=hackname _cap=]Test[=_eval _index=][] =
       [=test _krstr=];[=
    /test =][=
  _ENDIF =][=


#  Build the array of test descriptions for this fix: =][=

  _IF exesel       _exist
      select       _exist |
      bypass       _exist |
      test         _exist |
=]

#define    [=hackname _up =]_TEST_CT  [=
    _IF exesel _exist =][=
       _eval exesel       _count
      	     bypass       _count +
      	     test         _count + =][=
    _ELSE =][=
       _eval select       _count
      	     bypass       _count +
      	     test         _count + =][=
    _ENDIF =]
#define    [=hackname _up =]_RE_CT    [=
    _IF exesel _exist =][=
       _eval exesel _count bypass _count
             "#2$ct=`expr %d + %d` ; re_ct=`expr $ct + $re_ct` ; echo $ct"
             _printf _shell =][=
    _ELSE =][=
       _eval select _count bypass _count
             "#2$ct=`expr %d + %d` ; re_ct=`expr $ct + $re_ct` ; echo $ct"
             _printf _shell =][=
    _ENDIF =]
tTestDesc a[=hackname _cap=]Tests[] = {[=

    _FOR test =]
  { TT_TEST,   z[=hackname _cap=]Test[=_eval _index=],     0 /* unused */ },[=
    /test =][=

    _FOR bypass =]
  { TT_NEGREP, z[=hackname _cap=]Bypass[=_eval _index=],   (regex_t*)NULL },[=
    /bypass =][=

    #  IF there is an exesel, then use that (those) selection
          expressions, instead of the regular select expressions
    =][=
    _IF exesel _exist =][=
      _FOR exesel =]
  { TT_EGREP,  z[=hackname _cap=]Select[=_eval _index=],   (regex_t*)NULL },[=
      /exesel =][=

    _ELSE =][=
      _FOR select =]
  { TT_EGREP,  z[=hackname _cap=]Select[=_eval _index=],   (regex_t*)NULL },[=
      /select =][=
    _ENDIF =] };[=
  _ELSE =]
#define [=hackname _up=]_TEST_CT  0
#define [=hackname _up=]_RE_CT    0
#define a[=hackname _cap=]Tests   (tTestDesc*)NULL[=
  _ENDIF =]

/*
 *  Fix Command Arguments for [=hackname _cap=]
 */
const char* apz[=hackname _cap=]Patch[] = {[=
    _IF   sed         _exist =] "sed"[=_FOR sed=],
    "-e", [=sed _krstr=][=/sed=][=
    _ELIF shell       _exist =] "sh", "-c",
    [=shell _krstr=][=
    _ENDIF=],
    (char*)NULL };

/* * * * * * * * * * * * * * * * * * * * * * * * * *[=
/fix=]
 *
 *  List of all fixes
 */
#define  REGEX_COUNT  [=_eval "echo $re_ct" _shell =]
#define  FIX_COUNT    [=_eval fix _count =]
tFixDesc fixDescList[ FIX_COUNT ] = {[=


_FOR fix ",\n" =]
  {  z[=hackname _cap=]Name,    z[=hackname _cap=]List,
     apz[=hackname _cap=]Machs, (regex_t*)NULL,
     [=hackname  _up=]_TEST_CT, [=
       _IF not_machine _exist =]FD_MACH_IFNOT[=
       _ELSE                  =]FD_MACH_ONLY[=
       _ENDIF =][=
       _IF shell       _exist =] | FD_SHELL_SCRIPT[=
       _ENDIF =],
     a[=hackname _cap=]Tests,   apz[=hackname _cap=]Patch }[=

/fix=]
};
