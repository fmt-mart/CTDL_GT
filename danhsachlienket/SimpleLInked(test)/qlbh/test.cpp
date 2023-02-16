#include<iostream>
#include<string>
using namespace std;

struct LinkedList{
    string ten;
    int soluong;
    int dongia;
    struct LinkedList*next;
};
typedef LinkedList*List;
List head,tail;

void khoitao(List &head, List &tail){
    head=tail=NULL;
}

LinkedList*taophantu(string _ten, int _soluong, int _dongia){
    LinkedList*p=new LinkedList;
    p->ten=_ten;
    p->soluong=_soluong;
    p->dongia=_dongia;
    p->next=NULL;
    return p;
}

void InsertFirst(List &head, List &tail, string _ten, int _soluong, int _dongia){
    LinkedList*p=taophantu(_ten, _soluong, _dongia);
    if(head==NULL){
        head=tail=p;
    }
    else{
        p->next=head;
        head=p;
    }
}

int Sum(List head, string t){
    int sum=0;
    for(LinkedList*p=head;p!=NULL;p=p->next){
        if(p->ten==t){
            sum+=(p->soluong)*(p->dongia);
        }
    }
    return sum;
}

int main(){
    List head, tail;
    khoitao(head,tail);
    string _ten, s;
    int _soluong, _dongia;
    while(true){
        cin>>s;
        if(s=="Add"){
            cin.ignore();
            cin>>_ten>>_soluong>>_dongia;
            InsertFirst(head,tail,_ten,_soluong,_dongia);
        }
        else if(s=="Sum"){
            cin>>_ten;
            cout<<Sum(head,_ten)<<"\n"; 
        }
        else if(s=="Fin"){
            break;
        }
    }
}