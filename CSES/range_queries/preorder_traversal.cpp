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

void display(vector<vector<int>> adj, int n){
    for(int i = 1; i <= n; ++i){
        cout << "Node " << i << " has : ";
        for(int b : adj[i]){
            cout << b << ", ";
        }
        cout << endl;
    }
}

void solve (){
    int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 1; i < n; ++i){
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
    }
    display(adj, n);
}


int32_t main(){
#ifdef LOCAL
    auto begin = std::chrono::high_resolution_clock::now();
#endif
    solve();
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
#ifdef LOCAL
    auto end = std::chrono::high_resolution_clock::now();
    cout << setprecision(4) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end - begin).count() << " seconds" << endl;
#endif
}