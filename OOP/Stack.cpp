#include <iostream>

class Node {
	std::shared_ptr<int>data; std::shared_ptr<Node>next;
public:
	Node(const int data) {
		//std::cout << "Create n " << data << std::endl;
		this->data = std::make_unique<int>(data);
	}
	~Node() { //std::cout << "Delete n " << *data << std::endl; 
	}
	void setData() {}
	int& getData()const { return *data; }
	void setNext(std::shared_ptr <Node>next) { this->next = next; }
	std::shared_ptr<Node> getNext()const { return next; }
};

class Stack {
	std::shared_ptr<Node>first; std::shared_ptr<Node>last;
public:
	Stack() {}
	~Stack() {}
	void addElement(int value) {
		std::shared_ptr<Node>new_node = std::make_shared<Node>(value);
		if (!first)first = last = std::make_shared<Node>(value);
		else {
			last->setNext(new_node);
			//new_node->setNext();
			last = new_node;
		}
	}
	int popElement() {
		std::shared_ptr<Node>tmp = first;
		first = first->getNext();
		return tmp->getData();
	}
	void clearQueue() {
		while (!isEmpty()) {
			popElement();
			/*std::shared_ptr<Node>new_node;
			std::shared_ptr<Node>tmp = first;
			first->setNext(new_node);
			first = new_node;
			tmp.reset();*/
		}

	}
	bool isEmpty() {
		if (!first) {
			//std::cout << "Список пуст!";
			return 1;
		}
		else { //std::cout << "Список не пуст!"; 
			return 0;
		}
	}
};
int main() {
	system("chcp 1251");
	Stack q1;
	q1.isEmpty();
	for (int i = 0; i < 1000000; i++) {
		q1.addElement(100);
	}
	for (int i = 0; i < 5; i++) {
		std::cout << q1.popElement();
	}
	q1.isEmpty();
	for (int i = 0; i < 10; i++) {
		q1.addElement(10);
	}
	q1.clearQueue();
	q1.isEmpty();
}