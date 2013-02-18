//
//  Q1_6.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

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
    int all = rows * cols;
    std::srand((unsigned int)std::time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            t[i][j] = (std::rand() % all) + 1;
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

template <class T> void tranpost90(T** const t, int rows, int cols){
    assert(rows == cols);
    int n = rows;
    T temp;
    for (int layer = 0; layer < (n/2); layer++) {
        int first = layer;
        int last = n - layer - 1;
        for (int i = first; i < last; i++) {
            int offset = i - first;
            temp = t[first][i];
            t[first][i] = t[last-offset][first]; // left to top
            t[last-offset][first] = t[last][last-offset]; // bottom to left
            t[last][last-offset] = t[i][last]; // right to bottom
            t[i][last] = temp;
        }
    }
}

int main(){
    const int rows = 3;
    const int cols = 3;

    int *table1D = new int[cols];
    int **table2D;
    table2D = new int*[rows];
    for (int i = 0; i < rows; i++) {
        table2D[i] = new int[cols];
    }
    
    // 1D matrix testing
    getRandMatrix(table1D, rows);
    for (int i = 0; i < cols; i ++) {
        std::cout << table1D[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "2D random generation" << std::endl;
    // 2D matrix testing
    getRandMatrix(table2D, rows, cols);
    print2DMatrix(table2D, rows, cols);
    
    std::cout << "After Translation" << std::endl;
    tranpost90(table2D, rows, cols);
    print2DMatrix(table2D, rows, cols);
    
    delete [] table1D;
    delete [] table2D;
    return 0;
}