#include<bits/stdc++.h>
using namespace std;
long staircase(int n){
   long int fib[100];
   memset(fib,0,sizeof(fib));
   fib[0]=1;
   fib[1]=1;
   fib[2]=2;
//he can jump 1,2,3 steps from a point
   //just like the fibbonacci dp problem ..
   for(int i=3;i<=n;i++){
   	fib[i]=fib[i-1]+fib[i-2]+fib[i-3];
   } 
   return fib[n];
}

