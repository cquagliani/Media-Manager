// Media Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototypes
void createNewList(fstream&, int&);
void addToExistingList(fstream&, int&);
void displayList(fstream&);
void addMovie(fstream&, int&);
void storeListCount(fstream&, int&);
int getListCount(fstream&);

// Movie Class
class Movie {
public:
    std::string title = "NoTitle";
    int yearReleased = -1;
    std::string genre = "NoGenre";
    double rating = -1;
};

int main() {
    // Streams
    fstream listCount;
    fstream outputFile;

    // Movie Count
    int movieCount = getListCount(listCount);

    // Main Menu
    int usrSelection;
    cout << "-------------------- Movie Rating Log --------------------" << endl;
    cout << "[1] Create New List" << endl;
    cout << "[2] Add to Existing List" << endl;
    cout << "[3] Display Existing List" << endl;
    cout << "----------------------------------------------------------" << endl;
    cin >> usrSelection;

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
        main();
    }
    storeListCount(listCount, movieCount);
}

void createNewList(fstream& outputFile, int& movieCount) {
    int numEntries;
    char overwrite;
    cout << "Are you sure? You will overwrite any previous lists. (Y/N): ";
    cin >> overwrite;

    if (overwrite == 'Y') {
        movieCount = 1;
        cout << "How many movies would you like to enter? ";
        cin >> numEntries;
        cout << endl;

        outputFile.open("Rating.txt", ios::out);

        if (outputFile.is_open()) {
            outputFile << "-------------------- Movie Rating Log --------------------" << endl;
            for (int i = 0; i < numEntries; i++) {
                addMovie(outputFile, movieCount);
            }
            outputFile.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
    else if (overwrite == 'N') {
        main();
    }
    else {
        cout << "Please enter a valid response." << endl;
        main();
    }
}

void addToExistingList(fstream& outputFile, int& movieCount) {
    int numEntries;
    cout << "How many movies would you like to add? ";
    cin >> numEntries;
    cout << endl;

    outputFile.open("Rating.txt", ios::app);

    if (outputFile.is_open()) {
        for (int i = 0; i < numEntries; i++) {
            addMovie(outputFile, movieCount);
        }
        outputFile.close();
    }
    else {
        cout << "Unable to open file." << endl;
    }
}

void displayList(fstream& outputFile) {
    string data;
    outputFile.open("Rating.txt");
    if (outputFile.is_open()) {
        while (getline(outputFile, data)) {
            cout << data << endl;
        }
        outputFile.close();
    }
}

void addMovie(fstream& outputFile, int& movieCount) {
    Movie myMovie;
    cout << "Movie Title: ";
    cin.ignore();
    getline(cin, myMovie.title);
    outputFile << "[" << movieCount << "]" << "  Movie Title: " << myMovie.title << endl;

    cout << "Year Released: ";
    cin >> myMovie.yearReleased;
    outputFile << "     Year Released: " << myMovie.yearReleased << endl;

    cout << "Genre: ";
    cin.ignore();
    getline(cin, myMovie.genre);
    outputFile << "     Genre: " << myMovie.genre << endl;

    cout << "Your Rating (1-10): ";
    cin >> myMovie.rating;
    outputFile << "     Your Rating: " << myMovie.rating << endl;

    outputFile << "----------------------------------------------------------" << endl;
    cout << endl;
    movieCount += 1;
}

// Updates the listCount in the listCount.txt file
void storeListCount(fstream& listCount, int& movieCount) {
    listCount.open("listCount.txt");

    if (listCount.is_open()) {
        listCount << movieCount;
        listCount.close();
    }
    else {
        cout << "Unable to open the file." << endl;
    }
}

// Returns listCount stored in the listCount.txt file
int getListCount(fstream& listCount) {
    listCount.open("listCount.txt", ios::in);

    int intCount{};
    if (listCount.is_open()) {
        string strCount;
        // Assign top line of file to strCount
        getline(listCount, strCount);
        // Convert to int
        intCount = atoi(strCount.c_str());
        listCount.close();
    }
    else {
        cout << "Unable to open file." << endl;
        return 0;
    }
    return intCount;
}