/// \mainpage
///
/// Jeu de titatoe
///
/// Exemple d'utilisation
/// \code {.cpp}
/// Jeu jeu;
/// Status status = jeu.getStatus();
/// while(status == Status::RougeJoue || status == Status::VertJoue){
///     // Choisir un coup(i,j) ...
///     jeu.jouer(i, j);
///     status = jeu.getStatus();
///  }

/// \endcode
