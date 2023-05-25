#include "game.h"

game::game()
{
    init_window();
    init_game();
}

void game::play_game(Event *event)
{
}

void game::init_window()
{
    this->window = new RenderWindow(VideoMode(1920, 1080), "FLAPPY~BIRD", Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

void game::init_game()
{
    this->event = new Event();

    while (this->window->isOpen())
    {
        game_loop();
    }

    delete event;
}

void game::quit_game(Event *event)
{
    if (event->type == Event::Closed)
    {
        close_window();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
    {
        close_window();
    }
    else if (event->type == sf::Event::KeyPressed)
    {
        this->game_on = true;
    }
    else if (event->type == sf::Event::MouseButtonPressed)
    {
        this->game_on = true;
    }
}

void game::close_window()
{
    this->window->close();
}

void game::update_window()
{
    window->display();
    update_game(this->game_on);
    window->clear();
}

void game::game_loop()
{
    while (this->window->pollEvent(*event))
    {
        quit_game(this->event);
        play_game(this->event);
    }

    update_window();
    draw_objects();
}

void game::update_game(bool game_on)
{
    if(game_on)
    {
        this->game_on = bird_obj.update_bird(this->event);
        ground_obj.move_ground(object_speed);
        pipe_manager_obj.move_pipes(object_speed);
    }
}

void game::draw_objects()
{
    sky_obj.draw_sprite(this->window);
    pipe_manager_obj.draw_pipes(this->window);
    ground_obj.draw_sprite(this->window);
    start_screen_obj.draw_sprite(this->window,this->game_on);
    bird_obj.draw_sprite(this->window);
}