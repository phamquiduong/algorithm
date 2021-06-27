#include<iostream>
using namespace std;

struct node {
	int data;
	node *next;
};

int main() {
	node *start = new node;
	int n;
	
	cout<<"Number of Element: "; cin>>n;
	
	node *temp;
	temp = start;
	for (int i=0; i<n; i++) {
		int temp_data;
		cout<<"Element "<<i+1<<": "; cin>>temp_data;
		node *create = new node;
		create->data = temp_data;
		create->next = NULL;
		temp->next = create;
		temp = temp->next;
	}
	
	cout<<"\n-> Link List: ";
	
	temp = start;
	while (temp->next!=NULL) {
		temp = temp->next;
		cout<<temp->data<<" ";
	}
}
