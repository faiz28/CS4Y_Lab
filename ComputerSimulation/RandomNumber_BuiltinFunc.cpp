#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n,x;
    freopen("RandomNumber_Builtinfunc.txt","w",stdout);
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        x = rand()%m;
        cout<<((double)x/(double)m)<<" ";
    }

    return 0;
}