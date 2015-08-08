/* $Id$
 * 
 * Copyright (C) 2004 Jasper Huijsmans <jasper@xfce.org>
 * startup notification added by Olivier Fourdan based on gnome-desktop
 * developed by Elliot Lee <sopwith@redhat.com> and Sid Vicious
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

#ifndef _XFCE_EXEC_H
#define _XFCE_EXEC_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib.h>

G_BEGIN_DECLS

gboolean xfce_exec_argv (char **argv, gboolean in_terminal, gboolean use_sn, 
                         GError ** error);

gboolean xfce_exec_argv_with_envp (char **argv, gboolean in_terminal, 
				   gboolean use_sn, GError ** error,
				   char **envp);

gboolean xfce_exec (const char *cmd, gboolean in_terminal, gboolean use_sn,
	   	    GError **error);

gboolean xfce_exec_with_envp (const char *cmd, gboolean in_terminal, 
    			      gboolean use_sn, GError **error,
			      char **envp);

gboolean xfce_exec_sync (const char *cmd, gboolean in_terminal, gboolean use_sn,
			 GError **error);

gboolean xfce_exec_sync_with_envp (const char *cmd, gboolean in_terminal, 
				   gboolean use_sn, GError **error,
				   char **envp);

/* run on specific screen */
gboolean xfce_exec_argv_on_screen (GdkScreen * screen, char **argv,
                                   gboolean in_terminal, gboolean use_sn,
                                   GError ** error);

gboolean xfce_exec_argv_with_envp_on_screen (GdkScreen * screen, char **argv,
                                             gboolean in_terminal,
                                             gboolean use_sn, GError ** error,
                                             char **envp);

gboolean xfce_exec_on_screen (GdkScreen * screen, const char *cmd,
                              gboolean in_terminal, gboolean use_sn,
                              GError ** error);

gboolean xfce_exec_with_envp_on_screen (GdkScreen * screen, const char *cmd,
                                        gboolean in_terminal, gboolean use_sn,
                                        GError ** error, char **envp);

G_END_DECLS

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif /* _XFCE_EXEC_H */

