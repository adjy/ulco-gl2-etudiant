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
            break;
        case Status::VertJoue:
            _plateau[i][j] = Cell::Vert;
            _status = Status::RougeJoue;
            break;
        default:
            break;
    }
    win(i, j);
    return true;
}

void Jeu::raz() {
    _status = Status::RougeJoue;
    for(unsigned int i = 0; i < 3; i++)
        for(unsigned int j = 0; j < 3; j++)
            _plateau[i][j] = Cell::Vide;
}

void Jeu::win(int i, int j){
    Cell a = _plateau[i][j];

    if(a == Cell::Vide)
        return;

    bool gagne = false;
    // Test Colonne
    if (_plateau[(i + 1) % 3][j] == a && _plateau[(i + 2) % 3][j] == a)
        gagne = true;

    // Test Ligne
    if (_plateau[i][(j + 1) % 3] == a && _plateau[i][(j + 2) % 3] == a)
        gagne = true;

    // Test Diagonale 1
    if (i == j && _plateau[(i + 1) % 3][(j + 1) % 3] == a && _plateau[(i + 2) % 3][(j + 2) % 3] == a)
        gagne = true;

    // Test Diagonale 2
    if (i + j == 2 && _plateau[(i + 1) % 3][(j + 2) % 3] == a && _plateau[(i + 2) % 3][(j + 1) % 3] == a)
        gagne = true;
    

    if(gagne){
        if(a == Cell::Rouge)
            _status = Status::RougeGagne;
        else if(a == Cell::Vert)
            _status = Status::VertGagne;
    }        
    
}

