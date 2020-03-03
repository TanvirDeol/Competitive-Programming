#include <bits/stdc++.h>

using namespace std;

template<class C>constexpr int sz(const C&c){return int(c.size());}

using ll=long long;constexpr const char nl='\n',sp=' ';


int incorrect [1001][1001];
int k, num;

	   bool isPrime(int x){
	       for(int i=2; i<=sqrt(x); i++){
	           if(x%i==0){
	               return false;
	           }
	       }
	       return true;
	   }

	   int main(){
		   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
		   int n;
	       cin >> n;
	       for(int i=0; i<n; i++){
	           int x;
	           cin >> x;
	           for(int j=2; j<=x; j++){
	               if((isPrime(j))&&(isPrime(2*x-j))){
	                   cout << j << " " << 2*x-j << endl;
	                   break;
	               }
	           }
	       }
	   }