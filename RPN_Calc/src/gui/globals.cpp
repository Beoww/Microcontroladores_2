#include "gui/globals.h"

namespace globals{
	GtkWidget*	stack_top_label;
	GtkWidget*	input_label;
	Pending_Operation	op = PENDING_NONE;
}


void update_labels(void)
{
	if(is_num_initialized)
	{
		int num_result = ret_num();
		gchar* label_title = g_strdup_printf("%d", num_result);
		gtk_label_set_text(GTK_LABEL(globals::input_label),
		 		   label_title);
		g_free(label_title);
	}
	else
	{
		gtk_label_set_text(GTK_LABEL(globals::input_label),
		 		   "");
	}

	if(is_stack_empty())
	{
		gtk_label_set_text(GTK_LABEL(globals::stack_top_label),
		 		   "");
	}
	else
	{
		int peek_result = peek();
		gchar* label_title = g_strdup_printf("%d", peek_result);
		gtk_label_set_text(GTK_LABEL(globals::stack_top_label),
			 	   label_title);
		g_free(label_title);
	}
}
