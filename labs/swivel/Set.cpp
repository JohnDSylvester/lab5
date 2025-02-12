#include "Set.h"
#include <iostream>

Set::Set(){
	mRoot = nullptr;
	mCount = 0;
}

Set::Set(const Set& other){
	mRoot = other.mRoot->copy(other.mRoot);
	mCount = other.mCount;
}

Set::Set(Set&& other){
	mRoot = other.mRoot;
	mCount = other.mCount;
	other.mRoot = nullptr;
}

Set::~Set(){
	 mRoot->deleteSelf(mRoot);
	 delete mRoot;
}

size_t Set::insert(const std::string& value){
	size_t didInsert = mRoot->betterInsert(value, mRoot);
	if(didInsert){
		mCount++;
	}
	return didInsert;	
}

size_t Set::count() const{
	return mCount;
}

void Set::print() const{
	if(mRoot == nullptr){
		std::cout << "-" << std::endl;
		return;
	}
	std::string str = "";
	str = mRoot->printBetter(mRoot);
	std::cout << str << std::endl;
}

bool Set::contains(const std::string& value) const{
	Node* tracer = mRoot;
	while(tracer != nullptr){
		if(tracer->data == value){
			return 1;
		}
		else if(value < tracer->data){
			tracer = tracer->left;
		}
		else{
			tracer = tracer->right;
		}
	}
	return 0;
}

size_t Set::clear(){
	 mRoot->deleteSelf(mRoot);
         delete mRoot;
 	 mRoot = nullptr;
	 size_t cou = mCount;
	 mCount = 0;
	 return cou; 	 
}

size_t Set::remove(const std::string& value){
	if(mRoot->betterSwivel(value, mRoot, mRoot)){
                if(mRoot->left == nullptr && mRoot->right == nullptr){
                        mCount--;
			delete mRoot;
                        mRoot = nullptr;
                }
                else if (mRoot->left != nullptr && mRoot->right == nullptr){
			mCount--;
                        Node* temp = mRoot->left;
                        delete mRoot;
                        mRoot = temp;
                }
                else if (mRoot->left == nullptr && mRoot->right != nullptr){
                        mCount--;
			Node* temp = mRoot->right;
                        delete mRoot;
                        mRoot = temp;
                }
                else{/*
			mCount--;
                        Node* temp = mRoot->right;
                        Node* reattach = mRoot->left;
                        std::string lowest = (mRoot->left)->data;
                        delete mRoot;
                        temp->betterSwivel(lowest, temp, temp);
                        mRoot = temp;
                        mRoot->left = reattach;*/
                }
                return 1;
        }
        return 0;
}

 bool   Set::swivel(const std::string& value){
	if(mRoot->data == value){
                return 1;
         }
	 if(mCount == 0){
		return 0;
	 }
	 Node* prev = nullptr;
	 if(mRoot->betterSwivel(value, mRoot, prev)){
		return 1;
	 }
	 else{
	 return 0;
	 }
 }

void   Set::debug(){
	return;
}
