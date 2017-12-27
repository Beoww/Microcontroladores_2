#include "gui/gui_buttons.h"

void initialize_buttons(GtkWidget* buttons[])
{
	buttons[0] = gtk_button_new_with_label("   0   ");
	buttons[1] = gtk_button_new_with_label("   1   ");
	buttons[2] = gtk_button_new_with_label("   2   ");
	buttons[3] = gtk_button_new_with_label("   3   ");
	buttons[4] = gtk_button_new_with_label("   4   ");
	buttons[5] = gtk_button_new_with_label("   5   ");
	buttons[6] = gtk_button_new_with_label("   6   ");
	buttons[7] = gtk_button_new_with_label("   7   ");
	buttons[8] = gtk_button_new_with_label("   8   ");
	buttons[9] = gtk_button_new_with_label("   9   ");
	buttons[10] = gtk_button_new_with_label("   +   ");
	buttons[11] = gtk_button_new_with_label("   -   ");
	buttons[12] = gtk_button_new_with_label("   X   ");
	buttons[13] = gtk_button_new_with_label("   /   ");
	buttons[14] = gtk_button_new_with_label("   =   ");
	buttons[15] = gtk_button_new_with_label("  +/-  ");

	for(int i = 0; i < 16; i++)
	{
		g_signal_connect(buttons[i],
			 	 "clicked",
				 G_CALLBACK(button_response),
				 NULL);
	}
}

void button_response(GtkWidget* button, gpointer data)
{
	std::string response;
	response = gtk_button_get_label(GTK_BUTTON(button));
	if(response == "   0   ")
	{
		globals::op = PENDING_NONE;
		bnum(0);
		update_labels();
	}
	else if(response == "   1   ")
	{
		globals::op = PENDING_NONE;
		bnum(1);
		update_labels();
	}
	else if(response == "   2   ")
	{
		globals::op = PENDING_NONE;
		bnum(2);
		update_labels();
	}
	else if(response == "   3   ")
	{
		globals::op = PENDING_NONE;
		bnum(3);
		update_labels();
	}
	else if(response == "   4   ")
	{
		globals::op = PENDING_NONE;
		bnum(4);
		update_labels();
	}
	else if(response == "   5   ")
	{
		globals::op = PENDING_NONE;
		bnum(5);
		update_labels();
	}
	else if(response == "   6   ")
	{
		globals::op = PENDING_NONE;
		bnum(6);
		update_labels();
	}
	else if(response == "   7   ")
	{
		globals::op = PENDING_NONE;
		bnum(7);
		update_labels();
	}
	else if(response == "   8   ")
	{
		globals::op = PENDING_NONE;
		bnum(8);
		update_labels();
	}
	else if(response == "   9   ")
	{
		globals::op = PENDING_NONE;
		bnum(9);
		update_labels();
	}
	else if(response == "   +   ")
	{
		globals::op = PENDING_ADD;
		gtk_label_set_text(GTK_LABEL(globals::input_label),
				   "   +   ");
	}
	else if(response == "   -   ")
	{
		globals::op = PENDING_SUB;
		gtk_label_set_text(GTK_LABEL(globals::input_label),
				   "   -   ");
	}
	else if(response == "   X   ")
	{
		globals::op = PENDING_MUL;
		gtk_label_set_text(GTK_LABEL(globals::input_label),
				   "   X   ");
	}
	else if(response == "   /   ")
	{
		globals::op = PENDING_DIV;
		gtk_label_set_text(GTK_LABEL(globals::input_label),
				   "   /   ");
	}
	else if(response == "   =   ")
	{
		run status;

		switch (globals::op)
		{
		case PENDING_ADD:
			status = badd();
			break;
		case PENDING_SUB:
			status = bsub();
			break;
		case PENDING_DIV:
			status = bdiv();
			break;
		case PENDING_MUL:
			status = bmul();
			break;
		default:
			status = beq();
			break;
		}

		if(status == RUN_OKAY)
		{
			update_labels();
		}
		else if(status == RUN_DOMAIN_ERROR)
		{
			gtk_label_set_text(GTK_LABEL(globals::stack_top_label),
					   "MATHS ERROR");
		}
		else if(status == RUN_STACK_OVERFLOW)
		{
			gtk_label_set_text(GTK_LABEL(globals::stack_top_label),
					   "STACK OVERFLOW");
		}
		else if(status == RUN_INSUFFICIENT_STACK)
		{
			gtk_label_set_text(GTK_LABEL(globals::stack_top_label),
					   "SYNTAX ERROR");
		}

	}
	else if(response == "  +/-  ")
	{
		bpm();
		update_labels();
	}
}
