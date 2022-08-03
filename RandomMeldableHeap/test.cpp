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
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cstdint>
#include <cmath>
#include <chrono>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
using namespace std::chrono;
 
using ll = long long;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
#define f first
#define s second
#define NDEBUG
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#include "RandomMeldableHeap.hpp"

void kebab(string nome=""){
	cin.tie(0); ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(12);
	if(sz(nome)){
		freopen((nome+".txt").c_str(),"r",stdin);
		freopen((nome+"_in"+".txt").c_str(),"w",stdout);
	}
}

void caso_teste(){
	
	int t=100;
	
	double stl=0.0;
	double minha=0.0;
	
	while(t--){
		cout<<t<<'\n';
		cout.flush();
		int n=100000;
		int a[n];
		for(int i=0; i<n; i++) a[i]=rng()%1000000;
		
		{
		auto start = high_resolution_clock::now();
		
		priority_queue<int> pq;
		for(int i=0; i<n; i++) pq.push(a[i]);
		for(int i=0; i<n; i++) {pq.top(); pq.pop();}
		
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		stl+=duration.count();
		//cout<<"stl: "<<duration.count()<<'\n';
		}
		
		{
		auto start = high_resolution_clock::now();
		
		RandomMeldableHeap<int> pq;
		for(int i=0; i<n; i++) pq.push(a[i]);
		for(int i=0; i<n; i++) {pq.top(); pq.pop();}
		
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		minha+=duration.count();
		//cout<<"minha: "<<duration.count()<<'\n';
		}
	}
	cout<<"STL:\n";
	cout<<stl<<'\n';
	cout<<"minha:\n";
	cout<<minha<<'\n';
	cout<<"ratio:\n";
	cout<<minha/stl<<'\n';
}

int main(){
	
	kebab();
	
	int n_casos=1; //cin>>n_casos;
	
	while(n_casos--) caso_teste();
}
