#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <array>
#include <iostream>

enum class Status { Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue };

enum class Cell { Vide, Rouge, Vert };

// Moteur de jeu de tictactoe.
class Jeu {
    private:
        std::array<std::array<Cell, 3>, 3> _plateau;
        Status _status;
        void win(int i, int j);

    public:
        ///@brief Constructeur.
        Jeu();

        /// @brief Pour savoir le status du jeu courant
        /// @return le status du jeu courant (Egalite, RougeGagne, VertGagne, RougeJoue, VertJoue).
        Status getStatus() const;

        // Retourne l'état d'une case du plateau
        Cell getCell(int i, int j) const;

        ///@brief Joue un coup pour le joueur courant.
        /// 
        /// @param i ligne choisie (0, 1 ou 2)
        /// @param j colonne choisie (0, 1 ou 2)
        /// 
        ///@return Si le coup est invalide, retourne false. Si le coup est valide,
        /// joue le coup et retourne true.
        bool jouer(int i, int j);

        ///@brief Réinitialise le jeu.
        void raz();
};

/// @brief Retourne les infos du jeu, plus précisément la grille de jeu
std::ostream & operator<<(std::ostream & os, const Jeu & jeu);

#endif

