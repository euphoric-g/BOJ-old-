#include <bits/stdc++.h>

/*
    C++ Template by LJH
    Last Update : 21/10/07
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
    */
    public:
    bool is_root = false, finish = false;
    char ch = 'R';
    map<char, Trie> next;
    Trie *failure_link; // for Aho-Corasick
    Trie() { is_root = true; }
    Trie(char c) { ch = c; }
    bool exist(char to_find) { return next.find(to_find) != next.end(); }
    Trie *find(char to_find) {
        if(!exist(to_find)) { next[to_find] = Trie(to_find); }
        return &next[to_find];
    }
    void insert(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            cur = cur->find(word[cursor++]);
        }
        cur->finish = true;
    }
    bool search(string &word) {
        int cursor = 0;
        Trie *cur = this;
        while(cursor < word.size()) {
            if(!cur->exist(word[cursor])) return false;
            cur = &cur->next[word[cursor++]];
        }
        return cur->finish;
    }
    void explore(string s) {
        if(finish) cout << s << '\n';
        for(auto &n : next) n.second.explore(s + n.second.ch);
    }
    void Init() {
        Trie *root = this;
        queue<Trie*> q;
        q.push(root);
        while(!q.empty()) {
            Trie *cur = q.front(); q.pop();
            for(auto &ch : cur->next) {
                Trie *next = &ch.second;
                if(cur == root) next->failure_link = root;
                else {
                    Trie *prev = cur->failure_link;
                    while(prev != root && prev->next.find(ch.first) == prev->next.end()) prev = prev->failure_link;
                    if(prev->next.find(ch.first) != prev->next.end()) {
                        prev = &prev->next[ch.first];
                    }
                    next->failure_link = prev;
                }
                if(next->failure_link->finish) next->finish = true;
                q.push(next);
            }
        }
    }
    int aho_corasick(string text) {
        Trie *root = this, *cur = this;
        int cnt = 0;
        int n = text.size();
        REP(i, 0, n) {
            while(cur != root && cur->next.find(text[i]) == cur->next.end()) cur = cur->failure_link;
            if(cur->next.find(text[i]) != cur->next.end()) cur = &cur->next[text[i]];
            if(cur->finish) ++cnt;
        }
        return cnt;
    }
};
// Data Structure : Trie

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

// Definitions

// typedefs

// Global Variables

// functions

int main() {
    FASTIO;
    int n, q;
    cin >> n;
    Trie dict = Trie();
    while(n--) {
        string pattern;
        cin >> pattern;
        dict.insert(pattern);
    }
    dict.Init();
    cin >> q;
    while(q--) {
        string str;
        cin >> str;
        cout << (dict.aho_corasick(str) > 0 ? "YES\n" : "NO\n");
    }
}