#include "Tictactoe.hpp"

using namespace std;


void saisirUnCoup(int& i, int& j) {
        try {
            std::string l, k;
            std::cout << "Entrer un coup (i,j): ";
            std::cin >> l >>k;
            
            i = std::stoi(l);
            j = std::stoi(k);

    
            if (i < 0 || i >= 3 || j < 0 || j >= 3) {
                std::cout<<"Les valeurs doivent être comprises entre 0 et 2 inclusivement."<<std::endl;
                saisirUnCoup(i, j);
            }

        } catch (const std::exception& e) {
            std::cout<< "Entrée non valide. Veuillez entrer des nombres entiers."<<std::endl;
             saisirUnCoup(i, j);
        }
    }



int main() {
    Jeu jeu;
    Status status = jeu.getStatus();

    


    while(status == Status::RougeJoue || status == Status::VertJoue){
        std::cout<<jeu;
        int i, j;
        saisirUnCoup(i, j);
        std::cout<<i<<" "<< j<< std::endl;
        jeu.jouer(i, j);
        status = jeu.getStatus();
    }

    if(jeu.getStatus() == Status::Egalite)
        std::cout<< "La partie est nulle"<<std::endl;
    else{
        std::string winner = "vert";
        if(jeu.getStatus() == Status::RougeGagne)
            winner = "rouge";

        std::cout<< winner +" a gagne";
    }
   

    return 0;
}

