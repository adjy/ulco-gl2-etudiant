#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test View" ) {
    Task t {1, "TODO"};
    REQUIRE( showClass(t) == "1. TODO" );
    
}

