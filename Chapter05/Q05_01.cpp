//
//  Q5_1.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/6/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

int updateBits(int n, int m, int i, int j){
    if (j >= 32 || i > j) {
        return 0;
    }
    
    int allOnes = ~0;
    
    int left = allOnes << (j+1);
    int right = (1 << i) - 1;
    int mask = left | right;
    int n_clear = n & mask;
    int m_moved = m << i;
    return n_clear | m_moved;
}

int main(){
    int a = 1024;
    int b = 19;
    int i = 2;
    int j = 6;
    std::cout << "size of int = " << sizeof(a) << std::endl;
    std::cout << "N = " << updateBits(a, b, i, j) << std::endl;
    return 0;
}
