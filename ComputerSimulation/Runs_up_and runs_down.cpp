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


    int temp,check=-1,cnt=0;
    double chi_sqr,total=0;
    vector<int>vc;
	freopen("up_and_down_run_test.txt","w",stdout);
	cout<<"Sequence of ups and downs : \n";
    for(int i=0;i<=n;i++)
    {
        f_read>>x;
		if(i==0){
			temp=x;
		}
		else{
			if(temp<x)
			{
				cout<<"+ ";
				if(check!=1) cnt++;
				check=1;
				temp=x;
			}
			else{
				cout<<"- ";
				if(check!=0) cnt++;
				check=0;
				temp=x;
			}
		}
    }
	cout<<endl;
	double mean,variance,z;
	mean = (2*n-1)/3;
    variance = (16*n-29)/90;
    z = ((double)cnt - mean)/sqrt(variance);

	cout<<"\n\n";
	cout<<"Total Number : "<<n<<"\nNumber of runs : "<<cnt<<"\nMean : "<<mean<<"\nVariance : "<<variance<<"\nZ : "<<z<<endl;

	if(z>=-1.96 && z <= 1.96) cout<<"Result : ACCEPTED\n";
	else cout<<"Result : Not ACCEPTED\n";

    

    return 0;
}