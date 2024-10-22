#include "menu.h"
#include <graphics.h>
#include "hockey.h"
#include "define.h"



void Menu::update()
{
    getState();

    if (info) {info->update();}

    if (hockey) {hockey->update();}

    if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {

        if (hockey || info) { menu = true; }
    }
}
void Menu::draw()
{
    
    if (menu == true) {

        graphics::Brush br;

        br.texture = std::string(ASSET_PATH) + "R.png";

        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

        graphics::Brush br1;

        br1.fill_color[0] = 0.5f;
        br1.fill_color[1] = 0.5f;
        br1.fill_color[2] = 0.5f;
        br1.fill_opacity = 0.8f;

        drawRect(CANVAS_WIDTH / 6, CANVAS_HEIGHT / 3, 220, 60, br1);
        drawRect(CANVAS_WIDTH / 6, 1.8 * CANVAS_HEIGHT / 3, 220, 60, br1);

        drawText(CANVAS_WIDTH / 7, CANVAS_HEIGHT / 3, 30, "PLAY", br);
        drawText(CANVAS_WIDTH / 14, 1.8 * CANVAS_HEIGHT / 3, 30, "INFORMATION", br);

        br.fill_color[0] = 0.0f;
        br.fill_color[1] = 0.0f;
        br.fill_color[2] = 0.0f;

        graphics::drawText(270, 80, 70, "HOCKEYPONG", br);

     
    }
    if (hockey) { hockey->draw();  }

    if (info) { info->draw();  }

    graphics::setFont(std::string(ASSET_PATH) + "caesar.ttf");
}
void Menu::init()
{ 
   
}
Menu::Menu()
{
   
}

Menu::~Menu()
{
    delete hockey;

    delete info; 
}

void Menu::getState() {

    graphics::MouseState m;

    graphics::getMouseState(m);

    if ( m.cur_pos_x > 100 && m.cur_pos_x < 320 && m.cur_pos_y > 165 && m.cur_pos_y < 260 && m.button_left_pressed) {

        if (hockey) { delete hockey;}

        hockey = new Hockey();

        hockey->update();

        menu = false;

        graphics::playSound(std::string(ASSET_PATH) + "click.wav", 5, false);

    }
    else if ( m.cur_pos_x > 100 && m.cur_pos_x < 320 && m.cur_pos_y > 300 && m.cur_pos_y < 420  && m.button_left_pressed)
    {

   
        if (info) {delete info; }

        info = new Info();

        info->init();

        menu = false;

        graphics::playSound(std::string(ASSET_PATH) + "click.wav", 5, false);


    }

}
