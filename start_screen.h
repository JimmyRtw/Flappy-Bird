#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef START_SCREEN_H
#define START_SCREEN_H

class start_screen
{
    private:

    Texture *start_screen_texture;
    Sprite *start_screen_sprite;

    int speed;

    string path = "C:\\GAME PROJECTS\\Flappy-Bird\\images\\";

    public:

    start_screen();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float);
    void draw_sprite(RenderWindow*,bool);
};
   

#endif 




