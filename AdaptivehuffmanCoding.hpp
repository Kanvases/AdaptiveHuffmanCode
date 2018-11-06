//
//  AdaptivehuffmanCoding.hpp
//  lol
//
//  Created by ZhangFan on 2018/10/16.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#ifndef AdaptivehuffmanCoding_hpp
#define AdaptivehuffmanCoding_hpp

#include <vector>
#include <string>
#include <map>
#include "Node.hpp"
using namespace std;


class AdaptiveHuffmanTree{
private:
    vector<Node*> _nodeList;
    vector<Node*> _dataList;
    
    Node* _NYT;
    Node* _root;
    string _getCode(const char,Node*,string code="");
    void _swapNode(Node*,Node*);
    void _Insert(char);
    Node* _find_max_node(int);
    
public:
    string getCode(const char);
    AdaptiveHuffmanTree();
    string encoder(string);
    string decoder(string);
    //~AdaptiveHuffmanTree();
};



#endif /* AdaptivehuffmanCoding_hpp */
