#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

#include "sky.h"
#include "ground.h"
#include "pipe_manager.h"
#include "start_screen.h"
#include "bird.h"

#ifndef GAME_H
#define GAME_H

class game
{
    private:

    RenderWindow* window;
    Event* event;

    sky sky_obj;
    ground ground_obj;
    pipe_manager pipe_manager_obj;
    start_screen start_screen_obj;
    bird bird_obj;

    bool game_on = false;
    bool game_start = true;
    float object_speed = 2;

    public:

    game();

    void init_window();
    void init_game();
    void quit_game(Event*);
    void play_game(Event*);
    void game_loop();
    void draw_objects();
    void update_window();
    void update_game(bool);
    void close_window();
};
   
#endif





