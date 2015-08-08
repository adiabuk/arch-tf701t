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

#ifndef __XFCE_DECORTOGGLE_H__
#define __XFCE_DECORTOGGLE_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkmisc.h>


G_BEGIN_DECLS

#define XFCE_TYPE_DECORTOGGLE          (xfce_decortoggle_get_type ())
#define XFCE_DECORTOGGLE(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_decortoggle_get_type (), XfceDecortoggle)
#define XFCE_DECORTOGGLE_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_decortoggle_get_type (), XfceDecortoggleClass)
#define XFCE_IS_DECORTOGGLE(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_decortoggle_get_type ())

    typedef struct _XfceDecortoggle XfceDecortoggle;
    typedef struct _XfceDecortoggleClass XfceDecortoggleClass;

    struct _XfceDecortoggle
    {
	GtkMisc misc;
	GtkArrowType arrow_type;
	gboolean is_active;

	/* Private data */

	gboolean initialized;

	GdkBitmap *arrow_up_dark_bmap;
	GdkBitmap *arrow_up_mid_bmap;
	GdkBitmap *arrow_up_light_bmap;

	GdkBitmap *arrow_down_dark_bmap;
	GdkBitmap *arrow_down_mid_bmap;
	GdkBitmap *arrow_down_light_bmap;

	GdkBitmap *arrow_left_dark_bmap;
	GdkBitmap *arrow_left_mid_bmap;
	GdkBitmap *arrow_left_light_bmap;

	GdkBitmap *arrow_right_dark_bmap;
	GdkBitmap *arrow_right_mid_bmap;
	GdkBitmap *arrow_right_light_bmap;
    };

    struct _XfceDecortoggleClass
    {
	GtkMiscClass parent_class;
    };

    GtkType xfce_decortoggle_get_type (void);
    GtkWidget *xfce_decortoggle_new (GtkArrowType arrow_type);
    void xfce_decortoggle_toggled (XfceDecortoggle * decortoggle);
    void xfce_decortoggle_set_active (XfceDecortoggle * decortoggle,
				      gboolean is_active);
    void xfce_decortoggle_set_arrow_type (XfceDecortoggle * decortoggle,
					  GtkArrowType arrow_type);
    GtkArrowType xfce_decortoggle_get_arrow_type (XfceDecortoggle *
						  decortoggle);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif				/* __XFCE_DECORTOGGLE_H__ */
