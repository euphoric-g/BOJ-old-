#include <bits/stdc++.h>

/*
    C++ Template by LJH
    Last Update : 21/09/23
    Light Version
*/

using namespace std;

#define FASTIO FAST_IO()
#define ENDL cout << '\n'
#define MAX(a, b) max((a), (b))
#define MIN(a, b) min((a), (b))
#define MAX3(a, b, c) max(max((a), (b)), (c))
#define MIN3(a, b, c) min(min((a), (b)), (c))
#define ALL(v) (v).begin(), (v).end()
#define ALL_REV(v) (v).rbegin(), (v).rend()
#define UNIQUE(v) unique(ALL(v))
#define UNIQUE_ERASE(v) (v).erase(UNIQUE(v), (v).end())
#define FOREACH(it, v) for(__typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define REP(i, a, b) for(int i=(a); i<(b); ++i)
#define REPREV(i, a, b) for(int i=(a); i>=(b); --i)
#define SIZE(v) ((int)v.size())
#define POPCOUNT(n) (builtout_popcount(n))
#define LOWERBOUND(v, x) lower_bound(ALL(v), (x))
#define UPPERBOUND(v, x) upper_bound(ALL(v), (x))
#define REV(v) reverse(ALL(v))
#define SORT(v) sort(ALL(v))
#define SORT_REV(v) sort(ALL_REV(v))
#define MAX_ELEMENT(v) *max_element(ALL(v))
#define MIN_ELEMENT(v) *min_element(ALL(v))
#define SWAP(a, b) swap((a), (b))
#define DO_PERMUTATION(func, v) do {func;} while(next_permutation(ALL(v)))
#define DO_PREV_PERMUTATION(func, v) do {func;} while(prev_permutation(ALL(v)))
#define GCD(v) gcd(v)
#define LCM(v) lcm(v)
#define PRINT(v) REP(i, 0, SIZE(v)) cout << v[i] << ' '; ENDL
#define PRINTLN(v); REP(i, 0, SIZE(v)) { cout << v[i]; ENDL; }
#define N_TIMES(n) REP(i, 0, n)
#define VBOOL(n, b) vector<bool>(n, b)
#define DOUBLE_PRECISION(n) cout << fixed << setprecision(n)

// For interactive problems
#define FLUSH cout << flush

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef vector<pii> vpii;
typedef vector<pis> vpis;
typedef vector<pss> vpss;
typedef complex<double> cpx;
typedef unordered_map<int, int> umii;
typedef unordered_map<string, int> umsi;
typedef unordered_map<int, string> umis;

namespace pq_cmp {
    struct int_min { bool operator()(const int &a, const int &b) { return a > b; } };
    struct int_max { bool operator()(const int &a, const int &b) { return a < b; } };
    struct pii_011 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first < b.first; return a.second < b.second; } };
    struct pii_010 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first < b.first; return a.second > b.second; } };
    struct pii_001 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first > b.first; return a.second < b.second; } };
    struct pii_000 { bool operator()(const pii &a, const pii &b) { if(a.first != b.first) return a.first > b.first; return a.second > b.second; } };
    struct pii_111 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second < b.second; return a.first < b.first; } };
    struct pii_110 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second < b.second; return a.first > b.first; } };
    struct pii_101 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second > b.second; return a.first < b.first; } };
    struct pii_100 { bool operator()(const pii &a, const pii &b) { if(a.second != b.second) return a.second > b.second; return a.first > b.first; } };
};
// function : ?????????????????? int, pair<int, int>??? ???????????? ?????? ?????? ?????? ?????????

typedef priority_queue<int, vint, pq_cmp::int_min> pq_min;
typedef priority_queue<int, vint, pq_cmp::int_max> pq_max;

const double PI = acos(-1);

void FAST_IO() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
}
// function : ????????? ?????? ??????

