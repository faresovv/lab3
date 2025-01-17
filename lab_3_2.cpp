#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

double fmin(vector<double> xn) {
	double min = xn[0];
	for (int i = 1; i < xn.size(); i++) {
		if (xn[i] < min) {
			min = xn[i];
		}
	}
	return min;
}
double fmax(vector<double> xn) {
	double max = xn[0];
	for (int i = 1; i < xn.size(); i++) {
		if (xn[i] > max) {
			max = xn[i];
		}
	}
	return max;
}
double fn(vector<double> yn, vector<double> xn, double x)
{
	double result = 1.0;
	double k = 0.0;
	for (int i = 0; i < yn.size(); i++)
	{
		result = 1.0;
		for (int j = 0; j < xn.size(); j++)
		{
			if (i != j)
			{
				result *= (x - xn[j]) / (xn[i] - xn[j]);
			}

		}
		k += result * yn[i];
	}

	return k;
}
int main() {
	fstream fin;
	fin.open("18.csv", ios::in);
	double count;
	vector<vector<double>> row;
	string line, word, temp;
	getline(fin, line);
	int i = 0;
	while (!fin.eof()) {
		vector<double> n;
		n.clear();
		getline(fin, line);
		stringstream s(line);
		while (getline(s, word, ',')) {
			count = atof(word.c_str());
			n.push_back(count);
		}
		row.push_back(n);
	}
	fin.close();
	int m = 8;
	vector<double> yn;
	vector<double> xn;
	for (int i = 5; i < 17; i++)
	{
		if (row[i][m] == 999.9) continue;
		yn.push_back(row[i][m]);
	}
	int n = 0;
	for (int i = 5; i < 17; i++)
	{
		if (row[i][n] == 999.9) continue;
		xn.push_back(row[i][n]);
	}

	//	cout << fmin(xn) << endl << fmax(xn);
	double min = fmin(xn);
	double max = fmax(xn);
	double h = 0.1;
	double t = 0.0;
	vector<double> l;
	for (min; min <= max; min += h)
	{
		t = fn(yn, xn, min);
		l.push_back(t);

	}
	ofstream fout;
	fout.open("graf.txt");
	min = fmin(xn);
	for (int i = 0; i < l.size(); i++) {
		fout << min << " " << l[i] << endl;
		min += h;
	}
	fout.close();


	   /*import numpy as np
		import matplotlib.pyplot as plt
		data = np.loadtxt("graf.txt")
		plt.plot(data[:, 0], data[:, 1])
		plt.show()*/

	return 0;
}
