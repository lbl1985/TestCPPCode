//
//  DoubleLinkList_sharedPointer.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/10/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#ifndef __TestCPPCode__DOUBLELINKLIST_SHAREDPOINTER__
#define __TestCPPCode__DOUBLELINKLIST_SHAREDPOINTER__

#include <iostream>
#include <memory>
#include "Random2DArray.cpp"

namespace util {
    template <class T>
    class Node{
    public:
        // method section
        inline Node(T d){
            data = d;
        }
        // Data Section
        T data;
        std::shared_ptr< Node <T> > prev;
        std::shared_ptr< Node <T> > next;
    };
    
    template <class T>
    class DoubleLinkList {
        
           
    public:
        ~DoubleLinkList(void){
            std::shared_ptr< Node<T> > n = front;
            while (n) {
                std::shared_ptr< Node<T> > n2 = n;
                n = n2->next;
                n2->prev.reset();
                n2->next.reset();
                n2.reset();
                
            }
            front.reset();
            back.reset();
//            std::cout << "DoubleLinkList::~DoubleLinkList()" << std::endl;
        }
        
        // obtain the begin of the list like std::list l; l.begin()
        std::shared_ptr< Node<T> > begin(){
            return front;
        }
        
        std::shared_ptr< Node<T> > end(){
            return back;
        }
        
        void appendNodeFront(T d){
            std::shared_ptr< Node<T> > n (new Node<T>(d));
            if (!front) {
                front = n;
                back = n;
            }else{
                front->prev = n;
                n->next = front;
                front = n;
            }
        }
        void appendNodeBack(T d){
            std::shared_ptr< Node<T> > n (new Node<T>(d));
            if (!back) {
                front = n;
                back = n;
            }else{
                back->next = n;
                n->prev = back;
                back = n;
            }
        }
        
        void displayNodeForward(){
            std::shared_ptr< Node<T> > n = front;
            while (n) {
                std::cout << n->data << " ";
                n = n->next;
            }
            std::cout << std::endl;
        }
        
        void displayNodeBackward(){
            std::shared_ptr< Node<T> > n = back;
            while (n) {
                std::cout << n->data << " ";
                n = n->prev;
            }
            std::cout << std::endl;
        }
        
    private:
        std::shared_ptr< Node<T> > front;
        std::shared_ptr< Node<T> > back;
    };
    
    template <class T> void genearteRandomDoubleLinkedList(DoubleLinkList<T> &dl, int num, T min, T max){
        std::list<T> l = util::getRandList(num, min, max);
        typename std::list<T>::iterator iter = l.begin();
        for (int i = 0; i < num; i++, iter++) {
            dl.appendNodeBack(*iter);            
        }
    }
    
    template <class T> DoubleLinkList<T> genearteRandomDoubleLinkedList(int num, T min, T max){
        std::list<T> l = util::getRandList(num, min, max);
        typename std::list<T>::iterator iter = l.begin();
        DoubleLinkList<T> tmp;
        for (int i = 0; i < num; i++, iter++) {
            tmp.appendNodeBack(*iter);
        }
        return tmp;
    }
}
#endif

//int main(){
//    std::shared_ptr<DoubleLinkList<int> > dl (new DoubleLinkList<int>);
//    for (int i = 0; i < 4; i++) {
//        dl->appendNodeBack(i);
//    }    
//    dl->displayNodeBackward();
//    return 0;
//}