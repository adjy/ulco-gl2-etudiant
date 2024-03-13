#pragma once

#include "Forme.hpp"

#include <iostream>
#include <memory>
#include <vector>
#include <map>

using Description = std::map<std::string, std::string>;

class Descriptible {

    
    public:
        virtual const Description toDescription() const = 0;
        

    private:
       

};

