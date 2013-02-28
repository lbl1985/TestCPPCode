//
//  Q04_04.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/28/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/TreeNode.cpp"
#include "../Utility/Random2DArray.cpp"
#include <algorithm>

template <typename T>
void getLevelList(util::TreeNode<T> *root, int level, std::list< std::list<util::TreeNode<T>* > > &levelList){
    if (root == NULL) {
        return;
    }
    
    if (levelList.size() == level) {
        std::list<util::TreeNode<T>* > tmp;
        tmp.push_back(root);
        levelList.push_back(tmp);
    }else{
        typename std::list< std::list<util::TreeNode<T>* > >::iterator iter = levelList.begin();
        for (int i = 0; i < level; i++) {
            iter++;
        }        
        (*iter).push_back(root);
    }
    
    getLevelList(root->left, level+1, levelList);
    getLevelList(root->right, level+1, levelList);
}

template <typename T>
void myfunction(typename std::list< util::TreeNode<T>*>::const_iterator iter, std::list< util::TreeNode<T>*> &current) {
    if ( (*iter)->left != NULL) {
        current.push_back( (*iter)->left );
    }
    if ( (*iter)->right != NULL ) {
        current.push_back( (*iter)->right );
    }
}

template <typename T>
std::list< std::list<util::TreeNode<T>* > > getLevelList(util::TreeNode<T> *root){
    std::list< std::list<util::TreeNode<T>* > > result;
    std::list< util::TreeNode<T>* > current;
    
    if (root != NULL) {
        current.push_back(root);
    }
    
    while (current.size() > 0) {
        result.push_back(current);
        std::list< util::TreeNode<T>* > parent(current);
        current.clear();
        
        std::for_each(parent.cbegin(), parent.cend(), [&current](util::TreeNode<T>* iter){
            if ( iter->left != NULL) {
                current.push_back( iter->left );
            }
            if ( iter->right != NULL ) {
                current.push_back( iter->right );
            }
        });
        
//        typename std::list< util::TreeNode<T>* >::const_iterator iter = parent.cbegin();
//        for (; iter != parent.cend(); iter++) {
//            if ((*iter)->left != NULL) {
//                current.push_back((*iter)->left);
//            }
//            if ( (*iter)->right != NULL) {
//                current.push_back( (*iter)->right);
//            }
//        }
    }
    return result;
}


int main(){
    //    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    util::TreeNode<int> *root = new util::TreeNode<int>;
    root = root->createMinimalBST(arr, 0, 9);
    
    std::cout << "Display DFS (Inorder)" << std:: endl;
    std::list< util::TreeNode<int>* > s;
    root->getNodesDFSInorder(root, s);
    
    auto iter = s.cbegin();
    for (; iter != s.cend(); iter++) {
        std::cout << (*iter)->data << " ";
    }
    std::cout << std::endl << std::endl; 
    
    std::cout << "Display DFS" << std:: endl;
    root->displayDFS();
    std::cout << std::endl;
    std::cout << "display BFS" << std::endl;
    root->displayBFS();
    
    std::list< std::list< util::TreeNode<int>* > > levelList;
    getLevelList(root, 0, levelList);
    
    for (auto iter = levelList.cbegin(); iter != levelList.cend(); iter++) {
        std::list< util::TreeNode<int>* > tmp = *iter;
        for (auto iter1 = tmp.cbegin(); iter1 != tmp.cend(); iter1++) {
            std::cout << (*iter1)->data << " ";
        }
        std::cout << std::endl;
    }
    
    std::list< std::list< util::TreeNode<int>* > > levelListBFT = getLevelList(root);
    
    std::cout << "display level list BFS" << std::endl;
    
    for (auto iter = levelListBFT.cbegin(); iter != levelListBFT.cend(); iter++) {
        std::list< util::TreeNode<int>* > tmp = *iter;
        for (auto iter1 = tmp.cbegin(); iter1 != tmp.cend(); iter1++) {
            std::cout << (*iter1)->data << " ";
        }
        std::cout << std::endl;
    }
    
    delete root;
    return 0;
}