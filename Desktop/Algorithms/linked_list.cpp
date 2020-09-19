#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node(int x){
		data=x;
		next=NULL;
	}
};
Node *insertEnd(Node *head,int data){
	if(head==NULL){
		return new Node(data);
	}
	Node *curr=head;
	while(curr->next!=NULL)
		curr=curr->next;
	curr->next=new Node(data);
	return head;
}
void display(Node *head){
	while(head!=NULL){
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
	return;
}
void middle(Node *head){
	Node *p=head;
	while( head->next && head->next->next){
		head=head->next->next;
		p=p->next;
	}
	cout<<p->data<<endl;
	return;
}
Node *reverse(Node*head){
	Node *curr=head;
	Node *prev=NULL;
	Node *next;
	while(curr){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}
int main(){
	Node *head=NULL;
	int n;
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		head=insertEnd(head,x);
	}
	display(head);
	
	int pos;
	cin>>pos;
	cout<<"position of node you want to delete : "<<pos<<endl;
	Node *curr=head,*p=NULL;
	int cnt=0;
	while(curr){
		cnt++;
		if(cnt==pos){
			if(p==NULL){
				head=head->next;
			}
			else{
				p->next=curr->next;
				curr->next=NULL;
			}
		}
		p=curr;
		curr=curr->next;
	}
	display(head);
	head=reverse(head);
	cout<<"after reversing the linked list"<<endl;
	display(head);

}