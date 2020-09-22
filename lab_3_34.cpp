#include<iostream>
#include<vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
int fact(int n){
if(n==1)
  return 1;
return n*fact(n-1);
}
double raznx1(double x , std::vector<double> xl,int i){
double rez1 = 1;
for(int j = 0 ; j<i ; j++ ){
    rez1*=(x-xl[j]);
}
return rez1;
}
double razny1(std::vector<double>&yl,int i){
switch(i){
   case 1: return yl[1]-yl[0]; break;
   case 2: return yl[2]-2*yl[1]+yl[0]; break;
   case 3: return yl[3]-3*yl[2]+3*yl[1]-yl[0]; break;
   case 4: return yl[4]-4*yl[3]+6*yl[2] - 4*yl[1]+yl[0] ; break;
   case 5: return yl[5]- 5*yl[4]+10*yl[3] - 10*yl[2] + 5*yl[1] - yl[0]; break;

}
return 1;
}
double raznx2(double x,std::vector<double>xl, int i){
double rez2 =1;
reverse(xl.begin(),xl.end());
for(int j = 0 ; j<=i ; j++){
    rez2*=(x-xl[j]);
}
return rez2;
}
double razny2(std::vector<double>&yl ,int i ){
switch (i){
  case 1: return yl[5]-yl[4]; break;
  case 2: return yl[5]-2*yl[4]+yl[3]; break;
  case 3: return yl[5]-3*yl[4]+3*yl[3]-yl[2]; break;
  case 4: return yl[5]-4*yl[4]+6*yl[3]-4*yl[2]+yl[1] ; break;
  case 5: return yl[5]-5*yl[4]+10*yl[3] - 10*yl[2] + 5*yl[1] - yl[0]; break;
}
return 1;
}
double nyton1(vector<double> &yl, vector<double> &xl , double h , double x ){
double rezz1 = yl[0];
for(int i = 1  ; i <=5; i++){
  rezz1+=razny1(yl,i)*raznx1(x,xl,i)/fact(i)/pow(h,i);

}
return rezz1;
}

double nyton2(vector <double>&yl ,vector<double>&xl, double h , double x){
double rezz2 = yl[yl.size()-1];
for(int i = 1 ; i<6 ; i++){

  rezz2+=razny2(yl,i)*raznx2(x,xl,i)/fact(i)/pow(h,i);

}
return rezz2;
}
int main(){
	string str,word;
	ifstream In("18.csv");
	vector<vector<double>>b;
	vector<double> c;
	double number;
	getline(In,str);
	while ( ! In.eof())
	{
	  getline (In, str);
	  stringstream s(str);
	while(getline(s,word,',')){
	  number = stod(word); c.push_back(number);
	  if(c.size()==14){ b.push_back(c);
	  c.clear(); continue;
	}}}
	vector<double>xl2,yl2;
	for(int i = 85 ; i < 91 ; i++){
	  yl2.push_back(b[i][6]);
	}
	for(int j = 85 ; j < 91 ; j++ ){
	  xl2.push_back(b[j][0]);
}
for(int i = 0 ; i <yl2.size();i++){
	cout<<yl2[i]<<endl;
}
ofstream file1 , file2;
file1.open("laba31.txt");
file2.open("laba32.txt");
for(int i = 0 ; i < 6 ; i++){
  file1<<xl2[i]<<" "<<nyton1(yl2,xl2,1,xl2[i])<<endl;
}
for(int i = 0 ; i < 6 ; i++){
  file2<<xl2[i]<<" "<<nyton2(yl2,xl2,1,xl2[i])<<endl;
}
system("python3 3laba34.py");


       /*import numpy as np
		import matplotlib.pyplot as plt
		data = np.loadtxt("laba31.txt")
		plt.plot(data[:, 0], data[:, 1])
		plt.show()*/

	   /*import numpy as np
	   import matplotlib.pyplot as plt
		data = np.loadtxt("laba32.txt")
		plt.plot(data[:, 0], data[:, 1])
		plt.show()*/


return 0;
}
