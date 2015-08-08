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

#ifndef __XFCE_DECORBUTTON_H__
#define __XFCE_DECORBUTTON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkmisc.h>

G_BEGIN_DECLS

#define XFCE_TYPE_DECORBUTTON          (xfce_decorbutton_get_type ())
#define XFCE_DECORBUTTON(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_decorbutton_get_type (), XfceDecorbutton)
#define XFCE_DECORBUTTON_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_decorbutton_get_type (), XfceDecorbuttonClass)
#define XFCE_IS_DECORBUTTON(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_decorbutton_get_type ())

    typedef struct _XfceDecorbutton XfceDecorbutton;
    typedef struct _XfceDecorbuttonClass XfceDecorbuttonClass;

    /* this formatting is needed by glib-mkenums */
    typedef enum { /*< prefix=XFCE_DECORBUTTON_ >*/
	XFCE_DECORBUTTON_CLOSE,
	XFCE_DECORBUTTON_HIDE
    }
    XfceDecorbuttonType;

    struct _XfceDecorbutton
    {
	GtkMisc misc;
	XfceDecorbuttonType type;

	/* Private data */

	GdkBitmap *close_dark_bmap;
	GdkBitmap *close_mid_bmap;
	GdkBitmap *close_light_bmap;

	GdkBitmap *hide_dark_bmap;
	GdkBitmap *hide_mid_bmap;
	GdkBitmap *hide_light_bmap;
    };

    struct _XfceDecorbuttonClass
    {
	GtkMiscClass parent_class;
    };


    GtkType xfce_decorbutton_get_type (void);
    GtkWidget *xfce_decorbutton_new (XfceDecorbuttonType type);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif				/* __XFCE_DECORBUTTON_H__ */
