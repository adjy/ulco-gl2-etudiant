#include <todolist-cpp/Board.hpp>

#include <catch2/catch.hpp>

TEST_CASE( "test Board" ) {
    Board b;
    REQUIRE( b._todo.size() == 0 );
}

TEST_CASE( "test addTodo" ) {
    Board b;
    REQUIRE( b._todo.size() == 0 );
    
    b.addTodo("foobar");

    REQUIRE( b._todo.size() == 1 );
    Task t = b._todo.back();
    REQUIRE( t._id == 1 );
    REQUIRE( t._name == "foobar" );

    b.addTodo("foo");

    REQUIRE( b._todo.size() == 2 );
    Task t2 = b._todo.back();
    REQUIRE( t2._id == 2 );
    REQUIRE( t2._name == "foo" );
   
}

TEST_CASE( "test addTodo 2" ) {
    Board b;
    b.addTodo("foobar");
    Task t = b._todo.back();
    b.addTodo("foo");
    Task t2 = b._todo.back();
    
    REQUIRE( b._todo.size() == 2 );
    REQUIRE( t._id == 1 );
    REQUIRE( t._name == "foobar" );
    REQUIRE( t2._id == 2 );
    REQUIRE( t2._name == "foo" );
   
}

TEST_CASE( "Board toDone, 1" ) {
    Board b;
    b.addTodo("foo");
    b.addTodo("bar");
    b.toDone(2);
    REQUIRE( b._todo.size() == 1 );
    REQUIRE( b._done.size() == 1 );

    Task t = b._todo.back();
    REQUIRE( t._id == 1 );
    REQUIRE( t._name == "foo" );
    
    Task t2 = b._done.back(); 
    REQUIRE( t2._id == 2 );
    REQUIRE( t2._name == "bar" );
}

TEST_CASE( "Board toDone, 2" ) {
    Board b;
    b.addTodo("foo");
    b.addTodo("bar");
    b.toDone(3);
    REQUIRE( b._todo.size() == 2 );
    REQUIRE( b._done.size() == 0 );
}
