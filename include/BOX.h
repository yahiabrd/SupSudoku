#ifndef BOX_H
#define BOX_H

/**
* Classe BOX qui permet de gerer l'affichage du tableau et les differents niveaux de jeu
*/

class BOX
{
    private:
        /**
        * Attribut canChange
        * si il est true : on peut modifier les cases de départ
        * si il est false : on ne peut pas modifier les cases de départ
        */
        bool canChange;

    public:
        /**
        * Constructeur qui prend en parametre true ou false pour le canChange
        * Constructeur par defaut qui prend false pour le canChange
        */
        BOX(bool c=false);

        /**
        * Méthode qui va permettre d'afficher le tableau passé en parametre
        */
        void displayLevel(int board[9][9]);

        /**
        * Méhode qui va créer une copie du tableau passé en parametre et le retourner
        * pour verifier si les cases de depart sont inchangées
        */
        int createBoardCopy(int board[9][9], int copyBoard[9][9]);

        /**
        * Méthode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Easy
        */
        void initEasyLevel();

        /**
        * Méthode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Medium
        */
        void initMediumLevel();

        /**
        * Méthode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Hard
        */
        void initHardLevel();

        /**
        * Methode qui prend en parametre le tableau et va renvoyer
        * true si la partie de sudoku est finie ou
        * false dans le cas contraire
        */
        bool finishedGame(int easyBoard[9][9]);

        /**
        * Méthode qui va afficher que la partie est finie
        */
        void winner();

        /**
        * Méthode qui va afficher les regles basiques du jeu
        */
        void rules();

        /**
        * Méthode qui va afficher les informations concernant le programme
        */
        void about();
};

#endif // BOX_H
