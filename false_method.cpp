#include<bits/stdc++.h>
using namespace std;


double solution(double x)
    {

        return x*x*x -2 *x -5;
    }

int ibt(double a,double x,double b)
{
    if((solution(a)*solution(x)) <0 )
    {
        return 1;
    }
    else if((solution(x) *solution(b)) <0)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
int main()
{
    double temp=0;
    double a;
    double b;
    for(double i=1;i<100;i++)
    {
        if(solution(i)< 0 && solution(temp)>0 || solution(i)> 0 && solution(temp)<0)
        {
             a=temp;
             b=i;
             break;

        }
        temp=i;

    }

    double x =(a*solution(b) - b*solution(a))/( solution(b)- solution(a));
     while((x-a) >= 0.0001 || (x-b) >= 0.0001)
    {

        int check_ibt=ibt(a,x,b);
         if(check_ibt == 1)
            {
                 b=x;
                 cout<<"the new interval is : "<<'('<< a <<"-"<<b<<")"<<endl;
            }
        else if(check_ibt == 0 )
            {
                 a=x;
                 cout<<"the new interval is : "<<'('<< a <<"-"<<b<<")"<<endl;
            }
            x=(a*solution(b) - b*solution(a))/( solution(b)- solution(a));

    }
    cout<<"the answer is : "<<x<<endl;



   cout<<x;

    return 0;
}
