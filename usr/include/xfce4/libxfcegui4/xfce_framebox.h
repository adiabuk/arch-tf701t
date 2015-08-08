/*  xfce4
 *  Copyright (C) 2002 Olivier Fourdan (fourdan@xfce.org)
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

#ifndef __XFCE_FRAMEBOX_H__
#define __XFCE_FRAMEBOX_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkframe.h>

G_BEGIN_DECLS

#define XFCE_TYPE_FRAMEBOX          (xfce_framebox_get_type())
#define XFCE_FRAMEBOX(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_framebox_get_type (), XfceFramebox)
#define XFCE_FRAMEBOX_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_framebox_get_type (), XfceFrameboxClass)
#define XFCE_IS_FRAMEBOX(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_framebox_get_type ())

    typedef struct _XfceFramebox XfceFramebox;
    typedef struct _XfceFrameboxClass XfceFrameboxClass;

    struct _XfceFramebox
    {
        GtkFrame frame;
        GtkWidget *hbox;
        GtkWidget *indent_filler;
    };

    struct _XfceFrameboxClass
    {
        GtkFrameClass parent_class;
    };

    GType xfce_framebox_get_type        (void) G_GNUC_CONST;
    GtkWidget *xfce_framebox_new        (const gchar *text,
                                         gboolean indent);
    
    void xfce_framebox_add              (XfceFramebox *framebox, 
                                         GtkWidget *widget);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif                          /* __XFCE_FRAMEBOX_H__ */
