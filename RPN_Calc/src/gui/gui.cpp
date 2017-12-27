#include "gui/gui.h"

void initialize_gui(int* argc, char*** argv)
{
	gtk_init(argc, argv);
	GtkWidget* window;
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_signal_connect(window,
			 "delete-event",
		 	 G_CALLBACK(gtk_main_quit),
		 	 NULL);

	GtkWidget* buttons[16];
	initialize_buttons(buttons);

	GtkWidget* main_box;
	main_box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);

	GtkWidget* operat_grid;
	operat_grid = gtk_grid_new();
	/*
	 * 7 8 9 +
	 * 4 5 6 -
	 * 1 2 3 X
	 * ~ 0 = /       ~ is +/-
	 */
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[7]  , 0, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[8]  , 1, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[9]  , 2, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[10] , 3, 0, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[4]  , 0, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[5]  , 1, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[6]  , 2, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[11] , 3, 1, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[1]  , 0, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[2]  , 1, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[3]  , 2, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[12] , 3, 2, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[15] , 0, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[0]  , 1, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[14] , 2, 3, 1, 1);
	gtk_grid_attach(GTK_GRID(operat_grid), buttons[13] , 3, 3, 1, 1);


	globals::stack_top_label = gtk_label_new("STACK TOP");
	gtk_box_pack_start(GTK_BOX(main_box),
	 		   globals::stack_top_label,
			   FALSE,
			   FALSE,
			   0);

	globals::input_label = gtk_label_new("INPUT");
	gtk_box_pack_start(GTK_BOX(main_box),
			   globals::input_label,
			   FALSE,
			   FALSE,
			   0);

	gtk_box_pack_start(GTK_BOX(main_box), operat_grid, TRUE, TRUE, 6);

	gtk_container_add(GTK_CONTAINER(window), main_box);
	gtk_widget_set_size_request(window, 50, 100);
	gtk_container_set_border_width(GTK_CONTAINER(window), 12);
	gtk_widget_show_all(window);
	gtk_main();
}
