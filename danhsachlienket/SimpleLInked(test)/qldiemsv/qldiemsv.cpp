#include<bits/stdc++.h>
using namespace std;

struct Node{
	string name;
	string ns;
	string sex;
	int mark;
	struct Node* next;
};

struct List{
	Node* head;
	Node* tail;
};

Node* newnode(string _name, string _ns, string _sex, int _mark){
	Node* p=new Node;
	if(p==NULL){
		return NULL;
	}
	p->name=_name;
	p->ns=_ns;
	p->sex=_sex;
	p->mark=_mark;
	p->next=NULL;
	return p;
}

void newlist(List &l){
	l.head=l.tail=NULL;
}

void InsertFisrt(List &l, string _name, string _ns, string _sex, int _mark){
	Node*p =newnode(_name,_ns,_sex,_mark);
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		p->next=l.head;
		l.head=p;
	}
}

void InsertLast(List &l, string _name, string _ns, string _sex, int _mark){
	Node*p =newnode(_name,_ns,_sex,_mark);
	if(l.head==NULL){
		l.head=l.tail=p;
	}
	else{
		l.tail->next=p;
		l.tail=p;
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

void DeleteLast(List &l){
	Node* p=l.tail;
	if(l.tail!=NULL){
		if(p==l.tail){
			l.tail->next=p;
			delete(p);
		}
	}
}

void max(List l){
	int max=l.head->mark;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->mark>max){
			max=k->mark;
			cout<<k->name<<" "<<max<<endl;
		}
	}
}

void min(List l){
	int min=l.head->mark;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->mark<min){
			min=k->mark;
			cout<<k->name<<" "<<min<<endl;
		}
	}
}

int sizeMale(List &l){
	int s=0;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->sex=="male"){
			s++;
		}
	}
	return s;
}

int sizeFemale(List &l){
	int s=0;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->sex=="female"){
			s++;
		}
	}
	return s;
}

void avgMale(List l){
	float sum=0;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->sex=="male"){
			sum+=k->mark;
		}
	}
	cout<<fixed<<setprecision(1)<<(float)sum/sizeMale(l)<<endl;
}

void avgFemale(List l){
	float sum=0;
	for(Node* k=l.head; k!=NULL; k=k->next){
		if(k->sex=="female"){
			sum+=k->mark;
		}
	}
	cout<<fixed<<setprecision(1)<<(float)sum/sizeFemale(l)<<endl;
}

int main(){
	List l;
	newlist(l);
	string s,name, ns,sex;
	int mark;
	while(true){
		cin>>s;
		if(s=="insF"){
			cin>>name;
			cin>>ns;
			cin>>sex;
			cin>>mark;
			InsertFisrt(l,name,ns,sex,mark);
		}
		if(s=="insL"){
			cin>>name;
			cin>>ns;
			cin>>sex;
			cin>>mark;
			InsertLast(l,name,ns,sex,mark);
		}
		if(s=="delF"){
			DeleteFirst(l);
		}
		if(s=="delL"){
			DeleteLast(l);
		}
		if(s=="max"){
			max(l);
		}
		if(s=="min"){
			min(l);
		}
		if(s=="avgMale"){
			avgMale(l);
		}
		if(s=="avgFemale"){
			avgFemale(l);
		}
		if(s=="fin"){
			break;
		}
	}
}