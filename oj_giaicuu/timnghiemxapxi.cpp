#include<iostream>
#include<math.h>
using namespace std;

double f(double x){
    return 2*pow(x,4)+5*pow(x,3)-9*pow(x,2)-11*x+4;
}
double half(double a, double b, double e){
    double c=(a+b)/2, delta=b-a;
    while(delta>e){
        if(f(a)*f(c)<=0){
            b=c;
            delta=b-a;
            c=(b+a)/2;
        }
        else{
            a=c;
            delta=b-a;
            c=(b+a)/2;
        }
    }
    return c;
}
int main(){
    double a, b, e;
    cin>>a>>b>>e;
    cout<<half(a,b,e);
}