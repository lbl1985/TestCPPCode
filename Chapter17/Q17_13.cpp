//
//  Q17_13.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/26/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>
#include <string>

class BiNode {
public:
    BiNode(int _data):data(_data){}
    
    std::shared_ptr<BiNode> node1;
    std::shared_ptr<BiNode> node2;
    int data;
};

class NodePair {    
public:
    NodePair(std::shared_ptr<BiNode> _head, std::shared_ptr<BiNode> _tail):head(_head), tail(_tail){}
    
    std::shared_ptr<BiNode> head;
    std::shared_ptr<BiNode> tail;
};

void concat(std::shared_ptr<BiNode> x, std::shared_ptr<BiNode> y){
    x->node2 = y;
    y->node1 = x;
}

std::shared_ptr<NodePair> covert(std::shared_ptr<BiNode> root){
    if (!root) {
        return std::shared_ptr<NodePair>(0);
    }
    
    std::shared_ptr<NodePair> left = covert(root->node1);
    std::shared_ptr<NodePair> right = covert(root->node2);
    
    if (left) {
        concat(left->tail, root);
    }
    
    if (right) {
        concat(root, right->head);
    }
    
    
    
    return std::shared_ptr<NodePair>(new NodePair(left  ? left->head: root , right ? right->tail : root));
}

std::shared_ptr<BiNode> createTree(){
    std::vector<std::shared_ptr<BiNode> > nodes;

    for (int i = 0; i < 7; i++) {
        nodes.push_back(std::shared_ptr<BiNode>(new BiNode(i)));
    }
    
    nodes[4]->node1 = nodes[2];
    nodes[4]->node2 = nodes[5];
    nodes[2]->node1 = nodes[1];
    nodes[2]->node2 = nodes[3];
    nodes[5]->node2 = nodes[6];
    nodes[1]->node1 = nodes[0];
    return nodes[4];
}

void printLinkedListTree(std::shared_ptr<BiNode> root){
    for (std::shared_ptr<BiNode> node = root; node; node = node->node2) {
        if (node->node2 && node != node->node2->node1) {
            std::cout << "inconsistent node: " << node->data << std::endl;
        }
        std::cout << node->data << " ";
    }
    std::cout << std::endl;
}

void printAsTree(std::shared_ptr<BiNode> root, std::string spaces){
    if (!root) {
        return;
    }
    
    std::cout <<  root->data << " ";
    printAsTree(root->node1, spaces.append("  "));
    printAsTree(root->node2, spaces.append("  "));
}

int main(){
    std::shared_ptr<BiNode> root2(new BiNode(1));
    std::cout << root2->data << std::endl;
    std::shared_ptr<BiNode> root = createTree();
    printAsTree(root, "");
    std::cout << std::endl;
    std::shared_ptr<NodePair> n = covert(root);
    printLinkedListTree(n->head);
    return 0;
}