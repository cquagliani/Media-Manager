#include "list.h"
#include "movie.h"
#include "menu.h"
using namespace std;

void createNewList(fstream& outputFile, int& movieCount) {
    int mediaType;
    int numEntries;
    char overwrite;
    string media[4] = { "movies", "TV shows", "video games", "books" };

    cout << "Are you sure? You will overwrite any previous lists. (Y/N): ";
    cin >> overwrite;
    cout << endl;

    if (overwrite == 'Y' || overwrite == 'y') {
        outputFile.open("Rating.txt", ios::out);

        movieCount = 1; // resets the length of the list for proper numbering in the .txt file and output
        cout << "Please select the type of media you wish to log: " << endl;
        cout << "[1] Movie" << endl;
        cout << "[2] TV Show" << endl;
        cout << "[3] Video Game" << endl;
        cout << "[4] Book" << endl;

        cin >> mediaType;
        cout << endl;

        cout << "How many " << media[mediaType - 1] << " would you like to enter? ";
        cin >> numEntries;
        cout << endl;

        if (outputFile.is_open()) {

            switch (mediaType) {
            case 1:
                outputFile << "-------------------- Movie Rating Log --------------------" << endl;
                break;
            case 2:
                outputFile << "-------------------- TV Show Rating Log --------------------" << endl;
                break;
            case 3:
                outputFile << "-------------------- Video Game Rating Log --------------------" << endl;
                break;
            case 4:
                outputFile << "-------------------- Book Rating Log --------------------" << endl;
                break;
            default:
                cout << "Please select a valid media type." << endl;
                createNewList(outputFile, movieCount);
                break;
            }

            for (int i = 0; i < numEntries; i++) {
                addMovie(outputFile, movieCount);
            }
            outputFile.close();
        }
        else {
            cout << "Unable to open file." << endl;
        }
    }
    else if (overwrite == 'N' || overwrite == 'n') {
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