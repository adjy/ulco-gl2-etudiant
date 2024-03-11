#include "Logger.hpp"

#include <algorithm>
#include <iomanip>
#include <map>
#include <sstream>

void Logger::addItem(Level l, const std::string & m) {
  _items.push_back(std::make_tuple(l, m));
}

std::string Logger::reportByAdded() const {
  std::string str = "";

  for(auto &item: _items){
    //str += "[" + std::to_string(std::get<0>(item) )+ "]";
  }
  return "TODO Logger::reportByAdded";
}

std::string Logger::reportByLevel() const {
  // TODO Logger::reportByLevel
  return "TODO Logger::reportByLevel";
}

