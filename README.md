# AdaptiveHuffmanCode
Adaptive Huffman Code implement by C++

一万个push不上去，最后怒删repository拖文件拖进去了>A<

## usage:
- initialization：
```
AdaptiveHuffmanTree AHK=AdaptiveHuffmanTree();
```
- encoder
```
string test="ABBCADAD";
AHK.encoder(test);
```
- check the coding on each character
```
cout<<"A:"<<AHK.getCode('A')<<endl;
cout<<"B:"<<AHK.getCode('B')<<endl;
```

- decoder:
```
cout<<"00100011:"<<AHK.decoder("00100011")<<endl;
```
