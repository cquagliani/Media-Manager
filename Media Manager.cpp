// Media Manager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <string>
#include "movie.h"
#include "list.h"
#include "menu.h"
using namespace std;

// Prototypes
void createNewList(fstream&, int&);
void addToExistingList(fstream&, int&);
void displayList(fstream&);
void addMovie(fstream&, int&);
void storeListCount(fstream&, int&);
int getListCount(fstream&);

int main() {
	runProgram();
}