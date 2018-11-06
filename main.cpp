//
//  main.cpp
//  lol
//
//  Created by ZhangFan on 2018/10/16.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#include <iostream>
#include "AdaptivehuffmanCoding.hpp"
//#include "Node.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    if(argv[1]==nullptr){
        cout<<"useage:"<<endl;
        cout<<"'./ahk -e' to execute a example."<<endl;
        cout<<"'./ahk -i your_text' to encode&decode."<<endl;
    }
    else if(strcmp(argv[1],"-e")==0){
        AdaptiveHuffmanTree AHK=AdaptiveHuffmanTree();
        string test="ABBCADAD";
        cout<<"test string: "<<test<<endl;
        string coding="";
        cout<<AHK.encoder(test)<<endl;
        for(size_t i=0;i<test.size();i++){
            coding+=AHK.getCode(test[i]);
        }
        cout<<"coding: "<<coding<<endl;
        cout<<"decoding:  "<<AHK.decoder(coding)<<endl;
    }
    else if(strcmp(argv[1],"-i")==0){
        if(argv[2]==nullptr){
            cout<<"your text not found.try it:"<<endl;
            cout<<"'./ahk -i your_text'"<<endl;
        }
        AdaptiveHuffmanTree AHK=AdaptiveHuffmanTree();
        string test=argv[2];
        string coding="";
        cout<<AHK.encoder(test)<<endl;
        for(size_t i=0;i<test.size();i++){
            coding+=AHK.getCode(test[i]);
        }
        cout<<"coding: "<<coding<<endl;
        cout<<"decoding:  "<<AHK.decoder(coding)<<endl;
    }
    
    return 0;
}

