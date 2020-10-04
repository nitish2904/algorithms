#include<bits/stdc++.h>
using namespace std;
#define c_key 7 

string encrypt(string input_str){
    string output_str;
    for(int i=0;i<input_str.size();i++){
        if(input_str[i]>='0' && input_str[i]<='9'){
            output_str+=(input_str[i]-'0'+c_key)%10+'0';
        }
        else if(input_str[i]>='A' && input_str[i]<='Z'){
            output_str+=(input_str[i]-'A'+c_key)%26+'A';
        }
        else if(input_str[i]>='a' && input_str[i]<='z'){
            output_str+=(input_str[i]-'a'+c_key)%26+'a';
        }
    }
    return output_str;
}

string decrypt(string input_str){
    string output_str;
    for(int i=0;i<input_str.size();i++){
        if(input_str[i]>='0' && input_str[i]<='9'){
            output_str+=(input_str[i]-'0'-c_key+10)%10+'0';
        }
        else if(input_str[i]>='A' && input_str[i]<='Z'){
            output_str+=(input_str[i]-'A'-c_key+26)%26+'A';
        }
        else if(input_str[i]>='a' && input_str[i]<='z'){
            output_str+=(input_str[i]-'a'-c_key+26)%26+'a';
        }
    }
    return output_str;
}


int main(){
    string input_str;
    int choice;
    char ch='C';
    cout<<"Welcome To Cryptographic Techniques\n";
    while(ch!='E'){
        cout<<"Enter the string\n";
        cin>>input_str;
        cout<<"Enter 1 to encrypt the above entered string\n";
        cout<<"Enter 2 to decrypt the above entered string\n";
        cin>>choice;
        if(choice==1){
            string output_str=encrypt(input_str);
            cout<<"Encrypted string is: "<<output_str<<"\n";
        }
        if(choice==2){
            string output_str=decrypt(input_str);
            cout<<"Decrypted string is: "<<output_str<<"\n";
        }
        cout<<"If You want to continue press 'C'\n";
        cout<<"If you want to exit press 'E'\n";
        cin>>ch;
    }
    return 0;
}

