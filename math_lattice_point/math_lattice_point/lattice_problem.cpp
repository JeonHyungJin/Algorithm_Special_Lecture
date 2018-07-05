#include<iostream>
using namespace std;

int GCD(int n1, int n2)	//유클리드 호제법
{
	int temp;
	if (n1 < n2) {
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	while (n2 != 0) {
		temp = n1%n2;
		n1 = n2;
		n2 = temp;
	}
	return n1;	//n1과 n2의 최대 공약수 
}


int main() {
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	int point = GCD(x2-x1, y2-y1);
	point = point - 1;	//구간 수 -1개의 격자점이 존재

	cout << point;
	return 0;
}