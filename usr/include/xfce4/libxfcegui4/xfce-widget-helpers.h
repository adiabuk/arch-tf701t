/* 
 * Copyright (c) 2005 Brian Tarricone <bjt23@cornell.edu>
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

#ifndef __XFCE_DIALOG_HELPERS__H__
#define __XFCE_DIALOG_HELPERS__H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>

G_BEGIN_DECLS

GtkWidget *xfce_create_framebox(const gchar *title,
                                GtkWidget  **frame_bin);

GtkWidget *xfce_create_framebox_with_content (const gchar *title, 
                                              GtkWidget   *content);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* __XFCE_DIALOG_HELPERS__H__ */
