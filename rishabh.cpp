#include<bits/stdc++.h>
using namespace std;
double func(double x)
{

    return x*x*x + 2*x*x+x-1;
}
double derive(double x)
{

    return 3*x*x+4*x+1;
}
bool check_ivt(double a,double b)
{
    if(func(a)*func(b)<0)
    {
        return true;

    }
    return false;

}
int main()
{
    double a,b;
     double temp=func(0);
     double temp_index=0;
  for(double i=1;i<100;i++)
  {
      double f=func(i);

      if(temp<0 && f>=0 || temp>0 && f<=0)
      {
          a=temp_index;
          b=i;
          break;

      }
      temp=f;
      temp_index=i;


  }
  cout<<b<<" " <<temp_index<<endl;
    if(check_ivt(b,temp_index))
    {
        double x0=(a+b)/2;

  double x1=x0-func(x0)/derive(x0);
  double x2=x1-func(x1)/derive(x1);

  double x_cal;
  while(abs(x2-x1)>=0.0001)
  {
      x_cal=x2-func(x2)/derive(x2);
      x1=x2;

     x2=x_cal;



  }
  cout<<x_cal<<endl;
    }
    else
    {
        cout<<"find new interval"<<endl;
    }

return 0;
}
