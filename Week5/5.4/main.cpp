#define CATCH_CONFIG_MAIN

#include "intSet.hpp"
#include <iostream>
#include "catch.hpp"


TEST_CASE("add, double, max"){
    intSet <int, 10> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 0 0 0 0 0 ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "1");
}

TEST_CASE("add, zero and overflow, max"){
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
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "0 1 2 3 4 5 6 7 8 9 ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "9");
}


TEST_CASE("float, add, double, max"){
    intSet <float, 10> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 0 0 0 0 0 ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "1");
}

TEST_CASE("float, add, zero and overflow, max"){
    intSet <float, 10> lijst;
    lijst.add(0);
    lijst.add(1);
    lijst.add(2);
    lijst.add(3);
    lijst.add(4);
    lijst.add(5);
    lijst.add(6);
    lijst.add(7);
    lijst.add(8.6);
    lijst.add(9);
    lijst.add(10);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "0 1 2 3 4 5 6 7 8.6 9 ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "9");
}

TEST_CASE("float5, add, double, max"){
    intSet <float, 5> lijst;
    lijst.add(1);
    lijst.add(1);
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "1 0 0 0 0 ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "1");
}

TEST_CASE("float5, add, zero and overflow, max"){
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
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "4");
}
TEST_CASE("char3, add double, max"){
    intSet <char, 3> lijst;
    lijst.add('A');
    lijst.add('A');
    lijst.add('X');
    lijst.add('Z');
    std::stringstream test;
    test << lijst;
    REQUIRE(test.str() == "A X Z ");
    std::stringstream test1;
    test1 << lijst.max();
    REQUIRE(test1.str() == "Z");
}