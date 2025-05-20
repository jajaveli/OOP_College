#include <iostream>

class Node {
	std::unique_ptr<int>data;
	std::shared_ptr<Node>next;
public:
	Node(const int data) {
		std::cout << "Create n" << data << std::endl;
		this->data = std::make_unique<int>(data);
	}
	int& getData()const { return *data; }
	std::shared_ptr<Node> getNext()const { return next; }
	void setData(int data) { this->data = std::make_unique<int>(data);/* return std::shared_ptr<Node>(this); */ }
	void setNext(std::shared_ptr <Node>next) { this->next = next;/*return std::shared_ptr<Node>(this); */ }
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
				for (size_t i = 0; i <= id; i++) if (temp) { temp = temp->getNext(); }else break;
				if (temp)return temp->getData();
			
			throw std::out_of_range("Потекло по трубам");
			}
		}
	}
	void deleteNode(int id) {
		std::shared_ptr<Node> temp = first;
		for (int i = 0; i < id - 1; i++)
		{
			if (temp) { temp = temp->getNext(); }
			else break;
		}
		if (temp == first) first = first->getNext();
		if (temp)temp->setNext(temp -> getNext() -> getNext());
	}
	~List() {
		if (first){
			while (first) {
				std::shared_ptr<Node>temp = first->getNext();
				if (temp){
					first->setNext(nullptr);
					first.reset();
					first = temp;
				}
				else{
					first.reset();
				}
			}
		}
	}
};

int main() {
	List l1;

	l1.addElement(0);
	l1.addElement(1);
	l1.addElement(2);
	l1.addElement(3);
	//l1.deleteNode(0);
	l1.~List();
	std::cout << l1 << std::endl;

}