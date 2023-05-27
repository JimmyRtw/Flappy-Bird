#include "score.h"

score::score()
{
    set_image();
}

void score::set_image()
{
    init_texture();
    init_sprite();
    set_origin();
}

void score::init_texture()
{
    for(int i=0;i<=9;i++)
    {
        score_texture.push_back(new Texture());
    }

    for(int i=0;i<=9;i++)
    {
        score_texture[i]->loadFromFile(path+to_string(i)+".png");
    }
}

void score::init_sprite()
{
    for(int i=0;i<=9;i++)
    {
        score_sprite.push_back(new Sprite());
    }

    for(int i=0;i<=9;i++)
    {
        score_sprite[i]->setTexture(*score_texture[i]);
    }
}

void score::set_origin()
{
    for(int i=0;i<=9;i++)
    {
        float x = score_sprite[i]->getTexture()->getSize().x * score_sprite[i]->getScale().x;
        float y = score_sprite[i]->getTexture()->getSize().y * score_sprite[i]->getScale().y;

        score_sprite[i]->setOrigin(x / 2, y / 2);
    }

}

void score::set_position(float x, float y,int index)
{
    score_sprite[index]->setPosition(x, y);
}

void score::draw_score(int game_score,RenderWindow*window)
{
    string score = to_string(game_score);

    Sprite new_image;
    
    int odd = score.size()%2;
    int offset = 25;
    int num = 0;

    if(odd)
    {
        int mid_index = score.size()/2;

        num = int(score[mid_index]-'0');
        new_image = *score_sprite[num];
        new_image.setPosition(1920/2,1080/6);

        draw_sprite(window,&new_image);

        for(int i=mid_index-1;i>=0;i--)
        {
            num = int(score[i]-'0');

            new_image = *score_sprite[num];
            new_image.setPosition(1920/2-offset,1080/6);
            draw_sprite(window,&new_image);
            offset += 25;
        }

        offset = 25;

        for(int i=mid_index+1;i<score.size();i++)
        {
            num = int(score[i]-'0');

            new_image = *score_sprite[num];
            new_image.setPosition(1920/2+offset,1080/6);
            draw_sprite(window,&new_image);
            offset += 25;
        }
    }
    else
    {
        int mid_index = score.size()/2;

        num = int(score[mid_index]-'0');
        new_image = *score_sprite[num];
        new_image.setPosition(1920/2-offset,1080/6);

        num = int(score[mid_index-1]-'0');
        new_image = *score_sprite[num];
        new_image.setPosition(1920/2+offset,1080/6);

        offset = 50;

        for(int i=mid_index-2;i>=0;i--)
        {
            num = int(score[i]-'0');

            new_image = *score_sprite[num];
            new_image.setPosition(1920/2-offset,1080/6);
            draw_sprite(window,&new_image);
            offset += 25;
        }

        offset = 50 ;

        for(int i=mid_index+1;i<score.size();i++)
        {
            num = int(score[i]-'0');

            new_image = *score_sprite[num];
            new_image.setPosition(1920/2+offset,1080/6);
            draw_sprite(window,&new_image);
            offset += 25;
        }
    }
}

void score::draw_sprite(RenderWindow* window,Sprite* sprite)
{
    window->draw(*sprite);
}

