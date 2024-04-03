#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/Board.hpp>
#include <todolist-cpp/View.hpp>
#include <iostream>
#include <sstream>
#include <exception>

int main() {

    Board b;

    std::string input, iss;

    while(true){
        std::string cmd, rst;
        printBoard(std::cout, b);
        std::getline(std::cin, input);
        std::istringstream iss(input);
        std::getline(iss, cmd, ' ');
        std::getline(iss, rst);

        if(cmd == "add" && !rst.empty())
            b.addTodo(rst);
        try{
            if(cmd == "done" && !rst.empty())
                b.toDone(std::stoi(rst));
        }
        catch(std::exception){}
        
        if(cmd == "quit")
            return 0;
    }


    return 0;
}

