
// Faiz Ahmed
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
#define mx 100000

int main()
{
    int time,check=0,posx=0,posy=0;
    double XB[mx],YB[mx],XF[mx],YF[mx],VF,Dist,Sin_theta,Cos_theta;
    freopen("PurePursuit.txt","r",stdin);
    
    cout<<"Take input time : ";
    cin>>time;

    cout<<"Take input every time Target Position x and y coordinate: ";
    for(int i=0;i<=time;i++)
    {
        cin>>XB[i]>>YB[i];
        posx = min(posx,(int)XB[i]);
        posy = min(posy,(int)YB[i]);
    }
    
    cout<<"Take input Fighter Position x and y coordinate: ";
    cin>>XF[0]>>YF[0];

    cout<<"Take input fighter constant velocity : ";
    cin>>VF;

    for(int i=0;i<=time;i++)
    {
        Dist = sqrt(((YB[i]-YF[i])*(YB[i]-YF[i])) +((XB[i]-XF[i])*(XB[i]-XF[i])));
        Sin_theta = (YB[i]-YF[i])/Dist;
        Cos_theta = (XB[i]-XF[i])/Dist;
        XF[i+1] = XF[i]+VF*Cos_theta;
        YF[i+1] = YF[i]+VF*Sin_theta;

        posx = min(posx,(int)XF[i]);
        posy = min(posy,(int)YF[i]);

        if(Dist<=VF && i<time)
        {
            cout<<"Time : "<<i<<" Distance : "<<Dist<<endl;
            check=1;
            time=i;
            break;
        }    
    }

    if(!check) cout<<"Target Escaped!\n";

    //.....Plotting the graph....
    int gd=DETECT,gm;
    initgraph(&gd,&gm,NULL);

    int fct = 3,inc = 20,ymx,xmx; //inc for padding space side and down
    xmx = getmaxx();
    ymx = getmaxy();
    posx = abs(posx);
    posy = abs(posy);
    posx = posx+inc;
    posy = posy+inc;


    setcolor(6);
    line(posx*fct, 0, posx*fct, ymx); //y-axis
    line(0, ymx - posy*fct, xmx, ymx - posy*fct); //x-axis

    XB[0] = (XB[0]+posx)*fct;
    YB[0] = (YB[0]+posy)*fct;
    XF[0] = (XF[0]+posx)*fct;
    YF[0] = (YF[0]+posy)*fct;
    for(int i=1;i<=time;i++){

        XB[i] = (XB[i]+posx)*fct;
        YB[i] = (YB[i]+posy)*fct;
        XF[i] = (XF[i]+posx)*fct;
        YF[i] = (YF[i]+posy)*fct;

        setcolor(4);
        line(XB[i-1], ymx - YB[i-1], XB[i], ymx - YB[i]);
        delay(50);

        setcolor(2);
        line(XF[i-1], ymx - YF[i-1], XF[i], ymx - YF[i]);
        delay(50);
    }

    getch();
    closegraph();
    return 0;

}
