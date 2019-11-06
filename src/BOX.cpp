#include "BOX.h"
#include <iostream>

using namespace std;

BOX::BOX(bool c) { canChange = c; }

void BOX::displayLevel(int board[9][9]){

    for (int i = 0; i < 9; i++){

        for (int j = 0; j < 9; j++){

            //remplace les 0 par des "." pour l'affichage
            if (board[i][j] == 0){
                cout << "[.]";
            }else{
                //affichage de chaque element
                cout << "[" << board[i][j] << "]";
            }
            //espace pour les colonnes
            if(j == 2 || j == 5)
                cout << "  ";
        }

        //espace pour les lignes
        if(i == 2 || i == 5)
            cout << endl;

        //retour a la ligne
        cout << endl;
    }
}

int BOX::createBoardCopy(int board[9][9], int copyBoard[9][9]){

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            //ajout des elements du tableau passé en parametre au tableau copie
            copyBoard[i][j] = board[i][j];
        }
    }

    return copyBoard[9][9];
}

void BOX::initEasyLevel(){

    //tableau niveau easy
    int easyBoard[9][9] = {
              {0,0,3, 7,1,0, 5,0,0},
              {2,9,0, 5,6,0, 0,0,0},
              {0,5,0, 8,3,0, 0,2,4},

              {0,7,5, 3,2,0, 0,4,6},
              {4,0,0, 0,0,0, 0,0,0},
              {8,0,2, 0,5,0, 0,7,1},

              {1,8,0, 0,0,0, 0,0,7},
              {0,6,4, 0,0,0, 1,0,8},
              {3,0,0, 0,9,0, 0,0,5}};

    //copie du tableau easy pour verifier les cases possibles à changer
    int easyCopy[9][9];
    createBoardCopy(easyBoard, easyCopy);

    //affichage du tableau
    displayLevel(easyBoard);

    bool finished = false;
    int row, col, number;

    while(!finished){
        cout << endl;
        cout << "Choisissez une ligne : ";
        cin >> row;
        cout << "Choisissez une colonne : ";
        cin >> col;
        cout << "Choissisez un chiffre a mettre : ";
        cin >> number;

        //verification des limites des lignes et colonnes et du chiffre
        if( (row >= 0 && row <= 8) && (col >= 0 && col <= 8) && (number >= 0 && number <= 9) ){
            //si le canChange est false, alors on peut pas modifier les cases de depart,
            if(!canChange){
                //verifie si la copie de depart comportait des 0
                if(easyCopy[row][col] == 0){
                    easyBoard[row][col] = number;

                    //Réaffichage du tableau modifié
                    cout << endl;
                    displayLevel(easyBoard);

                    //verifie si la partie est finie pour sortir de la boucle
                    finished = finishedGame(easyBoard);
                }else{
                    cout << "Vous ne pouvez pas modifier cette case !" << endl;
                }
            }else{
                easyBoard[row][col] = number;

                //Réaffichage du tableau modifié
                cout << endl;
                displayLevel(easyBoard);

                //verifie si la partie est finie pour sortir de la boucle
                finished = finishedGame(easyBoard);
            }
        }else{
            cout << endl << "Impossible de choisir cette case ou ce chiffre" << endl << endl;
        }
    }
    //si la partie est finie, on peut afficher le message pour le gagnant
    if(finished)
        winner();
}

void BOX::initMediumLevel(){

    //tableau niveau medium
    int mediumBoard[9][9] = {
              {9,0,8, 0,0,6, 0,5,4},
              {0,3,4, 0,5,0, 8,0,0},
              {1,7,0, 8,0,0, 0,6,0},

              {7,0,0, 5,0,3, 4,0,0},
              {0,0,0, 1,2,0, 0,7,3},
              {2,0,0, 0,0,9, 6,1,0},

              {0,4,1, 2,0,0, 7,0,0},
              {5,0,0, 6,1,4, 2,0,8},
              {8,0,0, 3,0,0, 5,0,0}};

    //copie du tableau medium pour verifier les cases possibles à changer
    int mediumCopy[9][9];
    createBoardCopy(mediumBoard, mediumCopy);

    //affichage du tableau
    displayLevel(mediumBoard);

    bool finished = false;
    int row, col, number;

    while(!finished){
        cout << endl;
        cout << "Choisissez une ligne : ";
        cin >> row;
        cout << "Choisissez une colonne : ";
        cin >> col;
        cout << "Choissisez un chiffre a mettre : ";
        cin >> number;

        //verification des limites des lignes et colonnes et du chiffre
        if( (row >= 0 && row <= 8) && (col >= 0 && col <= 8) && (number >= 0 && number <= 9) ){
            //si le canChange est false, alors on peut pas modifier les cases de depart,
            if(!canChange){
                //verifie si la copie de depart comportait des 0
                if(mediumCopy[row][col] == 0){
                    mediumBoard[row][col] = number;

                    //Réaffichage du tableau modifié
                    cout << endl;
                    displayLevel(mediumBoard);

                    //verifie si la partie est finie pour sortir de la boucle
                    finished = finishedGame(mediumBoard);
                }else{
                    cout << "Vous ne pouvez pas modifier cette case !" << endl;
                }
            }else{
                mediumBoard[row][col] = number;

                //Réaffichage du tableau modifié
                cout << endl;
                displayLevel(mediumBoard);

                //verifie si la partie est finie pour sortir de la boucle
                finished = finishedGame(mediumBoard);
            }
        }else{
            cout << endl << "Impossible de choisir cette case ou ce chiffre" << endl << endl;
        }
    }
    //si la partie est finie, on peut afficher le message pour le gagnant
    if(finished)
        winner();
}

