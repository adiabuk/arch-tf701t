/* $Id$ */
/*-
 * Copyright (c) 2004 Benedikt Meurer <benny@xfce.org>
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
 */

#ifndef __XFCE_GDK_EXTENSIONS_H__
#define __XFCE_GDK_EXTENSIONS_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gdk/gdk.h>

G_BEGIN_DECLS;

gchar*      xfce_gdk_display_get_fullname (GdkDisplay *display) G_GNUC_CONST;
GdkScreen*  xfce_gdk_display_locate_monitor_with_pointer (GdkDisplay *display,
                                                          gint       *monitor_return);


gchar *xfce_gdk_screen_get_fullname (GdkScreen *screen) G_GNUC_CONST;


gboolean xfce_gdk_spawn_on_screen (GdkScreen           *screen,
                                   const gchar         *working_directory,
                                   gchar              **argv,
                                   gchar              **envp,
                                   GSpawnFlags          flags,
                                   GSpawnChildSetupFunc child_setup,
                                   gpointer             user_data,
                                   gint                *child_pid,
                                   GError             **error);

gboolean xfce_gdk_spawn_on_screen_with_pipes (GdkScreen            *screen,
				                                      const gchar          *working_directory,
                                        			gchar               **argv,
			                                        gchar               **envp,
                                              GSpawnFlags           flags,
                                              GSpawnChildSetupFunc  child_setup,
                                              gpointer              user_data,
                                              gint                 *child_pid,
                                              gint                 *standard_input,
                                              gint                 *standard_output,
                                              gint                 *standard_error,
                                              GError              **error);

gboolean xfce_gdk_spawn_command_line_on_screen (GdkScreen    *screen,
				                                        const gchar  *command_line,
                                        				GError      **error);

G_END_DECLS;

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* !__XFCE_GDK_EXTENSIONS_H__ */
