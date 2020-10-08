#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <bitset>
#include <map>
#include <assert.h>
#include <string>
#include <regex>
#include <unordered_map>
#include <time.h>
#define ll long long
#define mod 998244353
using namespace std;
int get(int p[], int a) {
	if (p[a] != a) {
		p[a] = get(p, p[a]);
	}
	return p[a];
}
void unionn(int p[], int siz[], int l, int m) {
	int a = get(p, l);
	int b = get(p, m);
	int swapDone = 0;
	if (siz[a] > siz[b]) {
		swap(a, b);
		swap(l, m);
	}
	p[a] = b;
	if (a != b)
		siz[b] += siz[a];

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 10;
	int* p = new int[n + 1];
	int* siz = new int[n + 1];
	for (int i = 0;i <= n;i++) {//initialize the size and parent array(p[])
		p[i] = i;
		siz[i] = 1;
	}
	unionn(p, siz, 1, 2);
	unionn(p, siz, 2, 3);
	unionn(p, siz, 2, 5);
	unionn(p, siz, 3, 4);
	unionn(p, siz, 4, 5);
	unionn(p, siz, 3, 6);
	unionn(p, siz, 8, 9);
	unionn(p, siz, 9, 10);
	//chedk if 1 and 3 are connected?
	int a = 1;
	int b = 3;
	if (get(p, a) == get(p, b))
		cout << "yes " << a << " and " << b << " are connected";
	else
		cout << "no " << a << " and " << b << " are connected";
	return 0;
}
