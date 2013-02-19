//
//  Q17_02.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include "../Utility/Random2DArray.cpp"


int checkWin(int** const table, int size){
    // check rows
    for (int c = 1; c <= 2; c++) {
        
        
        for (int i = 0; i < size; i++) {
            bool rowCheck = true;
            for (int j = 0; j < size; j++) {
                if (table[i][j] != c) {
                    rowCheck = false;
                }
            }
            if (rowCheck) {
                return c;
            }
        }
        
        for (int j = 0; j < size; j++) {
            bool colCheck = true;
            for (int i = 0; i < size; i++) {
                if (table[i][j] != c) {
                    colCheck = false;
                }
            }
            if (colCheck) {
                return c;
            }
        }
        
//        if (colCheck || rowCheck) {
//            return c;
//        }
    }
    
    // check diagonal
    for (int c = 1; c <= 2; c++) {
        bool diag = true;
        bool antidiag = true;
        
        for (int i = 0; i < size; i++) {
            if (table[i][i] != c) {
                diag = false;
            }
            if (table[size-1-i][size-1-i] != c) {
                antidiag = false;
            }            
        }
        if (diag || antidiag) {
            return c;
        }
    }
    
    return -1;
}

int main(){
    int rows = 4;
    int cols = 4;
    int **table = new int*[rows];
    for (int i = 0; i < rows; i++) {
        table[i] = new int[cols];
    }
    util::getRandMatrix(table, rows, cols, 0, 2);
    util::print2DMatrix(table, rows, cols);
    
    int success = checkWin(table, rows);
    std::cout << std::endl;
    std::cout << success << " is the result" << std::endl;
    return 0;
}
