//
//  Q2_1_2.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/10/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "DoubleLinkList_sharedPointer.cpp"

template <class T>
void removeDuplicate(util::DoubleLinkList<T> &dl){
    std::shared_ptr< util::Node<int> > archor = dl.begin();
    std::shared_ptr< util::Node<int> > runner = dl.begin();

    while (archor) {
        runner = archor;
        while (runner->next) {
            if (runner->next->data == archor->data) {
                std::shared_ptr< util::Node<int> > tmp = runner->next;
                runner->next = runner->next->next;
                if (runner->next) {
                    runner->next->prev = runner;
                }
                tmp.reset();
            }else{
                runner = runner->next;
            }
        }
        archor = archor->next;
        dl.displayNodeForward();
    }
}

template <class T>
void removeDuplicate_prev(util::DoubleLinkList<T> &dl){
    std::shared_ptr< util::Node<int> > archor = dl.begin();
    std::shared_ptr< util::Node<int> > runner = dl.begin();
    
    while (archor) {
          runner = archor->next;
          while (runner) {
              if (runner->data == archor->data) {
                  std::shared_ptr< util::Node<int> > tmp = runner->next;
                  runner->prev->next = runner->next;
                  if (runner->next) {
                      runner->next->prev = runner->prev;
                  }
                  runner.reset();
                  runner = tmp;
              }else{
                  runner = runner->next;
              }
          }
          archor = archor->next;
          dl.displayNodeForward();
      }
}


int main(){
    util::DoubleLinkList<int> dl = util::genearteRandomDoubleLinkedList(10, 0, 3);
    dl.displayNodeForward();    
    removeDuplicate(dl);
    
    std::cout << "remove with prev" << std::endl;
    util::DoubleLinkList<int> dl2 = util::genearteRandomDoubleLinkedList(10, 0, 3);
    dl2.displayNodeForward();
    removeDuplicate_prev(dl2);
    return 0;
}