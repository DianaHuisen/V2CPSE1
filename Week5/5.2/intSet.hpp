#ifndef _INTSET_HPP
#define _INTSET_HPP

#include <iostream>
#include <array>

template<typename T, int N>

class intSet{
private:
    std::array<T, N> setInt;
    int counter = 0;
    
public:
    intSet(){
        for (unsigned int i =0; i<=N; i++){
            setInt[i]=0;
        }
    }
    void add(T n){
        if (counter<N && (contains(n)==false || n==0)){
            setInt[counter]= n;
            counter++;
        }
    }
    void remove(T n){
        if(contains(n)==true){
            for(int i=0; i<counter; i++){
                if (setInt[i] == n){
                    while(i<counter){
                        setInt[i]=setInt[i+1];
                        i++;
                    }            
                    if (i == counter){
                        setInt[i-1]=0;
                    }
                }
            }
        counter--;
        }
    }
    bool contains(T n){
        for(unsigned int i=0; i<N; i++){
            if (setInt[i] == n){
                return true;
            }
        }
        return false;
    }
    friend std::ostream & operator<<(std::ostream & lhs, const intSet & rhs){
        for(unsigned int i=0; i<N; i++){
            lhs << rhs.setInt[i] <<" ";
        }
        return lhs;
    }
};

#endif