#include <iostream>
#include <cmath>
#include <iomanip>
#define X first
#define Y second
using namespace std;
const double PI = 3.141592653589793;
double dis(double ax, double ay, double bx, double by)
{
	return sqrtl((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
int main()
{
	double ax, ay, bx, by, cx, cy;
	while (cin >> ax >> ay >> bx >> by >> cx >> cy)
	{
		double A = dis(ax, ay, bx, by);
		double B = dis(ax, ay, cx, cy);
		double C = dis(cx, cy, bx, by);
		double P = (A + B + C) / 2;
		double S = sqrtl(P * (P - A) * (P - B) * (P - C));
		double R = A * B * C / (S * 4);
		cout << fixed << setprecision(2) << 2 * PI * R << endl;
	}
}
