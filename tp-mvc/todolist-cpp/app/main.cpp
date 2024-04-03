#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/View.hpp>
#include <iostream>

int main() {

    Board b;
    b.addTodo("foo");
    b.addTodo("bar");

    void printBoard(std::ostream &os, Board &b);

    printBoard(std::cout, b);

   

    return 0;
}

