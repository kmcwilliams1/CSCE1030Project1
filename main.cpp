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
        is.setstate(ios_base::failbit);

    return is;
}



int changeNumFunc(int &leftNum, int &rightNum) {
    do {
        leftNum = rand() % 100 + 100;
        rightNum = rand() % 100 + 100;
    } while (leftNum > rightNum);
    return leftNum && rightNum;
};

int guessNumFunc(int leftNum, int rightNum, int &lastGuessNum, int &lifePoints, int &guessNum , int &displayNum) {
    if(displayNum == 0) {
        if (leftNum < guessNum && guessNum < rightNum) {
            cout << "You guessed correctly!" << endl;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            lifePoints += 5;
        } else if (guessNum == lastGuessNum)
            cout << "You just guessed that number." << endl;
        else {
            cout << "You guessed incorrectly." << endl;
            cout << "Current score is: " << lifePoints << endl;
            lifePoints -= 5;
        }
    } else if(displayNum != 0 ){
        if (leftNum < guessNum && guessNum < rightNum) {
            cout << "You guessed correctly!" << endl;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
            lifePoints += 1;
        } else if (guessNum == lastGuessNum)
            cout << "You just guessed that number." << endl;
        else {
            cout << "You guessed incorrectly." << endl;
            cout << "Current score is: " << lifePoints << endl;
            lifePoints -= 10;
        }
    }

    return lifePoints;
};

void displayNumFunc(int choice, int leftNum, int rightNum, int &displayNum) {
    if (displayNum != leftNum && displayNum != rightNum) {
        choice == displayLeft ? displayNum = leftNum : displayNum = rightNum;
        cout << "The number is " << displayNum << endl;
    }
    else cout << "You already displayed a number." << endl;
};

void terminateFunc() {
    cout << "Goodbye, World!" << endl;
    exit(0);
};

void playGame() {

    int lifePoints = 100;
    MenuChoice choice;  // Initialize 'choice' to a default value
    int leftNum, rightNum, guessNum, lastGuessNum;
    int displayNum = 0;

    changeNumFunc(leftNum, rightNum);

    cout << "Enter your choice:"
         << "\n1. Display left"
         << "\n2. Display right"
         << "\n3. Guess"
         << "\n4. Change numbers"
         << "\n5. Quit" << endl;

    cin >> choice;

    // gets a user's choice
    while (choice != quit) {
        switch (choice) {
            case displayLeft:
                displayNumFunc(choice, leftNum, rightNum, displayNum);
                break;
            case displayRight:
                displayNumFunc(choice, leftNum, rightNum, displayNum);
                break;
            case guess:
                cout << "Enter your guess: ";
                cin >> guessNum;
                guessNumFunc(leftNum, rightNum, lastGuessNum, lifePoints, guessNum, displayNum);
                break;
            case changeNumbers:
                changeNumFunc(leftNum, rightNum);
                cout << "Change numbers." << endl;
                break;
            case quit:
                terminateFunc();
            default:
                cout << "Not a valid selection, sorry!" << endl;
                break;
        }
    }

}


int main() {


    string playerName;

    // main menu
    cout << "Enter your name: ";
    getline(cin, playerName);
    cout << "Welcome to the game, " << playerName << endl;


    playGame();


    cout << "Goodbye, World!" << endl;
}
