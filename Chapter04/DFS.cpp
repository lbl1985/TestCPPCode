//
//  DFS.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/5/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <iostream>
#include <ctime>

class node{
public:
    node(){
        next = NULL;
    }
    node(int d){
        info = d;
        next = NULL;
    }
    node & operator = (const node &other){
        if (this == &other) {
            return *this;
        }
        info = other.info;
        next = other.next;
        return *this;
    }
    int info;
    node *next;
};

class stack{
public:
    stack(){
        top = NULL;
    }
    void push(int d){
        node *p = new node(d);
        if (top != NULL) {
            // stack new item on top
            p->next = top;
        }
        top = p;        
    }
    
    int pop(){
        node *tmp;
        int value;
        if (top == NULL) {
            throw("\n The stack is empty\n");
        }else{
            tmp = top;
            top = top->next;
            value = tmp->info;
            delete tmp;
        }
        return value;        
    }
    
    bool isEmpty(){
        return top == NULL;
    }
    
    void display(){
        node *tmp = top;
        while (tmp != NULL) {
            std::cout << tmp->next->info << " ";
            tmp = tmp->next;
        }
        std::cout << std::endl;
    }
private:
    node *top;
};

class Graph {
private:
    int n;
    int **A;
public:
    Graph(int size = 2);
    ~Graph();
    bool isConnected(int x, int y);
    void addEdge(int x, int y);
    bool DFS(int x, int y);
};

Graph::Graph(int size){
    if (size < 2) {
        n = 2;
    }else{
        n = size;
    }
    A = new int*[n];
    for (int i = 0; i < n; i++) {
        A[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
}

Graph::~Graph(){
    for (int i = 0; i < n; i++) {
        delete [] A[i];
    }
    delete [] A;
}

bool Graph::isConnected(int x, int y){
    return (A[x-1][y-1] == 1);
}

void Graph::addEdge(int x, int y){
    A[x-1][y-1] = 1;
}

bool Graph::DFS(int x, int required){
    // Here the x is 1 based
    // The inner data A is 0 based
    stack s;
    bool *visited = new bool[n+1];
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
    }
    s.push(x);
    visited[x] = true;
    if (x == required) {
        return true;
    }
    while (!s.isEmpty()) {
        int k = s.pop();
        if (k == required) {
            return true;
        }
        for (int i = n; i > 0; i--) {
            if (!visited[i] && isConnected(k, i)) {
                s.push(i);
                visited[i] = true;
            }
        }
    }
    delete [] visited;
    return false;
}

int main(){
    Graph g(8);
    g.addEdge(1, 2); g.addEdge(1, 3); g.addEdge(1, 4);
    g.addEdge(2, 5); g.addEdge(2, 6); g.addEdge(4, 7);
    g.addEdge(4, 8);
    std::cout << "1 and 4 connected: " << g.DFS(6, 8) << std::endl;
    
    
    
//    std::srand((unsigned int)std::time(0));
//    int value = 0;
//    stack s;
//    std::cout << "random generated data: " << std::endl;
//    for (int i = 0; i < 10; i++) {
//        value = (int)(rand() % 10) + 1;
//        s.push(value);
//        std::cout << value << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "poping data" << std::endl;
//    for (int i = 0; i < 10; i++) {
//        std::cout << s.pop() << " ";
//    }
    return 0;
}