#include<bits/stdc++.h>
using namespace std;


int main()
{
    
    int n=5000,m=1000,opt,x,a,c;
    cout<<"Enter '1' to chose LCM, '2' to chose builtin fucntion : ";
    cin>>opt;
    //......segment one........
    //......open file..........
    ofstream  f_write;
    f_write.open("random_number.txt");

    if(opt==1){
        cout<<"Enter Seed (x0), constant multiplier (a) and increment (c) : ";
        cin>>x>>a>>c;
        for(int i=0;i<=n;i++)
        {
            x=(x*a+c)%m;
            f_write<<x<<" ";
        }
    }
    else{
        for(int i=0;i<=n;i++)
        {
            x=rand()%m;
            f_write<<x<<" ";
        }
    }
    f_write.close();

    ifstream f_read;
    f_read.open("random_number.txt");

    freopen("Chi_square.txt","w",stdout);

    int k=10,d=m/k,E=n/k,O[d+5],position,old=0,step=d/k,temp,rang=0;
    double chi_sqr,total=0;
    vector<int>vc;

    for(int i=0;i<n;i++)
    {
        f_read>>x;
        vc.push_back(x);
    }
    sort(vc.begin(),vc.end());

    for(int i=0;i<step;i++)
    {
        position=upper_bound(vc.begin(),vc.end(),(d*(i+1))-1)-vc.begin();
        O[i]=position-old;
        old=position;
    }

    cout<<"..............................................................................\n";
    cout<<"|  SL  |    Range    | Occurrence | Expected occ  |  (O-E)^2  |   (O-E)^2/E  |\n";
    cout<<"..............................................................................\n";

    for(int i=0;i<step;i++)
    {
        temp = (O[i]-E)*(O[i]-E);
        chi_sqr = (double)temp/(double)E;
        total += chi_sqr;
        printf("|  %2d  | %4d - %4d |    %4d    |     %4d      |  %7d  | %10.2lf   |\n",i,rang,rang+d-1,O[i],E,temp,chi_sqr);
        rang += d;
    }

    cout<<"..............................................................................\n";
    printf("|                                            Total chi-square = %10.4lf   |\n\n",total);
  
    if(total>=1.73 && total<=23.6) cout<<"Result : ACCEPTED\n";
    else cout<<"Result : NOT ACCEPTED\n";

    return 0;
}