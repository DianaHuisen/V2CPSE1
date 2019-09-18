#include "hwlib.hpp"
extern "C" void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void print_asciz( const char * s );

extern "C" void application();

extern "C" char toggle_case( char ch ){
    if(islower(ch)){
        return (ch-('a'-'A'));
    }
    else if(isupper(ch)){
        return (ch+('a'-'A'));
    }
    else{
        return ch;
    }
}


int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}