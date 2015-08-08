/* 
 * xfce-colorbutton - color-selector button for gtk 2.2, GtkColorButton
 *                    wrapper for gtk 2.4
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
 *
 * Portions based on GtkColorButton, Copyright (C) 1998, 1999 Red Hat, Inc.
 */

#ifndef __XFCE_COLOR_BUTTON_H__
#define __XFCE_COLOR_BUTTON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>

G_BEGIN_DECLS;

typedef GtkColorButtonClass XfceColorButtonClass;
typedef GtkColorButton      XfceColorButton;

#define XFCE_TYPE_COLOR_BUTTON            (gtk_color_button_get_type())
#define XFCE_COLOR_BUTTON(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), XFCE_TYPE_COLOR_BUTTON, XfceColorButton))
#define XFCE_COLOR_BUTTON_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), XFCE_TYPE_COLOR_BUTTON, XfceColorButtonClass))
#define XFCE_IS_COLOR_BUTTON(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), XFCE_TYPE_COLOR_BUTTON))
#define XFCE_IS_COLOR_BUTTON_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), XFCE_TYPE_COLOR_BUTTON))
#define XFCE_COLOR_BUTTON_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), XFCE_TYPE_COLOR_BUTTON, XfceColorButtonClass))

GtkWidget *xfce_color_button_new           (void);
GtkWidget *xfce_color_button_new_with_color(const GdkColor *color);
void       xfce_color_button_set_color     (XfceColorButton *color_button,
                                            const GdkColor *color);
void       xfce_color_button_get_color     (XfceColorButton *color_button,
                                            GdkColor *color);
void       xfce_color_button_set_alpha     (XfceColorButton *color_button,
                                            guint16 alpha);
guint16    xfce_color_button_get_alpha     (XfceColorButton *color_button);
void       xfce_color_button_set_use_alpha (XfceColorButton *color_button,
                                            gboolean use_alpha);
gboolean   xfce_color_button_get_use_alpha (XfceColorButton *color_button);
void       xfce_color_button_set_title     (XfceColorButton *color_button,
                                            const gchar *title);
G_CONST_RETURN gchar *xfce_color_button_get_title
                                           (XfceColorButton *color_button);

G_END_DECLS;

#endif  /* ifndef XFCE_DISABLE_DEPRECATED */

#endif  /* ifndef __XFCE_COLOR_BUTTON_H__ */
