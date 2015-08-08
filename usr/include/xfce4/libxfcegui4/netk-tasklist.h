/* tasklist object */

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

#ifndef NETK_TASKLIST_H
#define NETK_TASKLIST_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>
#include <libxfcegui4/netk-screen.h>

G_BEGIN_DECLS
#define NETK_TYPE_TASKLIST              (netk_tasklist_get_type ())
#define NETK_TASKLIST(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), NETK_TYPE_TASKLIST, NetkTasklist))
#define NETK_TASKLIST_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST ((klass), NETK_TYPE_TASKLIST, NetkTasklistClass))
#define NETK_IS_TASKLIST(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), NETK_TYPE_TASKLIST))
#define NETK_IS_TASKLIST_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE ((klass), NETK_TYPE_TASKLIST))
#define NETK_TASKLIST_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), NETK_TYPE_TASKLIST, NetkTasklistClass))
typedef struct _NetkTasklist NetkTasklist;
typedef struct _NetkTasklistClass NetkTasklistClass;
typedef struct _NetkTasklistPrivate NetkTasklistPrivate;

struct _NetkTasklist
{
    GtkContainer parent_instance;

    NetkTasklistPrivate *priv;
};

struct _NetkTasklistClass
{
    GtkContainerClass parent_class;
};

typedef enum
{
    NETK_TASKLIST_NEVER_GROUP,
    NETK_TASKLIST_AUTO_GROUP,
    NETK_TASKLIST_ALWAYS_GROUP
}
NetkTasklistGroupingType;

GType
netk_tasklist_get_type (void)
    G_GNUC_CONST;

     GtkWidget *netk_tasklist_new (NetkScreen * screen);
     void netk_tasklist_set_screen (NetkTasklist * tasklist,
                                    NetkScreen * screen);
     const int *netk_tasklist_get_size_hint_list (NetkTasklist * tasklist,
                                                  int *n_elements);

     void netk_tasklist_set_grouping (NetkTasklist * tasklist,
                                      NetkTasklistGroupingType grouping);
     void netk_tasklist_set_switch_workspace_on_unminimize (NetkTasklist *
                                                            tasklist,
                                                            gboolean
                                                            switch_workspace_on_unminimize);
     void netk_tasklist_set_grouping_limit (NetkTasklist * tasklist,
                                            gint limit);
     void netk_tasklist_set_include_all_workspaces (NetkTasklist * tasklist,
                                                    gboolean
                                                    include_all_workspaces);
     void netk_tasklist_set_show_label (NetkTasklist * tasklist,
                                         gboolean show_label);
     void netk_tasklist_set_minimum_width (NetkTasklist * tasklist,
                                           gint size);
     gint netk_tasklist_get_minimum_width (NetkTasklist * tasklist);
     void netk_tasklist_set_minimum_height (NetkTasklist * tasklist,
                                            gint size);
     gint netk_tasklist_get_minimum_height (NetkTasklist * tasklist);

     typedef GdkPixbuf *(*NetkLoadIconFunction) (const char *icon_name,
                                                 int size,
                                                 unsigned int flags,
                                                 void *data);

     void netk_tasklist_set_icon_loader (NetkTasklist * tasklist,
                                         NetkLoadIconFunction load_icon_func,
                                         void *data,
                                         GDestroyNotify free_data_func);

     void netk_tasklist_set_button_relief (NetkTasklist * tasklist,
                                           GtkReliefStyle relief);
                                           
     NetkScreen* netk_tasklist_get_screen(NetkTasklist * tasklist);
     NetkTasklistGroupingType netk_tasklist_get_grouping(NetkTasklist * tasklist);
     gboolean netk_tasklist_get_switch_workspace_on_unminimize(NetkTasklist * tasklist);
     gint netk_tasklist_get_grouping_limit(NetkTasklist * tasklist);
     gboolean netk_tasklist_get_include_all_workspaces(NetkTasklist * tasklist);
     gboolean netk_tasklist_get_show_label(NetkTasklist * tasklist);
     GtkReliefStyle netk_tasklist_get_button_relief(NetkTasklist * tasklist);
     
G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* NETK_TASKLIST_H */
