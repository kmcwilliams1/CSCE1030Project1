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

    // this happens when the person has not displayed a number yet and points are not reduced
    if(displayNum == 0) {
        if (guessNum == lastGuessNum) { cout << "You just guessed that number." << endl;  return lifePoints && lastGuessNum && guessNum && displayNum && leftNum && rightNum;}

        if (leftNum < guessNum && guessNum < rightNum) {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed correctly! +5" << endl;
            lifePoints += 5;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;
        }
        else {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed incorrectly. -5" << endl;
            lifePoints -= 5;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;

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


        }
        else {
            cout << "You guessed " << guessNum << "...\n";
            cout << "You guessed incorrectly. -10" << endl;
            lifePoints -= 10;
            cout << "Current score is: " << lifePoints << endl;
            lastGuessNum = guessNum;

        }
    }

    if (lifePoints <= 0) {
        cout << "You have no more life points. Game over." << endl;
        exit(0);
    }


    cout << "Play again? (y/n): ";
    char playAgain;
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        return lifePoints && lastGuessNum && guessNum && displayNum && leftNum && rightNum;
    } else if (playAgain == 'n' || playAgain == 'N') {
        exit(0);
    }
};

int displayNumFunc(int choice, int leftNum, int rightNum, int &displayNum) {
    if (displayNum != leftNum && displayNum != rightNum) {
        choice == displayLeft ? displayNum = leftNum : displayNum = rightNum;
        choice == displayLeft ? cout << "The lower number is " << displayNum << endl : cout << "The higher number is " << displayNum << endl;
    } else cout << "You already displayed a number." << endl;
    return displayNum && leftNum && rightNum;
};

void terminateFunc() {
    cout << "Goodbye, World!" << endl;
    exit(0);
};

void displayScreen(int leftNum, int rightNum, int &displayNum, int &lastGuessNum, int &lifePoints, int &guessNum){

    MenuChoice choice;

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
                break;
            default:
                cout << "Not a valid selection, sorry!" << endl;
                break;
        }
    }

}

void playGame() {

    int lifePoints = 100;
    int leftNum, rightNum, guessNum, lastGuessNum;
    int displayNum = 0;

    changeNumFunc(leftNum, rightNum);
    displayScreen(leftNum, rightNum, displayNum, lastGuessNum, lifePoints, guessNum);

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
