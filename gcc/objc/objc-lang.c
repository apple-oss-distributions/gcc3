/* Language-specific hook definitions for Objective-C front end.
   Copyright (C) 1991, 1995, 1997, 1998,
   1999, 2000, 2001 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free
Software Foundation; either version 2, or (at your option) any later
version.

GCC is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or
FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  */


#include "config.h"
#include "system.h"
#include "tree.h"
/* APPLE LOCAL Objective-C++ */
#ifdef OBJCPLUS
#include "cp-tree.h"
#else
#include "c-tree.h"
#endif
#include "objc-act.h"
#include "langhooks.h"
#include "langhooks-def.h"

/* APPLE LOCAL PFE */
#ifdef PFE
#include "pfe/pfe.h"
#include "pfe/objc-freeze-thaw.h"
#endif

/* APPLE LOCAL Objective-C++  */
static void lang_init_options PARAMS ((void));

/* APPLE LOCAL Objective-C++  */
#ifdef OBJCPLUS
#include "cp-lang.h"
#undef LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "GNU Objective-C++"
#else
#include "c-lang.h"
#undef LANG_HOOKS_NAME
#define LANG_HOOKS_NAME "GNU Objective-C"
#endif

/* APPLE LOCAL Objective-C++  */
/* Re-route some of the hooks through the ObjC front-end.  */
#undef LANG_HOOKS_DECODE_OPTION
#define LANG_HOOKS_DECODE_OPTION objc_decode_option
#undef LANG_HOOKS_INIT
#define LANG_HOOKS_INIT objc_init
#undef LANG_HOOKS_FINISH_FILE
#define LANG_HOOKS_FINISH_FILE objc_finish_file

/* APPLE LOCAL begin PFE */
#ifdef PFE
#undef LANG_HOOKS_PFE_LANG_INIT
#define LANG_HOOKS_PFE_LANG_INIT objc_pfe_lang_init
#undef LANG_HOOKS_PFE_FREEZE_THAW_COMPILER_STATE
#define LANG_HOOKS_PFE_FREEZE_THAW_COMPILER_STATE objc_freeze_thaw_compiler_state
#undef LANG_HOOKS_PFE_FREEZE_THAW_DECL
#define LANG_HOOKS_PFE_FREEZE_THAW_DECL	objc_pfe_freeze_thaw_decl
#undef LANG_HOOKS_PFE_FREEZE_THAW_TYPE
#define LANG_HOOKS_PFE_FREEZE_THAW_TYPE	objc_pfe_freeze_thaw_type
#undef LANG_HOOKS_PFE_FREEZE_THAW_SPECIAL
#define LANG_HOOKS_PFE_FREEZE_THAW_SPECIAL objc_pfe_freeze_thaw_special
#undef LANG_HOOKS_PFE_CHECK_ALL_STRUCT_SIZES
#define LANG_HOOKS_PFE_CHECK_ALL_STRUCT_SIZES objc_pfe_check_all_struct_sizes
#endif
/* APPLE LOCAL end PFE */

/* Each front end provides its own.  */
const struct lang_hooks lang_hooks = LANG_HOOKS_INITIALIZER;

static void
lang_init_options ()
{
  /* APPLE LOCAL compiling_objc  */
  compiling_objc = 1;
#ifdef OBJCPLUS
  cxx_init_options (clk_cplusplus);
#else
  c_common_init_options (clk_c);
#endif  
}
