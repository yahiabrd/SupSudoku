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
        * si il est true : on peut modifier les cases de d�part
        * si il est false : on ne peut pas modifier les cases de d�part
        */
        bool canChange;

    public:
        /**
        * Constructeur qui prend en parametre true ou false pour le canChange
        * Constructeur par defaut qui prend false pour le canChange
        */
        BOX(bool c=false);

        /**
        * M�thode qui va permettre d'afficher le tableau pass� en parametre
        */
        void displayLevel(int board[9][9]);

        /**
        * M�hode qui va cr�er une copie du tableau pass� en parametre et le retourner
        * pour verifier si les cases de depart sont inchang�es
        */
        int createBoardCopy(int board[9][9], int copyBoard[9][9]);

        /**
        * M�thode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Easy
        */
        void initEasyLevel();

        /**
        * M�thode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Medium
        */
        void initMediumLevel();

        /**
        * M�thode qui va initialiser le jeu et permettre de jouer si on a choisi le niveau Hard
        */
        void initHardLevel();

        /**
        * Methode qui prend en parametre le tableau et va renvoyer
        * true si la partie de sudoku est finie ou
        * false dans le cas contraire
        */
        bool finishedGame(int easyBoard[9][9]);

        /**
        * M�thode qui va afficher que la partie est finie
        */
        void winner();

        /**
        * M�thode qui va afficher les regles basiques du jeu
        */
        void rules();

        /**
        * M�thode qui va afficher les informations concernant le programme
        */
        void about();
};

#endif // BOX_H
