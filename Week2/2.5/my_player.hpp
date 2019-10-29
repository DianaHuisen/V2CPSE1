#ifndef _MY_PLAYER_HPP
#define _MY_PLAYER_HPP

#include "note_player.hpp"

class my_player : public note_player {
public: 
    my_player(){};
   void play( const note & n ) override;
};

#endif