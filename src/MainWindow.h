//
// Created by piotr on 17.09.16.
//

#ifndef TWM_SESSION_LOGOUT_MAINWINDOW_H
#define TWM_SESSION_LOGOUT_MAINWINDOW_H
#include <gtkmm.h>
#include <string>
#include <stdlib.h>


class MainWindow : public Gtk::Window {
public:
    MainWindow();
    ~MainWindow() {};
    bool onKeyPress(GdkEventKey*);
    void application_quit() {
        get_application()->quit();
    };
    void system_lock() {
        popen(lock_command.c_str(),"w");
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
    inline void setLockCommand(std::string p_new_command){ lock_command = p_new_command;}
private:
    Gtk::Box main_container;
    Gtk::Box button_container;

	Gtk::Button button_lock;
    Gtk::Button button_logout;
    Gtk::Button button_reset;
    Gtk::Button button_shutdown;
    Gtk::Button button_exit;
    Gtk::Label header_label;
	
    int button_width = 130;
    int button_height = 60;
    bool show_images = true;
	bool title_visible = false;
    std::string lock_command = "i3lock -c 2a2a2a -f";
};


#endif //TWM_SESSION_LOGOUT_MAINWINDOW_H
