/* $Id$ */
/*-
 * Copyright (c) 2002-2004 The Xfce development team.
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __LIBXFCEGUI4_LIBXFCEGUI4_CONFIG_H__
#define __LIBXFCEGUI4_LIBXFCEGUI4_CONFIG_H__

#ifndef __LIBXFCEGUI4_LIBXFCEGUI4_H__
#error  "Do not include <libxfcegui4/libxfcegui4-config.h> directly. Include <libxfcegui4/libxfcegui4.h> instead."
#endif

#include <libxfce4util/libxfce4util.h>

G_BEGIN_DECLS;

#define LIBXFCEGUI4_MAJOR_VERSION	4
#define LIBXFCEGUI4_MINOR_VERSION	10
#define LIBXFCEGUI4_MICRO_VERSION	0

#define LIBXFCEGUI4_CHECK_VERSION(major,minor,micro) \
  (LIBXFCEGUI4_MAJOR_VERSION > (major) \
   || (LIBXFCEGUI4_MAJOR_VERSION == (major) \
       && LIBXFCEGUI4_MINOR_VERSION > (minor)) \
   || (LIBXFCEGUI4_MAJOR_VERSION == (major) \
       && LIBXFCEGUI4_MINOR_VERSION == (minor) \
       && LIBXFCEGUI4_MICRO_VERSION >= (micro)))

G_END_DECLS;

#endif  /* !__LIBXFCEGUI4_LIBXFCEGUI4_CONFIG_H__ */
