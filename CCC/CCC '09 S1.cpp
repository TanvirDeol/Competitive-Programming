#include <iostream>
#include <string>
#include <cmath>
using namespace std;


int main() {
	int one=0,two=0,count=0;
	scanf("%d %d",&one,&two);
	int cba = cbrt(one);
	
	int cbb = cbrt(two);
	for (int i =cba;i<=cbb;i++){
		
		double n = i*i*i;
		if(n>=one){
			if (fmod(sqrt(n),1.0)==0.0){
				count++;
			}
		}
	}


	cout<<count<<"\n";
    return 0;
}