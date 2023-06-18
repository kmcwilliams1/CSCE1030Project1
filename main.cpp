#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;


// this is the enum for the menu choices
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

int mainMenu() {
    // main menu
    cout << "Enter your choice:"
         << "\n1. Display left"
         << "\n2. Display right"
         << "\n3. Guess"
         << "\n4. Change numbers"
         << "\n5. Quit \n" << endl;
    return choice;
}


int main() {

    //declaring variables
    string playerName;
    int lifePoints = 100;
    int leftNum, rightNum, guessNum, lastGuessNum;
    int displayNum = 0;

    do {
        srand(time(0));
        leftNum = rand() % 100 + 100;
        rightNum = rand() % 100 + 100;
    } while (leftNum >= rightNum);



    // starting menu
    cout << "Enter your name: ";
    getline(cin, playerName);
    cout << "\nWelcome to the game, " << playerName << endl;
    cout << "*******************************" << endl;



    // this combination shows the main menu and then gets the user's choice
    mainMenu();
    cout << "this round..." << leftNum << " " << rightNum << " " << displayNum << endl;
    cin >> choice;



    // gets a user's choice
    while (choice != quit) {
        switch (choice) {

            case displayLeft:

                if (displayNum != rightNum) {
                    displayNum = leftNum;
                    cout << "The lower number is " << leftNum << endl;
                } else cout << "You already displayed a number." << endl;
                cout << "*******************************" << endl;
                mainMenu();
                cin >> choice;
                break;


            case displayRight:

                if (displayNum != leftNum) {
                    displayNum = rightNum;
                    cout << "The upper number is " << rightNum << endl;
                } else cout << "You already displayed a number." << endl;
                cout << "*******************************" << endl;
                mainMenu();
                cin >> choice;
                break;


            case guess:
                cout << "Enter your guess: ";
                cin >> guessNum;

                if (guessNum == lastGuessNum) {
                    cout << "You just guessed that number." << endl;
                    cout << "*******************************" << endl;
                    break;
                }

                if (displayNum == 0) {
                    if (leftNum < guessNum && guessNum < rightNum) {
                        cout << "You guessed " << guessNum << "...\n";
                        cout << "You guessed correctly! +5" << endl;
                        lifePoints += 5;
                        cout << "Current score is: " << lifePoints << endl;
                        lastGuessNum = guessNum;
                        cout << "*******************************" << endl;

                    } else {
                        cout << "You guessed " << guessNum << "...\n";
                        cout << "You guessed incorrectly. -5" << endl;
                        lifePoints -= 5;
                        cout << "Current score is: " << lifePoints << endl;
                        lastGuessNum = guessNum;
                        cout << "*******************************" << endl;

                    }
                }

                //this means the person has already displayed a number and the points are reduced
                if (displayNum == leftNum || displayNum == rightNum) {
                    if (leftNum < guessNum && guessNum < rightNum) {
                        cout << "You guessed " << guessNum << "...\n";
                        cout << "You guessed correctly! +1" << endl;
                        lifePoints += 1;
                        cout << "Current score is: " << lifePoints << endl;
                        lastGuessNum = guessNum;
                        cout << "*******************************" << endl;

                    } else {
                        cout << "You guessed " << guessNum << "...\n";
                        cout << "You guessed incorrectly. -10" << endl;
                        lifePoints -= 10;
                        cout << "Current score is: " << lifePoints << endl;
                        lastGuessNum = guessNum;
                        cout << "*******************************" << endl;

                    }
                }
                break;


            case changeNumbers:

                do {
                    leftNum = rand() % 100 + 100;
                    rightNum = rand() % 100 + 100;
                } while (leftNum > rightNum);

                cout << "Change numbers." << endl;
                cout << "*******************************" << endl;
                break;


            case quit:
                exit(0);


            default:
                cout << "Not a valid selection, sorry!" << endl;
                cout << "*******************************" << endl;
                break;
        }

        mainMenu();
        cin >> choice;
    }

    cout << "Goodbye, World!" << endl;
    return 0;
}

