#include "intSet.hpp"

void intSet::add(int n){
    if (counter<10 && (contains(n)==false || n==0)){
        setInt[counter]= n;
        counter++;
    }
}
void intSet::remove(int n){
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
bool intSet::contains(int n){
    for(unsigned int i=0; i<10; i++){
        if (setInt[i] == n){
            return true;
        }
    }
    return false;
}
std::ostream & operator<<(std::ostream & lhs, const intSet & rhs ){
    for(unsigned int i=0; i<10; i++){
        lhs << rhs.setInt[i] <<" ";
    }
    return lhs;
}