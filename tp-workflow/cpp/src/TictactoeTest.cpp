#include "Tictactoe.hpp"
#include <sstream>
#include <iostream>

#include <catch2/catch.hpp>

TEST_CASE("test operator<<") { 
    Jeu jeu;
    std::ostringstream oss;
    oss << jeu;
    auto txt = "...\n...\n...\n";
    REQUIRE(oss.str() == txt );
}
