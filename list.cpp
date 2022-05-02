#include "list.h"
#include "movie.h"
#include "menu.h"
using namespace std;

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
        runProgram();
    }
    else {
        cout << "Please enter a valid response." << endl;
        runProgram();
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