// EightQueens.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

//The array queens[] is used to record every queue's location 
//Eg. queens[m]=n means there is a queen on row m, column n 

const int MAX = 8;

int sum = 0;

class QueenPuzzle
{
    int queens[MAX];
public:

    void printOut();
    int IsValid(int n); //Determine if the nth queen is valid 
    void placeQueen(int i);
};

void QueenPuzzle::printOut() {

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            if (j == queens[i])
                cout << "Q ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    cout << endl << "Please press 'q' key to quit, otherwise continue..." << endl;

    char k = '\0';
    cin >> k;

    if (k == 'q')
        exit(0);
}

void QueenPuzzle::placeQueen(int i) {

    //1. you need to implement this function using back-tracking
    //2. when a solution is obtained, please invoke printOut() to display it
    //3. you need to call IsValid() to determine whether you can legally place a queen in the current cell
    //4. you need to use placeQueen() to place a queen on the keyboard
    // Base case: if all 8 queens are placed

    if (i == MAX) {// 8 queens are placed successfully
        printOut();  
        return;
    }

    // Try placing queen in every column of row i
    for (int col = 0; col < MAX; col++) { // Try placing queen in column col of row i

        queens[i] = col;   // Place queen at row i, column col

        // Check if current placement is valid
        if (IsValid(i)) {

            // Recursively place next queen
            placeQueen(i + 1);
        }
    }
}


int QueenPuzzle::IsValid(int n) {

    //compare the queen n withe privous n-1 queens to test whether the current place is workable
    
    for (int i = 0; i < n; i++) {
        // Check if queens are in the same column
        if (queens[i] == queens[n]) {
            return 0; // 0 means conflict
        }
        // Check if queens are on the same diagonal
        if (abs(queens[i] - queens[n]) == abs(i - n)) {
            return 0; // 0 means conflict
        }
    }
    return 1; // 1 means no conflict 
}


int main() {

    QueenPuzzle queen;
    queen.placeQueen(0);

}