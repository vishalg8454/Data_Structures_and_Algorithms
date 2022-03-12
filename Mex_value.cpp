#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
//#include <dequeue>
#include <list>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stdlib.h>
#include <bitset>
#include<time.h>
#include <set>

#define ll long long
#define mod 998244353
using namespace std;

set<int> s; //this front of this set will be having mex value
map<int, int> m; //freq map

void init(int n) {
    s.clear();
    m.clear();
    for (int i = 0; i <= n + 2; i++)
        s.insert(i);
}

int query(int q, int x) {
    if (q == 0) {
        m[x]--;
        if (m[x] == 0)
            s.insert(x);
    } else if (q == 1) {
        m[x]++;
        if (s.find(x) != s.end())
            s.erase(s.find(x));
    }
    return *s.begin();
}
//this program efficiently finds mex value for each query in log(n). 
// The mex value is the smallest non-negative number not present in the array.
// ex mex(0,1,3,4) = 2, mex(1,2,3,4) = 0
// https://codeforces.com/blog/entry/81287?#comment-677837
int main() {
    int n;
    cout << "enter max value to be entered\n";
    cin >> n;
    init(n);
    cout << "Enter 1 (x) for addition, enter 0(x) for removal Enter -1 (x) for breaking\n";
    while (true) {
        int q, x;
        cin >> q >> x;
        if (q == -1)
            break;
        if (q == 0)
            cout << "The mex value is: " << query(0, x) << "\n";
        if (q == 1)
            cout << "The mex value is: " << query(1, x) << "\n";
    }
}
