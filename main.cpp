#include "SilverClawApp.h"

int main(int argc, char *argv[]) {

    // create the app and run it
    Glib::RefPtr<SilverClawApp> app(new SilverClawApp());
    return app->run(argc, argv);
}
