#include "Info.h"
#include <graphics.h>
#include "define.h"
#include "menu.h"

void Info::update() {

   if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) {

       menu = true;

       graphics::playSound(std::string(ASSET_PATH) + "click.wav", 5, false);
       
    }
}

void Info::draw() {

    graphics::Brush br;

    if ( menu == false) {

  
        br.texture = std::string(ASSET_PATH) + "ice1.png";

        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

        br.fill_color[0] = 0.0f;
        br.fill_color[1] = 0.0f;
        br.fill_color[2] = 0.0f;
        
        graphics::drawText(330, 100, 70, "KANONES", br);
        graphics::setFont(std::string(ASSET_PATH) + "word.ttf");
        
       
        graphics::drawText(80, 170, 30, "I.   If you are Player 1, press A and D to move left and right.", br);
        graphics::drawText(80, 220, 30, "II.   Press W and S to move up and down", br);
        graphics::drawText(80, 270, 30, "III.   If you are Player 2, press left and right", br);
        graphics::drawText(80, 320, 30, "IV.   Press up and down to move", br);
        graphics::drawText(80, 370, 30, "V.   The Player whose score is 10 , wins the game!", br);
        graphics::drawText(150, 420, 40, "   GOOD LUCK!", br);

        
        graphics::drawText(50, CANVAS_WIDTH / 2.1, 30, "back to menu >>> press backspace", br);
       
    }
        
}


void Info::init() {

   menu = false;
}


Info::Info()
{
    
}

Info::~Info()
{

}