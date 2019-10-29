#include "my_player.hpp"
#include <iostream>

void my_player::play( const note & n ){
    std::cout<<"duration: "<<n.duration<<", ";
    std::cout<<"frequency: "<<n.frequency<<"\n";
}