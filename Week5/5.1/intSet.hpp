#ifndef _INTSET_HPP
#define _INTSET_HPP

#include <iostream>
#include <array>

class intSet{
private:
    std::array<int, 10> setInt {0,0,0,0,0,0,0,0,0,0};
    int counter = 0;
    
public:
    void add(int n);
    void remove(int n);
    bool contains(int n);
    friend std::ostream & operator<<(std::ostream & lhs, const intSet & rhs);
};

#endif