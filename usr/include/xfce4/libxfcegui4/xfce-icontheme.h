/*
 *  xfce-icontheme - a themed icon lookup class
 *
 *  Copyright (c) 2004 Brian Tarricone <bjt23@cornell.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef _XFCE_ICONTHEME_H_
#define _XFCE_ICONTHEME_H_

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib-object.h>
#include <gdk/gdkscreen.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

#include <libxfcegui4/icons.h>

G_BEGIN_DECLS

#define XFCE_TYPE_ICON_THEME    (xfce_icon_theme_get_type())
#define XFCE_ICON_THEME(obj)    (G_TYPE_CHECK_INSTANCE_CAST((obj), XFCE_TYPE_ICON_THEME, XfceIconTheme))
#define XFCE_IS_ICON_THEME(obj) (G_TYPE_CHECK_INSTANCE_TYPE((obj), XFCE_TYPE_ICON_THEME))

typedef struct _XfceIconTheme XfceIconTheme;
typedef struct _XfceIconThemeClass XfceIconThemeClass;
typedef struct _XfceIconThemePriv XfceIconThemePriv;

struct _XfceIconTheme
{
	GObject gobject;
	
	/*< private >*/
	XfceIconThemePriv *priv;
};

struct _XfceIconThemeClass
{
	GObjectClass gobject_class;
	
	/*< signals >*/
	void (*changed)(XfceIconTheme *icon_theme);
	
	/*< reserved for future expansion >*/
	gpointer (*_xfce_reserved1)();
	gpointer (*_xfce_reserved2)();
};

GType xfce_icon_theme_get_type          (void) G_GNUC_CONST;

XfceIconTheme *xfce_icon_theme_get_for_screen
                                        (GdkScreen *screen) G_GNUC_DEPRECATED;

gchar *xfce_icon_theme_lookup           (XfceIconTheme *icon_theme,
                                         const gchar *icon_name,
                                         gint icon_size) G_GNUC_DEPRECATED;
gchar *xfce_icon_theme_lookup_list      (XfceIconTheme *icon_theme,
                                         GList *icon_names,
                                         gint icon_size) G_GNUC_DEPRECATED;
gchar *xfce_icon_theme_lookup_category  (XfceIconTheme *icon_theme,
                                         XfceIconThemeCategory category,
                                         gint icon_size) G_GNUC_DEPRECATED;

GdkPixbuf *xfce_icon_theme_load         (XfceIconTheme *icon_theme,
                                         const gchar *icon_name,
                                         gint icon_size) G_GNUC_DEPRECATED;
GdkPixbuf *xfce_icon_theme_load_list    (XfceIconTheme *icon_theme,
                                         GList *icon_names,
                                         gint icon_size) G_GNUC_DEPRECATED;
GdkPixbuf *xfce_icon_theme_load_category(XfceIconTheme *icon_theme,
                                         XfceIconThemeCategory category,
                                         gint icon_size) G_GNUC_DEPRECATED;

GList *xfce_icon_theme_get_search_path  (XfceIconTheme *icon_theme) G_GNUC_DEPRECATED;
void xfce_icon_theme_set_search_path    (XfceIconTheme *icon_theme,
                                         GList *search_paths) G_GNUC_DEPRECATED;
void xfce_icon_theme_prepend_search_path(XfceIconTheme *icon_theme,
                                         const gchar *search_path) G_GNUC_DEPRECATED;
void xfce_icon_theme_append_search_path (XfceIconTheme *icon_theme,
                                         const gchar *search_path) G_GNUC_DEPRECATED;

XfceIconThemeCategory xfce_icon_theme_register_category
                                        (XfceIconTheme *icon_theme,
                                         GList *icon_names) G_GNUC_DEPRECATED;
void xfce_icon_theme_unregister_category(XfceIconTheme *icon_theme,
                                         XfceIconThemeCategory category) G_GNUC_DEPRECATED;

void xfce_icon_theme_set_use_svg        (XfceIconTheme *icon_theme,
                                         gboolean use_svg) G_GNUC_DEPRECATED;
gboolean xfce_icon_theme_get_use_svg    (XfceIconTheme *icon_theme) G_GNUC_DEPRECATED;


G_END_DECLS

#endif  /* !defined(XFCE_DISABLE_DEPRECATED) */

#endif
