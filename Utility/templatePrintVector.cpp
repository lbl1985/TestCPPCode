//
//  main.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 1/29/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
void printVector(std::vector<T> myv){
    for(typename std::vector<T>::iterator it = myv.begin(); it != myv.end(); ++it)
        std::cout <<  " " << *it;
    std::cout << "\n";
}

int main(int argc, const char * argv[])
{

    std::vector<int> myvector;
    for(int i=1; i< 20; i++) myvector.push_back(20-i);
    printVector(myvector);
    std::random_shuffle(myvector.begin(), myvector.end());
    
    printVector(myvector);
    
    std::nth_element(myvector.begin(), myvector.begin()+3, myvector.end());
    printVector(myvector);
    
    return 0;
}

