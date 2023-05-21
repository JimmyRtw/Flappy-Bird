#include "ground.h"

ground::ground()
{
    ground_texture = new Texture();   
    ground_sprite = new Sprite();     
    
    set_image();
}

void ground::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    set_position(1920/2,1300);
}

void ground::init_texture()
{
    ground_texture->loadFromFile(path + "ground.png");
}

void ground::init_sprite()
{
    ground_sprite->setTexture(*ground_texture);
}

void ground::set_origin()
{
    float x = ground_sprite->getTexture()->getSize().x * ground_sprite->getScale().x;
    float y = ground_sprite->getTexture()->getSize().y * ground_sprite->getScale().y;

    ground_sprite->setOrigin(x / 2, y);
}

void ground::set_position(float x, float y)
{
    ground_sprite->setPosition(x, y);
}

void ground::draw_sprite(RenderWindow* window)
{
    window->draw(*ground_sprite);
}

