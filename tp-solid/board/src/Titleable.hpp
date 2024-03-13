#pragma once

#include <string>
#include <vector>

class Titleable {
    public:
        virtual ~Titleable() = default;
        virtual std::string getTitle() const = 0;
};

