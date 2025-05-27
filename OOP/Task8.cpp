#include <iostream>

class Node {
	std::unique_ptr<int>data;
	std::shared_ptr<Node>next;
	std::shared_ptr<Node>prev;
public:
	Node(const int data) {
		std::cout << "Create n" << data << std::endl;
		this->data = std::make_unique<int>(data);
	}
	int& getData()const { return *data; }
	std::shared_ptr<Node> getNext()const { return next; }
	std::shared_ptr<Node> getPrev()const { return prev; }
	void setData(int data) { this->data = std::make_unique<int>(data);}
	void setNext(std::shared_ptr <Node>next) { this->next = next;}
	void setPrev(std::shared_ptr <Node>prev) { this->prev = prev; }
	~Node() { std::cout << "Delete n" << *data << std::endl; }
};

class List {
	std::shared_ptr<Node>first, last;
public:
	List() { first = last = nullptr; }
	void addElement(int value) {
		std::shared_ptr<Node>new_node = std::make_shared<Node>(value);
		if (!first)first = last = std::make_shared<Node>(value);
		else {
			last->setNext(new_node);
			new_node->setPrev(last);
			last = new_node;
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
				for (size_t i = 0; i <= id; i++) if (temp) { temp = temp->getNext(); }
				else break;
				if (temp)return temp->getData();

				throw std::out_of_range("Pobezhali");
			}
		}
	}
	void deleteNode(int id) {
		if (id < 0) return;

		std::shared_ptr<Node> temp = first;
		for (int i = 0; i < id; i++)
		{
			if (temp) { temp = temp->getNext(); }
			else break;
		}
		std::shared_ptr<Node> prevNode = temp->getPrev();
		std::shared_ptr<Node> nextNode = temp->getNext();
		if (temp) {
			if (prevNode) prevNode->setNext(nextNode);
			else first = nextNode;

			if (nextNode) nextNode->setPrev(prevNode);
			else last = prevNode;
		}
	}
	void clearNode() {
		first.reset(); last.reset();
	}
};

int main() {
	List l1;
	l1.addElement(0);
	l1.addElement(1);
	l1.addElement(2);
	l1.addElement(3);
	std::cout << l1 << std::endl;
	system("pause");
	l1.deleteNode(3);
	std::cout << l1 << std::endl;
	system("pause");
	l1.clearNode();
	std::cout << l1 << std::endl;
	return 0;
}