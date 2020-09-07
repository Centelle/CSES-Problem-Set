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
#define sz(x) (int)(x).size()
#define times(n) for (int i = 0; i < (n); ++i)
#define bits(x) __builtin_popcount(x)

int query_number = 1;
void print_query() {
#ifdef LOCAL
    cout << "Query #" << query_number++ << ": ";
#endif
}
int test_case_number = 1;
void print_case() {
#ifdef LOCAL
    cout << "Case #" << test_case_number++ << ": ";
#endif
}

struct Node {
   public:
    int pref = 0;
    int suff = 0;
    int ans = 0;
    int len = 0;
    void display() {
        cout << "(" << pref << ", " << ans << ", " << suff << ")" << endl;
    }
};
const int maxn = 10;
int a[maxn];

class seg_tree {
   public:
    Node st[4 * maxn];

    void display() {
        for (Node val : st) {
            val.display();
        }
    }
    Node combine(Node a, Node b) {
        //a to left of b
        Node w;
        w.len = a.len + b.len;
        if (a.suff + b.pref == w.len) {
            w.pref = w.len;
            w.suff = w.len;
        } else {
            w.pref = a.pref;
            w.suff = b.suff;
        }
        w.ans = max({a.ans, b.ans, a.suff + b.pref});
        return w;
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            bool on = a[tl] == 1;
            st[v].ans = on;
            st[v].pref = on;
            st[v].suff = on;
            st[v].len = 1;
        } else {
            int tm = (tl + tr) >> 1;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            st[v] = combine(st[2 * v], st[2 * v + 1]);
        }
    }

    Node get(int v, int tl, int tr, int l, int r) {
        st[v].display();
        debug(v, tl, tr, l, r);
        if (l > r) {
            Node w;
            return w;
            // return value wrong, hence entire thing wrong
            // possible fix:
            // change default value of @Node 
            // change return value
            // change the combine function 
            // mqaybe add -1 
        }
        if (tl == l && tr == r) {
            return st[v];
        }
        Node p, q;
        int tm = (tl + tr) >> 1;
        p = get(2 * v, tl, tm, l, min(tm, r));
        q = get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(p, q);
    }
};

void solve() {
    seg_tree st;
    int n, q;
    read(n, q);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // cout << "1\n";
    st.build(1, 0, n - 1);
    // cout << "2\n";
    st.display();
    while (q--) {
        cout << "Query: [l...r]:";
        int l, r;
        cin >> l >> r;
        debug(l, r);
        Node w = st.get(1, 0, n - 1, l, r);
        w.display();
    }
}

int32_t main() {
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#endif
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    solve();
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}