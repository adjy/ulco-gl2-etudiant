#include "Tictactoe.hpp"
#include <sstream>
#include <iostream>

#include <catch2/catch.hpp>


TEST_CASE("test contructeur") { 
    Jeu jeu;
    REQUIRE(Status::RougeJoue == jeu.getStatus() ); 
    for(unsigned int i = 0; i < 3; i++)
        for(unsigned int j = 0; j < 3; j++)
            REQUIRE(jeu.getCell(i, j) == Cell::Vide );
}

TEST_CASE("raz") { 
    Jeu jeu;
    jeu.raz();
    REQUIRE(Status::RougeJoue == jeu.getStatus() ); 
    for(unsigned int i = 0; i < 3; i++)
        for(unsigned int j = 0; j < 3; j++)
            REQUIRE(jeu.getCell(i, j) == Cell::Vide );
}

TEST_CASE("test operator<<") { 
    Jeu jeu;
    std::ostringstream oss;
    oss << jeu;
    auto txt = "...\n...\n...\n";
    REQUIRE(oss.str() == txt );
}

TEST_CASE("test jouer (1)") { 
    Jeu jeu;
    REQUIRE(jeu.jouer(0, -1) == false );
    REQUIRE(jeu.jouer(-1, -1) == false );
    REQUIRE(jeu.jouer(-1, 0) == false );
    REQUIRE(jeu.jouer(-1, 3) == false );
}

TEST_CASE("test jouer (2)") { 
    Jeu jeu;
    int i = 2;
    int j = 1;

    REQUIRE(Status::RougeJoue == jeu.getStatus() );
    REQUIRE(jeu.getCell(i, j) == Cell::Vide );
    REQUIRE(jeu.jouer(i, j) == true );
    REQUIRE(jeu.getCell(i, j) == Cell::Rouge );
    REQUIRE(jeu.jouer(i, j) == false );
    REQUIRE(Status::VertJoue == jeu.getStatus() );
}

TEST_CASE("Win colonne") { 
    Jeu jeu;
    jeu.jouer(0,0); // Rouge
    jeu.jouer(0,1); // Vert
    jeu.jouer(1,0); // Rouge
    jeu.jouer(2,2); // Vert
    jeu.jouer(2,0); // Rouge

    REQUIRE(Status::RougeGagne == jeu.getStatus() );
    
}

TEST_CASE("Win ligne") { 
    Jeu jeu;
    jeu.jouer(0,0); // Rouge
    jeu.jouer(1,1); // Vert
    jeu.jouer(2,2); // Rouge
    jeu.jouer(1,2); // Vert
    jeu.jouer(0,2); // Rouge
    jeu.jouer(1,0); // Vert

    REQUIRE(Status::VertGagne == jeu.getStatus() );
}

TEST_CASE("Win diag 1") { 
    Jeu jeu;
    jeu.jouer(0,0); // Rouge
    jeu.jouer(0,1); // Vert
    jeu.jouer(2,2); // Rouge
    jeu.jouer(0,2); // Vert
    jeu.jouer(1,1); // Rouge
    jeu.jouer(1,0); // Rouge

    REQUIRE(Status::RougeGagne == jeu.getStatus() );
}

TEST_CASE("Win diag 2") { 
    Jeu jeu;
    jeu.jouer(1,1); // Rouge
    jeu.jouer(0,0); // Vert
    jeu.jouer(0,2); // Rouge
    jeu.jouer(2,2); // Vert
    jeu.jouer(2,0); // Rouge

    REQUIRE(Status::RougeGagne == jeu.getStatus() );
}

TEST_CASE("Egalite") {
    Jeu jeu;
    jeu.jouer(0, 0); // Rouge
    jeu.jouer(0, 2); // Vert
    jeu.jouer(0, 1); // Rouge
    jeu.jouer(1, 0); // Vert
    jeu.jouer(1, 2); // Rouge
    jeu.jouer(1, 1); // Vert
    jeu.jouer(2, 0); // Rouge
    jeu.jouer(2, 1); // Vert
    jeu.jouer(2, 2); // Rouge

 

    REQUIRE(Status::Egalite == jeu.getStatus());
}




