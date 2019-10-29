#include "my_player.hpp"
//#include <iostream>
#include <fstream>

void my_player::play( const note & n ){
    meldody << "\t p.play( note{"<<n.duration<<"," <<n.frequency<<"} );\n";
}