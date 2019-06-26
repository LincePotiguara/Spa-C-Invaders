#include <ncurses.h>
#include "main.h"
#include "animation.h"


void animation(int max_x, int max_y) {

    usleep(200000);
    mvprintw(max_y-5, max_x/2 - 15 , "    __                    ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4, max_x/2 - 15, "   / /   __  ______ _____ ");
    refresh();
    usleep(200000);
    mvprintw(max_y-3, max_x/2 - 15, "  / /   / / / / __ `/ __ \\");
    refresh();
    usleep(200000);
    mvprintw(max_y-2, max_x/2 - 15, " / /___/ /_/ / /_/ / / / /");
    refresh();
    usleep(200000);
    mvprintw(max_y-1, max_x/2 - 15, "/_____/\\__,_/\\__,_/_/ /_/ ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0, max_x/2 - 15, "                          ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y-5-max_y/3, max_x/2 - 15, "    ____                ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4-max_y/3, max_x/2 - 15, "   /  _/___ _____  _____");
    refresh();
    usleep(200000);
    mvprintw(max_y-3-max_y/3, max_x/2 - 15, "   / // __ `/ __ \\/ ___/");
    refresh();
    usleep(200000);
    mvprintw(max_y-2-max_y/3, max_x/2 - 15, " _/ // /_/ / /_/ / /    ");
    refresh();
    usleep(200000);
    mvprintw(max_y-1-max_y/3, max_x/2 - 15, "/___/\\__, /\\____/_/     ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0-max_y/3, max_x/2 - 15, "    /____/              ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y-5-2*max_y/3, max_x/2 - 15, "   ______          __     ");
    refresh();
    usleep(200000);
    mvprintw(max_y-4-2*max_y/3, max_x/2 - 15, "  / ____/___ _____/ /_  __");
    refresh();
    usleep(200000);
    mvprintw(max_y-3-2*max_y/3, max_x/2 - 15, " / /   / __ `/ __  / / / /");
    refresh();
    usleep(200000);
    mvprintw(max_y-2-2*max_y/3, max_x/2 - 15, "/ /___/ /_/ / /_/ / /_/ / ");
    refresh();
    usleep(200000);
    mvprintw(max_y-1-2*max_y/3, max_x/2 - 15, "\\____/\\__,_/\\__,_/\\__,_/  ");
    refresh();
    usleep(200000);
    mvprintw(max_y-0-2*max_y/3, max_x/2 - 15, "                          ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(0, max_x/2 - 20, "   ____        _       __       __     ");
    refresh();
    usleep(200000);
    mvprintw(1, max_x/2 - 20, "  / __ \\__  __(_)___  / /____  / /___ _");
    refresh();
    usleep(200000);
    mvprintw(2, max_x/2 - 20, " / / / / / / / / __ \\/ __/ _ \\/ / __ `/");
    refresh();
    usleep(200000);
    mvprintw(3, max_x/2 - 20, "/ /_/ / /_/ / / / / / /_/  __/ / /_/ / ");
    refresh();
    usleep(200000);
    mvprintw(4, max_x/2 - 20, "\\___\\_\\__,_/_/_/ /_/\\__/\\___/_/\\__,_/  ");
    refresh();
    usleep(200000);
    mvprintw(5, max_x/2 - 20, "                                       ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y/2 - 6, max_x/2 - 30, "   _____                   ______                     ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 5, max_x/2 - 30, "  / ___/____  ____ _      / ____/                     ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  \\__ \\/ __ \\/ __ `/_____/ /                          ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 3, max_x/2 - 30, " ___/ / /_/ / /_/ /_____/ /___                        ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/____/ .___/\\__,_/      \\____/                        ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 1, max_x/2 - 30, "    /_/      ____                     __              ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 0, max_x/2 - 30, "            /  _/___ _   ______ _____/ /__  __________");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 1, max_x/2 - 30, "            / // __ \\ | / / __ `/ __  / _ \\/ ___/ ___/");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 2, max_x/2 - 30, "          _/ // / / / |/ / /_/ / /_/ /  __/ /  (__  ) ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 3, max_x/2 - 30, "         /___/_/ /_/|___/\\__,_/\\__,_/\\___/_/  /____/  ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                      ");
    refresh();
    usleep(1500000);

    clear();
    refresh();

    usleep(200000);
    mvprintw(max_y/2 - 6, max_x/2 - 30, "    ____                                                  ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 5, max_x/2 - 30, "   / __ \\________  __________   _________  ____ _________ ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  / /_/ / ___/ _ \\/ ___/ ___/  / ___/ __ \\/ __ `/ ___/ _ \\");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 3, max_x/2 - 30, " / ____/ /  /  __(__  |__  )  (__  ) /_/ / /_/ / /__/  __/");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/_/   /_/   \\___/____/____/  /____/ .___/\\__,_/\\___/\\___/ ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 1, max_x/2 - 30, "           __                __  /_/        __            ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 - 0, max_x/2 - 30, "          / /_____     _____/ /_____ ______/ /_           ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 1, max_x/2 - 30, "         / __/ __ \\   / ___/ __/ __ `/ ___/ __/           ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 2, max_x/2 - 30, "        / /_/ /_/ /  (__  ) /_/ /_/ / /  / /_             ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 3, max_x/2 - 30, "        \\__/\\____/  /____/\\__/\\__,_/_/   \\__/             ");
    refresh();
    usleep(200000);
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                          ");
    refresh();

    char ch;
    while(1){
        ch = getch();
        if (ch == ' ')
            break;
    }

    clear();
    refresh();
    usleep(350000);

    mvprintw(max_y/2 - 6, max_x/2 - 30, "    ____                                                  ");
    refresh();
    mvprintw(max_y/2 - 5, max_x/2 - 30, "   / __ \\________  __________   _________  ____ _________ ");
    refresh();
    mvprintw(max_y/2 - 4, max_x/2 - 30, "  / /_/ / ___/ _ \\/ ___/ ___/  / ___/ __ \\/ __ `/ ___/ _ \\");
    refresh();
    mvprintw(max_y/2 - 3, max_x/2 - 30, " / ____/ /  /  __(__  |__  )  (__  ) /_/ / /_/ / /__/  __/");
    refresh();
    mvprintw(max_y/2 - 2, max_x/2 - 30, "/_/   /_/   \\___/____/____/  /____/ .___/\\__,_/\\___/\\___/ ");
    refresh();
    mvprintw(max_y/2 - 1, max_x/2 - 30, "           __                __  /_/        __            ");
    refresh();
    mvprintw(max_y/2 - 0, max_x/2 - 30, "          / /_____     _____/ /_____ ______/ /_           ");
    refresh();
    mvprintw(max_y/2 + 1, max_x/2 - 30, "         / __/ __ \\   / ___/ __/ __ `/ ___/ __/           ");
    refresh();
    mvprintw(max_y/2 + 2, max_x/2 - 30, "        / /_/ /_/ /  (__  ) /_/ /_/ / /  / /_             ");
    refresh();
    mvprintw(max_y/2 + 3, max_x/2 - 30, "        \\__/\\____/  /____/\\__/\\__,_/_/   \\__/             ");
    refresh();
    mvprintw(max_y/2 + 4, max_x/2 - 30, "                                                          ");
    refresh();

    usleep(300000);

    clear();
    refresh();

    usleep(1000000);
}