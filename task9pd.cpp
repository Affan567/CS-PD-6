#include<iostream>
using namespace std;
main()
{
    int h,x,y,x_1,x_2,x_3,y_1,y_2,y_3,y_4,x_0=0,y_0=0;
    cout<<"Enter height";
    cin>>h;
    cout<<"Enter X-coordinate: ";
    cin>>x;
    cout<<"Enter Y-coordinate: ";
    cin>>y;
    x_1 = h;
    x_2 = 2*h;
    x_3 = 3*h;
    y_1 =h;
    y_4 = 4*h;
    if((x>=x_0 && x<=x_3 && y==y_0 )||( y==y_1 &&  x>=x_0 && x<=x_3))
        cout<<"On boundary";
    else if(x>x_0 && x<x_3 && y>y_0 && y <y_1)
        cout<<"Inside";
    else if(x>x_1 && x<x_2 && y>y_0 && y<y_4 )
        cout<<"Inside";
    else if((y>=y_0 && y<=y_4 && x==x_1) || (y>=y_0 && y<=y_4  && x==x_2)  || ( y==y_4 && x>=x_1 && x <=x_2))
        cout<<"On boundary";
    else
        cout<<"Outside";  

}