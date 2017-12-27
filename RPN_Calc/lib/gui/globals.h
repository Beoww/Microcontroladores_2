#ifndef GLOBALS_H
#define GLOBALS_H

// Includes
#include "buttons.h"
#include "calculator_functions.h"
#include <gtk/gtk.h>

enum Pending_Operation
{
	PENDING_NONE,
	PENDING_ADD,
	PENDING_SUB,
	PENDING_DIV,
	PENDING_MUL,
};

namespace globals{
	extern GtkWidget*		stack_top_label;
	extern GtkWidget*		input_label;
	extern Pending_Operation	op;
}

void update_labels(void);

#endif // GLOBALS_H
