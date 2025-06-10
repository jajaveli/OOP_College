#include <iostream>
class Tree {
	class Node {
	public:
		std::shared_ptr<int>data; std::shared_ptr<Node>left, right;
		Node(int val) :data{ std::make_shared<int>(val) }, left{ nullptr }, right{ nullptr } {}
		~Node() { //std::cout << "Delete n " << *data << std::endl; 
		}

	};
	std::shared_ptr<Node>root;
	void inOrder(std::shared_ptr<Node>current){
		if (current){
		inOrder(current->left);
		std::cout << *current->data << " ";
		inOrder(current->right);}
	}
	void preOrder(std::shared_ptr<Node>current) {
		if (current) {
			std::cout << *current->data << " ";
			inOrder(current->left);
			inOrder(current->right);
		}
	}
	void postOrder(std::shared_ptr<Node>current) {
		if (current) {
			inOrder(current->left);
			inOrder(current->right);
			std::cout << *current->data << " ";
		}
	}
	int find(std::shared_ptr<Node> current, int val) {
			if(!current)throw std::exception("Такого элемента нет");
			if (*current->data == val) return *current->data;
			if (val < *current->data)
				return find(current->left, val);
			else
				return find(current->right, val);
	}
public:
	Tree() :root{ nullptr } {}
	~Tree() {};
	Tree& add(int val) {
		if (!root) { root = std::make_shared<Node>(val); return *this; }
		bool is_added = false;
		std::shared_ptr<Node>temp = root;
		while (!is_added) {
			if (val > (*temp->data)) {
				if (temp->right) { temp = temp->right; }
				else { temp->right = std::make_shared<Node>(val); is_added = true; }
			}
			if (val < *(temp->data))
				if (temp->left)temp = temp->left;
				else { temp->left = std::make_shared<Node>(val); is_added = true; }
		}
		return *this;
	}
	void inOrder(){inOrder(root);}
	void preOrder(){preOrder(root);}
	void postOrder(){postOrder(root);}
	Tree& erase(int val) {
		if (!root)return *this;
		std::shared_ptr<Node>current = root;
		bool is_finded = false;
		while (!is_finded){
			if (val < *current->data && current->left){
				if (*current->left->data == val)is_finded = true;
				else current = current->left;
			}
			else if (val < *current->data && current->right) {
				if (*current->right->data == val)is_finded = true;
				current = current->right;
			}
		}
	}
	int find(int val) {return find(root, val);}
};


int main() {
	system("chcp 1251");
	Tree t1; t1.add(18).add(99).add(2).add(-19).add(20).add(44).add(-5).add(0).add(1).add(88).add(-3).add(3).add(90);
	//t1.inOrder();
	//t1.postOrder();
	//t1.preOrder();
	try { std::cout << t1.find(2); }
	catch (const std::exception& e){std::cout << e.what();}
	
}