#include <pipe_manager.h>

pipe_manager :: pipe_manager()
{
    set_tnop(5);
    set_speed(10)
    set_ver_dist(50);
    set_hor_dist(50);
    init_pipes();

    up_pipes.resize(n,new pipe(true));
    down_pipes.resize(n,new pipe(false));
}

void pipe_manager :: set_tnop(int n)
{
    this->n = n;
}

void pipe_manager :: set_speed(int speed)
{
    this->speed = speed;
}

void pipe_manager :: set_ver_dist(int ver_dist)
{
    this->ver_dist = ver_dist;
}

void pipe_manager :: set_hor_dist()
{
    this->hor_dist = hor_dist;
}

