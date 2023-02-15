#include<bits/stdc++.h>
using namespace std;

struct Node{
    int mahang;
    int trongluong;
    int dongia;
    string tentraicay;
    Node* next;
}; 

struct List{
    Node* head;
    Node* tail;
};

Node* newnode(int _mahang, int _trongluong, int _dongia, string _tentraicay){
	Node* p=new Node;
	p->mahang=_mahang;
	p->trongluong=_trongluong;
    p->dongia=_dongia;
    p->tentraicay=_tentraicay;
	p->next=NULL;
	return p;
}

void newlist(List &l){
	l.head=l.tail=NULL;
}

void InsertLast(List &l, int _mahang, int _trongluong, int _dongia, string _tentraicay){
	Node*p =newnode(_mahang, _trongluong, _dongia, _tentraicay);
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
        l.tail=p;
	}
}

int SumSalary(List &l){
    Node *p=l.head;
    int sum=0;
	int c;
	cin>>c;
    while(p!=NULL){ 
		if(p->mahang==c){
			sum+=p->trongluong*p->dongia;
            cout<<p->mahang<<" "<<p->trongluong<<" "<<p->dongia<<" "<<p->tentraicay<<". ";
		}
        p=p->next;
    }
    if(sum>0){
        cout<< "Total:"<<sum<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
}

void DeleteFirst(List &l){
	Node* p=l.head;
	if(l.head!=NULL){
		if(p==l.head){
		    l.head=p->next;
			delete(p);
		}
    }
}
int main(){
	List l;
    newlist(l);
    string s, _tentraicay;
    int _mahang, _trongluong, _dongia;
    while(true){
        cin >> s;
        if(s=="Add"){
            cin.ignore();
            cin >> _mahang >> _trongluong >> _dongia >> _tentraicay;
            InsertLast(l, _mahang, _trongluong, _dongia, _tentraicay);
        }
        if(s=="Bill"){
            SumSalary(l);
        } 
        if(s=="Del"){
            DeleteFirst(l);
        }
        else if(s=="Fin"){
            break;
        }
    }
    return 0;
}