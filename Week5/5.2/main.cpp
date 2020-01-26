#define CATCH_CONFIG_MAIN

#include "intSet.hpp"
#include <iostream>
#include "catch.hpp"


TEST_CASE("add, double"){
    intSet <int, 10> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 0 0 0 0 0 ");
}

TEST_CASE("add, zero and overflow"){
    intSet <int, 10> lijst;
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
    intSet <int, 10> lijst;
    lijst.add(1);
    lijst.add(8);
    lijst.add(6);
    lijst.contains(5);
    lijst.contains(1);
    REQUIRE(lijst.contains(5)==false);
    REQUIRE(lijst.contains(1)==true);
}

TEST_CASE("remove, right, zero and wrong"){
    intSet <int, 10> lijst;
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
    intSet <int, 10> lijst;
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

TEST_CASE("add double,overflow, remove, cout"){
    intSet <int, 10> lijst;
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

TEST_CASE("float, add, double"){
    intSet <float, 10> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 0 0 0 0 0 ");
}

TEST_CASE("float, add, zero and overflow"){
    intSet <float, 10> lijst;
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

TEST_CASE("float, check true/false"){
    intSet <float, 10> lijst;
    lijst.add(1);
    lijst.add(8);
    lijst.add(6);
    lijst.contains(5);
    lijst.contains(1);
    REQUIRE(lijst.contains(5)==false);
    REQUIRE(lijst.contains(1)==true);
}

TEST_CASE("float, remove, right, zero and wrong"){
    intSet <float, 10> lijst;
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

TEST_CASE("float, remove, zero and last with overflow"){
    intSet <float, 10> lijst;
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

TEST_CASE("float, add double,overflow, remove, cout"){
    intSet <float, 10> lijst;
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

TEST_CASE("float5, add, double"){
    intSet <float, 5> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 ");
}

TEST_CASE("float5, add, zero and overflow"){
    intSet <float, 5> lijst;
    lijst.add(0);
    lijst.add(1);
    lijst.add(2.2);
    lijst.add(3.0);
    lijst.add(4.0);
    lijst.add(5.0);
    lijst.add(8);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "0 1 2.2 3 4 ");
}

TEST_CASE("float5, check true/false"){
    intSet <float, 5> lijst;
    lijst.add(1);
    lijst.add(8.8);
    lijst.add(6);
    lijst.contains(5);
    lijst.contains(1);
    REQUIRE(lijst.contains(5)==false);
    REQUIRE(lijst.contains(1)==true);
}

TEST_CASE("float5, remove, right, zero and wrong"){
    intSet <float, 5> lijst;
    lijst.add(1);
    lijst.add(1);
    lijst.add(8);
    lijst.add(2);
    lijst.add(3.1);
    lijst.add(4); 
    lijst.remove(8);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 2 3.1 4 0 ");
    lijst.remove(0);
    std::stringstream test1;
    test1 << lijst;
    REQUIRE(test1.str() == "1 2 3.1 4 0 ");
    lijst.remove(8);
    std::stringstream test2;
    test2 << lijst;
    REQUIRE(test2.str() == "1 2 3.1 4 0 ");
}

TEST_CASE("float5, remove, zero and last with overflow"){
    intSet <float, 5> lijst;
    lijst.add(0);
    lijst.add(1.7);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4.4);
    lijst.add(5);
    lijst.add(6);
    lijst.add(7);
    lijst.add(8);
    lijst.remove(0);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1.7 2 3 4.4 0 ");
    lijst.add(10);
    lijst.remove(10);
    std::stringstream test1;
    test1 << lijst;
    REQUIRE(test1.str() == "1.7 2 3 4.4 0 ");
}

TEST_CASE("float5, add double,overflow, remove, cout"){
    intSet <float, 5> lijst;
    lijst.add(1);
    lijst.add(1);
    lijst.add(8);
    lijst.add(6.8);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4);
    lijst.add(12);
    std::cout<<lijst<<"\n";    
    lijst.remove(8);
    std::cout<<lijst<<"\n";
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 6.8 2 3 0 ");
}

