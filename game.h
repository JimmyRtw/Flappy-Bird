#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

#include "sky.h"
#include "ground.h"
#include "pipe_manager.h"
#include "start_screen.h"
#include "bird.h"
#include "button.h"
#include "bounds.h"
#include "score.h"

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
    score score_obj;

    button button_restart;
    button button_quit;

    int game_on = 0;
    int game_score = 123454564;

    float object_speed = 3;

    public:

    game();

    void init_window();
    void init_game();
    void quit_game(Event*);
    void play_game(Event*);
    void start_game(Event*);
    void check_button_events(Event*);
    void game_loop();
    void draw_objects();
    void update_window();
    void update_game(int);
    void restart_game();
    void close_window();
};
   
#endif





