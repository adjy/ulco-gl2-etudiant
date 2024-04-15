#include "Tictactoe.hpp"

using namespace std;

int main() {
    Jeu jeu;
    Status status = jeu.getStatus();

    std::cout<<jeu;
   /* while(status == Status::RougeJoue || status == Status::VertJoue){
        // Choisir un coup(i,j) ...
        jeu.jouer(i, j);
        status = jeu.getStatus();
    }*/
   

    return 0;
}

