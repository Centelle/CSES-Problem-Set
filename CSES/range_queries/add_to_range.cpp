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
int query_number = 0;
void print_query(){
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

class Node {
   public:
    int val;
};
const int maxn = 40;
Node st[maxn];
int a[maxn];

class add_to_range {
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            st[v].val = 0;
        } else {
            int tm = (tl + tr) >> 1;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
        }
    }

    void update(int v, int tl, int tr, int l, int r, int c) {
        // debug(v, tl, tr, l, r, c);
        if (l > r) {
            return;
        }
        if (tl == l && tr == r) {
            cout << "added to: " << v << endl;
            st[v].val += c;
            return;
        }
        int tm = (tl + tr) >> 1;
        update(2 * v, tl, tm, l, min(r, tm), c);
        update(2 * v + 1, tm + 1, tr, max(tm + 1, l), r, c);
    }

    int get_val(int v, int tl, int tr, int pos, int addend) {
        // debug(v, tl, tr, pos, addend);
        addend += st[v].val;
        if (tl == tr) {
            return a[pos] + addend;
        }
        int tm = (tl + tr) >> 1;
        if (pos <= tm)
            return get_val(2 * v, tl, tm, pos, addend);
        return get_val(2 * v + 1, tm + 1, tr, pos, addend);
    }

   public:
    void solve() {
        cout << "format\nN Q\na[0]......a[n - 1]\nQuery: update [l...r] by val\nQuery: get value at pos\n";
        int n, q;
        read(n, q);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        build(1, 0, n - 1);
        while (q--) {
            int l, r, c, pos;
            cout << "l, r, c: ";
            read(l, r, c);
            update(1, 0, n - 1, l, r, c);
            cout << "pos: ";
            cin >> pos;
            cout << "value at pos: " << get_val(1, 0, n - 1, pos, 0) << endl;
        }
    }
};

int32_t main() {
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    add_to_range sovler;
    sovler.solve();
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}