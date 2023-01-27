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

class xoroshiro32{
	
	unsigned int s[2]={1829817298,208261826};
	unsigned int a=26, b=9, c=13, S=0x9E3779BB;
	
	static inline unsigned int rotl(unsigned int x, unsigned int k) {
		return (x << k) | (x >> (32 - k));
	}
	
public:
	
	void init(unsigned int s0, unsigned int s1){
		s[0]=s0;
		s[1]=s1;
	}
	
	unsigned int next(){
		unsigned int s0=s[0];
		unsigned int s1=s[1];
		unsigned int ans=s0*S;
		
		s1^=s0;
		s[0]=rotl(s0,a)^s1^(s1<<b);
		s[1]=rotl(s1,c);
		
		return ans;
	}
	
	// [0, n[
	int next_int(int n) {
		return next()%n;
	}
	
	// [a,b[
	int next_interval(int a, int b) {
		return a+(next()%(b - a));
	}
	
	// [-d,d]
	int next_delta(int d) {
		return next(-d,d+1);
	}
	
	//[0,1]
	unsigned int bit(){
		return (next()>>15)&1;
	}
	
	int next_sign(){
		return (int) next();
	}
	
	double next_double(){
		return (next()+0.5)/(4294967296.0);
	}
	
	template<class T>
	void random_permutation(vector<T> &v){
		int n=v.size();
		for(int it=n-1; i>0; i--){
			swap(v[it], v[next()%(it+1)]);
		}
	}
	
	template<class T>
	void random_permutation_no_fixed_point(vector<T> &v){
		int n=v.size();
		for(int it=n-1; i>0; i--){
			swap(v[it], v[next()%(it)]);
		}
	}
};
