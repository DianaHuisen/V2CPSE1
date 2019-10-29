class calcTime{
    public:
    int us_in_sec = 1000000;
    int sec_in_day = 86400;
    int max_sec = 60;
    int max_min = 60;
    int max_hour = 24;
    long unsigned int timePassed=0;
    int sec = 0;
    int min = 0;
    int hour = 0;
    int oldsec = 0;
    int changes =0;
    void update_time(int n_sec=0){
        changes+=n_sec%sec_in_day;
        timePassed= ((hwlib::now_us()/us_in_sec)+changes)%sec_in_day;
        sec = timePassed%max_sec;
        min = (timePassed/max_sec)%max_min;
        hour = (timePassed/max_sec/max_min)%max_hour;
        if (oldsec != sec){
            hwlib::cout<<"Time: "<<hwlib::setw(2)<<hwlib::setfill('0')<<hour<<":"<<hwlib::setw(2)<<min<<":"<<hwlib::setw(2)<<sec<<"\n";
            oldsec=sec;
        }
        
    }
};


class drawable {
protected:
	hwlib::glcd_oled & display;
	hwlib::xy pos;

public:
	drawable( hwlib::glcd_oled & display, const hwlib::xy & pos):
		display( display ),
		pos( pos )
	{}

	virtual void draw() = 0;
	virtual void update(){}
};

class clock_base : public drawable{
private:
	int radius;
public:
	clock_base( hwlib::glcd_oled & display, const hwlib::xy & pos,const int & radius ):
		drawable( display, pos ),
		radius( radius )
	{}
	void draw() override{
		for(int i=0; i<12; i++){
            hwlib::circle mins( circle_xy( pos, i*30, radius-2), 1);
             mins.draw( display );
		}
        hwlib::circle outerC( pos , radius );
		outerC.draw( display );
	}
};

class line : public drawable {
private:
	int radius;

public:
	int deg = 0;

	line( hwlib::glcd_oled & display, const hwlib::xy & pos, const int & radius):
		drawable( display, pos ),
		radius( radius )
	{}

	void draw() {
		hwlib::line l(pos, circle_xy(pos, deg, radius));
		l.draw( display );
	}
};

class clock_hands : public drawable{
private:
	line h_sec;
	line h_min;
	line h_hour;
	calcTime & time;

public:
	clock_hands( hwlib::glcd_oled & display, const hwlib::xy & pos, const int & radius, calcTime & time ):
		drawable( display, pos),
		h_sec( display, pos, radius ),
		h_min( display, pos, radius-7 ),
		h_hour( display, pos, radius-13 ),
		time( time )
	{}

	void draw() override{
		h_sec.draw();
		h_min.draw();
		h_hour.draw();
	}

	void update(){
		time.update_time();
		h_sec.deg=time.sec*6;
        h_min.deg=time.min*6;
		h_hour.deg=int((time.hour*30)+time.min*0.5)%360;
	}
};