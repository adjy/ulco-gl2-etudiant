#include "Forme.hpp"
#include <cmath>
#include <numeric>

Disque::Disque(double rayon) :
    _rayon(rayon)
{}
double Disque::aire() const{
    return _rayon * 2 * M_PI;
}

const Description Disque::toDescription() const{
    std::map<std::string, std::string> map;
    map.insert(std::make_pair("name", "Disque"));
    map.insert(std::make_pair("rayon", std::to_string(_rayon)));
    return map;
};



Rectangle::Rectangle(double largeur, double hauteur) :
    _largeur(largeur), _hauteur(hauteur)
{}
double Rectangle::aire() const{
    return _largeur * _hauteur;
}


