#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    // TODO
    return Status::RougeJoue;
}

Cell Jeu::getCell(int i, int j) const {
    // TODO
    return Cell::Vide;
}

std::ostream & operator<<(std::ostream & os, const Jeu & jeu) {
    for(unsigned int i = 0; i < 3; i++){
        for(unsigned int j = 0; j < 3; j++){
            switch (jeu.getCell(i, j)){
            case Cell::Vide:
                os<<".";
                break;
            case Cell::Vert:
                os<<"v";
                break;
            case Cell::Rouge:
                os<<"r";
                break;
            default:
                break;
            }        
        }
        os<<std::endl;
    }
    return os;
}

bool Jeu::jouer(int i, int j) {
    // TODO
    return false;
}

void Jeu::raz() {
    // TODO
}

