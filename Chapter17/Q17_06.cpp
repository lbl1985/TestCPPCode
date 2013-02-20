//
//  Q17_06.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/20/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>

template <class T>
bool getIndex(std::vector<T> data, int &start, int &end) {
    size_t s = data.size();
    // invaidate situation
    if (s <= 0) {
        return false;
    }
    
    int leftAnchor = data[0];
    int rightAnchor = data[s-1];
    
    start = 1; end = s-2;
    while (start < s && leftAnchor <= data[start]) {
        leftAnchor = data[start++];
    }
    leftAnchor = data[start];
    
    // Already sorted list
    if (start == (s-1)) {
        start = -1; end = -1;
        return true;
    }
    
    while (end > 0 && rightAnchor >= data[end]) {
        rightAnchor = data[end--];
    }
    rightAnchor = data[end];    
    
    
    start = start -1; end = end + 1;
    while (start >= 0) {
        if (leftAnchor < data[start]) {
            start--;
        }else{
            break;
        }
    }
    start++;
    
    while (end < s) {
        if (rightAnchor > data[end] ) {
            end++;
        }else{
            break;
        }
    }
    end--;
    
    return true;
}


int main(){
//    int data[] = {1, 2, 3, 4, 5, 3, 7, 9, 8, 12, 13, 14}; // start: 3 end: 8
//    int data[] = {1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19}; // start: 4 end: 9
    int data[] = {1, 2, 3, 4, 5, 11, 7, 12, 6, 7, 16, 18, 19}; // start: 5 end: 9
    std::vector<int> dataVect(data, data + sizeof(data) / sizeof(int));
    int start;
    int end;
    if (getIndex(dataVect, start, end)) {
        std::cout << "start: " << start << " end: " << end << std::endl;
    }
    return 0;
}
