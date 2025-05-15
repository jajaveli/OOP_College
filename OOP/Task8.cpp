#include <iostream>

class Node {
	std::unique_ptr<int>data;
	std::shared_ptr<Node>next;
public:
	Node(const int data) {
		std::cout << "Create n" << data << std::endl;
		this->data = std::make_unique<int>(data);
	}
	int getData()const { return *data; }
	std::shared_ptr<Node> getNext()const { return next; }
	std::shared_ptr<Node> setData(int data) { this->data = std::make_unique<int>(data);  return std::shared_ptr<Node>(this); }
	std::shared_ptr<Node> setNext(std::shared_ptr <Node>next) { this->next = next; return std::shared_ptr<Node>(this); }
	void delNode() { ; }
	~Node() { std::cout << "Delete n" << *data << std::endl; }
};
class List {
	std::shared_ptr<Node>first, last;
public:
	List() { first = last = nullptr; }
	void addElement(int value) {
		if (!first)first = last = std::make_shared<Node>(value);
		else {
			last->setNext(std::make_shared<Node>(value));
			last = last->getNext();
		}
	}
	friend std::ostream& operator<<(std::ostream& out, List& list) {
		if (list.first) {
			std::shared_ptr<Node> temp = list.first;
			while (temp) {
				out << temp->getData() << " ";
				temp = temp->getNext();
			}
		}
		return out;
	}
	int& operator[](int id) {
		if (first)
		{
			if (id >= 0) {
				std::shared_ptr<Node> temp = first; 
				for (size_t i = 0; i <= id; i++){
					if (temp)temp = temp->getNext();

				}
				return temp->getData();
			}
		}
	}
	void deleteNode(int id) {

	}
};

int main() {
	List l1;

	l1.addElement(0);
	l1.addElement(1);
	l1.addElement(2);
	l1.addElement(3);
	std::cout << l1 << std::endl;

}