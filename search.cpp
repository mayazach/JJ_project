#include <iostream>
#include <cstdlib>
#include "bfs.cpp"

using namespace std;

int main(){

	int n = 4;
	Buffer *bufferIn;
        Buffer *bufferOut;
        NodeIndex *indexIn;
        NodeIndex *indexOut;
        bufferIn = new Buffer(n,n);
        bufferOut = new Buffer(n,n);
        indexIn = new NodeIndex(n,n);
        indexOut = new NodeIndex(n,n);

	indexOut->insertNode(0,1,*bufferOut);
	indexOut->insertNode(0,7,*bufferOut);
	indexOut->insertNode(1,2,*bufferOut);
        indexOut->insertNode(1,3,*bufferOut);
	indexOut->insertNode(3,4,*bufferOut);
        indexOut->insertNode(4,5,*bufferOut);
        indexOut->insertNode(5,6,*bufferOut);
        indexOut->insertNode(6,2,*bufferOut);
	indexOut->insertNode(7,8,*bufferOut);
        indexOut->insertNode(7,9,*bufferOut);
        indexOut->insertNode(9,10,*bufferOut);
        indexOut->insertNode(10,11,*bufferOut);
        indexOut->insertNode(11,12,*bufferOut);
        indexOut->insertNode(11,13,*bufferOut);
        indexOut->insertNode(12,10,*bufferOut);
        indexOut->insertNode(13,14,*bufferOut);
	indexOut->insertNode(13,16,*bufferOut);
        indexOut->insertNode(14,15,*bufferOut);
        indexOut->insertNode(15,0,*bufferOut);

	indexIn->insertNode(1,0,*bufferIn);
	indexIn->insertNode(7,0,*bufferIn);
	indexIn->insertNode(2,1,*bufferIn);
        indexIn->insertNode(3,1,*bufferIn);
	indexIn->insertNode(4,3,*bufferIn);
        indexIn->insertNode(5,4,*bufferIn);
        indexIn->insertNode(6,5,*bufferIn);
        indexIn->insertNode(2,6,*bufferIn);
	indexIn->insertNode(8,7,*bufferIn);
        indexIn->insertNode(9,7,*bufferIn);
        indexIn->insertNode(10,9,*bufferIn);
        indexIn->insertNode(11,10,*bufferIn);
        indexIn->insertNode(12,11,*bufferIn);
        indexIn->insertNode(13,11,*bufferIn);
        indexIn->insertNode(10,12,*bufferIn);
        indexIn->insertNode(14,13,*bufferIn);
	indexIn->insertNode(16,13,*bufferIn);
        indexIn->insertNode(15,14,*bufferIn);
        indexIn->insertNode(0,15,*bufferIn);

	cout << bidirectionalBFS(0,16,indexIn,indexOut,bufferIn,bufferOut) << endl;
}
