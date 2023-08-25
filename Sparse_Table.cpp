//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

#define Ms(s, n) memset(s, n, sizeof(s))
#define Rp(i,l,m) for(int i=l; i<m; ++i)
#define Rpd(i,l,m) for(int i=l; i>=m; --i)
#define Rpp(i,l,m) for(int i=l; i<=m; i++)
#define RpAll(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define All(a) (a).begin(), (a).end()
#define Fi first
#define Se second
#define Pb push_back
#define Pf push_front
#define Is insert
#define Sz(a) int((a).size())
#define ooi INT_MAX
#define ool LLONG_MAX
typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
const int MOD = (int) 1e9 + 7;
const ld PI = acos((ld) -1);
inline ll gcd(ll a,ll b) {ll r;while(b){r=a%b;a=b;b=r;}return a;}
inline ll lcm(ll a,ll b) {return a/gcd(a,b)*b;}
inline ll fpow(ll n,ll k){ll r=1; for(;k;k>>=1){if(k&1)r=r*n%MOD;n=n*n%MOD;}return r;}
const int base = 311;
const int N = 1e5 + 5;

ll n, m, k, test, a[N], spr[N][20];
void Solve(){
    int query;
    cin >> n >> query;
    for(int i = 1; i <= n; i++) cin >> a[i], spr[i][0] = i;
    for(int j = 1; (1 << j) <= n; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            if(a[spr[i][j - 1]] < a[spr[i + (1 << (j - 1))][j - 1]]){
                spr[i][j] = spr[i][j - 1];
            }
            else spr[i][j] = spr[i + (1 << (j - 1))][j - 1];
        }
    }
    while(query--){
        int l, r;
        cin >> l >> r;
        int k = log2(r - l + 1);
        cout << min(a[spr[l][k]], a[spr[r - (1 << k) + 1][k]]) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solve();
    return 0;
}


