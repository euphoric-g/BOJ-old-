#include <bits/stdc++.h>

/*
    C++ Template by LJH
    Last Update : 21/09/28
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
typedef pair<ll, ll> pll;
typedef pair<int, string> pis;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
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

vvint GET_2D(int &n, int &m) {
    cin >> n >> m;
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

class Trie {
    /*
    ????????? ????????? Trie root = Trie(0); ?????? ?????? ???
    ????????? ???????????? root??? ??????
    ????????? ???????????? ?????? ??????
    */
    public:
    bool is_root = false, finish = false;
    char ch;
    map<char, Trie> next;
    Trie() {is_root = false;}
    Trie(int i) {is_root = true;}
    Trie *find(char to_find) {
        if(next.find(to_find) == next.end()) {
            next[to_find] = Trie();
            next[to_find].ch = to_find;
        }
        return &next[to_find];
    }
    int next_size() { return next.size(); }
    void insert(string word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor]);
            if(cursor == word.size() - 1) cur->finish = true;
            ++cursor;
        }
    }
};
// Data Structure : Trie

class SegTree_MAX {
    public:
    vector<ll> arr;
    vector<ll> tree;
    SegTree_MAX(vector<ll> arrin) {
        arr = arrin;
        tree.resize(1 << (1 + (int)ceil(log2(arr.size()))));
        init(0, arr.size()-1, 1);
    }
    ll init(int s, int e, int n) {
        if(s == e) return tree[n] = arr[s];
        int m = (s+e)/2;
        return tree[n] = MAX(init(s, m, n*2), init(m+1, e, n*2+1));
    }
    ll max_val(int s, int e, int l, int r, int n) {
        if(e < l || r < s) return INT32_MIN;
        if(l <= s && e <= r) return tree[n];
        if(s != e) {
            int m = (s+e)/2;
            return MAX(max_val(s, m, l, r, n*2), max_val(m+1, e, l, r, n*2+1));
        }
    }
};
class SegTree_MAX_AREA {
    /*
    vector<ll>??? ????????? ?????? ??????
    ?????? ??? ????????? ?????? ?????? max_area ??? ??????
    */
    public:
    vector<ll> arr;
    vector<ll> tree;
    int arrlen, tree_height, tree_size;
    ll max_area;
    SegTree_MAX_AREA() {}
    SegTree_MAX_AREA(vector<ll> arrin) {
        arr = arrin;
        arrlen = arr.size();
        max_area = 0;
        tree_height = (int)ceil(log2(arrlen));
        tree_size = 1 << (tree_height + 1);
        arr.resize(arrlen+1);
        tree.resize(tree_size);
        init(0, arrlen-1, 1);
        arr[arrlen] = INT64_MAX;
        find(0, arrlen-1);
    }
    ll init(int start, int end, int node) {
        if(start == end) return tree[node] = start;
        int mid = (start + end)/2;
        ll left = arr[init(start, mid, node*2)];
        ll right = arr[init(mid+1, end, node*2+1)];
        return tree[node] = ((left <= right) ? tree[node*2] : tree[node*2+1]);
    }
    ll min_val(int start, int end, int left, int right, int node) {
        if(right < start || end < left) return arrlen;
        if(left <= start && end <= right) return tree[node];
        int mid = (start + end)/2;
        ll left_val = min_val(start, mid, left, right, node*2);
        ll right_val = min_val(mid+1, end, left, right, node*2+1);
        return (arr[left_val] <= arr[right_val] ? left_val : right_val);
    }
    void find(int left, int right) {
        if(left > right) return;
        ll min_index = min_val(0, arrlen-1, left, right, 1);
        max_area = std::max(max_area, arr[min_index] * (right - left + 1));
        if(left != right) {
            find(left, min_index-1);
            find(min_index+1, right);
        }
    }
};
// Data Structure : Segment Tree (?????????, ??????????????? ?????? ??????)

