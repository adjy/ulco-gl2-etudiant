#include <todolist-cpp/Board.hpp>
#include <iostream>
#include <algorithm>

Board::Board() : _nextId(1){}

void Board::addTodo(const std::string desc){
    /*Task t{_nextId++, desc};
    _todo.emplace_back(t);*/
    _todo.push_back({(_nextId)++, desc});
}
void Board::toDone(unsigned int id){
    auto searchId = [id](const Task &t){
        return t._id == id;
    };

    auto it = std::find_if(_todo.begin(), _todo.end(), searchId);
    if(it != _todo.end()){
        _done.push_back(*it);
        _todo.erase(it);
    }
};