//
//  mergeSort.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/6/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

void merge(int* a, int* b, int low, int mid, int high){
    int helpleft = low;
    int helpRight = mid + 1;
    int current = low;
    
    while (helpleft <= mid && helpRight <= high) {
        if (a[helpleft] <  a[helpRight]) {
            b[current] = a[helpleft];
            helpleft++;
        }else{
            b[current] = a[helpRight];
            helpRight++;
        }
        current++;
    }
    
    while (helpleft <= mid) {
        b[current] = a[helpleft++];
        current++;
    }
    
    while (helpRight <= high) {
        b[current] = a[helpRight++];
        current++;
    }
    
    for (int k = low; k <= high; k++) {
        a[k] = b[k];
    }
}

void mergesort(int* a, int* b, int low, int high){
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, b, low, mid);
        mergesort(a, b, mid+1, high);
        merge(a, b, low, mid, high);
    }
}

int main(){
    int a[] = {12, 10, 43, 23, -78, 45, 123, 56, 98, 41, 90, 24};
    int num;
    num = sizeof(a) / sizeof(int);
    int b[num];
    mergesort(a, b, 0, num-1);
    for (int i = 0; i < num; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}
