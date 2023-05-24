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
    this->window->setFramerateLimit(120);
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

    draw_objects();
    update_window();
}

void game::update_game(bool game_on)
{
    if(game_on)
    {
        pipe_manager_obj.move_pipes();
        pipe_manager_obj.pipe_reset_position();
    }
}

void game::draw_objects()
{
    sky_obj.draw_sprite(this->window);
    pipe_manager_obj.draw_pipes(this->window);
    ground_obj.draw_sprite(this->window);
}