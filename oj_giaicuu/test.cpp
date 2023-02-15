#include<iostream>
using namespace std;
#include<vector>

/*cu phap: vector<T> <ten vector>
T: kieu du lieu cua mang 1 chieu cua vector ma chung ta se dung
vector<int> arr: khai bao mang vector chua cac so nguyen 
vector<Sinhvien> list: khai bao mang vector chua sinh vien
*/

void xuat_mang(vector<int>arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr.at(i)<<" ";
    }
}

int main(){
    vector<int>arr; //khai bao mang vector chua so nguyen
    for(int i=0; i<5; i++){
        arr.push_back(i); //them phan tu i vao cuoi mang vector
    }
    // cout<<"\n\n\t\tXuat mang\n";
    // xuat_mang(arr);
    // cout<<"\nPhan tu dau tien cua mang vector: "<<arr.front();
    // cout<<"\nPhan tu cuoi cung cua mang vector: "<<arr.back();
    // arr.pop_back();
    // cout<<"\n\n\t\tXuat mang\n";
    // xuat_mang(arr);
    
    // cout<<"\nKich thuoc thuc su cua mang vector hien tai: "<<arr.capacity();
    // cout<<"\nSo luong phan tu co the chua duoc trong vector: "<<arr.max_size();

    // arr.erase(arr.begin()+2); //xoa di 1 phan tu trong mang
    // cout<<"\n\n\t\tMang sau khi xoa\n";
    // xuat_mang(arr);

    // arr.insert(arr.begin()+2,69); //them mot phan tu tai vi tri trong mang
    // cout<<"\n\n\t\tMang sau khi them\n";
    // xuat_mang(arr);
    // arr.clear(); //xoa het tat ca cac phan tu hien co trong mang vector
    // cout<<"\nSo luong phan tu hien co trong vector: "<<arr.size();
    vector<int>x;
    for(int i=0; i<15; i++){
        x.push_back(i);
    }
    arr.swap(x); //hoan doi 2 cai mang vector cho nhau
    cout<<"\n\n\t\t xuat mang arr sau khi hoan doi\n";
    xuat_mang(arr);
    cout<<"\n\n\t\t xuat mang x sau khi hoan doi\n";
    xuat_mang(x);
    return 0;
}