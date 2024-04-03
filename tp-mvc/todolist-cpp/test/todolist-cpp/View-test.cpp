#include <todolist-cpp/View.hpp>

#include <catch2/catch.hpp>
#include <sstream>

TEST_CASE( " View showTask" ) {
    Task t {1, "TODO"};
    REQUIRE( showTask(t) == "1. TODO" );
    
}

TEST_CASE( "test printBoard, 1" ) {
    Board b;
    std::ostringstream oss;
    printBoard(oss, b);

    auto exp = "Todo:\nDone:\n";
    REQUIRE( oss.str() == exp );
    
}

TEST_CASE( "test printBoard, 2" ) {
    Board b;
    b.addTodo("foo");
    std::ostringstream oss;
    printBoard(oss, b);

    auto exp = "Todo:\n1. foo\nDone:\n";
    REQUIRE( oss.str() == exp );
    
}

