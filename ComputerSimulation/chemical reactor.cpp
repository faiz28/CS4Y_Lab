//Faiz Ahmed
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define MX 100000
int main()
{
	double k1,k2,A[MX],B[MX],C[MX],time=5,dt=0.10,mx;

	freopen("Chemical_Reactor.txt","r",stdin);

	cout<<"Take input k1 and k2 : ";
	cin>>k1>>k2;
	cout<<"Take input initial A and B : ";
	cin>>A[0]>>B[0];
	C[0]=0;

	cout<<"\n-----------------------------------------------------\n";
	cout<<"Time\t\t A(t)\t\t B(t)\t\t C(t)\n";
	cout<<"-------------------------------------------------------\n";
	cout<<0<<"\t\t"<<A[0]<<"\t\t"<<B[0]<<"\t\t"<<C[0]<<endl;

	int ind=0;
	for(double i=0;i<=time;i+=dt)
	{
		ind++;
		A[ind] = A[ind-1] + (k2*C[ind-1] - k1*A[ind-1]*B[ind-1])*dt;
        	B[ind] = B[ind-1] + (k2*C[ind-1] - k1*A[ind-1]*B[ind-1])*dt;
        	C[ind] = C[ind-1] + (2*k1*A[ind-1]*B[ind-1] - 2*k2*C[ind-1])*dt;
		cout<<i<<"\t\t"<<A[ind]<<"\t\t"<<B[ind]<<"\t\t"<<C[ind]<<endl;
		mx=max(A[ind],max(B[ind],C[ind]));
	}

	//Graphics Part:

	int gd=DETECT,gm;
    	initgraph(&gd,&gm,NULL);
	int x,y,space= 50,ymax,xmax; 
    	ymax = getmaxy();
	xmax=getmaxx();

	// initial x and y coordinate
	x = (xmax-space)/ind; 
	y = (ymax-space*4)/(int)mx;

	setcolor(9);
	line(space, 0, space, xmax);   //y-axis
	line(0, ymax-space, xmax, ymax - space); // x-axis

	for(int j=1,k=space+x; j<=ind; j++,k+=x){
        	setcolor(15);
		line(k-x, ymax - space - A[j-1]*y, k, ymax - space - A[j]*y);
		delay(10);

		setcolor(2);
		line(k-x, ymax - space - B[j-1]*y, k, ymax - space - B[j]*y);
		delay(10);

		setcolor(4);
		line(k-x, ymax - space - C[j-1]*y, k, ymax - space - C[j]*y);
		delay(10);
	}

	getch();
	closegraph();


}
