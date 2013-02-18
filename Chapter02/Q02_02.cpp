//
//  Q2_2.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <list>
#include "Random2DArray.cpp"

template <class T>
typename std::list<T>::const_iterator findLastK(std::list<T> const &list, const int K) {
    typename std::list<T>::const_iterator anchor = list.cbegin();
    typename std::list<T>::const_iterator runner = list.cbegin();
    int i = 0;
    while (runner != list.end() && i <= K) {
        runner++;
        i++;
    }
    
    if (i <= K) {
        return list.cbegin();
    }
    
    while (runner != list.end()) {
        anchor++;
        runner++;
    }
    return anchor;
}

class Node {    
public:
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int d){
        data = d;
        next = NULL;
    }
    Node( const Node* &n){
        data = n->data;
        next = n->next;
    }
    // Data section
    int data;
    Node *next;
};

class ListNode{
private:
    Node *front;
    Node *back;
public:
    ListNode(){
        front = NULL;
        back = NULL;
    }
    ~ListNode(){
        Node *tmp = front;
        while (tmp != NULL) {
            Node *tmp2(tmp);
            tmp = tmp->next;
            delete tmp2;
        }
    }
    void append(int d){
        Node *newNode = new Node(d);
        if (NULL == back) {
            front = newNode;
            back = newNode;
        }else{
            back->next = newNode;
            back = newNode;
        }
    }
    
    Node *getFront(void) const{
        return front;
    }
    
    void printForward(){
        Node *tmpNode = front;
        while (tmpNode != NULL) {
            std::cout << tmpNode->data << " ";
            tmpNode = tmpNode->next;
        }
    }
};

bool findLastK(const ListNode &ln, Node *(&begin), int K){
    begin = ln.getFront();
    Node *runner = begin;
    
    for(int i = 0; i < K; i++){
        if (runner == NULL) {
            return false;
        }else{
            runner = runner->next;
        }
    }
    
    if (runner == NULL) {
        return false;
    }
    
    while (runner != NULL) {
        begin = begin->next;
        runner = runner->next;
    }
    return true;
}

Node *findLastK2(const ListNode &ln, int K){
    Node *begin = ln.getFront();
    Node *runner = begin;
    
    for(int i = 0; i < K; i++){
        if (runner == NULL) {
            return NULL;
        }else{
            runner = runner->next;
        }
    }
    
    if (runner == NULL) {
        return NULL;
    }
    
    while (runner != NULL) {
        begin = begin->next;
        runner = runner->next;
    }
    return begin;
}

Node *findLastK3(Node *root, int K){
    if (root == NULL) {
        return NULL;
    }
    
    Node *begin = root;
    Node *runner = root;
    
    for(int i = 0; i < K; i++){
        if (runner == NULL) {
            return NULL;
        }else{
            runner = runner->next;
        }
    }
    
    if (runner == NULL) {
        return NULL;
    }
    
    while (runner != NULL) {
        begin = begin->next;
        runner = runner->next;
    }
    return begin;
}


int main(){
    
    std::list<int> list_int1 = util::getRandList(5, 0, 9);
    std::cout << "list_int 1: " << std::endl;
    util::printList(list_int1);
    //    std::cout << *findLastK(list_int1, 3) << std::endl;
    
    
    std::list<int>::const_iterator citer = list_int1.cbegin();
    ListNode ln;
    for (int i = 0; i < 5; i++) {
        ln.append(*citer++);
    }
    ln.printForward();
    Node *p = NULL;
    findLastK(ln, p, 3);
    std::cout << "test: " << std::endl;
    std::cout << findLastK2(ln, 3)->data << std::endl;
    std::cout << "test2: " << std::endl;
    std::cout << findLastK3(ln.getFront(), 3)->data << std::endl;
    
    return 0;
}
