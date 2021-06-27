#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *start;

void init() {
    start = NULL;
}

bool isEmpty() {
    return (start==NULL)? true : false;
}

void push (int x) {
    node *create = new node;
	create->data = x;
	create->next = start;
    start = create;
}

int pop() {
    if (start==NULL) {
        cout<<"Stack Empty";
        return -99999;
    }

    node *temp; temp = start;
    int x = start->data;
    start = start->next;
    delete temp;
    return x;
}

void input() {
    int n;
	cout<<"Number of Element: "; cin>>n;
	
	for (int i=0; i<n; i++) {
		int x;
		cout<<"Element "<<i+1<<": "; cin>>x;
		push(x);
	}
}

void print() {
    cout<<"\n-> Stack: ";
	
    node *temp;
	temp = start;
	while (temp!=NULL) {
        cout<<temp->data<<" ";
		temp = temp->next;
	}
}

void destroy() {
    while (!isEmpty()) {
        pop();
    }
}

int main(){
    init();
	
    input();

    print();
}
