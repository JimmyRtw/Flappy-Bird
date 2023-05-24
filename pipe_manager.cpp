#include "pipe_manager.h"

pipe_manager :: pipe_manager()
{
    set_tnop(10);
    set_speed(10);
    set_ver_dist(50);
    set_hor_dist(250);
    init_pipes();
    init_pipes_origin();
    init_pipes_position();
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

void pipe_manager :: set_hor_dist(int hor_dist)
{
    this->hor_dist = hor_dist;
}

void pipe_manager :: init_pipes()
{
    for (int i = 0; i < this->n; i++)
    {
        up_pipes.push_back(new pipe(true));
        down_pipes.push_back(new pipe(false));
    }
}

void pipe_manager :: draw_pipes(RenderWindow* window)
{
    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->draw_sprite(window);
        down_pipe->draw_sprite(window);
    }
}

void pipe_manager :: init_pipes_position()
{
    float x = 1920/3;
    float y = 500;

    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->set_position(x,y);
        down_pipe->set_position(x,y);

        x += hor_dist;
        y += 0;
    }
}

void pipe_manager :: init_pipes_origin()
{
    for(int i=0;i<this->n;i++)
    {
        pipe* up_pipe = up_pipes[i];
        pipe* down_pipe = down_pipes[i];

        up_pipe->set_origin();
        down_pipe->set_origin();   
    }
}

void pipe_manager :: move_pipes()
{
    
}

void pipe_manager :: pipe_reset_position()
{

}
