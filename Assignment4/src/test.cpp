#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>  
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using o_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>; 

#define ll long long
#define ld long double;
#define vll vector<ll>
#define vvll vector<vll>
#define vpll vector<pair<ll,ll>>
#define mll map<ll,ll>
#define sll set<ll>
#define mod 1000000007
#define mod2 998244353
#define inf 1000000000000000
#define maxN 1e5+1
#define pb push_back
#define loop(i,n) for(ll i=0; i<n; i++)
#define loop2(j,start,end) for(ll j=start; j<=end; j++)
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define p(x) cout<<x<<"\n"
#define pl(x) cout<<x<<" "
#define fix(f,n) std::fixed<<std::setprecision(n)<<f


ll gcd (ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll binpow(ll a, ll b, ll m) {
    m = LLONG_MAX;
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
} 

void solve(){
    int a = 4, b = 10;
    int *p =&a;

    *p = 10;
    cout << "Value of a: " << a << endl; // Should print 10
}

int main(){
   
    ll t=1;
    // cin>>t;
    while(t--) solve();
}