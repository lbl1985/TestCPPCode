//
//  Q4_3.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/5/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//
#ifndef __TestCPPCode__TREENODE__
#define __TestCPPCode__TREENODE__

#include <iostream>
#include <list>
#include <stack>
#include <queue>

namespace util {
    enum Status {UnVisisted, Visited, Visiting};
    
    template <class T>
    class TreeNode{
    public:
        TreeNode<T>(){
            left = NULL;
            right = NULL;
            st = UnVisisted;
        }
        TreeNode<T>(T d){
            data = d;
            left = NULL;
            right = NULL;
            st = UnVisisted;
        }
        TreeNode<T> & operator = (const TreeNode<T> &other){
            if (this == &other) {
                this = other;
            }
            data = other.data;
            left = other.left;
            right = other.right;
            st = other.st;
        }
        // Fancy operations
        TreeNode<T>* createMinimalBST(T* const arr, int start, int end);
        
        // Utility funnctions
        std::list< TreeNode<T>* > getNodesDFS(void);
        std::list< TreeNode<T>* > getNodesBFS(void);
        //    void setStatus(Status s); // set status for all nodes
        void displayDFS(void);
        void displayBFS(void);
        
        
        // Data section
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;
        Status st;
    };
    
    template <class T> TreeNode<T>* TreeNode<T>::createMinimalBST(T* const arr, int start, int end){
        if (start > end) {
            return NULL;
        }
        int midIndex = (start + end) / 2;
        int midValue = arr[midIndex];
        
        TreeNode<T> *root = new TreeNode<T>(midValue);
        root->left = createMinimalBST(arr, start, midIndex - 1);
        root->right = createMinimalBST(arr, midIndex + 1, end);
        return root;
    }
    
    template <class T> std::list< TreeNode<T>* > TreeNode<T>::getNodesDFS(){
        // DFS traverse the whole tree
        std::list< TreeNode<T>* > treeList;
        std::stack< TreeNode<T>* > s;
        
        this->st = Visited;
        s.push(this);
        
        while (!s.empty()) {
            TreeNode<T>* k = s.top();
            s.pop();
            if (k->right != NULL && k->right->st != Visited) {
                s.push(k->right);
                k->right->st = Visiting;
            }
            if (k->left != NULL && k->left->st != Visited) {
                s.push(k->left);
                k->left->st = Visiting;
            }
            k->st = Visited;
            treeList.push_back(k);
        }
        return treeList;
    }
    
    template <class T> std::list< TreeNode<T>* > TreeNode<T>::getNodesBFS(){
        std::list< TreeNode<T>* > treeList;
        std::queue< TreeNode<T>* > q;
        
        q.push(this);
        TreeNode<T>* k;
        while (!q.empty()) {
            k = q.front();
            q.pop();
            if (k->left != NULL) {
                q.push(k->left);
            }
            if (k->right != NULL) {
                q.push(k->right);
            }
            treeList.push_back(k);
        }
        return treeList;
    }
    
    template <class T>
    void TreeNode<T>::displayDFS(void) {
        // DFS for traverse the tree
        std::list<TreeNode<T>* > tmpList = TreeNode<T>::getNodesDFS();
        typename std::list<TreeNode<T>* >::iterator iter = tmpList.begin();
        while (iter != tmpList.end()) {
            std::cout << (*(iter++))->data << " ";
        }
        std::cout << std::endl;
        
    }
    
    template <class T>
    void TreeNode<T>::displayBFS(void) {
        std::list< TreeNode<T>* > tmpList = TreeNode<T>::getNodesBFS();
        typename std::list< TreeNode<T>* >::iterator iter = tmpList.begin();
        while (iter != tmpList.end()) {
            std::cout << (*(iter++))->data << " ";
        }
        std::cout << std::endl;
    }
}
#endif

// Testing main function
//int main(){
////    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
//    TreeNode<int> *root = new TreeNode<int>;
//    root = root->createMinimalBST(arr, 0, 10);
//    std::cout << "Display DFS" << std:: endl;
//    root->displayDFS();
//    std::cout << std::endl;
//    std::cout << "display BFS" << std::endl;
//    root->displayBFS();
//    delete root;
//    return 0;
//}