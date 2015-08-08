/*  xfce
 *  Copyright (C) 2004 Olivier Fourdan (fourdan@xfce.org)
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

#ifndef __XINERAMA_H__
#define __XINERAMA_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

G_BEGIN_DECLS;

gboolean xineramaInit (Display * dpy);
void xineramaFree (void);
gint xineramaGetHeads (void);
gint MyDisplayFullHeight (Display * dpy, int screen);
gint MyDisplayFullWidth (Display * dpy, int screen);
gint MyDisplayHeight (Display * dpy, int screen, gint x, gint y);
gint MyDisplayWidth (Display * dpy, int screen, gint x, gint y);
gint MyDisplayX (gint x, gint y);
gint MyDisplayY (gint x, gint y);
gint MyDisplayMaxX (Display * dpy, int screen, gint x, gint y);
gint MyDisplayMaxY (Display * dpy, int screen, gint x, gint y);
gboolean isRightMostHead (Display * dpy, int screen, gint x, gint y);
gboolean isLeftMostHead (Display * dpy, int screen, gint x, gint y);
gboolean isTopMostHead (Display * dpy, int screen, gint x, gint y);
gboolean isBottomMostHead (Display * dpy, int screen, gint x, gint y);

G_END_DECLS;

#endif /* XFCE_DISABLE_DEPRECATED */

#endif /* __XINERAMA_H__ */
