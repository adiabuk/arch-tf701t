/*
 * xfce-file-chooser - a wrapper around GtkFileChooser(Dialog) (gtk 2.4+)
 *                     and/or GtkFileChooser (gtk 2.0, 2.2)
 *
 * Copyright (c) 2004 Brian Tarricone <bjt23@cornell.edu>
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

#ifndef _XFCE_FILE_CHOOSER_H_
#define _XFCE_FILE_CHOOSER_H_

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtkdialog.h>

G_BEGIN_DECLS

#define XFCE_TYPE_FILE_CHOOSER            (xfce_file_chooser_get_type())
#define XFCE_FILE_CHOOSER(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), XFCE_TYPE_FILE_CHOOSER, XfceFileChooser))
#define XFCE_FILE_CHOOSER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), XFCE_TYPE_FILE_CHOOSER, XfceFileChooserClass))
#define XFCE_IS_FILE_CHOOSER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), XFCE_TYPE_FILE_CHOOSER))
#define XFCE_IS_FILE_CHOOSER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), XFCE_TYPE_FILE_CHOOSER))
#define XFCE_FILE_CHOOSER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS((obj), XFCE_TYPE_FILE_CHOOSER, XfceFileChooserClass))

typedef enum { /*< prefix=XFCE_FILE_CHOOSER_ACTION_ >*/
	XFCE_FILE_CHOOSER_ACTION_OPEN,
	XFCE_FILE_CHOOSER_ACTION_SAVE,
	XFCE_FILE_CHOOSER_ACTION_SELECT_FOLDER,
	XFCE_FILE_CHOOSER_ACTION_CREATE_FOLDER
} 
XfceFileChooserAction;

typedef GtkDialog XfceFileChooser;
typedef GtkDialogClass XfceFileChooserClass;
typedef GtkObject XfceFileFilter;

typedef void (*PreviewUpdateFunc)(XfceFileChooser *chooser, gpointer user_data);

#define xfce_file_chooser_get_type() gtk_dialog_get_type()

GtkWidget *xfce_file_chooser_new                    (const gchar *title,
                                                     GtkWindow *parent,
                                                     XfceFileChooserAction action,
                                                     const gchar *first_button_text,
                                                     ...);

void xfce_file_chooser_set_select_multiple          (XfceFileChooser *chooser,
                                                     gboolean select_multiple);

gboolean xfce_file_chooser_get_select_multiple      (XfceFileChooser *chooser);

void xfce_file_chooser_set_current_name             (XfceFileChooser *chooser,
                                                     const gchar *name);

gchar *xfce_file_chooser_get_filename               (XfceFileChooser *chooser);

gboolean xfce_file_chooser_set_filename             (XfceFileChooser *chooser,
                                                     const gchar *filename);

GSList *xfce_file_chooser_get_filenames             (XfceFileChooser *chooser);

gboolean xfce_file_chooser_set_current_folder       (XfceFileChooser *chooser,
                                                     const gchar *filename);

gchar *xfce_file_chooser_get_current_folder         (XfceFileChooser *chooser);

void xfce_file_chooser_set_preview_widget           (XfceFileChooser *chooser,
                                                     GtkWidget *preview_widget);

GtkWidget *xfce_file_chooser_get_preview_widget     (XfceFileChooser *chooser);

void xfce_file_chooser_set_preview_callback         (XfceFileChooser *chooser,
                                                     PreviewUpdateFunc func,
                                                     gpointer user_data);

void xfce_file_chooser_set_preview_widget_active    (XfceFileChooser *chooser,
                                                     gboolean active);

gboolean xfce_file_chooser_get_preview_widget_active(XfceFileChooser *chooser);

void xfce_file_chooser_set_use_preview_label        (XfceFileChooser *chooser,
                                                     gboolean use_label);

void  xfce_file_chooser_set_extra_widget            (XfceFileChooser *chooser,
                                                     GtkWidget *extra_widget);

GtkWidget *xfce_file_chooser_get_extra_widget       (XfceFileChooser *chooser);

/* noops for gtk 2.[02] */

void xfce_file_chooser_add_filter                   (XfceFileChooser *chooser,
                                                     XfceFileFilter *filter);

void xfce_file_chooser_remove_filter                (XfceFileChooser *chooser,
                                                     XfceFileFilter *filter);

void xfce_file_chooser_set_filter                   (XfceFileChooser *chooser,
                                                     XfceFileFilter *filter);

gboolean xfce_file_chooser_add_shortcut_folder      (XfceFileChooser *chooser,
                                                     const gchar *folder,
                                                     GError **error);

gboolean xfce_file_chooser_remove_shortcut_folder   (XfceFileChooser *chooser,
                                                     const gchar *folder,
                                                     GError **error);

/* file filter routines */

XfceFileFilter *xfce_file_filter_new                (void);

void xfce_file_filter_set_name                      (XfceFileFilter *filter,
                                                     const gchar *name);

void xfce_file_filter_add_mime_type                 (XfceFileFilter *filter,
                                                     const gchar *mime_type);

void xfce_file_filter_add_pattern                   (XfceFileFilter *filter,
                                                     const gchar *pattern);

GtkWidget *xfce_file_chooser_dialog_new             (const gchar *title,
                                                     GtkWindow *parent,
                                                     XfceFileChooserAction action,
                                                     const gchar *first_button_text,
                                                     ...);

void xfce_file_chooser_set_local_only               (XfceFileChooser *chooser,
                                                     gboolean local_only);

gboolean xfce_file_chooser_get_local_only           (XfceFileChooser *chooser);

G_END_DECLS

#endif /* ifndef XFCE_DISABLE_DEPRECATED */

#endif  /* ifndef _XFCE_FILE_CHOOSER_H_ */
