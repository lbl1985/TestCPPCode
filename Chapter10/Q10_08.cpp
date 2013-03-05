//
//  Q10_08.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 3/1/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

class RankNode {
public:
    RankNode(int _d):d(_d), left(NULL), right(NULL), leftNum(0){}
    ~RankNode(void);
    
    void insert(int _d);
    int getRank(int _d);
    void traverseInOrder(void);
    
    int leftNum;
    RankNode *left;
    RankNode *right;
    int d;
};

RankNode::~RankNode(){
    if (NULL != left) {
        delete left;
        left = NULL;
    }
    if (NULL != right) {
        delete right;
        right = NULL;
    }
}

void RankNode::insert(int _d){
    if (_d <= d) {
        if (left != NULL) {
            left->insert(_d);
        }else{
            left = new RankNode(_d);
        }
        leftNum++;
    }else{
        if (right != NULL) {
            right->insert(_d);
        }else{
            right = new RankNode(_d);
        }
    }
}

int RankNode::getRank(int _d){
    if (d == _d) {
        return leftNum;
    }else if (_d < d){
        if (NULL == left) {
            return -1;
        }
        return left->getRank(_d);
    }else{
        int rightNum = right == NULL ? -1 : right->getRank(_d);
        if (rightNum == -1) {
            return -1;
        }else{
            return leftNum + 1 + rightNum;
        }
        
    }
}

void RankNode::traverseInOrder(void){
    if (NULL != this->left) {
        this->left->traverseInOrder();
    }
    
    std::cout << d << " ";
    
    if (NULL != this->right) {
        this->right->traverseInOrder();
    }
    
}

int main(){
    RankNode *root = NULL;
    int a[] = { 3, 1, 5, 6, 2, 9, 7};
    
    std::for_each(a, a+sizeof(a)/sizeof(int), [&root](int a){
        if (NULL == root) {
            root = new RankNode(a);
        }else{
            root->insert(a);
        }
    });
    
    root->traverseInOrder();
    std::cout << std::endl;
    
    int x = 8;
    std::cout << "rank of " << x << " is: " << root->getRank(x) << std::endl;
    
    std::cout << std::endl;
    
//    int a = 3; int b = 5;
//    int m = 0;
//    while (a & 1) {
//        m += b;
//        a >>= 1;
//        b <<= 1;
//    }
//    std::cout << m << std::endl;
//    
}
