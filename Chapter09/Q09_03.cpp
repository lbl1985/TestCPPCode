//
//  Q9_3.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/3/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>


int magicFast(const std::vector<int>& array, int start, int end){
    if (end < start || start < 0 || end >= array.size()) {
        return -1;
    }
    
    int mid = (start + end) / 2;
    if (array[mid] == mid) {
        return mid;
    }
    
    int leftEnd = std::min(mid-1, array[mid]);
    int left = magicFast(array, start, leftEnd);
    if (left >= 0) {
        return left;
    }
    
    int rightStart = std::max(mid+1, array[mid]);
    int right = magicFast(array, rightStart, end);
    return right;
    
}

int main(){
//    int array[] = {-10, -5, 2, 2, 2, 3, 4, 7, 9, 12, 13};
//    int array[] = {-40, -20, -1, 1, 2, 3, 5, 7, 9, 12, 13};
    int array[] = {-40, -20, -1, 1, 2, 3, 5, 8, 9, 12, 13};
    std::vector<int> arr(array, array + sizeof(array) / sizeof(int));
    std::cout << "magic index is: " << magicFast(arr, 0, ((int)arr.size()-1));
}

