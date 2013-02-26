//
//  Random2DArray.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//
#ifndef __TestCPPCode__RANDOM2DARRAY__
#define __TestCPPCode__RANDOM2DARRAY__

#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <assert.h>
#include <list>
#include <algorithm>

namespace util {
    // Generate reandom
    template <class T> std::list<T> getRandList(int num, T min, T max ){
        std::list<T> randList;
        T all = max - min;
        std::srand((unsigned int) time(0));
        for (int i = 0; i < num; i++) {
            randList.push_back( (std::rand() % all) + min);
        }
        return randList;
    }
    
    
    // Generate random 2D array section
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
    
    template<class T> void getRandMatrix(T **t, int rows, int cols, T min, T max){
        T diff = std::abs(max - min)+1;
        std::srand(static_cast<unsigned int>(std::time(0)));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                t[i][j] = (std::rand() % diff) + min;
            }
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
    
    // Printing section
    template <class T> void print2DMatrix(T** const t, int rows, int cols){
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << t[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
    template <class T>
    void printList(std::list<T> const &other) {
        typename std::list<T>::const_iterator iter = other.cbegin();
        for (; iter != other.end(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
}

#endif
