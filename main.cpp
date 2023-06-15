#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

enum MenuChoice {
    displayLeft, displayRight, guess, changeNumbers, quit
};

istream &operator>>(istream &is, MenuChoice &choice) {
    string name;
    is >> name;

    if (name == "1")
        choice = displayLeft;
    else if (name == "2")
        choice = displayRight;
    else if (name == "3")
        choice = guess;
    else if (name == "4")
        choice = changeNumbers;
    else if (name == "5")
        choice = quit;
    else
        choice = quit;

    return is;
}
MenuChoice choice;


int changeNumFunc(int &leftNum, int &rightNum) {
    do {
        leftNum = rand() % 100 + 100;
        rightNum = rand() % 100 + 100;
    } while (leftNum > rightNum);
    return leftNum && rightNum;
};

int mainMenu(){
    // main menu
    cout << "Enter your choice:"
         << "\n1. Display left"
         << "\n2. Display right"
         << "\n3. Guess"
         << "\n4. Change numbers"
         << "\n5. Quit" << endl;
    return choice;
}


int guessNumFunc(int leftNum, int rightNum, int &lastGuessNum, int &lifePoints, int &guessNum , int &displayNum) {

    // this happens when the person has not displayed a number yet and points are not reduced
    if(displayNum == 0) {
        if (guessNum == lastGuessNum) { cout << "You just guessed that number." << endl;  return lifePoints && lastGuessNum && guessNum && displayNum && leftNum && rightNum;}

        if (leftNum < guessNum && guessNum < rightNum) {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed correctly! +5" << endl;
            lifePoints += 5;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            mainMenu();
        }
        else {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed incorrectly. -5" << endl;
            lifePoints -= 5;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            mainMenu();
        }
    }

    //this means the person has already displayed a number and the points are reduced
    else if(displayNum != 0 ){
        if (guessNum == lastGuessNum) { cout << "You just guessed that number." << endl;  return lifePoints && lastGuessNum && guessNum && displayNum && leftNum && rightNum;}

        if (leftNum < guessNum && guessNum < rightNum) {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed correctly! +1" << endl;
            lifePoints += 1;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            mainMenu();

        }
        else {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed incorrectly. -10" << endl;
            lifePoints -= 10;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            mainMenu();
        }
    }

    if (lifePoints <= 0) {
        cout << "You have no more life points. Game over." << endl;
        cout << "Play again? (y/n): ";
        char playAgain;
        cin >> playAgain;
        if (playAgain == 'y' || playAgain == 'Y') {
            mainMenu();
        } else if (playAgain == 'n' || playAgain == 'N') {
            exit(0);
        }

    }

    return lifePoints && lastGuessNum && guessNum && displayNum && leftNum && rightNum;

};


int main() {


    string playerName;

    int lifePoints = 100;
    int leftNum, rightNum, guessNum, lastGuessNum;
    int displayNum = 0;
    changeNumFunc(leftNum, rightNum);



    // starting menu
    cout << "Enter your name: ";
    getline(cin, playerName);
    cout << "Welcome to the game, " << playerName << endl;



    mainMenu();

    cin >> choice;

    // gets a user's choice
    while (choice != quit) {
        switch (choice) {
            case displayLeft:

                if (displayNum != leftNum && displayNum != rightNum) {
                    displayNum = leftNum;
                    cout << "The lower number is " << displayNum << endl;
                }
                else cout << "You already displayed a number." << endl;
                mainMenu();
                cin >> choice;

                break;
            case displayRight:

                if (displayNum != leftNum && displayNum != rightNum) {
                    displayNum = rightNum;
                    cout << "The upper number is " << displayNum << endl;
                }
                else cout << "You already displayed a number." << endl;
                mainMenu();
                cin >> choice;

                break;
            case guess:

                cout << "Enter your guess: ";
                cin >> guessNum;
                guessNumFunc(leftNum, rightNum, lastGuessNum, lifePoints, guessNum, displayNum);
                mainMenu();
                cin >> choice;

                break;
            case changeNumbers:

                changeNumFunc(leftNum, rightNum);
                cout << "Change numbers." << endl;
                mainMenu();
                cin >> choice;

                break;
            case quit:
                exit(0);
                break;
            default:
                cout << "Not a valid selection, sorry!" << endl;
                mainMenu();
                cin >> choice;

                break;
        }
    }


    cin >> choice;


    cout << "Goodbye, World!" << endl;
    return 0;
}
