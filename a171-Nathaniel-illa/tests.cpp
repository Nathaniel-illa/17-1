#define CATCH_CONFIG_MAIN // defines main() automatically
#include "catch.hpp"
#include "SLL.hpp"
#include "SLLNode.hpp"
// tests for exercise 1

TEST_CASE("Ex1 ", "[Test 1]")
{
	SLL<int> sll;
	sll.addtoHead(3);
	sll.addtoHead(2);
	sll.addtoHead(1);
	SLLNode<int> *ptr = sll.getHead();
	while(true){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == nullptr) break;
	}
	cout << endl;
	REQUIRE(sll.getHead()->getData() == 1);
	REQUIRE(sll.getTail()->getData() == 3);
	sll.deleteNode(3);
	REQUIRE(sll.getTail()->getData() == 2);
	REQUIRE(sll.getHead()->getData() == 1);
	sll.deleteNode(1);
	REQUIRE(sll.getHead()->getData() == 2);
	REQUIRE(sll.getTail()->getData() == 2);
	sll.deleteNode(2);
	REQUIRE(sll.isEmpty() == 1);
}
TEST_CASE("Ex2 ", "[Test 2]")
{
	SLL<string> sll;
	sll.addtoTail("a");
	sll.addtoTail("b");
	sll.addtoTail("c");
	SLLNode<string> *ptr = sll.getHead();
	while(true){
		cout << ptr->getData() << " ";
		ptr = ptr->getNext();
		if (ptr == nullptr) break;
	}
	cout << endl;
	REQUIRE(sll.getHead()->getData() == "a");
	REQUIRE(sll.getTail()->getData() == "c");
	sll.deleteNode("a");
	REQUIRE(sll.getHead()->getData() == "b");
	REQUIRE(sll.getTail()->getData() == "c");
	sll.deleteNode("c");
	REQUIRE(sll.getHead()->getData() == "b");
	REQUIRE(sll.getTail()->getData() == "b");
	sll.deleteNode("b");
	REQUIRE(sll.isEmpty() == 1);
}