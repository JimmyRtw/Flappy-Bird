#include<bits/stdc++.h>
#include<SFML/Graphics.hpp>

#include "pipe.h"

using namespace std;
using namespace sf;

#ifndef PIPE_MANAGER_H
#define PIPE_MANAGER_H

class pipe_manager
{
    private:

    int n;

    vector<pipe*>up_pipes;
    vector<pipe*>down_pipes;

    int ver_dist;
    int hor_dist;
    int speed;

    public:

    pipe_manager();

    void set_tnop(int);
    void set_speed(int);
    void set_ver_dist(int);
    void set_hor_dist(int);
    void init_pipes();
    void draw_pipes(RenderWindow* window);
    void init_pipes_position();
    void init_pipes_origin();
    void move_pipes();
    void pipe_reset_position();
};
   
#endif





