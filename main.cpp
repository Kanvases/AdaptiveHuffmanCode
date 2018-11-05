//
//  main.cpp
//  lol
//
//  Created by ZhangFan on 2018/10/16.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#include <iostream>
#include "AdaptivehuffmanCoding.hpp"
#include "Node.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    AdaptiveHuffmanTree AHK=AdaptiveHuffmanTree();
    string test="ABBCADAD";
    
    cout<<AHK.encoder(test)<<endl;
    cout<<"A:"<<AHK.getCode('A')<<endl;
    cout<<"B:"<<AHK.getCode('B')<<endl;
    cout<<"C:"<<AHK.getCode('C')<<endl;
    cout<<"D:"<<AHK.getCode('D')<<endl;
    
    
    return 0;
}
