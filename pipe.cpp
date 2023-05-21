#include "pipe.h"

pipe::pipe()
{
    pipe_texture = new Texture();   
    pipe_sprite = new Sprite();     
    
    set_image(this->pipe_up);
}

void pipe::set_image(bool up)
{
    init_texture(up);
    init_sprite();
    set_origin(up);
    set_position(1920/2,1000);
}

void pipe::init_texture(bool up)
{
    string mid = up==true?"_up":"_down";

    pipe_texture->loadFromFile(path + "pipe" + mid + ".png");
}

void pipe::init_sprite()
{
    pipe_sprite->setTexture(*pipe_texture);
}

void pipe::set_origin(bool up)
{
    float x = pipe_sprite->getTexture()->getSize().x * pipe_sprite->getScale().x;
    float y = pipe_sprite->getTexture()->getSize().y * pipe_sprite->getScale().y;

    y = up==true?y:0;

    pipe_sprite->setOrigin(x / 2, y);
}

void pipe::set_position(float x, float y)
{
    pipe_sprite->setPosition(x, y);
}

void pipe::draw_sprite(RenderWindow* window)
{
    window->draw(*pipe_sprite);
}

