#include "game.h"

game::game()
{
    init_window();
    init_game();
}

void game::init_window()
{
    this->window = new RenderWindow(VideoMode(1920,1080), " ");
    this->window->setFramerateLimit(60); 
}

void game::init_game()
{
    while(this->window->isOpen()) 
    {
        game_loop();
    }
}

void game::update_game(Event* event)
{
   if(event->type == Event::Closed)
   {
       close_window();
   }
   
   if(Keyboard::isKeyPressed(Keyboard::Key::Escape))
   {
        close_window();
   }
}

void game::close_window()
{
    this->window->close();
}

void game::update_window()
{
    window->display();
    window->clear(Color::Cyan);
}

void game::game_loop()
{
    while(this->window->pollEvent(*event))
    {
        update_game(this->event);
    }

    update_window();
}