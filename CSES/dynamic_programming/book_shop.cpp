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
    return to_string((string) s);
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
    for (const auto &x : v) {
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
template<typename T>
void read(T& val){
    cin >> val;
}
template<typename T>
void read(vector<T>& a){
    for(int i = 0; i < (int)a.size(); ++i){
      read(a[i]);
    }
}
template<typename Head, typename... Tail>
void read(Head& H, Tail&... T){
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
#define times(n) for(int i = 0; i < (n); ++i)
#define bits(x) __builtin_popcount(x)
 
int test_case_number = 1;
void print_case(){
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
// 4 10
// 4 8 5 3
// 5 12 8 1

void solve(){
    int n, target;  cin >> n >> target;
    vector<int> price(n), value(n);
    read(price, value);
    vector<vector<int>> dp(target + 1, vector<int> (n, 0));
    // show(dp);
    for(int i = 1; i <= target; ++i){
        for(int j = 0; j < n; ++j){
            if(j == 0){
                if(price[j] <= i) dp[i][j] = value[j];
            } else {
                if(price[j] <= i){
                    dp[i][j] = max(dp[i][j - 1], dp[i - price[j]][j - 1] + value[j]);
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    cout << dp[target][n - 1] << endl;
    //////////////////////////////////////////////////////

    // vector<int> dp(target + 1);
    // for(int i = 0; i < n; ++i){
    //     for(int j = target; j >= price[i]; --j){
    //         dp[j] = max(dp[j], dp[j - price[i]] + value[i]);
    //     }   
    // }
    // // debug(dp);
    // cout << dp[target] << endl;
}
 
int32_t main(){
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();

#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}