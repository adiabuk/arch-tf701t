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

#ifndef __XFCE_ICONBUTTON_H__
#define __XFCE_ICONBUTTON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkbutton.h>
#include <gtk/gtkenums.h>


G_BEGIN_DECLS

#define XFCE_TYPE_ICONBUTTON (xfce_iconbutton_get_type ())
#define XFCE_ICONBUTTON(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_iconbutton_get_type (), XfceIconbutton)
#define XFCE_ICONBUTTON_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_iconbutton_get_type (), XfceIconbuttonClass)
#define XFCE_IS_ICONBUTTON(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_iconbutton_get_type ())

    typedef struct _XfceIconbutton XfceIconbutton;
    typedef struct _XfceIconbuttonClass XfceIconbuttonClass;

    struct _XfceIconbutton
    {
	GtkButton button;

	GtkWidget *image;
	GdkPixbuf *pb;

        gint icon_width;
        gint icon_height;
    };

    struct _XfceIconbuttonClass
    {
	GtkButtonClass parent_class;
    };


    GtkType xfce_iconbutton_get_type (void);
    GtkWidget *xfce_iconbutton_new (void);
    GtkWidget *xfce_iconbutton_new_from_pixbuf (GdkPixbuf * pb);

    void xfce_iconbutton_set_pixbuf (XfceIconbutton * icon_button,
				     GdkPixbuf * pixbuf);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */


#endif				/* __XFCE_ICONBUTTON_H__ */
/* example-end */
