#include<iostream>
using namespace std;

struct element{
    int data;
    element*next;
};
typedef element*List;
List first, last;

void khoitao(List &first, List &last){
    first=last=NULL;
}

element*taophantu(int x){
    element *p=new element;
    p->data=x;
    p->next=NULL;
    return p;
}

void themdau(List &first, List &last, int x){
    element*p=taophantu(x);
    if(first==NULL){
        first=last=p;
    }
    else{
        p->next=first;
        first=p;
    }
}

void themcuoi(List &first, List &last, int x){
    element*p=taophantu(x);
    if(first==NULL){
        first=last=p;
    }
    else{
        last->next=p;
        last=p;
    }
}

void xoadau(List &first, List &last){
    if(first==NULL){
        return;
    }
    element*p=first;
    first=first->next;
    delete p;
}

void xoacuoi(List &first, List &last){
    if(first==NULL){
        return;
    }
    else if(first->next==NULL){
        xoadau(first, last);
        return;
    }
    for(element*p=first;p!=NULL;p=p->next){
        if(p->next==last){
            delete last;
            p->next=NULL;//node ke cuoi tro den null
            last->next=p;//cap nhat lai last
            return;
        }
    }
}

element*timkiem(List first, List last, int k){
    for(element*p=first; p!=NULL; p=p->next){
        if(p->data==k){
            return p;
        }
    }
}

void xoaphantu(List &first, List &last, int k){
    if(first==NULL){
        return;
    }
    if(first->data==k){
        xoadau(first,last);
    }
    element*q=new element;//cho node q tro den truoc node can xoa
    // for(element*p=first;p!=NULL;p=p->next){
    //     if(p->data==k){
    //         q->next=p->next;//cap nhat lien ket node q voi node p
    //         delete p;
    //         return;
    //     }
    //     q=p;//cho node q tro den node p
    // }
    element*p=timkiem(first,last,k);
    q->next=p->next;
    delete p;
}

void xuat(List &first, List &last){
    for(element*p=first; p!=NULL; p=p->next){
        cout<<p->data<<" ";
    }
}

void menu(List &first, List &last){
    int luachon;
    while(true){
        system("cls");
        cout<<"\n\n\t\t==============MENU==============";
        cout<<"\n\t1. Them vao dau danh sach";
        cout<<"\n\t2. Them vao cuoi danh sach";
        cout<<"\n\t3. Xuat phan tu";
        cout<<"\n\t4. Xoa phan tu dau";
        cout<<"\n\t5. Xoa phan tu cuoi";
        cout<<"\n\t6. Xoa phan tu bat ky";
        cout<<"\n\t0. Thoat";
        cout<<"\n\t\t==============END==============";

        cout<<"\nNhap lua chon: "; cin>>luachon;
        if(luachon==1){
            int x;
            cout<<"\nNhap vao so nguyen: "; cin>>x;
            themdau(first,last,x);
        }
        else if(luachon==2){
            int x;
            cout<<"\nNhap vao so nguyen: "; cin>>x;
            themcuoi(first,last,x);
        }
        else if(luachon==3){
            xuat(first,last);
            system("pause");
        }
        else if(luachon==4){
            xoadau(first,last);
        }
        else if(luachon==5){
            xoacuoi(first,last);
        }
        else if(luachon==6){
            int k;
            cout<<"\nNhap so nguyen can xoa: "; cin>>k;
            xoaphantu(first,last,k);
        }
        else{
            break;
        }
    }
}

int main(){
    List first, last;
    khoitao(first, last);
    menu(first,last);
}
