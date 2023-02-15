//ky thuat them 1 mode p vao sau node q
#include<iostream>
using namespace std;

//nhao danh sach lien ket don cac so nguyen
//khai bao cau truc danh sach lien ket don
struct node{
    int data;
    struct node *pNext;
};
typedef struct node Node;
//khai bao cau truc danh sach lien ket don
struct list{
    Node *pHead;
    Node *pTail;
};
typedef struct list List;
//khoi tao cau truc danh sach lien ket don
void khoitaoDSLK(List &l){
    //cho hai dau tro den vung nho rong
    l.pHead=NULL;
    l.pTail=NULL;
}
//ham khoi tao node
Node *khoitaonode(int x){
    Node *p=new Node;
    if(p==NULL){
        cout<<"khong du bo nho de cap phat";
        return NULL;
    }
    p->data=x;
    p->pNext=NULL;
    return p;
}
void themvaodau(List &l, Node *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        p->pNext=l.pHead;
        l.pHead=p;
    }
}
void themvaocuoi(List &l, Node *p){
    if(l.pHead==NULL){
        l.pHead=l.pTail=p;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void xuatdanhsach(List l){
    for(Node *k=l.pHead; k!=NULL; k=k->pNext){
        cout<<k->data<<" ";
    }
}
//them node p vao sau node q(nam trong danh sach lien ket don)
void themnode_p_vaosaunode_q(List &l, Node *p){
    int x;
    cout<<"\nnhap gia tri node q: ";
    cin>>x;
    Node *q=khoitaonode(x);
    //neu danh sach chi co 1 phan tu va phan tu do cung chinh la node q => bai toan tro thanh ky thuat them vao cuoi danh sach
    if(q->data==l.pHead->data && l.pHead->pNext==NULL){
        themvaocuoi(l,p);
    }
    else{
        //CACH 1: NEU TRONG DANH SACH TON TAI 1 NODE Q TRONG DANH SACH
        ////duyet danh sach tu dau den cuoi de tim node q
        //for(Node *k=l.pHead; k!=NULL; k=k->pNext){
        //    //neu node q co ton tai thi them node p vao sau node q
        //    if(q->data==k->data){
        //        Node *g = k->pNext;//cho cai node g tro den node nam sau node q
        //        p->pNext=g;//b1: tao moi lien ket tu node p den node g <=> cung chinh la tao moi lien ket tu node p den node nam sau node q
        //        k->pNext=p;//b2: tao moi lien ket tu node q den node p <=> chinh la node k den node p
        //    }
        //}
        //CACH 2: TRONG DANH SACH TON TAI 2 PHAN TU NODE Q TRO LEN
        //duyet danh sach tu dau den cuoi de tim node q
        for(Node *k=l.pHead; k!=NULL; k=k->pNext){
            //neu node q co ton tai thi them node p vao sau node q
            if(q->data==k->data){
                Node *h=khoitaonode(p->data); //khoi tao node h moi de them vao node q
                Node *g = k->pNext;//cho cai node g tro den node nam sau node q(giu lien ket)
                h->pNext=g;//b1: tao moi lien ket tu node h den node g <=> cung chinh la tao moi lien ket tu node h den node nam sau node q
                k->pNext=h;//b2: tao moi lien ket tu node q den node h <=> chinh la node k den node h
            }
        }
    }
}
void themnode_p_vaotruocnodeq(List &l, Node *p){
    int x;
    cout<<"\nnhap gia tri node q: ";
    cin>>x;
    Node *q=khoitaonode(x);
    if(q->data==l.pHead->data && l.pHead->pNext==NULL){
        themvaodau(l,p);
    }
    else{
        //CACH1:   NEU TRONG DANH SACH CHI TON TAI MOT NODE Q
        //Node *g=new Node;
        //for(Node *k=l.pHead; k!=NULL; k=k->pNext){
        //    if(q->data==k->data){
        //        //thuc hien bai toan them node p sau node g la ra van de <=> thme node p vao truoc node q
        //        Node *g=k->pNext;
        //        p->pNext=k; //b1: cho node p tro(lien ket) den node k 
        //        g->pNext=p; //b2: cho node g tro(lien ket) den node p
        //    }
        //    g=k;//giu lien ket voi node nam truoc node q trong danh sach
        //}
        //CACH2:    TRONG DANH SACH TON TAI TU 2 NODE Q TRO LEN
        Node *g=new Node;
        for(Node *k=l.pHead; k!=NULL; k=k->pNext){
            if(q->data==k->data){
                //thuc hien bai toan them node p sau node g la ra van de <=> them node p vao truoc node q
                Node *h=khoitaonode(p->data);//moi lan phat hien 1 node q thi ta khoi tao 1 node p moi <=> khoi tao node h
                h->pNext=k; //b1: cho node h tro(lien ket) den node k 
                g->pNext=h; //b2: cho node g tro(lien ket) den node h
            }
            g=k;//giu lien ket voi node nam truoc node q trong danh sach
        }
    }
}

//them node p vao vi tri bat ki vt trong danh sach
void themnode_p_vaovitribatky(List &l, Node *p, int vt, int n){
    //danh sach dang rong
    if(l.pHead==NULL || vt==1){
        //them node p vao dau
        themvaodau(l,p);
    }
    else if(vt==n+1){
        //them node p vao cuoi danh sach
        themvaocuoi(l,p);
    }
    //vt nam trong doan [2,n]
    else{
        int dem=0; //xac dinh vt can them
        Node *g=new Node;
        for(Node *k=l.pHead; k!=NULL; k=k->pNext){
            dem++;
            //tim vi tri vt can them
            if(dem==vt){
                //thuc hien bai toan them node p sau node g la ra van de <=> thme node p vao truoc node q
                Node *h=khoitaonode(p->data);//moi lan phat hien 1 node q thi ta khoi tao 1 node p moi <=> khoi tao node h
                h->pNext=k; //b1: cho node h tro(lien ket) den node k 
                g->pNext=h; //b2: cho node g tro(lien ket) den node h
                break;
            }
            g=k;//giu lien ket voi node nam truoc node q trong danh sach
        }
    }
}
//ham xoa dau
void xoadau(List &l){
    if(l.pHead==NULL){
       return;
    }
    Node*p=l.pHead;
    l.pHead=p->pNext;
    delete p;
}
//ham xoa cuoi
void xoacuoi(List &l){
    if(l.pHead==NULL){
       return;
    }
    //truong hop danh sach co 1 phan tu
    if(l.pHead->pNext==NULL){
        xoadau(l);
        return; 
    }
    //duyet dau danh sach den ke cuoi 
    for(Node*k=l.pHead; k!=NULL; k=k->pNext){
        //phat hien thang ke cuoi
        if(k->pNext==l.pTail){
            delete l.pTail; 
            k->pNext=NULL;
            l.pTail=k;
            return;
        }
    }
}
//ham xoa 1 node nam sau node q trong danh sach
void xoasaunode_q(List &l, Node*q){
    //duyet danh sach tu dau den cuoi de tim node q
    for(Node *k=l.pHead; k!=NULL; k=k->pNext){
        if(k->data==q->data){
            Node*g=k->pNext;//node g chinh la node nam sau node k(nam sau node q) <=> node ma ta se xoa
            k->pNext=g->pNext;//cap nhat moi lien ket giua node k(node q) voi node sau node g
            delete g;//xoa node nam sau node q
        }
    }
}
void xoanodecokhoabatky(List &l, int x){
    //neu node can xoa nam dau danh sach
    if(l.pHead->data==x){
        xoadau(l);
        return;
    }
    //neu node can xoa nam cuoi danh sach
    if(l.pTail->data==x){
        xoacuoi(l);
        return;
    }
    //duyet danh sach lien ket don de tim
    Node*g=new Node; //node g la node tro den node nam truoc node can xoa: x;
    for(Node *k=l.pHead; k!=NULL; k=k->pNext){
        //phat hien phan tu can xoa 
        if(k->data==x){
            g->pNext=k->pNext;//cap nhat moi lien ket giua node k(node q) voi node sau node g
            delete k;//xoa node nam sau node q
            return;
        }
        g=k;//cho node g tro den k
    }
}
//menu
void menu(List &l){
    int luachon;
    while(true){
        system("cls");
        cout<<"\n\n\t\t==========MENU==========";
        cout<<"\n\t1. them node cho danh sach";
        cout<<"\n\t2. xuat danh sach lien ket don";
        cout<<"\n\t3. them node p vao sau node q vao trong danh sach";
        cout<<"\n\t4. them node p vao truoc node q vao trong danh sach";
        cout<<"\n\t5. them node p vao vi tri bat ky trong danh sach";
        cout<<"\n\t6. xoa node p o dau danh sach";
        cout<<"\n\t7. xoa node p o cuoi danh sach";
        cout<<"\n\t8. xoa node sau node q";
        cout<<"\n\t9. xoa node khoa k bat ky";
        cout<<"\n\t0. thoat";
        cout<<"\n\n\t\t==========END==========";
        cout<<"\n nhap lua chon: ";
        cin>>luachon;
        if(luachon<0 || luachon>9){
            cout<<"\n lua chon khong hop le. Xin kiem tra lai !";
            system("pause");
        }
        if(luachon==1){
            int x;
            cout<<"\n nhap gia tri so nguyen: ";
            cin>>x;
            Node *p = khoitaonode(x);
            themvaocuoi(l,p);
        }
        else if(luachon==2){
            xuatdanhsach(l);
            system("pause");
        }
        else if(luachon==3){
            int x;
            cout<<"\n nhap gia tri node p can them vao sau: ";
            cin>>x;
            Node *p=khoitaonode(x);
            themnode_p_vaosaunode_q(l,p); //them node p vao sau node q trong danh sach l
        }
        else if(luachon==4){
            int x;
            cout<<"\n nhap gia tri node p can them vao truoc: ";
            cin>>x;
            Node *p=khoitaonode(x);
            themnode_p_vaotruocnodeq(l,p); //them node p vao truoc node q trong danh sach l
        }
        else if(luachon==5){
             //vong lap lay so luong danh sach
            int n=0;
            for(Node *k=l.pHead; k!=NULL; k=k->pNext){
                n++; 
            }
            //khoi tao gia tri cho node p
            int x;
            cout<<"\n nhap gia tri node p: ";
            cin>>x;
            Node*p=khoitaonode(x);
            //nhap vi tri can them cho node p ==> can kiem tra dieu kien
            int vt;
            do
            {
                cout<<"\n nhap vi tri can them node p: ";
                cin>>vt;
                if(vt<1 || vt>n+1){
                    cout<<"\n vi tri can them phai nam trong doan [1,"<<n+1<<"]";
                    system("pause");
                }
            } while (vt<1 || vt>n+1);
            themnode_p_vaovitribatky(l,p,vt,n);
            
        }
        else if(luachon==6){
            xoadau(l);
        }
        else if(luachon==7){
            xoacuoi(l);
        }
        else if(luachon==8){
            int x;
            cout<<"\n nhap node q: ";
            cin>>x;
            Node*q=khoitaonode(x);
            xoasaunode_q(l,q);
        }
        else if(luachon==9){
            int x;
            cout<<"\n nhap node q: ";
            cin>>x;
            xoanodecokhoabatky(l,x);
        }
        else{
            break;//thoat khoi vong lap hien tai
        }
    }
}
int main(){
    List l;
    khoitaoDSLK(l);//luon luon goi ham khoi tao DSLKD truoc khi thao tac voi danh sach
    menu(l);
    system("pause");
    return 0;
}