class TSP {
    /*
    n x n ?????? cost ????????? ????????? ?????? ??? exec(0, 1) ??? ?????? (n <= 16)
    */
    public:
    int n;
    const int MAX_VALUE = 100'000'000;
    int cost[16][16], dp[16][1 << 16];
    TSP() {}
    TSP(vector<vector<int>> _cost) {
        n = _cost.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) cost[i][j] = _cost[i][j];
            for(int j=0; j<(1 << n); j++) dp[i][j] = 0;
        }
    }
    int add(int bit, int x) {
        int ans = bit |= 1 << x;
        return ans;
    }
    int visit(int bit, int x) {
        int ans = bit &= 1 << x;
        return ans != 0;
    }
    int exec(int start, int bit) {
        if(bit == (1<<n) - 1 && cost[start][0] != 0) {
            dp[start][bit] = cost[start][0];
            return dp[start][bit];
        } else if(dp[start][bit] != 0) {
            return dp[start][bit];
        } else  {
            int limit = -1;
            for(int i=0; i<n; i++) {
                if(visit(bit, i) == 1) continue;
                if(cost[start][i] == 0) continue;
                limit = limit == -1 ?  exec(i, add(bit, i))+cost[start][i] : min(limit, exec(i, add(bit, i))+cost[start][i]);
            }
            dp[start][bit] = limit == -1 ? MAX_VALUE : limit;
            return dp[start][bit];
        }
    }
};
// Algorithm : Traveling Salesman Problem(TSP)

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

vint kmp(string &str) {
    vint ret(str.size());
    int j = 0;
    for(int i=1; i<str.size(); i++) {
        while(j > 0 && str[i] != str[j]) j = ret[j-1];
        if(str[i] == str[j]) ret[i] = ++j;
    }
    return ret;
}
// Algorithm : KMP

pair<int, vvint> knapsack(int n, vint weight, vint values, int bag_size) {
    // ?????? ?????? n, ?????? ?????? weight, ?????? ?????? values, ?????? ?????? bag_size
    // dp ????????? ?????? ?????? ??????
    vvint ret = INIT_VVINT(n, bag_size+1, 0);
    REP(i, 0, n) {
        if(i == 0) REP(j, weight[i], bag_size+1) ret[i][j] = values[i];
        else REP(j, 0, bag_size+1) ret[i][j] = (weight[i] <= j) ? max(values[i] + ret[i-1][j-weight[i]], ret[i-1][j]) : ret[i-1][j];
    }
    return {ret[n-1][bag_size], ret};
}
pair<int, vint> knapsack_light(int n, vint &weight, vint &values, int bag_size) {
    vint dp(bag_size+1, 0);
    REP(i, 0, n) {
        REPREV(j, bag_size, weight[i]) {
            if(dp[j-weight[i]]) dp[j] = dp[j] > dp[j-weight[i]] + values[i] ? dp[j] : dp[j-weight[i]] + values[i];
        }
        dp[weight[i]] = max(dp[weight[i]], values[i]);
    }
    return {MAX_ELEMENT(dp), dp};
}
// Algorithm : Knapsack Problem

