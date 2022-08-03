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
#include "xoroshiro32.hpp"

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

void kebab(string nome=""){
	cin.tie(0); ios_base::sync_with_stdio(0);
	cout<<fixed<<setprecision(12);
	if(sz(nome)){
		freopen((nome+".txt").c_str(),"r",stdin);
		freopen((nome+"_in"+".txt").c_str(),"w",stdout);
	}
}

double test_control(int n){
	
	vector<int> v(n);
	
	auto start = high_resolution_clock::now();
	
	for(int i=0; i<n; i++) v[i]=1;
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}

double test_rand(int n){
	
	vector<int> v(n);
	
	auto start = high_resolution_clock::now();
	
	for(int i=0; i<n; i++) v[i]=rand();
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}

double test_rng(int n){
	
	vector<int> v(n);
	
	auto start = high_resolution_clock::now();
	
	for(int i=0; i<n; i++) v[i]=rng();
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}

double test_xoroshiro32(int n){
	
	xoroshiro32 xrsr;
	xrsr.init(31982,4209871);
	vector<int> v(n);
	
	auto start = high_resolution_clock::now();
	
	for(int i=0; i<n; i++) v[i]=xrsr.next();
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}

void caso_teste(){
	int n=1e9;
	cout<<"control:"<<'\n';
	cout<<test_control(n)/n<<'\n';
	cout<<"stl rand():"<<'\n';
	cout<<test_rand(n)/n<<'\n';
	cout<<"rng aka mt19937():"<<'\n';
	cout<<test_rng(n)/n<<'\n';
	cout<<"xoroshiro32:"<<'\n';
	cout<<test_xoroshiro32(n)/n<<'\n';
}
 
int main(){
	
	kebab();
	
	int n_casos=1; //cin>>n_casos;
	
	while(n_casos--) caso_teste();
}
