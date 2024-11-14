#include "SLL.hpp"
#include "SLLNode.hpp"
#include <iostream>
using namespace std;

template <class T>
void printSLL(SLL<T> sll);

int main()
{
	SLL<int> sll;
	sll.addtoHead(3);		// test: add to head
	sll.addtoHead(2);		// test: add to head
	sll.addtoHead(1);		// test: add to head
	printSLL(sll);			//  1 2 3
	sll.addtoTail(4);		// test: add to tail
	sll.addtoTail(5);		// test: add to tail
	sll.addtoTail(6);		// test: add to tail
	printSLL(sll);			//  1 2 3 4 5 6
	sll.deleteNode(3);		// test: delete middle
	printSLL(sll);			//  1 2 4 5 6
	sll.deleteNode(6);		// test: delete tail
	printSLL(sll);			//  1 2 4 5
	sll.deleteNode(5);		// test: delete tail
	printSLL(sll);			//  1 2 4
	sll.deleteNode(1);		// test: delete head
	printSLL(sll);			//  2 4
}

template <class T>
void printSLL(SLL<T> sll){
	SLLNode<T> *ptr;
	ptr = sll.getHead();
	while (1){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == nullptr) break;
	}
	cout << endl;
}