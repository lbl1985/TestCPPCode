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
        std::list< TreeNode<T>* > getNodesDFS(std::string mode);
        
        void getNodesDFSPreorder( TreeNode<T>* root, std::list< TreeNode<T>* > &s);
        void getNodesDFSInorder( TreeNode<T>* root, std::list< TreeNode<T>* > &s);
        void getNodesDFSPostorder( TreeNode<T>* root, std::list< TreeNode<T>* > &s);
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
            
            treeList.push_back(k);
            
            if (k->left != NULL && k->left->st != Visited) {
                s.push(k->left);
                k->left->st = Visiting;
            }
            k->st = Visited;
//            treeList.push_back(k);
        }
        return treeList;
    }
    
    template <class T> std::list< TreeNode<T>* > TreeNode<T>::getNodesDFS(std::string mode){
        std::list< TreeNode<T>* > treeList;
        if (mode.compare("preorder") == 0) {
            getNodesDFSPreorder(this, treeList);
        }else if (mode.compare("inorder") == 0){
            getNodesDFSInorder(this, treeList);
        }else if (mode.compare("postorder") == 0){
            getNodesDFSPostorder(this, treeList);
        }else{
            throw("ONLY preorder, inorder and postorder is defined for DFS traverse");
        }
        return treeList;
    }
    
    template<class T> void TreeNode<T>::getNodesDFSPreorder(TreeNode<T> *root, std::list< TreeNode<T>* > &s){
        if (root != NULL) {
            s.push_back(root);
            getNodesDFSPreorder(root->left, s);
            getNodesDFSPreorder(root->right, s);
        }
    }
    
    template<class T> void TreeNode<T>::getNodesDFSInorder(TreeNode<T> *root, std::list< TreeNode<T>* > &s){
        if (root != NULL) {
            getNodesDFSInorder(root->left, s);
            s.push_back(root);
            getNodesDFSInorder(root->right, s);
        }
    }
    
    template<class T> void TreeNode<T>::getNodesDFSPostorder(TreeNode<T> *root, std::list< TreeNode<T>* > &s){
        if (root != NULL) {
            getNodesDFSPostorder(root->left, s);
            getNodesDFSPostorder(root->right, s);
            s.push_back(root);
        }
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
int main(){
//    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    util::TreeNode<int> *root = new util::TreeNode<int>;
    root = root->createMinimalBST(arr, 0, 9);
    std::cout << "Display DFS" << std:: endl;
    
    std::list< util::TreeNode<int>* > s;
    root->getNodesDFSPostorder(root, s);
    
    auto iter = s.cbegin();
    for (; iter != s.cend(); iter++) {
        std::cout << (*iter)->data << " ";
    }
    std::cout << std::endl;
    
    std::cout << std::endl;
    root->displayDFS();
    std::cout << std::endl;
    std::cout << "display BFS" << std::endl;
    root->displayBFS();
    delete root;
    return 0;
}