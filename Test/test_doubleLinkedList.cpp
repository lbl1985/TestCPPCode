//
//  test_doubleLinkedList.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/10/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//


//#include "DoubleLinkList_sharedPointer.cpp"
#include "../Utility/DoubleLinkList_sharedPointer.cpp"

int main(){
    util::DoubleLinkList<int> dl = util::genearteRandomDoubleLinkedList(10, 0, 3);
    util::genearteRandomDoubleLinkedList(dl, 10, 0, 3);
    dl.displayNodeForward();
    return 0;
}
