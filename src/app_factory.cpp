#include "app_factory.hpp"

#if defined(WINDOWS_CONSOLE)
    #include "windows_control_settings.hpp"
    #include "windows_keyboard.hpp"
    #include "console_ui_factory.hpp"

#elif defined(LINUX_CONSOLE)
    #include <ncurses.h>
    #include "linux_control_settings.hpp"
    #include "linux_keyboard.hpp"
    #include "console_ui_factory.hpp"

#elif defined(QT_GUI)
    #include "qt_control_settings.hpp"
    #include "qt_keyboard.hpp"
    #include "qt_ui_factory.hpp"

#endif

using biv::AppFactory;


AppFactory::AppFactory(
    Game* game, int map_height, int map_weight
) {
#if defined(WINDOWS_CONSOLE)
    control_settings = new WindowsControlSettings();
    keyboard = new WindowsKeyBoard();
    ui_factory = new ConsoleUIFactory(game);

#elif defined(LINUX_CONSOLE)
    control_settings = new LinuxControlSettings(
        map_height, map_weight
    );
    keyboard = new LinuxKeyBoard();
    ui_factory = new ConsoleUIFactory(game);

#elif defined(QT_GUI)
    control_settings = new QtControlSettings();
    keyboard = new QtKeyBoard();
    ui_factory = new QtUIFactory(game);
#endif
}

AppFactory::~AppFactory(){
    delete ui_factory;
    delete keyboard;
    delete control_settings;
}