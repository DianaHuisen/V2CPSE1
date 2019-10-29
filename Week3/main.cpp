#include "hwlib.hpp"
#include <array>
#include <cmath>
#include "table.hpp"
#include "clock.hpp"


int main( void ){

    hwlib::wait_ms(100);

   	auto scl = hwlib::target::pin_oc( hwlib::target::pins::scl );
   	auto sda = hwlib::target::pin_oc( hwlib::target::pins::sda );
   	auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda( scl,sda );
   	auto display = hwlib::glcd_oled( i2c_bus, 0x3c );  

   	display.clear();

   	hwlib::xy midpoint(64, 32);

   	calcTime time = calcTime();

   	auto b_min = hwlib::target::pin_in(hwlib::target::pins::d2);
   	auto b_hour = hwlib::target::pin_in(hwlib::target::pins::d3);

    auto clock_f = clock_base(display, midpoint, 29);
	auto clock_h = clock_hands(display, midpoint, 28, time);

    std::array< drawable*, 2 > clock = { &clock_f, &clock_h };

	for(;;){
		display.clear();
		for(auto c : clock){
			c->draw();
			c->update();
		}
		display.flush();
		if(b_min.read()==0){
			time.update_time(60);
            hwlib::wait_us(100);
		}
        if(b_hour.read()==0){
			time.update_time(3600);
            hwlib::wait_us(100);
		}
   }
}
