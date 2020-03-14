#ifndef SILVERCLAW_SILVERCLAWAPP_H
#define SILVERCLAW_SILVERCLAWAPP_H

#include <gtkmm/application.h>
#include <gtkmm/applicationwindow.h>
#include <gtkmm/builder.h>

class SilverClawApp : public Gtk::Application {
public:
    SilverClawApp();

protected:
    void on_startup() override;
    void on_activate() override;

private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::ApplicationWindow *window;

    void onWindowHide(Gtk::Window *window);
    void onFileOpen();
    void onFileExit();
};

#endif //SILVERCLAW_SILVERCLAWAPP_H
