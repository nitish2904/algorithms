#include<bits/stdc++.h>
using namespace std;
int* getLPS(string pattern){
	int len = pattern.length();
	int* lps = new int[len];

	lps[0]=0;
	int i=1;
	int j=0;

	while(i<len){
		if(pattern[i]==pattern[j]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j!=0){
				j=lps[j-1];
			}
			else{
				lps[i]=0;
				i++;
			}
		}

	}
	return lps;
}
bool KMPsearch(string text,string pattern){
	int lenText = text.length();
	int lenPat = pattern.length();

	int i=0;
	int j=0;

	int* lps = getLPS(pattern);
	while(i<lenText && j<lenPat){
		if(text[i] == pattern[j]){
			i++;
			j++;
		}
		else{
			if(j!=0){
				j = lps[j-1];
			}
			else{
				i++;
			}
		}
	}
}

int main(){
	string str;
	cin>>str;
	string pattern;
	cin>>pattern;
	cout<<KMPsearch(str,pattern)<<endl;
	return 0;
}
