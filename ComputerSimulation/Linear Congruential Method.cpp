#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,a,c,m,i,n=100;
    cout<<"Enter Seed (x0), constant multiplier (a), increment (c), and modulus (m) : ";

    freopen("Linear_congruential_method.txt","w",stdout);

    cin>>x>>a>>c>>m;

    for(i=0;i<=n;i++){
        x = (x*a + c)%m;
        cout<<((double)x/(double)m)<<" ";
    }

    return 0;
}