#ifndef ONLINE_JUDGE
#pragma warning(disable : 4996)
#endif
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
 
#define MAX_N 1000
int n, k;
double x;	// 搜索过程中的正确率
struct Test
{
	int a, b;
	bool operator < (const Test& other) const
	{
		return a - x * b > other.a - x * other.b;	// 按照对准确率的贡献从大到小排序
	}
};
Test test[MAX_N];
 
// 判断是否能够获得大于mid的准确率
bool C(double mid)
{
	x = mid;
	sort(test, test + n);
	double total_a = 0, total_b = 0;
	for (int i = 0; i < n - k; ++i)					// 去掉后k个数计算准确率
	{
		total_a += test[i].a;
		total_b += test[i].b;
	}
 
	return total_a / total_b  > mid;
}
 
int main(int argc, char *argv[])
{

	while (cin >> n >> k && (n || k))
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> test[i].a;
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> test[i].b;
		}
 
		double lb = 0; double ub = 1;
		while (abs(ub - lb) > 1e-4)
		{
			double mid = (lb + ub) / 2;
			if (C(mid)) lb = mid;
			else ub = mid;
		}
		cout << fixed << setprecision(0) << lb * 100 << endl;
	}
}