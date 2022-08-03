/*
	  ______  _____  _______ _     _ _______ __   _  _____  _  _  _
	 |_____/ |     | |       |____/  |______ | \  | |     | |  |  |
	 |    \_ |_____| |_____  |    \_ ______| |  \_| |_____| |__|__|
	
	
	       .      .           .      .           .      .    	
	       _\/  \/_           _\/  \/_           _\/  \/_    	
	        _\/\/_             _\/\/_             _\/\/_     	
	    _\_\_\/\/_/_/_     _\_\_\/\/_/_/_     _\_\_\/\/_/_/_ 	
	     / /_/\/\_\ \       / /_/\/\_\ \       / /_/\/\_\ \  	
	        _/\/\_             _/\/\_             _/\/\_     	
	        /\  /\             /\  /\             /\  /\     	
	       '      '           '      '           '      '    	
	
*/

#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

#include <algorithm>
#include "../PseudoRandomGenerators/xoroshiro32.hpp"
 
using namespace std;
xoroshiro32 xoroshiro;

template<class T>
class RandomMeldableHeap{
	
	class RMHnode{
	public:
		T value;
		RMHnode *left, *right;
		RMHnode(int x){
			value=x;
			left=right=nullptr;
		}
	};
	
	RMHnode *meld(RMHnode *h1, RMHnode *h2){
		if(h1==nullptr||h2==nullptr) return h1?h1:h2;
		//both have a value
		if(h2->value < h1->value) swap(h1,h2);
		if(h1->left==nullptr) h1->left=h2;
		else if(h1->right==nullptr) h1->right=h2;
		else if(xoroshiro.bit()) h1->left=meld(h1->left, h2);
		else h1->right=meld(h1->right, h2);
		return h1;
	}
	
	RMHnode *root;
	int n;
	
public:
	RandomMeldableHeap(){
		root=nullptr;
		n=0;
	}
	
	void push(T i){
		RMHnode *u=new RMHnode(i);
		root=meld(root, u);
		n++;
	}
	
	int size(){
		return n;
	}
	
	T top(){
		return root->value;
	}
	
	void pop(){
		RMHnode *tmp=root;
		root=meld(root->left, root->right);
		delete tmp;
		n--;
	}
	
	bool empty(){
		return n==0;
	}
};
