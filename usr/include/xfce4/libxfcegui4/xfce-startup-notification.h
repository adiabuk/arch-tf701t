/*
 * Copyright (C) 2003-2011 The Xfce Development Team
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

#ifndef __XFCE_STARTUP_NOTIFICATION_H
#define __XFCE_STARTUP_NOTIFICATION_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

/* not thread safe */

/* returns: id */
char* xfce_startup_notification_start(GdkScreen* screen, char const* path);

void xfce_startup_notification_cancel(const char* id);

#define XFCE_STARTUP_NOTIFICATION_ENVIRONMENT_DESKTOP_STARTUP_ID "DESKTOP_STARTUP_ID"

char** xfce_startup_notification_modify_environment(const char** envp, const char* id);
char** xfce_startup_notification_cleanup_environment(const char** envp);

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif
