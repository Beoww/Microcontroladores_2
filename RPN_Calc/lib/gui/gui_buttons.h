#ifndef GUI_BUTTONS_H
#define GUI_BUTTONS_H

// Includes
#include <gtk/gtk.h>
#include "buttons.h"
#include "globals.h"
#include <string>

void initialize_buttons(GtkWidget* buttons[]);

void button_response(GtkWidget* button, gpointer data);

#endif // GUI_BUTTONS_H
