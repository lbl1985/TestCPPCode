//
//  webTest.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/5/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

// multiple two integer values without using * operator
int mul(int a, int b){
    int sign = ((a ^ b) >> 31);
    a = abs(a);
    b = abs(b);
    int sum = 0;
    
    while (b) {
        if (b & 0x01) {
            sum += a;
        }
        b >>= 1;
        a <<= 1;
    }
    return sign? ~sum + 1 : sum;
    
}


#include <vector>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <algorithm>

typedef std::unordered_map<int, int > hashmap;

// finding the most frequent number within a number array
class MajorityElement{
public:
    static int mode(int *myArray, int size){
        hashmap h;  // hashmap with key for number and element for count
        for(int i = 0; i < size; i++){
            int curr = myArray[i];
            if (h.find(curr) != h.end()){
                h[curr]++;   // if curr has been showed up before, count adding
            }else{
                h[curr] = 1;  // if curr has not been showed up before, adding new element
            }
        }
        
        int maxNum;
        int maxFeq = 0;
        for(auto &x: h){
            if (x.second > maxFeq){
                maxNum = x.first;
                maxFeq = x.second;
            }
        }
        
        return maxNum;
    }
};

int main(){
    int a = 2;
    int b = 4;
    std::cout << mul(a, b) << std::endl;
    
    int myArray[] = {9, 3, 2, 11, 87, 4, 3, 9, 21, 11, 91, 11, 9, 2, 9};
    std::cout << MajorityElement::mode(myArray, 15) << std::endl;
}
