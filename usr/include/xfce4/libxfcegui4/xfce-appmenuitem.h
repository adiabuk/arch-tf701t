/* 
 * xfce-appmenuitem - a GtkImageMenuItem subclass that handles menu
 * items that are intended to represent applications
 *
 * Copyright (c) 2004 Brian Tarricone <bjt23@cornell.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef __XFCE_APP_MENU_ITEM_H__
#define __XFCE_APP_MENU_ITEM_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtkimagemenuitem.h>
#include <libxfce4util/libxfce4util.h>

G_BEGIN_DECLS

#define XFCE_TYPE_APP_MENU_ITEM            (xfce_app_menu_item_get_type())
#define XFCE_APP_MENU_ITEM(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), XFCE_TYPE_APP_MENU_ITEM, XfceAppMenuItem))
#define XFCE_APP_MENU_ITEM_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), XFCE_TYPE_APP_MENU_ITEM, XfceAppMenuItemClass))
#define XFCE_IS_APP_MENU_ITEM(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), XFCE_TYPE_APP_MENU_ITEM))
#define XFCE_IS_APP_MENU_ITEM_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), XFCE_TYPE_APP_MENU_ITEM))
#define XFCE_APP_MENU_ITEM_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), XFCE_TYPE_APP_MENU_ITEM, XfceAppMenuItemClass))

typedef struct _XfceAppMenuItem       XfceAppMenuItem;
typedef struct _XfceAppMenuItemClass  XfceAppMenuItemClass;
typedef struct _XfceAppMenuItemPriv   XfceAppMenuItemPriv;

struct _XfceAppMenuItem
{
	GtkImageMenuItem image_menu_item;
	
	/*< private >*/
	XfceAppMenuItemPriv *priv;
};

struct _XfceAppMenuItemClass
{
	GtkImageMenuItemClass parent_class;
};

GType xfce_app_menu_item_get_type                     (void) G_GNUC_CONST;

GtkWidget *xfce_app_menu_item_new                     (void);

GtkWidget *xfce_app_menu_item_new_with_label          (const gchar *label);

GtkWidget *xfce_app_menu_item_new_with_mnemonic       (const gchar *label);

GtkWidget *xfce_app_menu_item_new_with_command        (const gchar *label,
                                                       const gchar *command);

GtkWidget *xfce_app_menu_item_new_full                (const gchar *label,
                                                       const gchar *command,
                                                       const gchar *icon_filename,
                                                       gboolean needs_term,
                                                       gboolean snotify);

GtkWidget *xfce_app_menu_item_new_from_desktop_entry  (gpointer *entry,
                                                       gboolean show_icon);

void xfce_app_menu_item_set_name                      (XfceAppMenuItem *app_menu_item,
                                                       const gchar *name);
													   
void xfce_app_menu_item_set_icon_name                 (XfceAppMenuItem *app_menu_item,
                                                       const gchar *filename);
													   
void xfce_app_menu_item_set_command                   (XfceAppMenuItem *app_menu_item,
                                                       const gchar *command);
													   
void xfce_app_menu_item_set_needs_term                (XfceAppMenuItem *app_menu_item,
                                                       gboolean needs_term);
													   
void xfce_app_menu_item_set_startup_notification      (XfceAppMenuItem *app_menu_item,
                                                       gboolean snotify);
													   
#define xfce_app_menu_item_set_image(mi, img) gtk_image_menu_item_set_image(GTK_IMAGE_MENU_ITEM(mi), img)

G_CONST_RETURN gchar *xfce_app_menu_item_get_name     (XfceAppMenuItem *app_menu_item);

G_CONST_RETURN gchar *xfce_app_menu_item_get_icon_name(XfceAppMenuItem *app_menu_item);

G_CONST_RETURN gchar *xfce_app_menu_item_get_command  (XfceAppMenuItem *app_menu_item);

gboolean xfce_app_menu_item_get_needs_term            (XfceAppMenuItem *app_menu_item);

gboolean xfce_app_menu_item_get_startup_notification  (XfceAppMenuItem *app_menu_item);

#define xfce_app_menu_item_get_image(mi) gtk_image_menu_item_get_image(GTK_IMAGE_MENU_ITEM(mi))

void xfce_app_menu_item_set_icon_theme_name           (const gchar *theme_name);

void xfce_app_menu_item_set_icon_size                 (guint icon_size);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* !def __XFCE_APP_MENU_ITEM_H__ */
