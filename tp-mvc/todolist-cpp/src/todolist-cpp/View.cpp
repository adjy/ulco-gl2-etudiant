#include <todolist-cpp/View.hpp>


std::string showClass(const Task &t){
    return std::to_string(t._id) + ". " + t._name;
}