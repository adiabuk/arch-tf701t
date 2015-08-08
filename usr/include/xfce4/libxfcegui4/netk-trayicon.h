/*
 * Copyright (c) 2003 Benedikt Meurer <benedikt.meurer@unix-ag.uni-siegen.de>
 * All rights reserved.
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
 *
 * http://www.freedesktop.org/standards/systemtray.html
 */

#ifndef __NETK_TRAY_ICON_H__
#define __NETK_TRAY_ICON_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>

#include <gtk/gtk.h>

G_BEGIN_DECLS 

#define NETK_TYPE_TRAY_ICON     (netk_tray_icon_get_type())
#define NETK_TRAY_ICON(o)       (G_TYPE_CHECK_INSTANCE_CAST((o),        \
                                 NETK_TYPE_TRAY_ICON,                   \
                                 NetkTrayIcon))
#define NETK_TRAY_ICON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST((k),           \
                                 NETK_TYPE_TRAY_ICON,                   \
                                 NetkTrayIconClass))
#define NETK_IS_TRAY_ICON(o)    (G_TYPE_CHECK_INSTANCE_TYPE((o),        \
                                 NETK_TYPE_TRAY_ICON))

typedef struct _NetkTrayIcon NetkTrayIcon;
typedef struct _NetkTrayIconClass NetkTrayIconClass;

struct _NetkTrayIcon
{
    /* */
    GtkPlug parent;

    /* atoms */
    struct
    {
        Atom data;
        Atom manager;
        Atom opcode;
        Atom selection;
    }
    atoms;

    /* system tray window */
    Window tray;

    /*
     * "This ID number should never be reused by the same tray icon. (The
     * simplest way to generate the ID number is to increment it with each
     * message sent.)
     */
    glong count;
};

struct _NetkTrayIconClass
{
    GtkPlugClass parent;
};

/* functions */
GType netk_tray_icon_get_type (void);
GtkWidget *netk_tray_icon_new (Screen *screen);
NetkTrayIcon *netk_tray_icon_new_gdk (GdkScreen *screen);
void netk_tray_icon_set_screen (NetkTrayIcon *trayicon, Screen *screen);
void netk_tray_icon_set_gdkscreen (NetkTrayIcon *trayicon, GdkScreen *screen);
/* netk_tray_icon_get_gdkscreen = gtk_window_get_screen */
glong netk_tray_icon_message_new (NetkTrayIcon *trayicon, glong id,
                                         const gchar *text);
void netk_tray_icon_message_cancel (NetkTrayIcon *trayicon, glong id);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* !__NETK_TRAY_ICON_H__ */