void FFT(vector<cpx> &arr, bool invert) {
    int n = SIZE(arr);
    for(int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for( ; j>=bit; bit>>=1) j -= bit; j+= bit;
        if(i < j) swap(arr[i], arr[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        double angle = 2*PI/len*(invert ? -1 : 1);
        cpx wlen(cos(angle), sin(angle));
        for(int i=0; i<n; i+=len) {
            cpx w(1, 0);
            for(int j=0; j<len/2; j++) {
                cpx u = arr[i+j], v = arr[i+j+len/2] * w;
                arr[i+j] = u+v;
                arr[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if(invert) REP(i, 0, n) arr[i] /= n;
}
vint FFT_multiply(vint a, vint b) {
    vector<cpx> fa(ALL(a)), fb(ALL(b));
    int n = 1;
    while(n < max(SIZE(a), SIZE(b))) n <<= 1; n <<= 1;
    fa.resize(n), fb.resize(n); FFT(fa, false); FFT(fb, false);
    REP(i, 0, n) fa[i] *= fb[i]; FFT(fa, true);
    vint res(n, 0);
    REP(i, 0, n) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));
    return res;
}
// Algorithm : Fast Fourier Transform(FFT)
// Reference : blog.myungwoo.kr/54

int binary_do_lower(int start, int end, bool (*func)(int)) {
    // func ?????? ???????????? false??? ?????? ??? ??????
    // ????????? func ?????? ??????
    while(start < end) {
        int mid = (start + end)/2;
        if(!func(mid)) {
            end = mid;
        } else {
            start = mid+1;
        }
    }
    return start;
}
// Function : ?????????????????? ?????? ????????? ???????????? ?????? ?????? ??? ??????

vint LIS_dp(vint &arr) {
    vint dp(SIZE(arr), 1);
    REP(i, 0, SIZE(arr)) REP(j, 0, i) if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
    return dp;
}
int LIS_light(vint& arr) {
    vint ret;
    ret.push_back(arr[0]);
    REP(i, 1, SIZE(arr)) {
        auto it = lower_bound(ALL(ret), arr[i]);
        if((it - ret.begin()) < SIZE(ret)) *it = arr[i];
        else ret.push_back(arr[i]);
    }
    return SIZE(ret);
}
vint LIS_tracking(vint &arr) {
    vint lis(SIZE(arr)), mlis(SIZE(arr));
    int idx = 1;
    REP(i, 0, SIZE(arr)) {
        if(arr[i] > lis[idx-1]) {
            lis[idx++] = arr[i];
            mlis[i] = idx;
        } else {
            int nidx = lower_bound(lis.begin(), lis.begin() + idx, arr[i]) - lis.begin();
            lis[nidx] = arr[i];
            mlis[i] = nidx+1;
        }
    }
    vint ans;
    REPREV(i, SIZE(arr)-1, 0) if(mlis[i] == idx) { ans.push_back(arr[i]); --idx; }
    REV(ans);
    return ans;
}
// Algorithm : Longest Increasing Subsequence(LIS)

pair<ll,pll> xGCD(ll a, ll b) {
    if(b == 0) return {a,{1,0}};
    pair<ll,pair<ll,ll>> ret = xGCD(b, a%b);
    ll g, x, y;
    g = ret.first;
    tie(x,y) = ret.second;
    return {g,{y,x-(a/b)*y}};   
}

pll CRT(vll &M, vll &A) {
    // x == A (mod M)
    typedef __int128_t i128;
    if(A.size() != M.size()) return {-1,-1};
    int N = A.size();
    ll a1 = A[0], m1 = M[0];
    a1 %= m1;
    for(int i=1;i<N;++i) {
        ll a2 = A[i], m2 = M[i], g = __gcd(m1, m2);
        if(a1 % g != a2 % g) return {-1,-1};
        ll p, q;
        auto res = xGCD(m1/g, m2/g);
        tie(p,q) = res.second;
        i128 mod = (i128)m1 / g * m2;
        a1 = ((i128)a1 * (m2/g) % mod) * q % mod + ((i128)a2*(m1/g)%mod)*p % mod;
        a1 = (a1 + mod) % mod;
        m1 = mod;
    }
    return {a1, m1};
}
// Algorithm : Chinese Remainder Theorem(CRT)
// reference : forthright48.com/chinese-remainder-theorem-part-2-non-coprime-moduli/

// Definitions

// typedefs
typedef tuple<int, int, int, int> dat;
typedef vector<dat> vdat;
// ????????????, ????????????, ??????, ????????????

// Global Variables
struct vdat_cmp {
    bool operator()(dat &a, dat &b) {
        // ????????????(???????????? - ?????? ??????) ?????? ??? -> ?????? ?????? ?????? ??? -> ?????? ?????? ???
        int p1, b1, n1, t1, p2, b2, n2, t2;
        tie(p1, b1, n1, t1) = a;
        tie(p2, b2, n2, t2) = b;
        if(p1 - t1 != p2 - t2) return p1-t1 < p2-t2;
        if(b1 != b2) return b1 > b2;
        return n1 > n2;
    }
};

// functions

int main() {
    FASTIO;
    int n;
    cin >> n;
    vdat vec;
    priority_queue<dat, vdat, vdat_cmp> pq;
    REP(i, 0, n) {
        int t, p, b;
        cin >> t >> p >> b;
        vec.push_back(make_tuple(p, b, i+1, t));
    }
    sort(ALL(vec), [](const dat &a, const dat &b) -> bool {
        int p1, b1, n1, t1, p2, b2, n2, t2;
        tie(p1, b1, n1, t1) = a;
        tie(p2, b2, n2, t2) = b;
        // ??????????????? ???????????? ??? ?????? ?????? ????????? ?????????
        return t1 > t2;
    });
    vint ans;
    int time = 0;
    while(!(vec.empty() && pq.empty())) {
        while(!vec.empty() && get<3>(vec.back()) <= time) {
            pq.push(vec.back()); vec.pop_back();
        }
        if(pq.empty()) {
            ++time;
            continue;
        }
        auto cur = pq.top(); pq.pop();
        ans.push_back(get<2>(cur));
        time += get<1>(cur);
    }
    PRINT(ans);
    return 0;
}