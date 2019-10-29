#ifndef _MY_PLAYER_HPP
#define _MY_PLAYER_HPP

#include "note_player.hpp"
#include <fstream>
extern std::ofstream meldody;

class my_player : public note_player {
public: 
   void play( const note & n ) override;
};

#endif