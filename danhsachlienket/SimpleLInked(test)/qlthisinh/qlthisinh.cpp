#include<bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    int mark;
    struct Node* next;
};

struct List{
    Node *head;
    Node *tail;
};

Node* newnode(string _vname, int _vmark){
    Node* p=new Node;
    p->name=_vname;
    p->mark=_vmark;
    p->next=NULL;
    return p;
}

void newlist(List &l){
    l.head=NULL;
    l.tail=NULL;
}

void InsertFirst(List &l, string _vname, int _vmark){
    Node*p=newnode(_vname, _vmark);
    if(l.head=NULL){
        l.head=l.tail=p;
    }
    else{
        p->next=l.head;
        l.head=p;
    }
}

void DeleteFirst(List &l){
    if(l.head==NULL){
        return ;
    }
    Node*p=l.head;
    l.head=p->next;
    delete p;
}

void count(List &l, int _vmark){
    int dem=0;
    for(Node*k=l.head; k!=NULL; k=k->next){
        if(k->mark>=15){
            dem++;
        }
        cout<<dem<<endl;
    }
    for(Node *k=l.head; k!=NULL; k=k->next){
        if(k->mark>=15){
            cout<<k->name<<" "<<k->mark<<endl;
        }
    }
}

int main(){
    List l;
    newlist(l);
    string s;
    while(true){
        cin>>s;
        if(s=="ins"){
            string m;
            cin>>m;
            int d;
            cin>>d;
            InsertFirst(l,m,d);
        }
        if(s=="del"){
            DeleteFirst(l);
        }
        if(s=="count"){
            int d;
            cin>>d;
            count(l,d);
        }
        if(s=="END"){
            break;
        }
    }
}



