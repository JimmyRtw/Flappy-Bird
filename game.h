#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

#include "sky.h"
#include "ground.h"
#include "pipe_manager.h"

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

    public:

    game();

    void init_window();
    void init_game();
    void quit_game(Event*);
    void play_game(Event*);
    void game_loop();
    void draw_objects();
    void update_window();
    void close_window();
};
   
#endif





