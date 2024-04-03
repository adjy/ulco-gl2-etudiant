#include <todolist-cpp/Board.hpp>
#include <iostream>

Board::Board() : _nextId(1){}

void Board::addTodo(const std::string desc){
    /*Task t{_nextId++, desc};
    _todo.emplace_back(t);*/
    _todo.push_back({(_nextId)++, desc});
}
void toDone(unsigned int id);