size_t STR_FIND(string str, char c) { return str.find(c, 0); }
size_t STR_FIND(string str, char c, int start) { return str.find(c, start); }
// function : ??????????????? ?????? ?????? ?????? ??? ?????? ??????

string SUBSTR(string str, int start, int len) { return str.substr(start, len); }
string SUBSTR(string str, int start) { return str.substr(start, SIZE(str)); }
// function : ???????????? ?????? ????????? ??????

vstr PARSE(string str, char delim) {
    vector<string> ret;
    while(!str.empty()) {
        auto it = STR_FIND(str, delim, 0);
        if(it == string::npos) {
            ret.push_back(str);
            break;
        }
        ret.push_back(SUBSTR(str, 0, it));
        str = SUBSTR(str, it+1);
    }
    return ret;
}
// function : ???????????? ?????? ?????????????????? ??????

vvint INIT_VVINT(int n, int m, int init) {
    vvint ret;
    REP(i, 0, n) ret.push_back(vint(m, init));
    return ret;
}
// function : init?????? ???????????? n*m ????????? vector<vector<int>> ??????

vvint GET_2D(int n, int m) {
    vvint ret(n);
    REP(i, 0, n) {
        ret[i] = vint(m);
        REP(j, 0, m) cin >> ret[i][j];
    }
    return ret;
}
// function : ?????? n*m?????? ???????????? n*m ????????? vector<vector<int>> ????????? ??????

string GET_ONE_LINE() {
    string ret;
    getline(cin, ret);
    return ret;
}
// function : ?????? ???????????? ??? ?????? ???????????? ???????????? ??????

vint GET_N_INTS(int n) {
    vector<int> ret = vint(n, 0);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}
// function : ?????? n?????? ???????????? vector<int> ????????? ??????

vpii GET_N_PII(int n) {
    vector<pair<int, int>> ret;
    REP(i, 0, n) {
        int a, b;
        cin >> a >> b;
        ret.push_back({a, b});
    }
    return ret;
}
// function : n?????? ?????? ?????? ???????????? vector<pair<int, int>> ????????? ??????

vstr GET_N_STR(int n) {
    vector<string> ret = vstr(n);
    REP(i, 0, n) cin >> ret[i];
    return ret;
}
// function : n?????? ???????????? ???????????? vector<string> ????????? ??????

vint VINT_SUM(vint a, vint b) { REP(i, 0, SIZE(a)) a[i] += b[i]; return a; }
// function : ????????? ?????? ??? vint??? ?????? ????????? ??????

int SUM_OF_VINT(vint &a) { int sum = 0; REP(i, 0, SIZE(a)) sum += a[i]; return sum; }
// function : vint??? ?????? ?????? ?????? ??????

vint VINT_NATURAL(int n) {
    vint ret(n);
    REP(i, 0, n) ret[i] = i+1;
    return ret;
}
// function : 1 ?????? n ????????? ???????????? ???????????? ????????? ????????? vint ??????

vint STR_TO_VINT(string &s) {
    vint ret;
    FOREACH(it, s) ret.push_back(*it-'0');
    return ret;
}
// function : ????????? ???????????? ???????????? ??? ???????????? ????????? ????????? vint ??????

int builtout_popcount(int n) {
    int ret = 0;
    REP(i, 0, 32) if((n >> i) % 2) ++ret;
    return ret;
}
int builtout_popcount(ll n) {
    int ret = 0;
    REP(i, 0, 64) if((n >> i) % 2) ++ret;
    return ret;
}
int builtout_popcount(ull n) {
    int ret = 0;
    REP(i, 0, 64) if((n >> i) % 2) ++ret;
    return ret;
}
// Function : ????????? ????????? ?????? 1??? ????????? ??????

// Definitions

// typedefs

// Global Variables

// functions


int main() {
    FASTIO;
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        REV(a); REV(b);
        string ans = to_string(stoi(a) + stoi(b));
        while(!ans.empty() && ans.back() == '0') ans.pop_back();
        REV(ans);
        cout << ans << '\n';
    }
}