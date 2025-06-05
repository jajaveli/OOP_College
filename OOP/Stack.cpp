#include <iostream>

class Node {
	std::shared_ptr<int>data; std::shared_ptr<Node>prev;
public:
	Node(const int data) {
		//std::cout << "Create n " << data << std::endl;
		this->data = std::make_unique<int>(data);
	}
	~Node() { //std::cout << "Delete n " << *data << std::endl; 
	}
	int& getData() const { return *data; }
	std::shared_ptr<Node> getPrev() const { return prev; }
	void setData(int value) { data = std::make_unique<int>(value); }
	void setPrev(std::shared_ptr<Node> prev_) { prev = prev_; }
};

class Stack {
	std::shared_ptr<Node>top;
public:
	Stack() : top(nullptr) {}

	bool isEmpty() const { return top == nullptr; }
	~Stack() {}
	void addElement(int value) {
		std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
		new_node->setPrev(top);
		top = new_node;
		}
	
	int popElement() {
		std::shared_ptr<Node>tmp = top;
		top = top->getPrev();
		return tmp->getData();
	}
	void clearStack() {
		while (!isEmpty()) {
			popElement();
		}

	}
	bool isEmpty() {
		if (!top) {
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
	Stack s1;
	s1.isEmpty();
	for (int i = 0; i < 100; i++)s1.addElement(100);
	for (int i = 0; i < 5; i++)s1.popElement();
	s1.isEmpty();
	for (int i = 0; i < 10; i++)s1.addElement(10);
	s1.clearStack();
	s1.isEmpty();
}