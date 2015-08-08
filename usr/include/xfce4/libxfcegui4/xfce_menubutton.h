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

#ifndef __XFCE_MENUBUTTON_H__
#define __XFCE_MENUBUTTON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkbutton.h>
#include <gtk/gtkenums.h>


G_BEGIN_DECLS

#define XFCE_TYPE_MENUBUTTON (xfce_menubutton_get_type ())
#define XFCE_MENUBUTTON(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_menubutton_get_type (), XfceMenubutton)
#define XFCE_MENUBUTTON_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_menubutton_get_type (), XfceMenubuttonClass)
#define XFCE_IS_MENUBUTTON(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_menubutton_get_type ())

    typedef struct _XfceMenubutton XfceMenubutton;
    typedef struct _XfceMenubuttonClass XfceMenubuttonClass;

    struct _XfceMenubutton
    {
	GtkButton button;

	GtkWidget *hbox;

	GtkWidget *image;
	GdkPixbuf *pb;
        gint icon_size;

	GtkWidget *label;
    };

    struct _XfceMenubuttonClass
    {
	GtkButtonClass parent_class;
    };


    GtkType xfce_menubutton_get_type (void);

    GtkWidget *xfce_menubutton_new (const char *text);

    GtkWidget *xfce_menubutton_new_with_pixbuf (const char *text,
						GdkPixbuf * pb);

    GtkWidget *xfce_menubutton_new_with_stock_icon (const char *text,
						    const char *stock);

    void xfce_menubutton_set_text (XfceMenubutton * menubutton,
				   const char *text);

    void xfce_menubutton_set_pixbuf (XfceMenubutton * menubutton,
				     GdkPixbuf * pixbuf);

    void xfce_menubutton_set_stock_icon (XfceMenubutton * menubutton,
					 const char *stock);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */


#endif				/* __XFCE_MENUBUTTON_H__ */
/* example-end */
