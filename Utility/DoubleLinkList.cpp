//
//  DoubleLinkList.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/5/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//
#ifndef __TestCPPCode__DOUBLELINKLIST__
#define __TestCPPCode__DOUBLELINKLIST__

#include <iostream>
#include "Random2DArray.cpp"

template <class T>
class Node {
public:
    Node(T d){
        data = d;
        prev = next = NULL;
    }
    
    // Data section
    T data;
    Node *prev;
    Node *next;
};


template <class T>
class DoubleLinkList {
public:
    inline DoubleLinkList(){
        front = NULL;
        back = NULL;
    }
    
    ~DoubleLinkList(){
        Node<T> *n = back;
        while (n != NULL) {
            Node<T> *n2 = n;
            n = n2->prev;
            delete n2;
        }
        front = NULL;
        back = NULL;
    }
    
    void appendNodeFront(T d){
        Node<T> *n = new Node<T>(d);
        if (front == NULL) {
            front = n;
            back = n;
        }else{
            front->prev = n;
            n->next = front;
            front = n;
        }
        dispNodeForward();
//        std::cout << "Append " << front->data << " ";
    }
    
    void appendNodeBack(T d){
        Node<T> *n = new Node<T>(d);
        if (back == NULL) {
            front = n;
            back = n;
        }else{
            back->next = n;
            n->prev = back;
            back = n;
        }
    }
    
    void dispNodeForward(){
        Node<T> *n = front;
        while (n != NULL) {
            std::cout << n->data << " ";
            n = n->next;
        }
        std::cout << std::endl;
    }
    
    void dispNodeBackward(){
        Node<T> *n = back;
        while (n != NULL) {
            std::cout << n->data << " ";
            n = n->prev;
        }
    }    
    
private:
    Node<T> *front;
    Node<T> *back;
};
#endif