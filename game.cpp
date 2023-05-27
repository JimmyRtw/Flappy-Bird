#include "game.h"

game::game() : button_restart("Restart", 1920 / 2 , 1080 / 3 - 50),button_quit("Quit", 1920 / 2 , 1080 / 3 + 50)
{
    init_window();
    init_game();
}

void game::play_game(Event *event)
{
    start_game(event);
    check_button_events(event);
}

void game:: start_game(Event* event)
{
    if (event->type == sf::Event::KeyPressed and !this->game_on)
    {
        this->game_on = 1;
    }
    else if (event->type == sf::Event::MouseButtonPressed and !this->game_on)
    {
        this->game_on = 1;
    }
}

void game:: check_button_events(Event* event)
{
    button_restart.set_events(event,&game_on);
    button_quit.set_events(event,&game_on);
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
}

void game::close_window()
{
    this->window->close();
    exit(0);
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

void game::update_game(int game_on)
{
    if(this->game_on==1)
    {
        vector<FloatRect> pipes_bounds; // = this->pipe_manager_obj.pipes_global_bounds();

        bird_obj.update_bird(this->event,&this->game_on,pipes_bounds);
        ground_obj.move_ground(object_speed);
        pipe_manager_obj.move_pipes(object_speed);
        pipe_manager_obj.set_game_score(&this->game_score);
    }
    else if(this->game_on==3)
    {
        restart_game();
    }
}

void game::restart_game()
{
    this->game_on = 0;

    sky_obj.init_position();
    pipe_manager_obj.init_pipes_position();
    ground_obj.init_position();
    bird_obj.init_position();
    start_screen_obj.init_position();
}

void game::draw_objects()
{
    if(this->game_on==0)
    {
        sky_obj.draw_sprite(this->window);
        pipe_manager_obj.draw_pipes(this->window);
        ground_obj.draw_sprite(this->window);
        bird_obj.draw_sprite(this->window);
        start_screen_obj.draw_sprite(this->window);
    }
    else if(this->game_on==1)
    {
        sky_obj.draw_sprite(this->window);
        pipe_manager_obj.draw_pipes(this->window);
        ground_obj.draw_sprite(this->window);
        bird_obj.draw_sprite(this->window);
        score_obj.draw_score(this->game_score,this->window);
    }
    else if(this->game_on==2)
    {
        sky_obj.draw_sprite(this->window);
        pipe_manager_obj.draw_pipes(this->window);
        ground_obj.draw_sprite(this->window);
        bird_obj.draw_sprite(this->window);
        button_restart.draw_button(this->window);
        button_quit.draw_button(this->window);
    }
    
}