#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef GROUND_H
#define GROUND_H

class ground
{
    private:

    Texture *ground_texture;
    Sprite *ground_sprite;

    string path = "C:\\Users\\admin\\Desktop\\GAME PROJECTS\\Flappy Bird\\images\\";

    public:

    ground();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float);
    void draw_sprite(RenderWindow*);
};
   

#endif 




