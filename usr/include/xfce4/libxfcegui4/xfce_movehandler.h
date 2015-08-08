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

#ifndef __XFCE_MOVEHANDLER_H__
#define __XFCE_MOVEHANDLER_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtkwidget.h>


G_BEGIN_DECLS

#define XFCE_TYPE_MOVEHANDLER          (xfce_movehandler_get_type())
#define XFCE_MOVEHANDLER(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_movehandler_get_type (), XfceMovehandler)
#define XFCE_MOVEHANDLER_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_movehandler_get_type (), XfceMovehandlerClass)
#define XFCE_IS_MOVEHANDLER(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_movehandler_get_type ())

    typedef struct _XfceMovehandler XfceMovehandler;
    typedef struct _XfceMovehandlerClass XfceMovehandlerClass;

    typedef void (*XfceMoveFunc) (GtkWidget *win, int *x, int *y, 
				  gpointer data);
    
    struct _XfceMovehandler
    {

	GtkWidget widget;	/* parent */
	GtkWidget *gtk_window;	/* top_level managed window */

	/* Private data */

	GdkWindow *float_window;
	GtkAllocation float_allocation;
	gboolean in_drag;
	gint deskoff_x, deskoff_y;
	GdkBitmap *dark_bmap;
	GdkBitmap *mid_bmap;
	GdkBitmap *light_bmap;

	XfceMoveFunc move;
	gpointer move_data;
    };

    struct _XfceMovehandlerClass
    {
	GtkWidgetClass parent_class;

	void (*move_start) (GtkWidget * widget);
	void (*move) (GtkWidget * widget, gint new_x, gint new_y);
	void (*move_end) (GtkWidget * widget);
    };


    GtkType xfce_movehandler_get_type (void);
    GtkWidget *xfce_movehandler_new (GtkWidget * window);

    void xfce_movehandler_set_move_func (XfceMovehandler *handler,
					 XfceMoveFunc move,
					 gpointer data);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */


#endif				/* __XFCE_MOVEHANDLER_H__ */
