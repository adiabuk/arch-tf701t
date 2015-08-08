/* pager object */

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

#ifndef NETK_PAGER_H
#define NETK_PAGER_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>
#include <libxfcegui4/netk-screen.h>

G_BEGIN_DECLS

#define NETK_TYPE_PAGER              (netk_pager_get_type ())
#define NETK_PAGER(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), NETK_TYPE_PAGER, NetkPager))
#define NETK_PAGER_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), NETK_TYPE_PAGER, NetkPagerClass))
#define NETK_IS_PAGER(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), NETK_TYPE_PAGER))
#define NETK_IS_PAGER_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), NETK_TYPE_PAGER))
#define NETK_PAGER_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), NETK_TYPE_PAGER, NetkPagerClass))
typedef struct _NetkPager NetkPager;
typedef struct _NetkPagerClass NetkPagerClass;
typedef struct _NetkPagerPrivate NetkPagerPrivate;

struct _NetkPager
{
    GtkContainer parent_instance;

    NetkPagerPrivate *priv;
};

struct _NetkPagerClass
{
    GtkContainerClass parent_class;
};

typedef enum
{
    NETK_PAGER_DISPLAY_NAME,
    NETK_PAGER_DISPLAY_CONTENT
}
NetkPagerDisplayMode;

GType
netk_pager_get_type (void)
    G_GNUC_CONST;

     GtkWidget *netk_pager_new (NetkScreen * screen);

     void netk_pager_set_screen (NetkPager * pager, NetkScreen * screen);
     void netk_pager_set_orientation (NetkPager * pager,
                                      GtkOrientation orientation);
     void netk_pager_set_n_rows (NetkPager * pager, int n_rows);
     void netk_pager_set_display_mode (NetkPager * pager,
                                       NetkPagerDisplayMode mode);
     void netk_pager_set_show_all (NetkPager * pager,
                                   gboolean show_all_workspaces);
     void netk_pager_set_workspace_scrolling (NetkPager * pager,
                                              gboolean workspace_scrolling);
     void netk_pager_set_shadow_type (NetkPager * pager,
                                      GtkShadowType shadow_type);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* NETK_PAGER_H */
