/* $Id$ */
/*-
 * Copyright (c) 2006 Benedikt Meurer <benny@xfce.org>.
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

#ifndef __XFCE_HEADING_H__
#define __XFCE_HEADING_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>

G_BEGIN_DECLS;

typedef struct _XfceHeadingPrivate XfceHeadingPrivate;
typedef struct _XfceHeadingClass   XfceHeadingClass;
typedef struct _XfceHeading        XfceHeading;

#define XFCE_TYPE_HEADING             (xfce_heading_get_type ())
#define XFCE_HEADING(obj)             (G_TYPE_CHECK_INSTANCE_CAST ((obj), XFCE_TYPE_HEADING, XfceHeading))
#define XFCE_HEADING_CLASS(klass)     (G_TYPE_CHECK_CLASS_CAST ((klass), XFCE_TYPE_HEADING, XfceHeadingClass))
#define XFCE_IS_HEADING(obj)          (G_TYPE_CHECK_INSTANCE_TYPE ((obj), XFCE_TYPE_HEADING))
#define XFCE_IS_HEADING_CLASS(klass)  (G_TYPE_CHECK_CLASS_TYPE ((klass), XFCE_TYPE_HEADING))
#define XFCE_HEADING_GET_CLASS(obj)   (G_TYPE_INSTANCE_GET_CLASS ((obj), XFCE_TYPE_HEADING, XfceHeadingClass))

struct _XfceHeadingClass
{
  /*< private >*/
  GtkWidgetClass __parent__;

  /* reserved for future expansion */
  void (*reserved0) (void);
  void (*reserved1) (void);
  void (*reserved2) (void);
  void (*reserved3) (void);
  void (*reserved4) (void);
  void (*reserved5) (void);
};

struct _XfceHeading
{
  /*< private >*/
  GtkWidget           __parent__;
  XfceHeadingPrivate *priv;
};

GType                 xfce_heading_get_type      (void) G_GNUC_CONST;

GtkWidget            *xfce_heading_new           (void) G_GNUC_MALLOC;

GdkPixbuf            *xfce_heading_get_icon      (XfceHeading *heading);
void                  xfce_heading_set_icon      (XfceHeading *heading,
                                                  GdkPixbuf   *icon);

G_CONST_RETURN gchar *xfce_heading_get_icon_name (XfceHeading *heading);
void                  xfce_heading_set_icon_name (XfceHeading *heading,
                                                  const gchar *icon_name);

G_CONST_RETURN gchar *xfce_heading_get_subtitle  (XfceHeading *heading);
void                  xfce_heading_set_subtitle  (XfceHeading *heading,
                                                  const gchar *subtitle);

G_CONST_RETURN gchar *xfce_heading_get_title     (XfceHeading *heading);
void                  xfce_heading_set_title     (XfceHeading *heading,
                                                  const gchar *title);

G_END_DECLS;

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* !__XFCE_HEADING_H__ */
