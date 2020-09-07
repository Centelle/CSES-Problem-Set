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

int test_case_number = 1;
void print_case() {
#ifdef LOCAL
    cout << "Case #" << test_case_number++ << ": ";
#endif
}

struct Node {
    int count;
};

const int maxN = 15;  // change
Node st[4 * maxN];
int a[maxN];

class kth_zero {
   public:
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            if (a[tl] == 0) {
                st[v].count = 1;
            } else {
                st[v].count = 0;
            }
        } else {
            int tm = (tl + tr) >> 1;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            st[v].count = st[2 * v].count + st[2 * v + 1].count;
        }
    }

    int get_kth(int v, int tl, int tr, int k) {
        if (st[v].count < k) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int tm = (tl + tr) >> 1;
        if (st[2 * v].count >= k) {
            return get_kth(2 * v, tl, tm, k);
        }
        return get_kth(2 * v + 1, tm + 1, tr, k - st[2 * v].count);
    }

    void update(int v, int tl, int tr, int pos){
        if(tl == tr){
            st[v].count = (a[pos] == 0);
            return;
        }
        int tm = (tl + tr) >> 1;
        if(pos <= tm){
            update(2 * v, tl, tm, pos);
        } else {
            update(2 * v + 1, tm + 1, tr,  pos);
        }
    }
    void solve() {
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        build(1, 0, n - 1);
        for(Node val : st){
            cout << val.count << ' ' ;
        }
        cout << endl;
        while(q--){
            cout << "Query: " ;
            int k; cin >> k;
            cout << get_kth(1, 0, n - 1, k) << endl;
            cout << "Update: ";
            int pos, new_val;
            cin >> pos;
            cout << "new_value: ";
            cin >> new_val;
            a[pos] = new_val;
            update(1, 0, n - 1, pos);
        }
    }
};

int32_t main() {
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    kth_zero solver; 
    solver.solve();
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}