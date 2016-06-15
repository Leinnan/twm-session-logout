#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <gdk/gdkkeysyms.h>

void system_lock(void) {
    g_print("Lock system\n");
    system("i3lock -c 2a2a2a -f");
    gtk_main_quit();
    //todo: logout command
}
void system_logout(void) {
    g_print("Logging out\n");
    system("pkill -KILL -u $USER");
    gtk_main_quit();
    //todo: logout command
}
void system_reset(void) {
    g_print("Restarting system\n");
    system("reboot");
    gtk_main_quit();
    //todo: Restarting command
}
void system_shutdown(void) {
    g_print("Shutdown system\n");
    system("poweroff");
    gtk_main_quit();
    //todo: Shutdown command
}

static gboolean check_escape(GtkWidget *widget, GdkEventKey *event, gpointer data) {
  if (event->keyval == GDK_KEY_Escape) {
    gtk_main_quit();
    return TRUE;
  }
  if(event->keyval == GDK_KEY_R || event->keyval == GDK_KEY_r){
    system_reset();
    return TRUE;
  }
  if(event->keyval == GDK_KEY_L || event->keyval == GDK_KEY_l){
    system_lock();
    return TRUE;
  }
  if(event->keyval == GDK_KEY_O || event->keyval == GDK_KEY_o){
    system_logout();
    return TRUE;
  }
  if(event->keyval == GDK_KEY_S || event->keyval == GDK_KEY_s){
    system_shutdown();
    return TRUE;
  }
  return FALSE;
}


void destroy (void) {
  gtk_main_quit ();
}

int main (int argc, char *argv[]){
    GtkWidget *window;
    GtkWidget *rootbox;
    GtkWidget *vbox;
    GtkWidget *header_label;
    GtkWidget *button_lock;
    GtkWidget *button_logout;
    GtkWidget *button_reset;
    GtkWidget *button_shutdown;
    GtkWidget *image_lock;
    GtkWidget *image_logout;
    GtkWidget *image_reset;
    GtkWidget *image_shutdown;
    int button_width = 130;
    int button_height = 60;


    gtk_init (&argc, &argv);

    window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
    rootbox = gtk_vbox_new(FALSE, 10);
    vbox = gtk_hbox_new(FALSE, 5);
    gtk_container_add(GTK_CONTAINER(window), rootbox);
    //ustawienia okna
    gtk_window_set_position(window, GTK_WIN_POS_CENTER);
    gtk_window_set_title(GTK_WINDOW(window),"Session manager");
    gtk_window_set_skip_taskbar_hint(GTK_WINDOW(window), TRUE);
    gtk_window_set_keep_above (GTK_WINDOW(window), TRUE);
    gtk_window_set_decorated(GTK_WINDOW(window), FALSE);

    gtk_signal_connect (GTK_OBJECT (window), "destroy",
              GTK_SIGNAL_FUNC (destroy), NULL);
    gtk_container_border_width (GTK_CONTAINER (window), 10);

    header_label = gtk_label_new ("Session manager");
    button_lock = gtk_button_new_with_label ("Lock");
    image_lock = gtk_image_new_from_icon_name("system-lock-screen", GTK_ICON_SIZE_DIALOG);
    gtk_button_set_image(button_lock, image_lock);
    gtk_button_set_image_position(button_lock, GTK_POS_TOP);

    button_logout = gtk_button_new_with_label ("L(o)gout");
    image_logout = gtk_image_new_from_icon_name("system-log-out", GTK_ICON_SIZE_DIALOG);
    gtk_button_set_image(button_logout, image_logout);
    gtk_button_set_image_position(button_logout, GTK_POS_TOP);

    button_reset = gtk_button_new_with_label ("Restart");
    image_reset = gtk_image_new_from_icon_name("system-restart", GTK_ICON_SIZE_DIALOG);
    gtk_button_set_image(button_reset, image_reset);
    gtk_button_set_image_position(button_reset, GTK_POS_TOP);

    button_shutdown = gtk_button_new_with_label ("Shutdown");
    image_shutdown = gtk_image_new_from_icon_name("system-shutdown", GTK_ICON_SIZE_DIALOG);
    gtk_button_set_image(button_shutdown, image_shutdown);
    gtk_button_set_image_position(button_shutdown, GTK_POS_TOP);


    gtk_signal_connect (GTK_OBJECT (button_lock), "clicked",
                GTK_SIGNAL_FUNC (system_lock), NULL);
    gtk_signal_connect (GTK_OBJECT (button_logout), "clicked",
                GTK_SIGNAL_FUNC (system_logout), NULL);
    gtk_signal_connect (GTK_OBJECT (button_reset), "clicked",
                GTK_SIGNAL_FUNC (system_reset), NULL);
    gtk_signal_connect (GTK_OBJECT (button_shutdown), "clicked",
                GTK_SIGNAL_FUNC (system_shutdown), NULL);
    g_signal_connect(GTK_OBJECT(window), "key-release-event",
                G_CALLBACK(check_escape), NULL);
    // pakujemy przyciski do kontenera
    gtk_box_pack_start (GTK_BOX(rootbox), header_label, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(rootbox), vbox, TRUE, TRUE, 0);

    gtk_box_pack_start (GTK_BOX(vbox), button_lock, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), button_logout, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), button_reset, TRUE, TRUE, 0);
    gtk_box_pack_start (GTK_BOX(vbox), button_shutdown, TRUE, TRUE, 0);

    // ustalamy rozmiar przycisków(opcjonalne
    gtk_widget_set_size_request(button_lock, button_width,button_height);
    gtk_widget_set_size_request(button_logout, button_width,button_height);
    gtk_widget_set_size_request(button_reset, button_width,button_height);
    gtk_widget_set_size_request(button_shutdown, button_width,button_height);

    gtk_widget_show_all(window);

    gtk_main ();

    return 0;
}
