#include "listCount.h"
using namespace std;

// Updates the length of the list (listCount) in the listCount.txt file
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

// Returns the length of the list stored in the listCount.txt file
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