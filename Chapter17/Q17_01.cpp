//
//  Q17_01.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>

template <class T>
void swapFunc(T &a, T &b){
    a = a - b;
    b = a + b;
    a = b - a;
}

int main(){
    std::vector<double> a;
    a.push_back(10);
    a.push_back(15);
    std::cout << "a = " << a[0] << "\t" << "b = " << a[1] << "\t" << std::endl;
    swapFunc(a[0], a[1]);
    std::cout << "a = " << a[0] << "\t" << "b = " << a[1] << "\t" << std::endl;
    return 0;
}
