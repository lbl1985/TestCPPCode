//
//  test.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/4/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include "../Utility/DoubleLinkList.cpp"
#include "../Utility/Random2DArray.cpp"
#include <memory>

class C {
    std::shared_ptr<int> data;
    
public:
    C():data(new int){}
    void setData(int _data){
        *data = _data;
    }
    void print(){
        std::cout << "data = " << *data << std::endl;
    }
    ~C(){
        std::cout << "C::~C\n";
    }
};

class Foo{
    
public:
    Foo(){ std::cout << "Foo::Foo\n"; }
    ~Foo() {std::cout << "Foo::~Foo\n"; }
    void bar() {std::cout << "Foo::bar\n"; }
};

void f(const Foo &foo){
    std::cout << "f (const Foo&)\n";
}

int main(){
//    DoubleLinkList<double> *list = new DoubleLinkList<double>();
//    for (int i = 1; i < 4; i++) {
//        list->appendNodeFront(i * 1.1);
//    }
//    list->dispNodeForward();
//    list->dispNodeBackward();
//    
//    std::cout << std::endl;
//    
//    for (int i = 1; i < 4; i++) {
//        list->appendNodeBack(11.0 - (1.1 * i));
//    }
//    list->dispNodeForward();
//    list->dispNodeBackward();
//    
//    delete list;
//    
//    return 0;
    
    // shared pointer
    std::unique_ptr<Foo> p1(new Foo);
    if (p1) {
        p1->bar();
    }
    {
        std::unique_ptr<Foo> p2(std::move(p1));
        f(*p2);
        
        p1 = std::move(p2);
        std::cout << "destroying p2...\n";
    }
    if (p1) {
        p1->bar();
    }
    
    std::shared_ptr<C> pC (new C);
    pC->print();
    std::shared_ptr<C> pC2(pC);
    pC2->print();
    pC->setData(1);
    pC2->print();
    pC->setData(2);
    pC->print();
    std::shared_ptr<C> pC3(new C);
    return 0;
}