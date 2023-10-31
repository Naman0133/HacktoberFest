// Karya ko arrambh karo to uska ant krne par hi viraam lo
// Anyatha karya hi tumhara Ant kar dega.  ~Guru Brishpati

#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<deque>
#include<set>
#include<stack>

// Some type Def
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<vector<int>> VVI;
typedef vector<int> VI;
typedef vector<string> VS;
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define two(w) (1<<(w))
#define test(x,w) (x&two(w))
#define sz(v) (int)v.size()
#define all(c) c.begin(),c.end() 
#define clr(buf,val) memset(buf,val,sizeof(buf))
#define rep(i,l,r) for(int i=(l); i<(r) ; i++)
#define repv(i,v)  for(int i=0;i<(int)v.size();i++)
#define repi(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();++it)
#define inf INT_MAX
#define nl "\n"
#define debug(v)  for(int i = 0 ; i < v.size() ; i++){cout<<v[i]<<" ";} cout<<"\n";
#define inparr(arr,n) int arr[n] ; for(int i = 0 ; i < n ; i++){cin>>arr[i];}

bool sortbysec(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.ss < b.ss;
}

void dvpii(vector<PII> v){
    rep(i , 0 , v.size()) cout<<i+1<<" "<<v[i].ff<<" "<<v[i].ss<<nl;
}
int  gcd(int a, int b){
    if(a == 0)  return b;
    return gcd(b%a , a);
}

bool isprime(int n){
    if(n == 2 || n == 3)
        return true;
    if(n % 2  == 0 || n% 3 == 0)
        return false;
    int i = 5;
    while(i * i <= n){
        if(n% (i ) == 0 || n%(i+2) == 0)
            return false;
        i += 6;
    }
    return true;
}
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
void canonical(int n , vector<int>& ans){
    for(int i = 2; i*i <= n ; i++){
        int cnt= 0;
        while(n%i == 0){
            cnt++;
            n /= i;
        }
        if(cnt > 0){
            ans.PB(i);
        }
    }
    if(n > 1 ) ans.PB(n);
}
VI divisors(int a , VI& div){
    int cnt = 1;
    div.PB(1);
    for(int i = 2; i <= sqrt(a) ; i++){
        if(a%i == 0){
            if(a/i ==i){
                div.PB(i);
            }
            else{
                div.PB(i);
                div.PB(a/i);
            }
        }
    }
    div.PB(a);
    return div;
}

VI adj[100001] , vis(100001), onstack(100001) , low(100001) , in(100001) , sp(100001);
stack<int> s;
int timer = 1 , SSC = 0;
void dfs(int i){
    vis[i] =1;
    low[i] = in[i] = timer++;
    s.push(i);
    onstack[i] = 1;
    for(int child : adj[i]){
        if(vis[child] && onstack[child] ){
            low[i] = min(low[i] , in[child]);
        }
        else if(!vis[child]){
            dfs(child);
            if(onstack[i]){
                low[i] = min(low[i] ,low[child]);
            }
        }
    }
    int cnt = 0;
    if(in[i] == low[i]){
        while(true){
            int t = s.top();
            cnt++;
            s.pop();
            if(cnt > 1 || cnt == 1 && t != i){
                sp[t] = 1;
            }
            onstack[t] = 0;
            if(t == i)  break;
        }
    }
}
void solve(){
    int n , m;
    cin>>n>>m;
    rep(i , 0 , m){
        int a,b;
        cin>>a>>b;
        adj[a].PB(b);
    }
    for(int i =1 ; i<= n ; i++){
        if(!vis[i]) dfs(i);
    }
    for(int i = 1; i<= n ; i++){
        cout<<sp[i]<<" ";
    }
}
int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin>>t;
    // while(t--)
    solve();   
}
