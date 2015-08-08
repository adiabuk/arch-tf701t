/* $Id$ */
/*-
 * Copyright (c) 2002-2006 Benedikt Meurer <benny@xfce.org>
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

#ifndef __LIBXFCEGUI4_XFCE_ABOUTDIALOG_H__
#define __LIBXFCEGUI4_XFCE_ABOUTDIALOG_H__

#if defined(LIBXFCEGUI4_COMPILATION) || !defined(XFCE_DISABLE_DEPRECATED)

#include <gtk/gtk.h>

#include <libxfce4util/libxfce4util.h>

G_BEGIN_DECLS;

#define XFCE_COPYRIGHT_TEXT(years, owner) ("Copyright (c) " years "\n" owner "\nAll rights reserved.")


typedef struct _XfceAboutInfo XfceAboutInfo;

#define XFCE_TYPE_ABOUT_INFO (xfce_about_info_get_type ())

GType             xfce_about_info_get_type        (void) G_GNUC_CONST;

XfceAboutInfo    *xfce_about_info_new             (const gchar          *program,
                                                   const gchar          *version,
                                                   const gchar          *description,
                                                   const gchar          *copyright,
                                                   const gchar          *license) G_GNUC_MALLOC;

XfceAboutInfo    *xfce_about_info_copy            (const XfceAboutInfo  *info) G_GNUC_MALLOC;

void              xfce_about_info_free            (XfceAboutInfo        *info);

const gchar      *xfce_about_info_get_program     (const XfceAboutInfo  *info);
void              xfce_about_info_set_program     (XfceAboutInfo        *info,
                                                   const gchar          *program);

const gchar      *xfce_about_info_get_version     (const XfceAboutInfo  *info);
void              xfce_about_info_set_version     (XfceAboutInfo        *info,
                                                   const gchar          *version);

const gchar      *xfce_about_info_get_description (const XfceAboutInfo  *info);
void              xfce_about_info_set_description (XfceAboutInfo        *info,
                                                   const gchar          *description);

const gchar      *xfce_about_info_get_copyright   (const XfceAboutInfo  *info);
void              xfce_about_info_set_copyright   (XfceAboutInfo        *info,
                                                   const gchar          *copyright);

const gchar      *xfce_about_info_get_license     (const XfceAboutInfo  *info);
void              xfce_about_info_set_license     (XfceAboutInfo        *info,
                                                   const gchar          *license);

const gchar      *xfce_about_info_get_homepage    (const XfceAboutInfo  *info);
void              xfce_about_info_set_homepage    (XfceAboutInfo        *info,
                                                   const gchar          *homepage);

void              xfce_about_info_add_credit    (XfceAboutInfo        *info,
                                                 const gchar          *name,
                                                 const gchar          *mail,
                                                 const gchar          *task);


typedef struct _XfceAboutDialogPrivate XfceAboutDialogPrivate;
typedef struct _XfceAboutDialogClass   XfceAboutDialogClass;
typedef struct _XfceAboutDialog        XfceAboutDialog;

#define XFCE_TYPE_ABOUT_DIALOG            (xfce_about_dialog_get_type ())
#define XFCE_ABOUT_DIALOG(obj)            (G_TYPE_CHECK_INSTANCE_CAST((obj), XFCE_TYPE_ABOUT_DIALOG, XfceAboutDialog))
#define XFCE_ABOUT_DIALOG_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST((klass), XFCE_TYPE_ABOUT_DIALOG, XfceAboutDialogClass))
#define XFCE_IS_ABOUT_DIALOG(obj)         (G_TYPE_CHECK_INSTANCE_TYPE((obj), XFCE_TYPE_ABOUT_DIALOG))
#define XFCE_IS_ABOUT_DIALOG_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), XFCE_TYPE_ABOUT_DIALOG))
#define XFCE_ABOUT_DIALOG_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), XFCE_TYPE_ABOUT_DIALOG, XfceAboutDialogClass))

struct _XfceAboutDialogClass
{
  GtkDialogClass __parent__;
};

struct _XfceAboutDialog
{
  GtkDialog __parent__;
  XfceAboutDialogPrivate *priv;
};

GType       xfce_about_dialog_get_type (void) G_GNUC_CONST;

GtkWidget*  xfce_about_dialog_new_with_values (GtkWindow            *parent,
                                   const XfceAboutInfo  *info,
                                   GdkPixbuf            *icon) G_GNUC_MALLOC;

/* old: xfce_about_dialog_new */
GtkWidget*  xfce_about_dialog_new (GtkWindow            *parent,
                                   const XfceAboutInfo  *info,
                                   GdkPixbuf            *icon) G_GNUC_DEPRECATED G_GNUC_MALLOC;

GtkWidget*  xfce_about_dialog_new_empty (void) G_GNUC_MALLOC;
void xfce_about_dialog_set_program(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_version(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_description(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_copyright(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_license(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_homepage(XfceAboutDialog* dialog, const gchar *value);
void xfce_about_dialog_set_icon(XfceAboutDialog* dialog, GdkPixbuf *icon);
void xfce_about_dialog_add_credit(XfceAboutDialog* dialog,
	const gchar   *name,
	const gchar   *mail,
	const gchar   *task);

const gchar *xfce_about_dialog_get_program(XfceAboutDialog* dialog);
const gchar *xfce_about_dialog_get_version(XfceAboutDialog* dialog);
const gchar *xfce_about_dialog_get_description(XfceAboutDialog* dialog);
const gchar *xfce_about_dialog_get_copyright(XfceAboutDialog* dialog);
const gchar *xfce_about_dialog_get_license(XfceAboutDialog* dialog);
const gchar *xfce_about_dialog_get_homepage(XfceAboutDialog* dialog);
GdkPixbuf   *xfce_about_dialog_get_icon(XfceAboutDialog* dialog);

G_END_DECLS;

#endif /* !XFCE_DISABLE_DEPRECATED */

#endif  /* !__LIBXFCEGUI4_XFCE_ABOUTDIALOG_H__ */
