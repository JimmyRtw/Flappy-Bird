#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef SKY_H
#define SKY_H

class sky
{
    private:

    Texture *sky_texture;
    Sprite *sky_sprite;

    string path = "C:\\GAME PROJECTS\\Flappy-Bird\\images\\";

    public:

    sky();
    
    void set_image();
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_position(float,float);
    void draw_sprite(RenderWindow*);
};
   

#endif 




