//
//  Q04_03.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/27/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include "../Utility/Random2DArray.cpp"

class Node {
public:
    Node(int d):data(d){}
    int data;
    Node *left;
    Node *right;
};

Node* arrToTree(int *arr, int start, int end){
    if (end < start) {
        return NULL;
    }
    
    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    
    root->left = arrToTree(arr, start, mid - 1);
    root->right = arrToTree(arr, mid + 1, end);
    return root;
}

int main(){
    int size = 10;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
//    util::getRandMatrix(arr, size);
    
    Node *root = arrToTree(arr, 0, size-1);
    
    std::cout << root->data << std::endl;
    return 0;
}