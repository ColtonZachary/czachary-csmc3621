#include <iostream>

using namespace std;

const int row = 4;
const int col = 5;

void display(int ** matrix){ 

    // This function is used to output a matrix
    // You are NOT allowed to use 'index' to access the elements in this 2D array.
    // Therefore, if you use any [] in this part, you will get 0
    // To Do (3 points)
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << *(*(matrix + i) + j) << " ";
        }
        cout << endl;
    }
}

int ** createMatrix(){ 

    // Please first create a matrix, and the shape is row*col
    // To Do (2 points)
    int ** matrix = new int*[row];

    for(int i = 0; i < row; i++){
        *(matrix + i) = new int[col];
    }
    
    // Please initialize the matrix using the following values
    // 11, 21, 31, 41, 51
    // 12, 22, 32, 42, 52
    // 13, 23, 33, 43, 53
    // 14, 24, 34, 44, 54 
    // To Do (2 points)
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            *(*(matrix + i) + j) = (j + 1) * 10 + (i + 1);
        }
    }


    return matrix; 
} 


int main() {
	
	int ** my_matrix = createMatrix();
	
	cout<<endl;
	
	display(my_matrix);
	
	// Destroy the new established matrix. 
	// In other words, you are to completely release the allcoated memeory space.
	// To Do (3 points)
    // free memory
	for(int i = 0; i < row; i++){
        delete[] *(my_matrix + i);
    }

    delete[] my_matrix;

	return 0;
}
	
