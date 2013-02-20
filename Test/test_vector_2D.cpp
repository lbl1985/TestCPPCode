//
//  test_vector_2D.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/19/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <vector>
#include <iostream>

int main(){
    std::vector<int> test[2];
    for (int i = 0; i < 5; i++) {
        test[0].push_back(i);
        test[1].push_back(i+10);
    }
    
    for (int i = 0; i < 2; i++) {
        std::cout << "X/Y:" << std::endl;
        for (std::vector<int>::iterator iter = test[i].begin(); iter != test[i].end(); iter++) {
            std::cout << *iter << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}