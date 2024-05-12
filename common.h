#pragma GCC optimize("03,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <queue>
#include <deque>
#include <bitset>
#include <set>
#include <unordered_set>
#include <utility>
#include <numeric>
#include <iomanip>
#include <stack>
#include <list>
#include <bitset>
#include <sstream>
#include <fstream>
#include <cctype>
#include <random>
#include <stdlib.h>
#include <time.h>
#define ll long long
#define ld long double
#define INF 0x3f3f3f3f
#define MXN 1000005
#define cl(x) (x << 1)
#define cr(x) ((x << 1) | 1)
#define SZ(x) (int)x.size()
#define PB push_back
#define lowbit(x) (x & (-x))
#define NO_TAG false
#define P1 75577
#define P2 12721
#define MOD1 998244353
#define MOD2 1000000007

using namespace std;

class Common {
public:
    string hexToString(string hexstr, int length);
    int getDec(string hexstr, int bits);
    string getHex(int val, int bits);
    vector<string> readfile(string srcfile);
    string getNameWithoutSpace(string originalname);
};