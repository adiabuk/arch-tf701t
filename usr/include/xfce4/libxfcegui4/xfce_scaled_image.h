/* $Id$
 * Copyright (C) 2004 Jasper Huijsmans (jasper@xfce.org)
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

#ifndef __XFCE_SCALED_IMAGE_H__
#define __XFCE_SCALED_IMAGE_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtkimage.h>

G_BEGIN_DECLS

#define XFCE_TYPE_SCALED_IMAGE          (xfce_scaled_image_get_type ())
#define XFCE_SCALED_IMAGE(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_scaled_image_get_type (), XfceScaledImage)
#define XFCE_SCALED_IMAGE_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_scaled_image_get_type (), XfceScaledImageClass)
#define XFCE_IS_SCALED_IMAGE(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_scaled_image_get_type ())

typedef struct _XfceScaledImage XfceScaledImage;
typedef struct _XfceScaledImageClass XfceScaledImageClass;

struct _XfceScaledImage
{
    GtkImage image;

    GdkPixbuf *pb;

    gint width;
    gint height;
};

struct _XfceScaledImageClass
{
    GtkImageClass parent_class;
};


GtkType xfce_scaled_image_get_type (void);

GtkWidget *xfce_scaled_image_new (void);

GtkWidget *xfce_scaled_image_new_from_pixbuf (GdkPixbuf * pb);

void xfce_scaled_image_set_from_pixbuf (XfceScaledImage * image, 
					GdkPixbuf * pixbuf);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif				/* __XFCE_SCALED_IMAGE_H__ */
