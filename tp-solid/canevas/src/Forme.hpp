#pragma once
#include "Descriptible.hpp"

class Forme: public Descriptible {
    public:
        virtual ~Forme() = default;
        virtual double aire() const = 0;
       
};

class Disque : public Forme {
    public:
        double _rayon;
        Disque(double rayon);
        double aire() const;
        const Description toDescription() const;
        

        
};

class Rectangle : public Forme {
    public:
        double _largeur;
        double _hauteur;
        Rectangle(double largeur, double hauteur);
        double aire() const;
};

