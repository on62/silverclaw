#include "SilverClawApp.h"
#include <giomm.h>
#include <gtkmm/messagedialog.h>
#include <gtkmm/filechooser.h>
#include <gtkmm/filechooserdialog.h>

SilverClawApp::SilverClawApp() : Gtk::Application(
        "org.wlfgang.silverclaw",
        Gio::APPLICATION_FLAGS_NONE),
                                 window{nullptr} {
    Glib::set_application_name("silverclaw");
}

void SilverClawApp::on_startup() {
    Application::on_startup();

    add_action("open", sigc::mem_fun(*this, &SilverClawApp::onFileOpen));
    add_action("exit", sigc::mem_fun(*this, &SilverClawApp::onFileExit));

    builder = Gtk::Builder::create();
    try {
        builder->add_from_file("resources/silverclaw.glade");
        builder->add_from_file("resources/sc_menu.ui");
    } catch (const Glib::Error &ex) {
        Gtk::MessageDialog dialog("Error building UI: " + ex.what());
        dialog.run();
    }

    // add the menu bar
    auto obj = builder->get_object("sc-menu");
    auto menu = Glib::RefPtr<Gio::Menu>::cast_dynamic(obj);
    if (!menu) {
        Gtk::MessageDialog dialog("Error creating menu");
        dialog.run();
    } else {
        set_menubar(menu);
    }
}

void SilverClawApp::on_activate() {
    builder->get_widget("SilverClawWindow", window);
    add_window(*window);
    window->show_all();
}

void SilverClawApp::onFileExit() {
    quit();
    onWindowHide(window);
}

void SilverClawApp::onFileOpen() {

    // prompt user to select the file
    Gtk::FileChooserDialog dialog("Open File", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*window);
    dialog.add_button("_Cancel", Gtk::RESPONSE_CANCEL);
    dialog.add_button("_Open", Gtk::RESPONSE_OK);

    // open the file if the user clicks ok
    if (Gtk::RESPONSE_OK == dialog.run()) {

    }
}

void SilverClawApp::onWindowHide(Gtk::Window *wnd) {
    delete wnd;
}
