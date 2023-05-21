#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#ifndef PIPE_H
#define PIPE_H

class pipe
{
    private:

    Texture *pipe_texture;
    Sprite *pipe_sprite;

    bool pipe_up = false;

    string path = "C:\\Users\\admin\\Desktop\\GAME PROJECTS\\Flappy Bird\\images\\";

    public:

    pipe();
    
    void set_image(bool);
    void init_sprite();
    void init_texture(bool);
    void set_origin(bool);
    void set_position(float,float);
    void draw_sprite(RenderWindow*);
};
   

#endif 




