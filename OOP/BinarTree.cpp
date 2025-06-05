#include <iostream>
class Tree {
	class Node {
	public:
		std::shared_ptr<int>data; std::shared_ptr<Node>left,right;
		Node(int val) :data{ std::make_shared<int>(val) }, left{ nullptr },right{nullptr}{}
		~Node() { //std::cout << "Delete n " << *data << std::endl; 
		}
		
	};
	std::shared_ptr<Node>root;
public:
	Tree() :root{nullptr} {}
	Tree& add(int val){
		if (!root) { root = std::make_shared<Node>(val); return *this; }
		bool is_added = false;
		std::shared_ptr<Node>temp = root;
		while(!is_added){
			if (val > (*temp->data)){
				if (temp->right) { temp = temp->right; }
				else { temp->right = std::make_shared<Node>(val); is_added = true; }
			}
			if (val < *(temp->data))
				if (temp->left)temp = temp->left;
				else { temp->left = std::make_shared<Node>(val); is_added = true; }
		}
		return *this;
	}
};


int main() {
	system("chcp 1251");
	Tree t1; t1.add(-8).add(-2).add(3).add(-13).add(24).add(0).add(81).add(-60).add(1).add(-1).add(4);
}