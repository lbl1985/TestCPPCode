//
//  test_lambda.cpp
//  TestCPPCode
//
//  Created by Binlong Li on 2/18/13.
//  Copyright (c) 2013 Binlong Li. All rights reserved.
//

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

//int main(){
//    vector<int> v;
//    for (int i = 0; i < 10; ++i) {
//        v.push_back(i);
//    }
//    
//    int eventCount = 0;
//    for_each(v.begin(), v.end(), [&eventCount](int n){
//        cout << n;
//        if (n % 2 == 0) {
//            cout << " is even " << endl;
//            eventCount++;
//        }else{
//            cout << " is odd " << endl;
//        }
//    });
//    
//    cout << "There are " << eventCount << " even numbers in the vector. " << endl;
//}
class FunctorClass {
private:
    FunctorClass& operator=(const FunctorClass&);
    int &m_eventCount;
public:
    explicit FunctorClass(int& eventCount):m_eventCount(eventCount){}
    void operator()(int n)const{
        cout << n;
        if (n%2 == 0) {
            cout << " is even " << endl;
            ++m_eventCount;
        }else{
            cout << " is odd " << endl;
        }
    }
};

int main(){
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    
    int eventCount = 0;
    for_each(v.begin(), v.end(), FunctorClass(eventCount));
    
    cout << "There are " << eventCount << " even numbers in the vector." << endl;
    return 0;
}