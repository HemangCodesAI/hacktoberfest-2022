#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

class SGT{
private:
  vector<ll> seg;
public:
  SGT(ll n)
  {
    seg.resize(4*n+1);
  }

  void build(ll ind,ll low,ll high,vector<ll> a)
  {
    if(low==high)
    {
      seg[ind]=a[low];
      return;
    }
    ll mid=low+(high-low)/2;
    build(2*ind+1,low,mid,a);
    build(2*ind+2,mid+1,high,a);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
  }

  ll query(ll ind,ll low,ll high,ll l,ll r)
  {
    if(high<l or r>low) return INT_MAX;
    if(l>=low and r<=high) return seg[ind];
    ll mid=low+(high-low)/2;
    ll lft=query(2*ind+1,low,mid,l,r);
    ll rgt=query(2*ind+2,mid+1,high,l,r);
    return min(lft,rgt);
  }

  void update(ll ind,ll low,ll high,ll i,ll val)
  {
    if(low==high)
    {
      seg[ind]=val;
      return;
    }
    ll mid=(low+(high-low)/2);
    if(i<=mid) update(2*ind+1,low,mid,i,val);
    else update(2*ind+2,mid+1,high,i,val);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
  }
};

void solve() {
  ll n;
  cin >> n;
  SGT sgt = SGT(n);
}

int main() {
  solve();
  return 0;
}
