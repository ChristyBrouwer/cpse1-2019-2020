#include "rtttl_player.hpp"
#include <iostream>

const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,16d6,8c6,16a,8g,e.6,p,8e6,8f,8e6,8d6,16p,16e6,16d6,8d6,2c.6";

class dummy_note_player : public note_player {
public:
    void play(const note & n) override {
        std::cout << n.frequency << "   " << n.duration << std::endl;
    };
};

int main(void){
    std::cout << "I start" << std::endl;
    auto p = dummy_note_player();
    rtttl_play(p, let_it_be);
    std::cout << "I end" << std::endl;
}
