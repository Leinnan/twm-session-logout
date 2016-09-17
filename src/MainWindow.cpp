//
// Created by piotr on 17.09.16.
//

#include "MainWindow.h"
#include <iostream>

MainWindow::MainWindow()
: main_container(Gtk::ORIENTATION_VERTICAL ,5),
  button_container(Gtk::ORIENTATION_HORIZONTAL ,5),
  button_lock("Lock"),
  button_logout("Logout"),
  button_reset("Reset"),
  button_shutdown("Shutdown"),
  button_exit("Quit"),
  header_label("Session manager", true)
{
    // config window
    this->set_title("Session manager");
    this->set_border_width(10);
    this->set_position(Gtk::WIN_POS_CENTER);
    this->set_skip_taskbar_hint(true);
    this->set_keep_above(true);
    this->set_decorated(false);
    this->signal_key_press_event().connect( sigc::mem_fun( *this, &MainWindow::onKeyPress ) );

    header_label.set_use_markup(true);

    this->add(main_container);
    main_container.pack_start(header_label);
    main_container.pack_start(button_container);
    main_container.pack_start(button_exit);

    button_container.pack_start(button_lock);
    button_container.pack_start(button_logout);
    button_container.pack_start(button_reset);
    button_container.pack_start(button_shutdown);
    //window.set_default_size(200, 200);


    button_exit.set_margin_left(button_width*3+30);
    button_exit.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::application_quit));

    button_lock.set_image_from_icon_name("system-lock-screen",Gtk::ICON_SIZE_DIALOG);
    button_lock.set_relief(Gtk::RELIEF_NONE);
    button_lock.set_image_position(Gtk::POS_TOP);
    button_lock.set_always_show_image();
    button_lock.set_tooltip_markup("Press <b>L</b> to lock");
    button_lock.set_size_request(button_width,button_height);
    button_lock.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::system_lock));

    button_logout.set_image_from_icon_name("system-log-out",Gtk::ICON_SIZE_DIALOG);
    button_logout.set_relief(Gtk::RELIEF_NONE);
    button_logout.set_image_position(Gtk::POS_TOP);
    button_logout.set_always_show_image();
    button_logout.set_tooltip_markup("Press <b>O</b> to logout");
    button_logout.set_size_request(button_width,button_height);
    button_logout.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::system_logout));

    button_reset.set_image_from_icon_name("system-restart",Gtk::ICON_SIZE_DIALOG);
    button_reset.set_relief(Gtk::RELIEF_NONE);
    button_reset.set_image_position(Gtk::POS_TOP);
    button_reset.set_always_show_image();
    button_reset.set_tooltip_markup("Press <b>R</b> to restart");
    button_reset.set_size_request(button_width,button_height);
    button_reset.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::system_reset));

    button_shutdown.set_image_from_icon_name("system-shutdown",Gtk::ICON_SIZE_DIALOG);
    button_shutdown.set_relief(Gtk::RELIEF_NONE);
    button_shutdown.set_image_position(Gtk::POS_TOP);
    button_shutdown.set_always_show_image();
    button_shutdown.set_tooltip_markup("Press <b>S</b> to shutdown");
    button_shutdown.set_size_request(button_width,button_height);
    button_shutdown.signal_clicked().connect(sigc::mem_fun(this, &MainWindow::system_shutdown));


    this->show_all_children();
}


bool MainWindow::onKeyPress(GdkEventKey* event) {
    std::cout << event->keyval << ' ' << event->hardware_keycode << ' ' << event->state << std::endl;

    switch(event->keyval){
        case 76:
            this->system_lock();
            break;
        case 108:
            this->system_lock();
            break;
        case 79:
            this->system_logout();
            break;
        case 111:
            this->system_logout();
            break;
        case 82:
            this->system_reset();
            break;
        case 114:
            this->system_reset();
            break;
        case 83:
            this->system_shutdown();
            break;
        case 115:
            this->system_shutdown();
            break;
        case 65307:
            this->application_quit();
        default:
            header_label.set_text("<span weight='heavy' fgcolor='red'> Wrong Key! </span>");
            header_label.set_use_markup(true);
            break;
    }

    return false;
}