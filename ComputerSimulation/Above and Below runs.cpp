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
        cout<<"Enter Seed (x), constant multiplier (a) and increment (c) : ";
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


    int temp,check=-1,cnt=0,n1=0,n2=0;
    double chi_sqr,total=0,mean_middle=((double)m-1.0+0)/2.0;
	freopen("above_and_below_run_test.txt","w",stdout);

	cout<<"Sequence of Above and Below : \n";
    for(int i=0;i<=n;i++)
    {
        f_read>>x;
        if(mean_middle<x)
        {
            cout<<"+ ";
            if(check!=1) cnt++,n1++;
            check=1;
        }
        else{
            cout<<"- ";
            if(check!=0) cnt++,n2++;
            check=0;
        }
		
    }
	double mean,variance,z;
    mean = 2*n1*n2/n + .5;
    variance = 2*n1*n2*(2*n1*n2 - n)/n*n*(n-1);
    z = ((double)cnt - mean)/sqrt(variance);

	cout<<"\n\n";
	cout<<"Above from the mean : "<<n1<<"\nBelow from the mean  : "<<n2<<"\nMiddle position mean : "<<mean_middle<<"\nTotal_number : "<<n<<"\nNumber of runs : "<<cnt<<"\nMean : "<<mean<<"\nVariance : "<<variance<<"\nZ : "<<z<<endl;

	if(z>=-1.96 && z <= 1.96) cout<<"Result : ACCEPTED\n";
	else cout<<"Result : Not ACCEPTED\n";

    

    return 0;
}