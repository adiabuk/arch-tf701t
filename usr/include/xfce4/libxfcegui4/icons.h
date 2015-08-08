/*
 * Copyright (c) 2002-2004 The Xfce Development Team
 * Copyright (c) 2004-2006 Brian Tarricone <bjt23@cornell.edu>
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

#ifndef _LIBXFCEGUI4_ICONS_H
#define _LIBXFCEGUI4_ICONS_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

G_BEGIN_DECLS

/* NB: do NOT add new categories to the beginning or middle of this list.
 * only add them to the end, right before XFCE_N_BUILTIN_ICON_CATEGORIES. */
typedef enum { /*< prefix=XFCE_ICON_CATEGORY_ >*/
    XFCE_ICON_CATEGORY_UNKNOWN = 0,
    XFCE_ICON_CATEGORY_EDITOR,
    XFCE_ICON_CATEGORY_FILEMAN,
    XFCE_ICON_CATEGORY_UTILITY,
    XFCE_ICON_CATEGORY_GAME,
    XFCE_ICON_CATEGORY_HELP,
    XFCE_ICON_CATEGORY_MULTIMEDIA,
    XFCE_ICON_CATEGORY_NETWORK,
    XFCE_ICON_CATEGORY_GRAPHICS,
    XFCE_ICON_CATEGORY_PRINTER,
    XFCE_ICON_CATEGORY_PRODUCTIVITY,
    XFCE_ICON_CATEGORY_OFFICE,
    XFCE_ICON_CATEGORY_SOUND,
    XFCE_ICON_CATEGORY_TERMINAL,
    XFCE_ICON_CATEGORY_DEVELOPMENT,
    XFCE_ICON_CATEGORY_SETTINGS,
    XFCE_ICON_CATEGORY_SYSTEM,
    XFCE_ICON_CATEGORY_WINE,
    XFCE_ICON_CATEGORY_ACCESSORIES,
    XFCE_N_BUILTIN_ICON_CATEGORIES
} XfceIconThemeCategory;


#ifdef HAVE_GDK_PIXBUF_NEW_FROM_STREAM
#define gdk_pixbuf_new_from_inline gdk_pixbuf_new_from_stream
#endif

/* pixbuf utility functions */

GdkPixbuf *xfce_inline_icon_at_size          (const guint8 *data,
                                              int width,
                                              int height);


/* themed icon convenience wrappers */

gchar *xfce_themed_icon_lookup               (const gchar *name,
                                              gint size);
GdkPixbuf *xfce_themed_icon_load             (const gchar *name,
                                              gint size);

gchar *xfce_themed_icon_lookup_list          (GList *names,
                                              gint size);
GdkPixbuf *xfce_themed_icon_load_list        (GList *names,
                                              gint size);

gchar *xfce_themed_icon_lookup_category      (XfceIconThemeCategory category,
                                              gint size);
GdkPixbuf *xfce_themed_icon_load_category    (XfceIconThemeCategory category,
                                              gint size);

void xfce_themed_icon_add_search_path(const gchar *path);
void xfce_set_icon_theme(const gchar *theme_name);
GdkPixbuf *inline_icon_at_size(const guint8 *data,
                               int width,
                               int height);
GdkPixbuf *xfce_load_themed_icon(const gchar *name,
                                 gint size);
GdkPixbuf *xfce_pixbuf_new_from_file_at_size(const gchar *filename,
                                             gint width,
                                             gint height,
                                             GError **error);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* _LIBXFCEGUI4_ICONS_H */