void BOX::initHardLevel(){

    //tableau niveau hard
    int hardBoard[9][9] = {
              {0,0,0, 0,0,0, 0,7,6},
              {3,0,0, 4,0,0, 0,0,5},
              {0,0,0, 9,6,0, 0,0,0},

              {0,0,6, 3,0,0, 0,0,0},
              {0,9,4, 7,1,0, 0,5,0},
              {7,2,0, 0,5,0, 0,9,0},

              {0,4,0, 0,0,3, 8,0,1},
              {0,1,0, 2,9,6, 7,0,0},
              {0,0,0, 0,0,1, 5,6,0}};

    //copie du tableau hard pour verifier les cases possibles à changer
    int hardCopy[9][9];
    createBoardCopy(hardBoard, hardCopy);

    //affichage du tableau
    displayLevel(hardBoard);

    bool finished = false;
    int row, col, number;

    while(!finished){
        cout << endl;
        cout << "Choisissez une ligne : ";
        cin >> row;
        cout << "Choisissez une colonne : ";
        cin >> col;
        cout << "Choissisez un chiffre a mettre : ";
        cin >> number;

        //verification des limites des lignes et colonnes et du chiffre entré
        if( (row >= 0 && row <= 8) && (col >= 0 && col <= 8) && (number >= 0 && number <= 9) ){
            //si le canChange est false, alors on peut pas modifier les cases de depart,
            if(!canChange){
                //verifie si la copie de depart comportait des 0
                if(hardCopy[row][col] == 0){
                    hardBoard[row][col] = number;

                    //Réaffichage du tableau modifié
                    cout << endl;
                    displayLevel(hardBoard);

                    //verifie si la partie est finie pour sortir de la boucle
                    finished = finishedGame(hardBoard);
                }else{
                    cout << "Vous ne pouvez pas modifier cette case !" << endl;
                }
            }else{
                hardBoard[row][col] = number;

                //Réaffichage du tableau modifié
                cout << endl;
                displayLevel(hardBoard);

                //verifie si la partie est finie pour sortir de la boucle
                finished = finishedGame(hardBoard);
            }
        }else{
            cout << endl << "Impossible de choisir cette case ou ce chiffre" << endl << endl;
        }
    }
    //si la partie est finie, on peut afficher le message pour le gagnant
    if(finished)
        winner();
}

bool BOX::finishedGame(int board[9][9]){

    //partie qui va verifier les lignes et les colonnes
    int cptColLignes = 0;

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            cptColLignes+=board[i][j];
        }
    }

    //partie qui va verifier si toutes les cases sont remplies
    int cptCases = 0;

    for (int i = 0; i < 9; i++){
        for (int j = 0; j < 9; j++){
            if (board[i][j] != 0)
                cptCases+=1;
        }
    }

    //on verifie le compteur de cases et le compteur lignes colonnes
    if( (cptCases==9*9) && (cptColLignes==45*9) )
        return true;
    return false;
}

void BOX::winner(){
    cout << endl << "Partie finie !! vous avez gagne, Bravo !" << endl << endl;
}

void BOX::rules(){
    cout << endl << "Regles du jeu : " << endl
         << "\tLe but du jeu est de remplir ces cases avec des chiffres allant de 1 a 9 " << endl
         << "\ten veillant toujours a ce qu'un meme chiffre ne figure qu'une seule fois par colonne," << endl
         << "\tune seule fois par ligne, et une seule fois par carre de neuf cases." << endl << endl;
}

void BOX::about(){
    cout << endl << "SupSodoku project " << endl;
}
