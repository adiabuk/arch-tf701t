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

#ifndef __XFCE_TOGGLEBUTTON_H__
#define __XFCE_TOGGLEBUTTON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>
#include <gtk/gtktogglebutton.h>
#include <gtk/gtkenums.h>
#include <libxfcegui4/xfce_decortoggle.h>


G_BEGIN_DECLS

#define XFCE_TYPE_TOGGLEBUTTON (xfce_togglebutton_get_type ())
#define XFCE_TOGGLEBUTTON(obj)          G_TYPE_CHECK_INSTANCE_CAST (obj, xfce_togglebutton_get_type (), XfceTogglebutton)
#define XFCE_TOGGLEBUTTON_CLASS(klass)  G_TYPE_CHECK_CLASS_CAST (klass, xfce_togglebutton_get_type (), XfceTogglebuttonClass)
#define XFCE_IS_TOGGLEBUTTON(obj)       G_TYPE_CHECK_INSTANCE_TYPE (obj, xfce_togglebutton_get_type ())

    typedef struct _XfceTogglebutton XfceTogglebutton;
    typedef struct _XfceTogglebuttonClass XfceTogglebuttonClass;

    struct _XfceTogglebutton
    {
	GtkToggleButton button;
	GtkWidget *decortoggle;
    };

    struct _XfceTogglebuttonClass
    {
	GtkToggleButtonClass parent_class;
    };


    GtkType xfce_togglebutton_get_type (void);
    GtkWidget *xfce_togglebutton_new (GtkArrowType arrow_type);
    void xfce_togglebutton_set_arrow_type (XfceTogglebutton * togglebutton,
					   GtkArrowType arrow_type);
    GtkArrowType xfce_togglebutton_get_arrow_type (XfceTogglebutton *
						   togglebutton);

/* API compat. */
#define xfce_togglebutton_set_active(togglebutton, is_active)     gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(togglebutton), is_active)
#define xfce_togglebutton_get_active(togglebutton)                gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton))
#define xfce_togglebutton_toggled(togglebutton)                   gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(togglebutton))
#define xfce_togglebutton_set_inconsistent(togglebutton, setting) gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(togglebutton), setting)
#define xfce_togglebutton_get_inconsistent(togglebutton)          gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON(togglebutton))
#define xfce_togglebutton_set_relief(togglebutton, newstyle)      gtk_button_set_relief(GTK_BUTTON(togglebutton), newstyle)
#define xfce_togglebutton_get_relief(togglebutton)                gtk_button_get_relief(GTK_BUTTON(togglebutton))

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* __XFCE_TOGGLEBUTTON_H__ */
