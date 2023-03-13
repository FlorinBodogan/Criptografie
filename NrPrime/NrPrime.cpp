#include<iostream>
#include<math.h>
using namespace std;

//#include <iostream>
//#include<math.h>
//using namespace std;
//
//bool prim(int n) {
//    n = abs(n);
//    if (n < 2) return false;
//    if (n == 2) return true;
//    if (n % 2 == 0) return false;
//    for (int i = 3; i < sqrt(n); i += 2)
//        if (n % i == 0) return false;
//    return true;
//}
//
//int main()
//{
//    cout << prim(31) << endl;
//    cout << prim(25) << endl;
//    cout << prim(32) << endl;
//}

//#include <iostream>
//#include <stdlib.h>
//#include <time.h>
//using namespace std;
//unsigned long long cmmdc(unsigned long long x, unsigned long long y) {
//	if (x == 0 || y == 0)
//		return x + y;
//	unsigned long long r;
//	do {
//		r = x % y;
//		x = y;
//		y = r;
//	} while (r != 0);
//	return x;
//
//}
//unsigned long long a_la_b_mod_c(unsigned long long a, unsigned long long b, unsigned long long c) {
//
//	int p = 1;
//	a = a % c;
//	while (b > 0)
//	{
//		if (b % 2)
//			p = (p * a) % c;
//		a = (a * a) % c;
//		b /= 2;
//	}
//	return p;
//}
//
//bool test_Fermat(unsigned long long n, unsigned int nr_incercari) {
//	if (n == 2)return 1;
//	if (n % 2 == 0)return 0;
//	for (; nr_incercari > 0; nr_incercari--) {
//		int random1 = rand(), random2 = rand();
//		long long b = (random1 << 16) | random2;//pentru a avea numar obtinut random mare(rand intoarce un int)
//		b = 2 + b % (n - 2);
//		if (cmmdc(b, n) != 1)return 0;
//		if (a_la_b_mod_c(b, n - 1, n) != 1)return 0;
//	}
//	return 1;
//}
//void main() {
//	unsigned long long n, nr_incercari;
//	srand(time(NULL));
//	cout << "Programul va stabili daca numarul ""n"" poate fi prim aplicand testul Fermat de un numar dat de ori" << endl;
//	cout << "\nDati un numar natural nenul-->";
//	cin >> n;
//	cout << "\nDati numarul maxim de incercari-->";
//	cin >> nr_incercari;
//	if (test_Fermat(n, nr_incercari))
//		cout << "\nNumarul " << n << " poate fi prim" << endl;
//	else
//		cout << "\nNumarul " << n << " nu este prim" << endl;
//	system("pause");
//}


int** factor(unsigned int n, int& nr)
{
	int** descompunere = new int* [2];
	descompunere[0] = new int[n];
	descompunere[1] = new int[n];
	int copyN = n;
	for (unsigned long long i = 0; i < n; i++)
		descompunere[0][i] = descompunere[1][i] = 0;
	if (n % 2 == 0)
	{
		descompunere[0][0] = 2;
		nr++;
		while (n % 2 == 0)
		{
			descompunere[1][0]++;
			n /= 2;
		}
	}
	for (unsigned long long i = 3; i <= sqrt(copyN) && n>1; i += 2)
	{
		if (n % i == 0)
		{
			descompunere[0][nr] = i;
			while (n % i == 0)
			{
				descompunere[1][nr]++;
				n /= i;
			}
			nr++;
		}
	}
	return descompunere;
}
void main()
{
	unsigned int n = 341;
	int nr = 0;
	int** a = factor(n, nr);
	for (int i = 0; i < nr; i++)
		cout << a[0][i] << " la puterea " << a[1][i] << endl;
}