#include "Tictactoe.hpp"

Jeu::Jeu() {
    raz();
}

Status Jeu::getStatus() const {
    return _status;
}

Cell Jeu::getCell(int i, int j) const {
    return _plateau[i][j];
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
    if(i < 0 || i >= 3 || j < 0 || j >= 3)
        return false;
    if(getCell(i, j) != Cell::Vide)
        return false;

    switch (getStatus()){
        case Status::RougeJoue:
            _plateau[i][j] = Cell::Rouge;
            _status = Status::VertJoue;
            return true;
            
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            _status = Status::RougeJoue;
            return true;
        default:
            break;
    }
    return false;
}

void Jeu::raz() {
    _status = Status::RougeJoue;
    for(unsigned int i = 0; i < 3; i++)
        for(unsigned int j = 0; j < 3; j++)
            _plateau[i][j] = Cell::Vide;
}

