#include<iostream>
#include<string>
using namespace std;

struct SinhVien{
    int stt;
    string hoten;
    float diem;
};

void khoitao(SinhVien a[], int &n){
    n=0;
}

void themcuoi(SinhVien a[], int &n, SinhVien k){
    for(int i=0; i<n; i++){
        a[n]=k;
    }
    n++;
}

void nhap(SinhVien a[], int &n){
    cout<<"\n\n\t\tNhap danh sach";
    cout<<"\nNhap so luong sinh vien: "; cin>>n;
    for(int i=0; i<n; i++){
        cout<<"\nNhap stt: "; cin>>a[i].stt;
        cout<<"\nNhap ho va ten: "; fflush(stdin); getline(cin, a[i].hoten);
        cout<<"\nNhap diem: "; cin>>a[i].diem;
    }
}

void themdau(SinhVien a[], int &n, SinhVien k){
    cout<<"\nNhap thong tin sinh vien can them vao dau danh sach"<<endl;
    cout<<"\nNhap stt: "; cin>>k.stt;
    cout<<"\nNhap ho va ten: "; fflush(stdin); getline(cin, k.hoten);
    cout<<"\nNhap diem: "; cin>>k.diem;
    for(int i=n-1; i>=0; i--){
        a[i+1]=a[i];
    }
    a[0]=k;
    n++;
}

void xuat(SinhVien a[], int &n){
    cout<<"\n\n\t\tXuat danh sach";
    for(int i=0; i<n; i++){
        cout<<"\nSTT: "<<a[i].stt;
        cout<<"\nHo va ten: "<<a[i].hoten;
        cout<<"\nDiem: "<<a[i].diem;
    }
}

int timkiemhoten(SinhVien a[], int &n){
    cout<<"\n\n\t\tTim kiem sinh vien theo ten";
    string k;
    cout<<"\nNhap ten cua sinh vien can tim kiem: "; fflush(stdin); getline(cin, k);
    for(int i=0; i<n; i++){
        if(a[i].hoten==k){
            cout<<"\nSTT: "<<a[i].stt;
            cout<<"\nHo va ten: "<<a[i].hoten;
            cout<<"\nDiem: "<<a[i].diem;
        }
    }
    return -1;
}

main(){
    SinhVien a[100];
    SinhVien k;
    int n=0;
    khoitao(a,n);
    nhap(a,n);
    themdau(a,n,k);
    xuat(a,n);
    timkiemhoten(a,n);
    // int n;
    // cout<<"\nNhap phan tu cua mang: "; cin>>n;
    // int a[50];
    // cout<<"\nNhap vao cac phan tu trong mang: ";
    // for(int i=0; i<n; i++){
    //     cin>>a[i];
    // }
    // cout<<"\nXuat danh sach mang: ";
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // int k;
    // cout<<"\n\nNhap phan tu can chen vao cuoi mang: "; cin>>k;
    // for(int i=0; i<n; i++){
    //     a[n]=k;
    // }
    // n++;
    // cout<<"\nXuat danh sach mang sau khi chen: "; 
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
    // int m;
    // cout<<"\n\nNhap phan tu can chen vao dau mang: "; cin>>m;
    // for(int i=n-1; i>=0; i--){
    //     a[i+1]=a[i];
    // }
    // a[0]=m;
    // n++;
    // cout<<"\nXuat danh sach mang sau khi chen: "; 
    // for(int i=0; i<n; i++){
    //     cout<<a[i]<<" ";
    // }
}