#include <array>
#include <iostream>

class set{
private:
    std::array<int,10> KUT;
public:
    set(std::array<int,10> KUT):
        KUT(KUT){}

    void add( int a){
        if(KUT.size()<10){
            //iets met elke doorlopen tot er een lege is
        };
    };

    void remove( int b){
        for(uint8_t x=0;x<=KUT.size(); x++){
            if(KUT[x] == b){
                //iets met elke volgende eentje terug schuiven
            }
        }
    };

    bool contains( int b){
        for(uint8_t x=0;x<=KUT.size(); x++){
            if(KUT[x] == b){
                std::cout << "yes" << std::endl;
                return true;
            }
        }
        std::cout << "check" << std::endl;
        return false;
    };

};

int main(){
    std::array<int, 10> c = {0,1};
    set d(c);
    d.contains(3);
};