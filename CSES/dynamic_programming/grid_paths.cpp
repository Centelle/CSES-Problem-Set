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

void show(vector<vector<int>> dp) {
    for (auto something : dp) {
        for (auto val : something)
            cout << val << ' ';
        cout << endl;
    }
    cout << "------------------" << endl;
}
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<string> g(n);
    read(g);
    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = g[0][0] == '.';
    for (int j = 1; j < n; ++j) {
        if (g[0][j] == '*') {
            dp[0][j] = 0;
        } else {
            dp[0][j] = dp[0][j - 1];
        }
    }

    for (int i = 1; i < n; ++i) {
        if (g[i][0] == '*') {
            dp[i][0] = 0;
        } else {
            dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (g[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}

int32_t main() {
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();

#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}