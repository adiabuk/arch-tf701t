/*
 * xfce4    - (c) 2002 Olivier Fourdan
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

#ifndef __GTKSTYLE_H__
#define __GTKSTYLE_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib.h>
#include <gtk/gtk.h>
#include <pango/pango-font.h>

G_BEGIN_DECLS

gchar *get_style (GtkWidget *widget, const gchar *name, const gchar *state);
GdkGC *get_style_gc (GtkWidget *widget, const gchar *state, const gchar *style);
PangoFontDescription *get_font_desc (GtkWidget *widget);
PangoContext *pango_get_context (GtkWidget *widget);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif
