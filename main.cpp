#include <gtkmm.h>
#include <stdlib.h>

void application_quit() {
    Gtk::Main::quit();
}

void system_lock() {
    popen("i3lock -c 2a2a2a -f","w");
    application_quit();
}
void system_logout() {
    system("pkill -KILL -u $USER");
    application_quit();
}
void system_reset() {
    system("systemctl reboot");
    application_quit();
}
void system_shutdown() {
    system("systemctl poweroff");
    application_quit();
}



int main(int argc, char *argv[])
{
    int button_width = 130;
    int button_height = 60;

    char* language;
    language = getenv ("LANG");


    auto app =
    Gtk::Application::create(argc, argv,
      "org.leinnan.twmsesionlogout");



    Gtk::Window window;
    // config window
    window.set_title("Session manager");
    window.set_border_width(10);
    window.set_position(Gtk::WIN_POS_CENTER);
    window.set_skip_taskbar_hint(true);
    window.set_keep_above(true);
    window.set_decorated(false);


    Gtk::Box main_container(Gtk::ORIENTATION_VERTICAL ,5);
    Gtk::Box button_container(Gtk::ORIENTATION_HORIZONTAL ,5);

    Gtk::Button button_lock("Lock");
    Gtk::Button button_logout("Logout");
    Gtk::Button button_reset("Reset");
    Gtk::Button button_shutdown("Shutdown");
    Gtk::Button button_exit("Quit");

    Gtk::Label header_label("Session manager", true);




    window.add(main_container);
    main_container.pack_start(header_label);
    main_container.pack_start(button_container);
    main_container.pack_start(button_exit);
    button_container.pack_start(button_lock);
    button_container.pack_start(button_logout);
    button_container.pack_start(button_reset);
    button_container.pack_start(button_shutdown);
    //window.set_default_size(200, 200);
    
    
    button_exit.set_margin_left(button_width*3+30);
    button_exit.signal_clicked().connect(sigc::ptr_fun(&application_quit));

    button_lock.set_image_from_icon_name("system-lock-screen",Gtk::ICON_SIZE_DIALOG);
    button_lock.set_image_position(Gtk::POS_TOP);
    button_lock.set_always_show_image();
    button_lock.set_tooltip_markup("Press <b>L</b> to lock");
    button_lock.set_size_request(button_width,button_height);
    button_lock.signal_clicked().connect(sigc::ptr_fun(&system_lock));

    button_logout.set_image_from_icon_name("system-log-out",Gtk::ICON_SIZE_DIALOG);
    button_logout.set_image_position(Gtk::POS_TOP);
    button_logout.set_always_show_image();
    button_logout.set_tooltip_markup("Press <b>O</b> to logout");
    button_logout.set_size_request(button_width,button_height);
    button_logout.signal_clicked().connect(sigc::ptr_fun(&system_logout));

    button_reset.set_image_from_icon_name("system-restart",Gtk::ICON_SIZE_DIALOG);
    button_reset.set_image_position(Gtk::POS_TOP);
    button_reset.set_always_show_image();
    button_reset.set_tooltip_markup("Press <b>R</b> to restart");
    button_reset.set_size_request(button_width,button_height);
    button_reset.signal_clicked().connect(sigc::ptr_fun(&system_reset));

    button_shutdown.set_image_from_icon_name("system-shutdown",Gtk::ICON_SIZE_DIALOG);
    button_shutdown.set_image_position(Gtk::POS_TOP);
    button_shutdown.set_always_show_image();
    button_shutdown.set_tooltip_markup("Press <b>S</b> to shutdown");
    button_shutdown.set_size_request(button_width,button_height);
    button_shutdown.signal_clicked().connect(sigc::ptr_fun(&system_shutdown));


    window.show_all_children();
    return app->run(window);
}
