//
// Created by piotr on 17.09.16.
//

#ifndef TWM_SESSION_LOGOUT_MAINWINDOW_H
#define TWM_SESSION_LOGOUT_MAINWINDOW_H
#include <gtkmm.h>
#include <stdlib.h>


class MainWindow : public Gtk::Window {
public:
    MainWindow();
    ~MainWindow() {};
    bool onKeyPress(GdkEventKey*);
    void application_quit() {
        Gtk::Main::quit();
    };
    void system_lock() {
        popen("i3lock -c 2a2a2a -f","w");
        application_quit();
    };
    void system_logout() {
        system("pkill -KILL -u $USER");
        application_quit();
    };
    void system_reset() {
        system("systemctl reboot");
        application_quit();
    };
    void system_shutdown() {
        system("systemctl poweroff");
        application_quit();
    };
private:
    Gtk::Box main_container;
    Gtk::Box button_container;


    Gtk::Label header_label;

    Gtk::Button button_lock;
    Gtk::Button button_logout;
    Gtk::Button button_reset;
    Gtk::Button button_shutdown;
    Gtk::Button button_exit;
    int button_width = 130;
    int button_height = 60;
    bool show_images = true;
};


#endif //TWM_SESSION_LOGOUT_MAINWINDOW_H
