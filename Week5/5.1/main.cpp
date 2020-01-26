#define CATCH_CONFIG_MAIN

#include "intSet.hpp"
#include <iostream>
#include "catch.hpp"

TEST_CASE("add, double"){
    intSet lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 0 0 0 0 0 ");
}

TEST_CASE("add, zero and overflow"){
    intSet lijst;
    lijst.add(0);
    lijst.add(1);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4);
    lijst.add(5);
    lijst.add(6);
    lijst.add(7);
    lijst.add(8);
    lijst.add(9);
    lijst.add(10);
    lijst.add(11);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "0 1 2 3 4 5 6 7 8 9 ");
}

TEST_CASE("check true/false"){
    intSet lijst;
    lijst.add(1);
    lijst.add(8);
    lijst.add(6);
    lijst.contains(5);
    lijst.contains(1);
    REQUIRE(lijst.contains(5)==false);
    REQUIRE(lijst.contains(1)==true);
}

TEST_CASE("remove, right, zero and wrong"){
    intSet lijst;
    lijst.add(1);
    lijst.add(1);
    lijst.add(8);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4); 
    lijst.remove(8);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 2 3 4 0 0 0 0 0 0 ");
    lijst.remove(0);
    std::stringstream test1;
    test1 << lijst;
    REQUIRE(test1.str() == "1 2 3 4 0 0 0 0 0 0 ");
    lijst.remove(8);
    std::stringstream test2;
    test2 << lijst;
    REQUIRE(test2.str() == "1 2 3 4 0 0 0 0 0 0 ");
}

TEST_CASE("remove, zero and last with overflow"){
    intSet lijst;
    lijst.add(0);
    lijst.add(1);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4);
    lijst.add(5);
    lijst.add(6);
    lijst.add(7);
    lijst.add(8);
    lijst.add(9);
    lijst.add(10);
    lijst.add(11);
    lijst.remove(0);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 2 3 4 5 6 7 8 9 0 ");
    lijst.add(10);
    lijst.remove(10);
    std::stringstream test1;
    test1 << lijst;
    REQUIRE(test1.str() == "1 2 3 4 5 6 7 8 9 0 ");
}

TEST_CASE("add double,overflow, checks, remove, cout"){
    intSet lijst;
    lijst.add(1);
    lijst.add(1);
    lijst.add(8);
    lijst.add(6);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4);
    lijst.add(7);
    lijst.add(9);
    lijst.add(10);
    lijst.add(11);
    lijst.add(12);
    std::cout<<lijst<<"\n";    
    lijst.remove(8);
    std::cout<<lijst<<"\n";
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 6 2 3 4 7 9 10 11 0 ");
}
