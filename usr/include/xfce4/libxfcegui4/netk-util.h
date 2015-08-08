/* util header */

/*
 * Copyright (C) 2001 Havoc Pennington
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

#ifndef NETK_UTIL_H
#define NETK_UTIL_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>
#include <glib.h>
#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <gdk/gdk.h>
#include <gdk/gdkx.h>
#include "netk-window.h"

G_BEGIN_DECLS

typedef struct DesktopMargins
{
    guint left;
    guint top;
    guint right;
    guint bottom;
}
DesktopMargins;

void netk_gtk_window_set_type (GtkWindow * window, NetkWindowType type);
/* netk_gtk_window_set_dock_type() kept for backward compat */
#define netk_gtk_window_set_dock_type(w) \
        netk_gtk_window_set_type (w, NETK_WINDOW_DOCK)
void netk_gtk_window_avoid_input (GtkWindow * window);
gboolean netk_get_cardinal (Window xwindow, Atom atom, int *val);
int netk_get_wm_state (Window xwindow);
gboolean netk_get_window (Window xwindow, Atom atom, Window * val);
gboolean netk_get_pixmap (Window xwindow, Atom atom, Pixmap * val);
gboolean netk_get_atom (Window xwindow, Atom atom, Atom * val);
char *netk_get_text_property (Window xwindow, Atom atom);
char *netk_get_utf8_property (Window xwindow, Atom atom);
gboolean netk_get_window_list (Window xwindow, Atom atom, Window ** windows,
                               int *len);
gboolean netk_get_atom_list (Window xwindow, Atom atom, Atom ** atoms,
                             int *len);
gboolean netk_get_cardinal_list (Window xwindow, Atom atom,
                                 gulong ** cardinals, int *len);
char **netk_get_utf8_list (Window xwindow, Atom atom);
void netk_close (Screen * screen, Window xwindow);
void netk_change_state (Screen * screen, Window xwindow, gboolean add,
                        Atom state1, Atom state2);
void netk_change_workspace (Screen * screen, Window xwindow, int new_space);
void netk_activate (Screen * screen, Window xwindow);
void netk_activate_workspace (Screen * screen, int new_active_space);
Window netk_get_group_leader (Window xwindow);
char *netk_get_session_id (Window xwindow);
int netk_get_pid (Window xwindow);
char *netk_get_name (Window xwindow);
char *netk_get_res_class_utf8 (Window xwindow);
void netk_set_desktop_layout (Screen * xscreen, int rows, int columns);
gboolean netk_get_desktop_margins (Screen * xscreen,
                                   DesktopMargins * margins);
void netk_set_desktop_margins (Window xwindow, DesktopMargins * margins);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* NETK_UTIL_H */
