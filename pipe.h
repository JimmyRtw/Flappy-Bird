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

    string path = "C:\\GAME PROJECTS\\Flappy-Bird\\images\\";

    public:

    pipe(bool up);
    
    void set_image(bool);
    void init_sprite();
    void init_texture();
    void set_origin();
    void set_pipe_orientation(bool);
    void set_position(float,float);
    void draw_sprite(RenderWindow*);
};
   

#endif 




