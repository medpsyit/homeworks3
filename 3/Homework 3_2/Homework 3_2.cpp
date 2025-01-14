#include "mylist.h"
#include <catch2/catch_test_macros.hpp>
//#include<catch2/catch_session.hpp>
#include <cstdint>

TEST_CASE( "Add and Delete functions", "[add delete]" ) {
    SECTION("exceptions")
    {
        List test;
        CHECK_THROWS_AS(test.PopFront(), std::exception);
        CHECK_THROWS_AS(test.PopBack(), std::exception);
    }
    SECTION("add")
    {
        List test;
        test.PushFront(1);
        CHECK(test.Empty() == false);
        test.PushBack(4);
        CHECK(test.Size() == 2);
        test.PushFront(2);
        test.PushBack(3);
        test.PushFront(5);
        test.PushBack(10);
        CHECK(test.Size() == 6);
    }
    SECTION("delete")
    {
        List test;
        test.PushBack(4);
        test.PushFront(1);
        CHECK(test.PopFront() == 1);
        test.PushFront(10);
        CHECK(test.PopBack() == 4);
        test.PushFront(2);
        test.PushFront(5);
        test.PushFront(18);
        CHECK(test.PopFront() == 18);
        test.PopFront();
        test.PopBack();
        CHECK(test.PopBack() == 2);
    }
}