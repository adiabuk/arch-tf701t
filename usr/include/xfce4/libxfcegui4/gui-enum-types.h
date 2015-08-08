


#ifndef __GUI_ENUM_TYPES_H__
#define __GUI_ENUM_TYPES_H__
#include <glib-object.h>
/* enumerations from "icons.h" */
GType xfce_icon_theme_category_get_type (void);
#define GUI_TYPE_ICON_THEME_CATEGORY (xfce_icon_theme_category_get_type())
/* enumerations from "xfce_clock.h" */
GType xfce_clock_mode_get_type (void);
#define GUI_TYPE_CLOCK_MODE (xfce_clock_mode_get_type())
GType xfce_clock_led_size_get_type (void);
#define GUI_TYPE_CLOCK_LED_SIZE (xfce_clock_led_size_get_type())
/* enumerations from "xfce_decorbutton.h" */
GType xfce_decorbutton_type_get_type (void);
#define GUI_TYPE_DECORBUTTON_TYPE (xfce_decorbutton_type_get_type())
/* enumerations from "xfce-filechooser.h" */
GType xfce_file_chooser_action_get_type (void);
#define GUI_TYPE_FILE_CHOOSER_ACTION (xfce_file_chooser_action_get_type())
/* enumerations from "session-client.h" */
GType session_interact_style_get_type (void);
#define GUI_TYPE_INTERACT_STYLE (session_interact_style_get_type())
GType session_restart_style_get_type (void);
#define GUI_TYPE_RESTART_STYLE (session_restart_style_get_type())
GType session_client_state_get_type (void);
#define GUI_TYPE_CLIENT_STATE (session_client_state_get_type())
/* enumerations from "gtktoxevent.h" */
GType xfce_filter_status_get_type (void);
#define GUI_TYPE_FILTER_STATUS (xfce_filter_status_get_type())
#endif /* __GUI_ENUM_TYPES_H__ */



