#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long long int high(long long int x, long long int u){
	return x/(long long int)sqrt(u);
}

long long int low(long long int x, long long int u){
	return x%(long long int)sqrt(u);
}

typedef struct vEB{
	long long int u;
	long long int mx, mn;
	struct vEB *sumario;
	struct vEB **cluster;
}vEB;

inline long long int maximo(vEB* V){
	return V->mx;
}

inline long long int minimo(vEB* V){
	return V->mn;
}

long long int membroQ(vEB* V, long long int x){
	if(!V){
		return 0;
	}else if(x==minimo(V)||x==maximo(V)){
		return 1;
	}else{
		return membroQ(V->cluster[high(x,V->u)],low(x,V->u));
	}
}


int main(){
	
	vEB* V=NULL;
	printf("%lld\n", maximo(V));
	V->mx=3;
	printf("%lld\n", maximo(V));
	
	return 0;
}

