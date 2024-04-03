#pragma once

#include <string>
#include <todolist-cpp/Task.hpp>
#include <todolist-cpp/Board.hpp>


std::string showTask(const Task &t);

void printBoard(std::ostream &os, const Board &b);