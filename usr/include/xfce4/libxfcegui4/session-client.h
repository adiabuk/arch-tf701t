/*  xfce4
 *  Copyright (C) 1999 Olivier Fourdan (fourdan@xfce.org)
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

#ifndef SESSION_CLIENT_H
#define SESSION_CLIENT_H

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <glib.h>
#include <unistd.h>
#include <sys/types.h>
#ifdef HAVE_LIBSM
#include <X11/ICE/ICElib.h>
#include <X11/SM/SMlib.h>
#endif

/* this formatting is needed by glib-mkenums */
typedef enum /*< prefix=SESSION_INTERACT_ >*/ {
    SESSION_INTERACT_NONE,
    SESSION_INTERACT_ERRORS,
    SESSION_INTERACT_ANY
}
SessionInteractStyle;

/* this formatting is needed by glib-mkenums */
typedef enum /*< prefix=SESSION_RESTART_ >*/ {
    SESSION_RESTART_IF_RUNNING,
    SESSION_RESTART_ANYWAY,
    SESSION_RESTART_IMMEDIATELY,
    SESSION_RESTART_NEVER
}
SessionRestartStyle;

/* this formatting is needed by glib-mkenums */
typedef enum /*< prefix=SESSION_CLIENT_ >*/ {
    SESSION_CLIENT_IDLE,
    SESSION_CLIENT_SAVING_PHASE_1,
    SESSION_CLIENT_WAITING_FOR_PHASE_2,
    SESSION_CLIENT_SAVING_PHASE_2,
    SESSION_CLIENT_WAITING_FOR_INTERACT,
    SESSION_CLIENT_DONE_WITH_INTERACT,
    SESSION_CLIENT_FROZEN,
    SESSION_CLIENT_DISCONNECTED,
    SESSION_CLIENT_REGISTERING
}
SessionClientState;

typedef void (*save_phase_2_callback) (gpointer client_data);
typedef void (*interact_callback) (gpointer client_data,
				   SessionInteractStyle interact_style);
typedef void (*shutdown_cancelled_callback) (gpointer client_data);
typedef void (*save_complete_callback) (gpointer client_data);
typedef void (*die_callback) (gpointer client_data);
typedef void (*save_yourself_callback) (gpointer client_data, int save_style,
					gboolean shutdown, int interact_style,
					gboolean fast);

typedef struct SessionClient
{
    save_phase_2_callback save_phase_2;
    interact_callback interact;
    shutdown_cancelled_callback shutdown_cancelled;
    save_complete_callback save_complete;
    die_callback die;
    save_yourself_callback save_yourself;

    gpointer data;
    gpointer session_connection;

    SessionClientState current_state;
    SessionRestartStyle restart_style;
    SessionInteractStyle interact_style;

    gchar priority;

    gchar *client_id;
    gchar *given_client_id;

    gchar *current_directory;
    gchar *program;
    gchar **clone_command;
    gchar **resign_command;
    gchar **restart_command;
    gchar **discard_command;
    gchar **shutdown_command;

    /* Private */

    gboolean shutdown;
}
SessionClient;

SessionClient *client_session_new_full (gpointer data,
					SessionRestartStyle restart_style,
					gchar priority, gchar * client_id,
					gchar * program,
					gchar * current_directory,
					gchar ** restart_command,
					gchar ** clone_command,
					gchar ** discard_command,
					gchar ** resign_command,
					gchar ** shutdown_command);
SessionClient *client_session_new (gint argc, gchar * argv[], gpointer data,
				   SessionRestartStyle restart_style,
				   gchar priority);

void client_session_free(SessionClient * session_client);

gboolean session_init (SessionClient * session_client);
void session_shutdown (SessionClient * session_client);
void logout_session (SessionClient * session_client);

void client_session_set_save_phase_2_callback(SessionClient * session_client, save_phase_2_callback value);
void client_session_set_interact_callback(SessionClient * session_client, interact_callback value);
void client_session_set_shutdown_cancelled_callback(SessionClient * session_client, shutdown_cancelled_callback value);
void client_session_set_save_complete_callback(SessionClient * session_client, save_complete_callback value);
void client_session_set_die_callback(SessionClient * session_client, die_callback value);
void client_session_set_save_yourself_callback(SessionClient * session_client, save_yourself_callback value);
void client_session_set_data(SessionClient * session_client, gpointer value);
void client_session_set_restart_style(SessionClient * session_client, SessionRestartStyle value);
void client_session_set_priority(SessionClient * session_client, gchar value);
void client_session_set_client_id(SessionClient * session_client, gchar const* value);
void client_session_set_current_directory(SessionClient * session_client, gchar const* value);
void client_session_set_program(SessionClient * session_client, gchar const* value);
void client_session_set_clone_command(SessionClient * session_client, gchar** const value);
void client_session_set_resign_command(SessionClient * session_client, gchar** const value);
void client_session_set_restart_command(SessionClient * session_client, gchar** const value);
void client_session_set_discard_command(SessionClient * session_client, gchar** const value);
void client_session_set_shutdown_command(SessionClient * session_client, gchar** const value);
save_phase_2_callback client_session_get_save_phase_2_callback(SessionClient * session_client);
interact_callback client_session_get_interact_callback(SessionClient * session_client);
shutdown_cancelled_callback client_session_get_shutdown_cancelled_callback(SessionClient * session_client);
save_complete_callback client_session_get_save_complete_callback(SessionClient * session_client);
die_callback client_session_get_die_callback(SessionClient * session_client);
save_yourself_callback client_session_get_save_yourself_callback(SessionClient * session_client);
gpointer client_session_get_data(SessionClient * session_client);
gpointer client_session_get_session_connection(SessionClient * session_client);
SessionClientState client_session_get_current_state(SessionClient * session_client);
SessionRestartStyle client_session_get_restart_style(SessionClient * session_client);
SessionInteractStyle client_session_get_interact_style(SessionClient * session_client);
gchar client_session_get_priority(SessionClient * session_client);
gchar const* client_session_get_client_id(SessionClient * session_client);
gchar const* client_session_get_given_client_id(SessionClient * session_client);
gchar const* client_session_get_current_directory(SessionClient * session_client);
gchar const* client_session_get_program(SessionClient * session_client);
G_CONST_RETURN gchar* G_CONST_RETURN * client_session_get_clone_command(SessionClient * session_client);
G_CONST_RETURN gchar* G_CONST_RETURN * client_session_get_resign_command(SessionClient * session_client);
G_CONST_RETURN gchar* G_CONST_RETURN * client_session_get_restart_command(SessionClient * session_client);
G_CONST_RETURN gchar* G_CONST_RETURN * client_session_get_discard_command(SessionClient * session_client);
G_CONST_RETURN gchar* G_CONST_RETURN * client_session_get_shutdown_command(SessionClient * session_client);

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif
