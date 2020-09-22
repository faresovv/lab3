#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

double * gauss(double **a, double *y, int n)
{
  double *x, max;
  int k, index;
  const double eps = 0.00001;  // ????????
  x = new double[n];
  k = 0;
  while (k < n)
  {
    // ????? ?????? ? ???????????? a[i][k]
    max = abs(a[k][k]);
    index = k;
    for (int i = k + 1; i < n; i++)
    {
      if (abs(a[i][k]) > max)
      {
        max = abs(a[i][k]);
        index = i;
      }
    }
    // ???????????? ?????
    if (max < eps)
    {
      // ??? ????????? ???????????? ?????????
      cout << "??????? ???????? ?????????? ??-?? ???????? ??????? ";
      cout << index << " ??????? A" << endl;
      return 0;
    }
    for (int j = 0; j < n; j++)
    {
      double temp = a[k][j];
      a[k][j] = a[index][j];
      a[index][j] = temp;
    }
    double temp = y[k];
    y[k] = y[index];
    y[index] = temp;
    // ???????????? ?????????
    for (int i = k; i < n; i++)
    {
      double temp = a[i][k];
      if (abs(temp) < eps) continue; // ??? ???????? ???????????? ??????????
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] / temp;
      y[i] = y[i] / temp;
      if (i == k)  continue; // ????????? ?? ???????? ???? ?? ????
      for (int j = 0; j < n; j++)
        a[i][j] = a[i][j] - a[k][j];
      y[i] = y[i] - y[k];
    }
    k++;
  }
  // ???????? ???????????
  for (k = n - 1; k >= 0; k--)
  {
    x[k] = y[k];
    for (int i = 0; i < k; i++)
      y[i] = y[i] - a[i][k] * x[k];
  }
  return x;
}



int main()
{
string str,word;
ifstream In("18_.csv");
vector<vector<double>>b;
vector<double> c;
double number;
getline(In,str);
while ( ! In.eof())
{
  getline (In, str);
  stringstream s(str);
while(getline(s,word,',')){
  number = stoi(word); c.push_back(number);
  if(c.size()==14){ b.push_back(c);
  c.clear(); continue;
}}}
vector<double>yl3;
vector<double>xl3;
for(int i = 0 ; i <b.size() ; i++){
  if(b[i][5]!=999)yl3.push_back(b[i][5]);
}

int i = 0 ;
while(i<yl3.size()){
  xl3.push_back(i);
  i++;
}
static double d=0,g=0,h=0,l=0,z=0,o=0,e=0,w=0;
vector<vector<double>> newxl;
vector<double> to;
for(int i = 0 ; i<xl3.size(); i++){
d+=xl3[i];
g+=pow(xl3[i],2);
h+=pow(xl3[i],3);
l+=pow(xl3[i],4);
z+=pow(xl3[i],5);
o+=pow(xl3[i],6);
e+=pow(xl3[i],7);
w+=pow(xl3[i],8);
}
to.push_back(152);
to.push_back(d);
to.push_back(g);
to.push_back(h);
to.push_back(l);
newxl.push_back(to);
to.clear();
to.push_back(d);
to.push_back(g);
to.push_back(h);
to.push_back(l);
to.push_back(z);
newxl.push_back(to);
to.clear();
to.push_back(g);
to.push_back(h);
to.push_back(l);
to.push_back(z);
to.push_back(o);
newxl.push_back(to);
to.clear();
to.push_back(h);
to.push_back(l);
to.push_back(z);
to.push_back(o);
to.push_back(e);
newxl.push_back(to);
to.clear();
to.push_back(l);
to.push_back(z);
to.push_back(o);
to.push_back(e);
to.push_back(w);
newxl.push_back(to);
double r=0,t=0,p=0,v=0,u=0;
vector<double>newy;
for(int i = 0 ; i<152;i++){
  r+=yl3[i];
  t+=yl3[i]*xl3[i];
  p+=yl3[i]*pow(xl3[i],2);
  v+=yl3[i]*pow(xl3[i],3);
  u+=yl3[i]*pow(xl3[i],4);
}
newy.push_back(r);
newy.push_back(t);
newy.push_back(p);
newy.push_back(v);
newy.push_back(u);

  double **a, *y, *x;
  int n=5;

  a = new double*[n];
  y = new double[n];
  for (int i = 0; i < n; i++)
  {
    a[i] = new double[n];
    for (int j = 0; j < n; j++)
    {
      a[i][j]=newxl[i][j];
    }
  }
  for (int i = 0; i < n; i++)
  {

    y[i]=newy[i];
  }

  x = gauss(a, y, n);
ofstream file("laba33.txt");
for(int i = 0 ; i<152 ; i++){
double rez = x[0]+x[1]*i+x[2]*i*i+x[3]*i*i*i+x[4]*i*i*i*i;
file<<i<<" "<<rez<<endl;
}
system("python3 3laba5.py");



     /*import numpy as np
	 import matplotlib.pyplot as plt
	 data = np.loadtxt("laba33.txt")
	 plt.plot(data[:, 0], data[:, 1])
	 plt.show()*/

return 0;
}
