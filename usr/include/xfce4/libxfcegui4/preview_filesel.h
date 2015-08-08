/* preview-filesel.h
 * Copyright (C) 2001 Ximian, Inc.
 *
 * Written by Rachel Hestilow <hestilow@ximian.com> 
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

#ifndef __PREVIEW_FILESEL_H__
#define __PREVIEW_FILESEL_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtkfilesel.h>

G_BEGIN_DECLS

#define TYPE_PREVIEW_FILE_SELECTION          preview_file_selection_get_type ()
#define PREVIEW_FILE_SELECTION(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, TYPE_PREVIEW_FILE_SELECTION, PreviewFileSelection)
#define PREVIEW_FILE_SELECTION_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, TYPE_PREVIEW_FILE_SELECTION, PreviewFileSelectionClass)
#define IS_PREVIEW_FILE_SELECTION(obj)        G_TYPE_CHECK_INSTANCE_TYPE (obj, TYPE_PREVIEW_FILE_SELECTION)
typedef struct _PreviewFileSelection PreviewFileSelection;
typedef struct _PreviewFileSelectionClass PreviewFileSelectionClass;
typedef struct _PreviewFileSelectionPrivate PreviewFileSelectionPrivate;

struct _PreviewFileSelection
{
    GtkFileSelection parent;

    PreviewFileSelectionPrivate *priv;
};

struct _PreviewFileSelectionClass
{
    GtkFileSelectionClass parent_class;
};


GType preview_file_selection_get_type (void);

GtkWidget *preview_file_selection_new (const gchar * title,
				       gboolean do_preview);

GdkPixbuf *preview_file_selection_intelligent_scale (GdkPixbuf * pixbuf,
						     guint scale);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* __PREVIEW_FILESEL_H__ */
