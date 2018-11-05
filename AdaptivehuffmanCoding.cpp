//
//  AdaptivehuffmanCoding.cpp
//  lol
//
//  Created by ZhangFan on 2018/10/16.
//  Copyright © 2018 ZhangFan. All rights reserved.
//

#include "AdaptivehuffmanCoding.hpp"
#include "Node.hpp"
#include <bitset>
//AHT Realization
AdaptiveHuffmanTree::AdaptiveHuffmanTree():_NYT(new Node('\0')),_root(_NYT){
    _dataList=vector<Node*>(100);
    //_nodeList=vector<Node*>(10);
};

string AdaptiveHuffmanTree::_getCode(const char data,Node* node, string code){
    if(!node->left()&&!node->right()){
        return node->data()==data?code:"";
    }else{
        string tmp="";
        if(node->left()){
            tmp=_getCode(data,node->left(), code+"0");
        }
        if(tmp==""&& node->right()){
            tmp=_getCode(data,node->right(), code+"1");
        }
        return tmp;
    }
}
void AdaptiveHuffmanTree::_swapNode(Node* n1,Node* n2){
    vector<Node*>::iterator itr=find(_nodeList.begin(),_nodeList.end(),n1);
    auto i1=distance(begin(_nodeList),itr);
    itr=find(_nodeList.begin(),_nodeList.end(),n2);
    auto i2=distance(begin(_nodeList),itr);
    swap(_nodeList[i1], _nodeList[i2]);

    Node* tmpNode=n1->parent();
    n1->parent(n2->parent());
    n2->parent(tmpNode);
    if(n1->parent()->left()==n2){
        n1->parent()->left(n1);
    }else{
        n1->parent()->right(n1);
    }
    if(n2->parent()->left()==n1){
        n2->parent()->left(n2);
    }else{
        n2->parent()->right(n2);
    }

}
Node* AdaptiveHuffmanTree::_find_max_node(int w) {
    vector<Node*>::reverse_iterator it=_nodeList.rbegin();
    for (; it!=_nodeList.rend(); ++it) {
        Node* tmpN=*it;
        if(tmpN){
            if (tmpN->weigth()==w){
            return tmpN;
            }
        }
    }
    return (new Node());
}
void AdaptiveHuffmanTree::_Insert(char data){
    Node* node=_dataList[(int)data];
    if(!node){
        Node* spawn=new Node(data,1);
        Node* internal = new Node('\0',1,_NYT->parent(),_NYT,spawn);
        spawn->parent(internal);
        _NYT->parent(internal);
        if(internal->parent()){
            internal->parent()->left(internal);
        }else{
            _root=internal;
        }
        _nodeList.insert(_nodeList.begin(), internal);
        _nodeList.insert(_nodeList.begin(), spawn);
        _dataList[int(data)]=spawn;
        node=internal->parent();
    }
    while (node) {
        Node *maxNode=_find_max_node(node->weigth());
        if(maxNode!=node&&maxNode->parent()!=node&&maxNode!=node->parent()){
            _swapNode(maxNode, node);
        }
        node->weigth(node->weigth()+1);
        node=node->parent();
    }
    
}
string AdaptiveHuffmanTree::encoder(string text){
    string result="";
    for(size_t i=0;i<text.size();i++){
        const char data =text[i];
        Node* node=_dataList[(int)data];
        if(node){
            result+=_getCode(data, _root);
        }else{
            result+=_getCode('\0', _root);
            result+=bitset<8>(int(data)).to_string();
        }
        _Insert(data);
        result+='\n';
    }
    return result;
}
string AdaptiveHuffmanTree::getCode(const char data){
    return _getCode(data, _root);
}

char getSymbol(string binStr){
    bitset<8> bint = bitset<8>(binStr);
    return char(bint.to_ulong());
}

