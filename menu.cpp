#include "menu.h"
#include "list.h"
#include "listCount.h"
#include "movie.h"
using namespace std;

void displayMenu() {
    // Main Menu
    cout << "-------------------- Media Log --------------------" << endl;
    cout << "[1] Create New List" << endl;
    cout << "[2] Add to Existing List" << endl;
    cout << "[3] Display Existing List" << endl;
}

void menuLogic(fstream& outputFile, int movieCount) {
    // Get User Selection
    int usrSelection;
    cin >> usrSelection;
    cout << endl;

    // Main Logic
    if (usrSelection == 1) {
        createNewList(outputFile, movieCount);
    }
    else if (usrSelection == 2) {
        addToExistingList(outputFile, movieCount);
    }
    else if (usrSelection == 3) {
        displayList(outputFile);
    }
    else {
        cout << "Please enter a valid response." << endl;
        runProgram();
    }
}

void runProgram() {
    // Streams
    fstream listCount;
    fstream outputFile;

    // Movie Count
    int movieCount = getListCount(listCount);

    displayMenu();
    menuLogic(outputFile, movieCount);

    storeListCount(listCount, movieCount);
}