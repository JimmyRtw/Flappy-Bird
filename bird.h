#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef BIRD_H
#define BIRD_H

class bird
{
    private:

    Texture *bird_texture_1,*bird_texture_2,*bird_texture_3;
    Sprite *bird_sprite;

    float vertical_speed = 0;
    float flap = -10;
    float gravity = 0.5;

    bool alive = true;

    string path = "C:\\GAME PROJECTS\\Flappy-Bird\\images\\";

    public:

    bird();
    
    void set_image();
    void set_vertical_speed(float);
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float);
    void set_bird_life();
    void draw_sprite(RenderWindow*);

    bool update_bird(Event*);
};
   

#endif 




