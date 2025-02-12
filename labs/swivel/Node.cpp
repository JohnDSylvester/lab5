#include "Node.h"


Node::Node(std::string value){
        data = value;
        left = nullptr;
	right = nullptr;
}

size_t Node::betterInsert(const std::string& value, Node* &head){
        if(head == nullptr){
                Node* temp = new Node(value);
		head = temp;
                return 1;
        }
	if(value == head->data){
		return 0;
	}
	else if(value < head->data){
		return betterInsert(value, head->left);
	}
	else{
		return betterInsert(value, head->right);
	}
}

std::string Node::printBetter(Node* head){
	if(head == nullptr){
		return "-";
	}
	if(head->left == nullptr && head->right == nullptr){
		return head->data;
	}

	return "(" + printBetter(head->left) + " " + head->data + " " + printBetter(head->right) + ")";
}

void Node::deleteSelf(Node* head){
	if(head != nullptr){
		deleteSelf(head->left);
		delete head->left;
		deleteSelf(head->right);
		delete head->right;

	}
}

Node* Node::copy(Node* origin){
	if(origin != nullptr){
		Node* temp = new Node(origin->data);
		temp->left = copy(origin->left);
		temp->right = copy(origin->right);
		return temp;
	}
	else{	
		return nullptr;	
	}
}

bool Node::betterSwivel(const std::string& value, Node* &head, Node* &prev){
        if(head == nullptr){
                return 0;
        }
        if(value < head->data){
                return betterSwivel(value, head->left, head);
        }
        else if(value > head->data){
                return betterSwivel(value, head->right, head);
        }
        else{
                return 1;
        }
        if(head != prev){
                if(prev->left != nullptr && prev->right == nullptr){
                        Node* temp = head;
                        std::cout << head << " " << temp << " " << prev;
                        Node* tempLeft = head->left;
                        Node* tempRight = head -> right;
                        head = prev;
                        prev = temp;
                        prev->right= head;
                        prev->left = nullptr;
                        std::cout << head << " " << temp << " " << prev;
                        head->left = tempLeft;
                        head->right = tempRight;
                }
                if(prev->right != nullptr && prev->left == nullptr){
                Node* temp = head;
                        std::cout << head << " " << temp << " " << prev;
                        Node* tempLeft = head->left;
                        Node* tempRight = head -> right;
                        head = prev;
                        prev = temp;
                        prev->left = head;
                        prev->right = nullptr;
                        std::cout << head << " " << temp << " " << prev;
                        head->left = tempLeft;
                        head->right = tempRight;
                }
        }
} 
