//
//  CheckTreeBinary.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <algorithm>
struct node{
    int n;
    node *left, *right;
};

node *newnode(int n){
    node *np = new node;
    np->n = n;
    np->left = NULL;
    np->right = NULL;
    return np;
}

void insert(node* &root, node *np){
    if(root == NULL)
    {
        root = np;
        return;
    }
    if (root->n > np->n) {
        if (root->left == NULL) {
            root->left = np;
        }else{
            insert(root->left, np);
        }
        
    }else{
        if(root->right == NULL){
            root->right = np;
        }else{
            insert(root->right, np);
        }

    }
}

void inorder(node* nd){
    if (nd == NULL) {
        return;
    }
    inorder(nd->left);
    std::cout<< nd->n << " ";
    inorder(nd->right);
}

int checkHeight(node* root){
    if(root == NULL) return 0;
    
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1;
    }
    
    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1){
        return -1;
    }
    
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }else{
        return std::max(leftHeight, rightHeight) + 1;
    }
}

bool isBalanced(node* root){
    if(checkHeight(root) == -1){
        return false;
    }else{
        return true;
    }
}

int main(){
    int a[] = {5,2,4,7,8,2,4,67,9,2,3,56}, n = 12;
    //int a[] = {5, 3, 4, 2, 1, 8, 10, 6, 9}, n = 9;
    node *root = NULL;
    
    for (int i = 0; i < n; i++) {
        insert(root, newnode(a[i]));
    }
    inorder(root); std::cout << std::endl;
    
    std::cout << "Is Balanced: " << isBalanced(root) << std::endl;
    
    
}
