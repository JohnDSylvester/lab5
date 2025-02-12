#include "Set.h"
#include <iostream>

Set::Set(){
	mRoot = nullptr;
	mCount = 0;
}

Set::Set(const Set& other){
	mRoot = other.mRoot->copy(other.mRoot);
}

Set::Set(Set&& other){
	std::cout << "Ran Move\n";
	mRoot = other.mRoot;
	mCount = other.mCount;
	other.mRoot = nullptr;
}

Set::~Set(){
	 mRoot->deleteSelf(mRoot);
	 delete mRoot;
}

size_t Set::insert(const std::string& value){
	return mRoot->betterInsert(value, mRoot);	
}

size_t Set::count() const{
	return mCount;
}

void Set::print() const{
	if(mRoot == nullptr){
		std::cout << "()" << std::endl;
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
