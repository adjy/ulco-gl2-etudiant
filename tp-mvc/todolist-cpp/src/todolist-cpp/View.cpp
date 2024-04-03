#include <todolist-cpp/View.hpp>
#include <iostream>

std::string showTask(const Task &t){
    return std::to_string(t._id) + ". " + t._name;
}

void printBoard(std::ostream &os, Board &b){
    os << "Todo:"<<std::endl;
    for(auto bTask: b._todo)
        os<<showTask(bTask)<<std::endl;
    

    os << "Done:"<<std::endl;
    for(auto bTask: b._done)
        os<<showTask(bTask)<<std::endl;
}