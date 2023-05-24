#include "pipe.h"

pipe::pipe(bool up)
{
    pipe_texture = new Texture();   
    pipe_sprite = new Sprite();     
    
    set_image(up);
}

void pipe::set_image(bool up)
{
    set_pipe_orientation(up);
    init_texture();
    init_sprite();
    set_origin();
    set_position(1920/2,1000);
}

void pipe::set_pipe_orientation(bool up)
{
    this->pipe_up = up;
}

void pipe::init_texture()
{
    string mid = pipe_up==true?"_up":"_down";

    pipe_texture->loadFromFile(path + "pipe" + mid + ".png");
}

void pipe::init_sprite()
{
    pipe_sprite->setTexture(*pipe_texture);
}

void pipe::set_origin()
{
    float x = pipe_sprite->getTexture()->getSize().x * pipe_sprite->getScale().x;
    float y = pipe_sprite->getTexture()->getSize().y * pipe_sprite->getScale().y;

    y = pipe_up==true?0:y;

    pipe_sprite->setOrigin(x / 2, y);
}

void pipe::set_position(float x, float y)
{
    pipe_sprite->setPosition(x, y);
}

void pipe::draw_sprite(RenderWindow* window)
{
    window->draw(*this->pipe_sprite);
}

void pipe :: move_pipe(float speed)
{
    pipe_sprite->setPosition(pipe_sprite->getPosition().x - speed, pipe_sprite->getPosition().y);
}

void pipe :: reset_pipe_position(Sprite* img,int hor_dist)
{
    float x = pipe_sprite->getTexture()->getSize().x * pipe_sprite->getScale().x; 

    float position = this->pipe_sprite->getPosition().x + x/2;

    float img_pos_x = img->getPosition().x;
    float img_pos_y = img->getPosition().y;

    if(position<0)
    {
        this->pipe_sprite->setPosition(img_pos_x+hor_dist,img_pos_y);
    }
}

Sprite* pipe :: return_pipe_sprite()
{
    return this->pipe_sprite;
}