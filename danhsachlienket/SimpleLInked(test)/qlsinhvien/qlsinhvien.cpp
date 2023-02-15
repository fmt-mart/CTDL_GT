#include<iostream>
#include<string>
using namespace std;

struct Node{
    string name;
    int mark;
    string ns;
    struct Node*next;
};

struct List{
    Node* head;
    Node* tail;
};

Node* newnode(string _name, int _mark, string _ns){
    Node*p=new Node;
    p->name=_name;
    p->mark=_mark;
    p->ns=_ns;
    p->next=NULL;
    return p;
}

void newlist(List &l){
    l.head=l.tail=NULL;
}

void InsertLast(List &l, string _name, int _mark, string _ns){
    Node*p=newnode(_name,_mark,_ns);
    if(l.head==NULL){
        l.head=l.tail=p;
    }
    else{
        l.tail->next=p;
        l.tail=p;
    }
}

void swap(List &l){
    for(Node*k=l.head; k!=NULL; k=k->next){
        for(Node*h=k->next; h!=NULL; h=h->next){
            if(k->mark>h->mark){
                int tg=k->mark;
                k->mark=h->mark;
                h->mark=tg;
            }
        }
    }
    for(Node*k=l.head; k!=NULL; k=k->next){
         cout<<k->mark<<" ";
    }
}

void search(List &l){
    for(Node*k=l.head;k!=NULL;k=k->next){
        int x;
        cin>>x;
        if(k->mark=x){
            cout<<k->name<<" "<<k->ns;
        }
    }
}

int main(){
    List l;
    newlist(l);
    int mark;
    string name,ns,s;
    while(true){
        cin>>s;
        if(s=="insL"){
            cin>>name;
            cin>>mark;
            cin>>ns;
            InsertLast(l,name,mark,ns);
        }
        if(s=="swap"){
            swap(l);
        }
        if(s=="search"){
            search(l);
        }
    }
}