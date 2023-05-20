#include <SFML/Graphics.hpp>
#include<bits/stdc++.h>

using namespace std;
using namespace sf;

class game
{
    private:

    RenderWindow* window;
    Event* event;

    public:

    game();

    void init_window();
    void init_game();
    void update_game(Event*);
    void game_loop();
    void update_window();
    void close_window();
};
   







