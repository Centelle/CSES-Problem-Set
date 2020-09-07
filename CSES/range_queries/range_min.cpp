
#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
template <typename T>
void read(T& val) {
    cin >> val;
}
template <typename T>
void read(vector<T>& a) {
    for (int i = 0; i < (int)a.size(); ++i) {
        read(a[i]);
    }
}
template <typename Head, typename... Tail>
void read(Head& H, Tail&... T) {
    read(H);
    read(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define vec vector
#define i64 long long
#define endl '\n'
#define sz(x) (x).size()
#define times(n) for (int i = 0; i < (n); ++i)
#define bits(x) __builtin_popcount(x)
#define forn(i, s, n) for (int i = s; i < n; ++i)

int test_case_number = 1;
void print_case() {
#ifdef LOCAL
    cout << "Qeury #" << test_case_number++ << ": ";
#endif
}

class Node {
    public:
    int mn;
    Node(int minimum){
        this->mn = minimum;
    }
};

const int maxN = 2e5;
int st[4 * maxN];
int a[maxN];

class range_min {
public:
    void build(int v, int tl, int tr){
        if(tl ==tr){
            st[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            st[v] = min(st[2 * v], st[2 * v + 1]);
        }
    }

    int get_min(int v, int tl, int tr, int l, int r){
        if(l > r)
            return INT_MAX;
        if(tl == l && tr == r)
            return st[v];
        int tm = (tl + tr) / 2;
        int left_min = get_min(2 * v, tl, tm, l, min(r, tm));
        int right_min = get_min(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
        return min(left_min, right_min);
    }

    void solve(){
        int n, k; cin >> n >> k;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        build(1, 0, n - 1);
        // display_st();
        while(k --){
            int u, v;
            cin >> u >> v;
            u --; v --;
            print_case();
            cout << get_min(1, 0, n - 1, u, v) << endl;
        }
    }
    
    void display_st(){
        int c = 0;
        for(int val : st){
            if(val == 0){
                c ++;
            }
            if(c == 2){
                return;
            }
            cout << val << ' ' ;
        }
        cout << endl;
    }


};

int32_t main() {    
    range_min solver; 
    solver.solve();
}
