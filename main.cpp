#include "graphics.h"
#include "menu.h"
#include "define.h"
 


void update(double ms)
{
    Menu* menu;
    menu = (Menu*) (graphics::getUserData());

    menu->update();
}

void draw()
{
    Menu* menu;
    menu = (Menu*) (graphics::getUserData());

    menu->draw();
}

int main()
{
    Menu menu;

    graphics::createWindow(1200, 700, "HOCKEYPONG");

    graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);

    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
 
    graphics::setUserData( &menu );

    graphics::setUpdateFunction(update);

    graphics::setDrawFunction(draw);

    menu.init();

    graphics::startMessageLoop();
 
    return 0;
}
