//
//  Q17_08.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/20/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <list>
#include <iostream>

template <class T>
T getMaxSum(std::list<T> const l){
    size_t s = l.size();
    if (s == 0) {
        return NULL;
    }
    int sum = 0;
    int maxsum = 0;
    
    for (auto iter = l.cbegin(); iter != l.cend(); iter++) {
        sum += *iter;
        if (maxsum < sum) {
            maxsum = sum;
        }else if (sum < 0){
            sum = 0;
        }
    }
    return maxsum;
}

int main(){
    int data[] = {2, -8, 3, -2, 4, -10};
    std::list<int> l(data, data + sizeof(data) / sizeof(int));
    
    int maxsum = getMaxSum(l);
    std::cout << "maxsum is: " << maxsum << std::endl;
}