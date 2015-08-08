/*
 * Copyright (c) 2003-2004 Benedikt Meurer <benny@xfce.org>
 * Copyright (c) 2003-2004 Olivier Fourdan <fourdan@xfce.org>
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
 * A complete system tray implementation. See the specification:
 *
 *	 http://www.freedesktop.org/standards/systemtray.html
 */

#ifndef __HAVE_XFCE_SYSTEM_TRAY_H__
#define __HAVE_XFCE_SYSTEM_TRAY_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib.h>
#if defined (GTK_CHECK_VERSION) && GTK_CHECK_VERSION(2,2,0)
#include <gdk/gdkscreen.h>
#endif
#include <gtk/gtkwidget.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xmd.h>

G_BEGIN_DECLS

/*
 * Tray icons can send "opcodes" to the system tray. These are X client
 * messages, sent with NoEventMask, a message_type of _NET_SYSTEM_TRAY_OPCODE,
 * and format 32.
 */
#define SYSTEM_TRAY_REQUEST_DOCK	0
#define SYSTEM_TRAY_BEGIN_MESSAGE	1
#define SYSTEM_TRAY_CANCEL_MESSAGE	2
typedef struct _XfceSystemTray XfceSystemTray;
typedef struct _XfceSystemTrayClass XfceSystemTrayClass;

#define XFCE_TYPE_SYSTEM_TRAY       (xfce_system_tray_get_type())
#define XFCE_SYSTEM_TRAY(obj)						\
	G_TYPE_CHECK_INSTANCE_CAST(obj, xfce_system_tray_get_type(),	\
			XfceSystemTray)
#define XFCE_SYSTEM_TRAY_CLASS(klass)					\
	G_TYPE_CHECK_CLASS_CAST(klass, xfce_system_tray_get_type(),	\
			XfceSystemTrayClass)
#define XFCE_IS_SYSTEM_TRAY(obj)					\
	G_TYPE_CHECK_INSTANCE_TYPE(obj, xfce_system_tray_get_type())

#define XFCE_SYSTEM_TRAY_ERROR		(xfce_system_tray_error_quark())

/* errors */
enum
{
    XFCE_SYSTEM_TRAY_ERROR_GET_SELECTION_FAILED
};

struct _XfceSystemTray
{
    GObject parent;

    /*
     * The specification requires three Atoms to be used by the system
     * tray.
     */
    struct
    {
	/* _NET_SYSTEM_TRAY_MESSAGE_DATA */
	Atom message_data;

	/* _NET_SYSTEM_TRAY_OPCODE */
	Atom opcode;

	/* _NET_SYSTEM_TRAY_Sn */
	Atom selection;
    }
    atoms;

    /* an invisible window */
    GtkWidget *window;

    /* list of client sockets */
    GHashTable *sockets;

    /* list of pending balloon messages */
    GList *messages;
};

/*
 * Description:
 *
 *	message_new(tray, socket, id, timeout, text)
 *	message_clear(tray, socket, id)
 */
struct _XfceSystemTrayClass
{
    GObjectClass parent;

    void (*icon_docked) (XfceSystemTray *tray, GtkWidget *item);
    void (*icon_undocked) (XfceSystemTray *tray, GtkWidget *item);
    void (*selection_cleared) (XfceSystemTray *tray);
    void (*message_new) (XfceSystemTray *tray, GtkWidget *item, guint id, guint timeout,
			 const gchar *text);
    void (*message_clear) (XfceSystemTray *tray, GtkWidget *item, guint id);
};

/* get XfceSystemTray error source identifier */
GQuark xfce_system_tray_error_quark (void);

/* get XfceSystemTray object type identifier */
GType xfce_system_tray_get_type (void);

/* create a new system tray */
XfceSystemTray *xfce_system_tray_new (void);

/* register a system tray for a specific screen */
gboolean xfce_system_tray_register (XfceSystemTray *tray,
					   Screen *screen, GError **error);

/* unregister a system tray */
void xfce_system_tray_unregister (XfceSystemTray *tray);

/* check if a system tray is already running for the screen */
gboolean xfce_system_tray_check_running (Screen *screen);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* !__HAVE_XFCE_SYSTEM_TRAY_H__ */
