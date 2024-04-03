#pragma once

#include <string>
#include <list>
#include <todolist-cpp/Task.hpp>

class Board{
    public:
        Board();       
        std::list<Task> _todo;
        std::list<Task> _done;
        void addTodo(std::string desc);
        void toDone(unsigned int id);

    private:
        int _nextId;
};