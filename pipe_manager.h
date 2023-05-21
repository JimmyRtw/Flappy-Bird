#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

#include "pipe.h"

#ifndef PIPE_MANAGER_H
#define PIPE_MANAGER_H

class pipe_manager
{
    private:

    int n;

    vector<pipe>up_pipes;
    vector<pipe>down_pipes;

    int ver_dist;
    int hor_dist;
    int speed;

    public:

    void set_tnop(int n);
    void set_speed();
    void set_ver_dist();
    void set_hor_dist();
    void init_pipes();

};
   
#endif





