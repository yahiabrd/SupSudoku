#include <iostream>
#include <stdlib.h> //librairie qui contient le system("cls") pour effacer l'écran
#include "BOX.h"

using namespace std;

/**
* Fonction affichant le Menu
*/
void Menu(){
    int choice;
    char answer;
    bool continueProgram = true;

    BOX sudoku(false); //instanciation avec false (on ne pourra donc pas modifier les cases de départ)

    cout << "Bienvenue dans le jeu SupSudoku !" << endl << endl;

    while(continueProgram){
        cout << "---------------------------" << endl;
        cout << "|          Menu           |" << endl;
        cout << "---------------------------" << endl;

        cout << "Niveaux : " << endl;
        cout << "\t1 - Niveau facile" << endl;
        cout << "\t2 - Niveau Moyen" << endl;
        cout << "\t3 - Niveau difficile" << endl;

        cout << endl;

        cout << "Informations : " << endl;
        cout << "\t4 - Regles du jeu" << endl;
        cout << "\t5 - A propos" << endl;

        cout << endl;

        cout << "Que voulez-vous faire ? : ";
        cin >> choice;

        switch(choice){
            case 1:
                sudoku.initEasyLevel();
                break;
            case 2:
                sudoku.initMediumLevel();
                break;
            case 3:
                sudoku.initHardLevel();
                break;
            case 4:
                sudoku.rules();
                break;
            case 5:
                sudoku.about();
                break;
            default:
                cout << endl << "Le numero entre ne correspond a rien dans le menu" << endl << endl;
                break;
        }

        cout << "Voulez-vous continuer sur le menu ? O/N : ";
        cin >> answer;

        system("cls");//permet d'effacer la console

        //verifie si le caractere entré est different de "o" ou "O" en le mettant en majuscule
        if (toupper(answer) != 'O'){
            continueProgram = false;
            cout << "A bientot !" << endl;
        }
    }
}

/**
* Fonction principale du programme
*/
int main()
{
    Menu();

    return 0;
}
