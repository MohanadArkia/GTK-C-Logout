#include <gtk/gtk.h>
#include <stdlib.h>

void cancel_button_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}

void shutdown_button_clicked(GtkWidget *widget, gpointer data)
{
    system("shutdown now");
}

void reboot_button_clicked(GtkWidget *widget, gpointer data)
{
    system("reboot");
}

void sleep_button_clicked(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
    system("systemctl suspend");
}

int main(int argc, char *argv[])
{
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Logout");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 300, 100);

    // Create a horizontal box to align buttons
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5); // 5 is the spacing between buttons

    // Load images for buttons
    GtkWidget *cancel_image = gtk_image_new_from_file("./images/cancel.png");
    GtkWidget *shutdown_image = gtk_image_new_from_file("./images/shutdown.png");
    GtkWidget *reboot_image = gtk_image_new_from_file("./images/reboot.png");
    GtkWidget *sleep_image = gtk_image_new_from_file("./images/sleep.png");

    // Create buttons and set images
    GtkWidget *cancel_button = gtk_button_new();
    GtkWidget *shutdown_button = gtk_button_new();
    GtkWidget *reboot_button = gtk_button_new();
    GtkWidget *sleep_button = gtk_button_new();

    gtk_button_set_image(GTK_BUTTON(cancel_button), cancel_image);
    gtk_button_set_image(GTK_BUTTON(shutdown_button), shutdown_image);
    gtk_button_set_image(GTK_BUTTON(reboot_button), reboot_image);
    gtk_button_set_image(GTK_BUTTON(sleep_button), sleep_image);

    // Connect the clicked signals of all buttons to their respective callback functions
    g_signal_connect(cancel_button, "clicked", G_CALLBACK(cancel_button_clicked), NULL);
    g_signal_connect(sleep_button, "clicked", G_CALLBACK(sleep_button_clicked), NULL);
    g_signal_connect(reboot_button, "clicked", G_CALLBACK(reboot_button_clicked), NULL);
    g_signal_connect(shutdown_button, "clicked", G_CALLBACK(shutdown_button_clicked), NULL);

    // Add buttons to the horizontal box
    gtk_box_pack_start(GTK_BOX(hbox), cancel_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), shutdown_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), reboot_button, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), sleep_button, TRUE, TRUE, 0);

    // Add the horizontal box to the window
    gtk_container_add(GTK_CONTAINER(window), hbox);

    // Show all widgets
    gtk_widget_show_all(window);

    // Run the GTK main loop
    gtk_main();

    return 0;
}