//
//  quickSort.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/6/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>

// merge Sort section
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

void merge(int *a, int low, int mid, int high, int n){
    int *helper = new int[n];
    
    for (int i = low; i <= high; i++) {
        helper[i] = a[i];
    }
    
    int helperLeft = low;
    int helperRight = mid + 1;
    int current = low;
    
    while (helperLeft <= mid && helperRight <= high) {
        if (helper[helperLeft] <= helper[helperRight]) {
            a[current] = helper[helperLeft];
            helperLeft++;
        }else{
            a[current] = helper[helperRight];
            helperRight++;
        }
        current++;
    }
    
    int diff = mid-helperLeft;

        for (int i = 0; i <= diff; i++) {
            a[current+i] = helper[helperLeft+i];
        }
    delete [] helper;

}

void mergesort(int *a, int low, int high, int n){
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid, n);
        mergesort(a, mid+1, high, n);
        merge(a, low, mid, high, n);
    }    
}

// quick sort section
int partition(int* arr, int left, int right){
    int pivot = arr[(left + right)/2];
    while (left <= right) {
        while (arr[left] < pivot)
            left++;
        while (arr[right] > pivot) 
            right--;
        
        if (left <= right) {
            int tmp = arr[left];
            arr[left] = arr[right];
            arr[right] = tmp;
            left++;
            right--;
        }
    }
    return left;
}

void quicksort(int *arr, int left, int right){
    int index = partition(arr, left, right);
    if (left < index - 1) {
        quicksort(arr, left, index - 1);
    }
    if (index < right) {
        quicksort(arr, index, right);
    }
}

// bubble sorting section
void bubblesort(int *arr, int arrsize){
    int tmp = 0;
    for (int i = 0; i < arrsize-1; i++) {
        for (int j = 0; j < arrsize - i-1; j++) {
            if (arr[j] > arr[j+1]) {
                tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

// section sorting section
void selectionSort(int *arr, int arrsize){
    int tmp = 0;
    for (int i = 0; i < arrsize; i++) {
        for (int j = i + 1; j < arrsize; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

int main(){
    int a[] = {12, 10, 43, 23, -78, 45, 123, 56, 98, 41, 90, 24};
    int num;
    num = sizeof(a) / sizeof(int);
//    int b[num];
    mergesort(a, 0, num-1, num);
//    mergesort(a, b, 0, num-1);
//    quicksort(a, 0, num-1);
//    bubblesort(a, num);
//    selectionSort(a, num);
    for (int i = 0; i < num; i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}