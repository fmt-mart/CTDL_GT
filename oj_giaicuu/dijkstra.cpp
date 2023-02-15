#define maxf 1000000000
#define maxn 1000
#include<iostream>
using namespace std;

//cong thuc: d[v]=min(d[v], d[u]+len(u,v))
int a[maxn][maxn],n,m,s,e;
int f[maxn],trace[maxn],checkt2[maxn];

void nhap(){
	cin>>n>>m;
	cin>>s>>e;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			a[i][j]=0;
		}
	}
	for(int i=1; i<=m; i++){
		int u,v;
		cin>>u>>v;
		cin>>a[u][v];
		a[v][u]=a[u][v];
	}
}
void dijkstra(){
	for(int i=1; i<=n; i++){
		f[i]=maxf;
		checkt2[i]=true;
	}
	f[s]=0;
	int v=s, fmin, sum;
	while(v!=e){
		//tim v
		fmin=maxf;
		for(int i=1; i<=n; i++){
			if(checkt2[i] && fmin>f[i]){
				fmin=f[i];
				v=i;
				if(fmin==maxf){
					break;
				}
			}
		}
		//xoa v khoi T2
		checkt2[v]=false;
		//toi uu cac dinh trong T2
		for(int i=1; i<=n; i++){
			if(a[v][i]>0 && f[i]>f[v]+a[v][i]){
				f[i]=f[v]+a[v][i];
				trace[i]=v;
			}
		}
    }
}
void xuat(){
	cout<<f[e];
}
int main(){
	nhap();
	dijkstra();
	xuat();
}

