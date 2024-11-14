#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdbool.h>

static bool sleep_inhibited = false;
static GtkWidget *label;

void toggle_sleep(GtkWidget *widget, gpointer data) {
    if (sleep_inhibited) {
        system("pkill gnome-session-inhibit");  // Stop sleep inhibition
        gtk_label_set_markup(GTK_LABEL(label), "<span foreground='red' weight='bold'>Sleep Inhibition Disabled</span>");
        gtk_button_set_label(GTK_BUTTON(widget), "Enable Sleep Inhibition");
    } else {
        system("gnome-session-inhibit --inhibit-only &");  // Inhibit sleeping
        gtk_label_set_markup(GTK_LABEL(label), "<span foreground='green' weight='bold'>Sleep Inhibition Enabled</span>");
        gtk_button_set_label(GTK_BUTTON(widget), "Disable Sleep Inhibition");
    }
    sleep_inhibited = !sleep_inhibited;
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "NoScreenSleep");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 100);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    label = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(label), "<span foreground='red' weight='bold'>Sleep Inhibition Disabled</span>");
    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);

    GtkWidget *button = gtk_button_new_with_label("Enable Sleep Inhibition");
    g_signal_connect(button, "clicked", G_CALLBACK(toggle_sleep), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), button, TRUE, TRUE, 0);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

