#include <gtkmm.h>
#include "src/MainWindow.h"

int main(int argc, char *argv[])
{
    char* language;
    language = getenv ("LANG");
    auto app =
    Gtk::Application::create(argc, argv,
      "org.leinnan.twmsesionlogout");
    MainWindow window;

	
    return app->run(window);
}
