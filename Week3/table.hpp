
template< typename T, int N >
class lookup_table {
private:
	std::array< T, N > values = {};

public:
	template< typename F >
	constexpr lookup_table( F function ){
		for( int i=0; i < N; i++ ){
			values[ i ] = function( i );
		}
	}

	constexpr T get( double n ) const {
		return values[ n ];
	}
};

constexpr double convert(int deg){
	return double(deg) * (3.14 / 180);
}

constexpr double sine(int deg){
    return (std::sin(convert(deg)));
}

constexpr auto t_sin = lookup_table< double, 360>( sine );

hwlib::xy circle_xy(hwlib::xy pos, int deg, int radius){
	return hwlib::xy(t_sin.get(deg)*radius+pos.x, t_sin.get((deg+90)%360)*-radius+pos.y);
}

std::array< char, 2 > int_to_char_array(const int & number){
	std::array< char, 2 > result;
	result[0] = (number % 10) + 0x30;
	result[1] = (number / 10) + 0x30;
	return result;
}
