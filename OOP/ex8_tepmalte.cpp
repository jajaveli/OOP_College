#include <iostream>
template <typename T>
class Node {
	std::unique_ptr<T>data;
	std::shared_ptr<Node<T>>next;
	std::shared_ptr<Node<T>>prev;
public:
	Node(const T data) {
		std::cout << "Create n" << data << std::endl;
		this->data = std::make_unique<T>(data);
	}
	T& getData()const { return *data; }
	std::shared_ptr<Node<T>> getNext()const { return next; }
	std::shared_ptr<Node<T>> getPrev()const { return prev; }
	void setData(T data) { this->data = std::make_unique<T>(data); }
	void setNext(std::shared_ptr <Node<T>>next) { this->next = next; }
	void setPrev(std::shared_ptr <Node<T>>prev) { this->prev = prev; }
	~Node() { std::cout << "Delete n" << *data << std::endl; }
};
template <typename T>
class List {
	std::shared_ptr<Node<T>>first, last;
public:
	List() { first = last = nullptr; }
	void addElement(T value) {
		std::shared_ptr<Node<T>>new_node = std::make_shared<Node<T>>(value);
		if (!first)first = last = std::make_shared<Node<T>>(value);
		else {
			last->setNext(new_node);
			new_node->setPrev(last);
			last = new_node;
		}
	}
	friend std::ostream& operator<<(std::ostream& out, List& list) {
		if (list.first) {
			std::shared_ptr<Node<T>> temp = list.first;
			while (temp) {
				out << temp->getData() << " ";
				temp = temp->getNext();
			}
		}
		return out;
	}
	T& operator[](int id) {
		if (first)
		{
			if (id >= 0) {
				std::shared_ptr<Node<T>> temp = first;
				for (size_t i = 0; i <= id; i++) if (temp) { temp = temp->getNext(); }
				else break;
				if (temp)return temp->getData();

				throw std::out_of_range("Pobezhali");
			}
		}
	}
	void deleteNode(int id) {
		if (id < 0) return;

		std::shared_ptr<Node<T>> temp = first;
		for (int i = 0; i < id; i++)
		{
			if (temp) { temp = temp->getNext(); }
			else break;
		}
		std::shared_ptr<Node<T>> prevNode = temp->getPrev();
		std::shared_ptr<Node<T>> nextNode = temp->getNext();
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
	List<int> l1;
	l1.addElement(0);
	l1.addElement(1);
	l1.addElement(2);
	l1.addElement(3);
	std::cout << l1 << std::endl;
	system("pause");
	List<std::string> l2;
	l2.addElement(" asd");
	l2.addElement(" asdgfhd");
	l2.addElement(" aggjt5d");
	l1.clearNode();
	std::cout << l1 << std::endl;
	return 0;
}