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
#define int long long
const int maxN = (2 * 1e5) + 5;
int a[maxN];
int st[4 * maxN];
int query_number = 1;
#define endl '\n'
void print_query() {
#ifdef LOCAL
    cout << "Query #" << query_number++ << ": ";
#endif
}

class range_sum {
   public:
    void build(int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = a[tl];
        } else {
            int tm = (tl + tr) >> 1;
            build(2 * v, tl, tm);
            build(2 * v + 1, tm + 1, tr);
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }

    void update(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            st[v] = a[pos];
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos);
            } else {
                update(2 * v + 1, tm + 1, tr, pos);
            }
            st[v] = st[2 * v] + st[2 * v + 1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return st[v];
        }
        int tm = (tl + tr) / 2;
        int left_sum = sum(2 * v, tl, tm, l, min(r, tm));
        int right_sum = sum(2 * v + 1, tm + 1, tr, max(tm + 1, l), r);
        return left_sum + right_sum;
    }

    void solve() {
        // cout << "format\nN Q\na[0]......a[n - 1]\nQuery 1: sum[l...r]\nupdate: pos new_val\nQuery 2 : sum[l...r]\nupdate: pos new_val\n......\n" << endl;
        int n, q;
        cin >> n >> q;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        build(1, 0, n - 1);
        while (q--) {
            int t;
            cin >> t;
            if (t == 1) {
                int k, u;
                cin >> k >> u;
                k--;
                a[k] = u;
                query_number++;
                update(1, 0, n - 1, k);
            } else {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                print_query();
                cout << sum(1, 0, n - 1, l, r) << endl;
            }
        }
    }
};

int32_t main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    range_sum solver;
    solver.solve();
}
