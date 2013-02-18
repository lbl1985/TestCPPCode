//
//  Q_01_07.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <assert.h>

// 1 row vector
template <class T> void getRandMatrix(T* t, int rows){
    std::srand((unsigned int)std::time(0));
    
    for (int i = 0; i < rows; i++) {
        t[i] = (std::rand() % rows) + 1;
    }
}

// 2d matrix
template <class T> void getRandMatrix(T** t, int rows, int cols){
//    int all = rows * cols;
    std::srand((unsigned int)std::time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[i][j] = (std::rand() % 5) + 0;
        }
    }
}

template <class T> void print2DMatrix(T** const t, int rows, int cols){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << t[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T> void fillZeros(T** t, int rows, int cols){
    std::vector<bool> rowRec(rows, false);
    std::vector<bool> colRec(cols, false);
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (t[i][j] == 0) {
                rowRec[i] = true;
                colRec[j] = true;
            }
        }
    }
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowRec[i] | colRec[j]) {
                t[i][j] = 0;
            }
        }
    }
}

int main(){
    const int rows = 4;
    const int cols = 4;
    int **table;
    table = new int* [rows];
    for (int i = 0; i < rows; i++) {
        table[i] = new int[cols];
    }
    
    getRandMatrix(table, rows, cols);
    std::cout << "Generated Matrix: " << std::endl;
    print2DMatrix(table, rows, cols);
    
    fillZeros(table, rows, cols);
    std::cout << "After Zero Filling" << std::endl;
    print2DMatrix(table, rows, cols);
    
    return 0;
}
