int playGuessTheNumber(); // lance le jeu
int rand(int min, int max); // renvoie un entier aléatoire entre le min et le max donnés en paramètres 
int getUserInput(); // demande un nombre à l'utilisateur et le renvoie
void giveHint(int userGuess, int numberToGuess); // donne un indice sur le prochain nombre à deviner
void endGame(int finalGuessCount); // fini le jeu