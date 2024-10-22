#include "hockey.h"
#include <graphics.h>
#include "math.h"
#include "define.h"
#include "menu.h"

void Hockey::update()
{
    if (ready == false && menu == false && end == false) {

        ball = new Ball(500, 250, 4); //CREATE AND PLACE THE BALL

        if ((listofplayers.empty()) == true) { //CREATE AND PLACE THE PLAYERS

            listofplayers.push_back(new Player(1, CANVAS_WIDTH / 5, 250));

            listofplayers.push_back(new Player(2, 4 * CANVAS_WIDTH / 5, 250));
        }


        if (graphics::getKeyState(graphics::SCANCODE_SPACE)) // READY TO PLAY 
        {
            graphics::playSound(std::string(ASSET_PATH) + "click.wav", 5, false);

            ready = true;

        }
    }
    

    if ( end == false && listofplayers.size() > 0 )
    {
        for (auto p : listofplayers)
        {
            p->update();

            if (p->getWinner() == 1 || p->getWinner() == 2) { end = true; } //END OF GAME WE HAVE A WINNER

        }
    }

    if (graphics::getKeyState(graphics::SCANCODE_SPACE) && end == true) //THE GAME STARTS AGAIN  
    {
        for (auto p : listofplayers) { delete p; }

        listofplayers.clear();

        ready = false; //ARXIKOPOIISI

        end = false; //ARXIKOPOIISI
    }

    if (ready == true) {

        game();  //  WE PRESSED SPACE
    }

    if (graphics::getKeyState(graphics::SCANCODE_BACKSPACE)) //WE GO BACK TO MENU
    {
        graphics::playSound(std::string(ASSET_PATH) + "click.wav", 5, false);

        menu = true; //NO DRAW , WE STAY IN MENU (menu->draw())

        ball = nullptr; //NO BALL
    }

}    



void Hockey::draw()
{
    graphics::Brush br;

    if (menu == false) { //WE HAVE NOT PRESSED BACKSPACE 


        graphics::setFont(std::string(ASSET_PATH) + "caesar.ttf");

        br.texture = std::string(ASSET_PATH) + "table.png";


        graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT, br);

        graphics::Brush br1;
        br1.fill_color[0] = 0.0f;
        br1.fill_color[1] = 0.0f;
        br1.fill_color[2] = 1.0f;


        if (ready == false) {

            graphics::resetPose();

            br1.outline_opacity = 3.0f;
            br1.outline_width = 5.0f;
            br1.outline_color[0] = 3.0f;
            br1.outline_color[1] = 0.5f;
            br1.outline_color[2] = 0.1f;

            graphics::drawRect(500, 180, 350, 80, br1);

            br1.fill_color[0] = 1.0f;
            br1.fill_color[1] = 1.0f;
            br1.fill_color[2] = 1.0f;
            graphics::drawText(370, 180, 30, "PRESS SPACE TO PLAY", br1);

        }

        br1.fill_color[0] = 0.0f;
        br1.fill_color[1] = 0.0f;
        br1.fill_color[2] = 0.0f;

        for (auto p : listofplayers)
        {
            if (p->getWinner() == 1 || p->getWinner() == 2) {
                drawText(370, 90, 40, "Player: " + std::to_string(p->getWinner()) + " wins!", br1);
                graphics::playSound(std::string(ASSET_PATH) + "winner.wav", 5, false);
            }

        }
        graphics::setFont(std::string(ASSET_PATH) + "caesar.ttf");


        if (listofplayers.empty() == false )
        {
            for (auto p : listofplayers) { p->draw(); }

            ball->draw();
        }



    }
}
void Hockey::game() // HOW IT WORKS
{
    ball->update();

    for (auto p : listofplayers)
    {
        if ((ball->getX() == p->getX() + p->getWidthP() || ball->getX() == p->getX() - p->getWidthP()) && ball->getY() >= p->getY() - 50 && ball->getY() <= p->getY() + 50) {

            graphics::playSound(std::string(ASSET_PATH) + "catch.mp3", 5, false);

            ball->setSpeed(-ball->getSpeed());

            if (ball->getY() > p->getY() || ball->getY() < p->getY()) {

                double n = ((double)ball->getY() - (double)p->getY()) / (double)(p->getHeightP() / 2);

                double m = n * (double)((2 * pi) / 8);

                klisi = m;

                ball->setDirection(klisi);
            }

        }
    }


    if (ball->getX() > CANVAS_WIDTH - 10) {

        (*listofplayers.begin())->addPoints();

        ready = false; //PRESS START AGAIN TO PLAY
    }
    else if (ball->getX() < 10) {

        (*listofplayers.rbegin())->addPoints();

        ready = false; //PRESS START AGAIN TO PLAY 
    }
}



    

void Hockey::init()
{
   
}

Hockey::Hockey()
{

}

Hockey::~Hockey()
{
    if (listofplayers.empty() == false )
    {
        for (auto p : listofplayers) {
            delete p;
        }
        listofplayers.clear();
    }
    delete ball;
}