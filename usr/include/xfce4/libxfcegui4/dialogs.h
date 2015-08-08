/*  xfce4
 *  
 *  Copyright (C) 2003 Jasper Huijsmans (huysmans@users.sourceforge.net)
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

#ifndef _LIBXFCEGUI4_DIALOGS_H
#define _LIBXFCEGUI4_DIALOGS_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <stdarg.h>

#include <glib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>

G_BEGIN_DECLS

/* new wrappers aroung gtk_message_dialog */

/* compat stubs, to be removed someday! */
void show_info (const char *text);
void show_warning (const char *text);
void show_error (const char *text);
gboolean confirm (const char *text, const char *stock, const char *action);
GtkWidget *create_header (GdkPixbuf * icon, const char *text);
GtkWidget *create_header_with_image (GtkWidget *image, const char *text);
GtkWidget *small_label (const char *text);
GtkWidget *mixed_button_new (const char *stock, const char *text);
gboolean exec_command (gchar * command);
gboolean exec_command_full_with_envp (gchar ** argv, gchar ** envp);

#define XFCE_CUSTOM_PIXBUF_BUTTON        "custom-button-pixbuf"
#define XFCE_CUSTOM_STOCK_BUTTON         "custom-button-stock"
#define XFCE_CUSTOM_BUTTON               "custom-button"

void       xfce_err                      (const gchar *format, ...);
void       xfce_verr                     (const gchar *format, va_list ap);
void       xfce_warn                     (const gchar *format, ...);
void       xfce_vwarn                    (const gchar *format, va_list ap);
void       xfce_info                     (const gchar *format, ...);
void       xfce_vinfo                    (const gchar *format, va_list ap);

gboolean   xfce_confirm                  (const gchar *text,
					  const gchar *stock_id,
					  const gchar *action);

gint       xfce_message_dialog           (GtkWindow *parent,
					  const gchar *title,
					  const gchar *icon_id,
					  const gchar *primary_text,
					  const gchar *secondary_text,
					  const gchar *first_button_type, ...);

GtkWidget *xfce_message_dialog_new       (GtkWindow *parent,
                                          const gchar *title,
                                          const gchar *icon_id,
                                          const gchar *primary_text,
                                          const gchar *secondary_text,
                                          const gchar *first_button_type,
                                          ...);

GtkWidget *xfce_create_header            (GdkPixbuf   *icon,
                                          const gchar *text);
GtkWidget *xfce_create_header_with_image (GtkWidget   *image,
                                          const gchar *text);

GtkWidget *xfce_create_small_label       (const gchar *text);

GtkWidget *xfce_create_mixed_button      (const gchar *stock,
                                          const gchar *text);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* _LIBXFCEGUI4_DIALOGS_H */
