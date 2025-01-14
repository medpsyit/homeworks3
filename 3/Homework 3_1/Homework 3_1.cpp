#include "mylist.h"
#include <catch2/catch_test_macros.hpp>
//#include<catch2/catch_session.hpp>
#include <cstdint>

TEST_CASE( "Simple functions", "[simple]" ) {
    SECTION("Empty") {
        List test;
        CHECK(test.Empty() == true);
    }
    SECTION("Size") {
        List test;
        test.PushFront(1);
	    CHECK(test.Size() == 1);
        test.PushFront(2);
        CHECK(test.Size() == 2);
        test.PushFront(3);
        test.PushFront(5);
        test.PushFront(10);
        CHECK(test.Size() == 5);
    }
    SECTION("Clear") {
        List test;
        test.PushFront(3);
        test.PushFront(5);
        test.PushFront(10);
        test.Clear();
        CHECK(test.Size() == 0);
    }
}