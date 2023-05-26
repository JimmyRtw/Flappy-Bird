#include "bird.h"

bird::bird()
{
    bird_texture_1 = new Texture();   
    bird_texture_2 = new Texture();   
    bird_texture_3 = new Texture();   

    bird_sprite = new Sprite();     
    
    set_image();
}

void bird::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
    init_position();
}

void bird::init_position()
{
    set_position(init_pos_x,init_pos_y);
}

void bird::set_vertical_speed(float vertical_speed)
{
    this->vertical_speed = vertical_speed;
}

void bird::init_texture()
{
    bird_texture_1->loadFromFile(path + "bird_1.png");
    bird_texture_2->loadFromFile(path + "bird_2.png");
    bird_texture_3->loadFromFile(path + "bird_3.png");
}

void bird::init_sprite()
{
    bird_sprite->setTexture(*bird_texture_1);
}

void bird::set_origin()
{
    float x = bird_sprite->getTexture()->getSize().x * bird_sprite->getScale().x;
    float y = bird_sprite->getTexture()->getSize().y * bird_sprite->getScale().y;

    bird_sprite->setOrigin(x/2, y/2);
}

void bird::set_position(float x, float y)
{
    bird_sprite->setPosition(x, y);
}

void bird::update_bird(Event* event,int* game_on)
{
    this->vertical_speed += this->gravity;

    if(this->vertical_speed>=-10 and (event->type == Event::MouseButtonPressed or event->type == Event::KeyPressed))
    {
        this->vertical_speed = this->flap;
    }

    float pos = bird_sprite->getPosition().y + this->vertical_speed;

    set_position(1920/2,pos);

    set_bird_life(game_on);
}

void bird::set_bird_life(int* game_on)
{
    float pos_offset = (bird_sprite->getTexture()->getSize().y * bird_sprite->getScale().y)/2;
    float curr_pos = bird_sprite->getPosition().y;

    if((curr_pos+pos_offset)>=(1080-184) or (curr_pos-pos_offset)<=0)
    {
        this->alive = false;

        *game_on = 2;
    }
}

void bird::draw_sprite(RenderWindow* window)
{
    window->draw(*bird_sprite);
}


