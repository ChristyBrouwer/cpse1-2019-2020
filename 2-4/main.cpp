#include "rtttl_player.hpp"
#include <iostream>
#include <fstream>

const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,16d6,8c6,16a,8g,e.6,p,8e6,8f,8e6,8d6,16p,16e6,16d6,8d6,2c.6";

class dummy_note_player : public note_player {
public:
    void play(const note & n) override {
        std::cout << n.frequency << "   " << n.duration << std::endl;
    };
};

class text_file : public note_player {
public:
    text_file(){
        std::ofstream outfile ("melody.cpp");
        outfile << "#include \"melody.hpp\" \n\n"
                << "class creator : public melody {\n"
                << "public:\n"
                << "    void play(note_player & p){\n";
        outfile.close();
    };
    ~text_file(){
        std::fstream outfile;
        outfile.open("melody.cpp", std::ios::app);
        outfile << "\n    }\n"
                << "};";
    };

    void play(const note & n) override{
        std::fstream outfile;
        outfile.open("melody.cpp", std::ios::app);
        outfile << "        p.play( note{ " << n.frequency << ",  " << n.duration << " } );\n";
        outfile.close();
    }
};

int main(void){
    std::cout << "I start" << std::endl;
    auto p = text_file();
    rtttl_play(p, let_it_be);
    std::cout << "I end" << std::endl;
}
