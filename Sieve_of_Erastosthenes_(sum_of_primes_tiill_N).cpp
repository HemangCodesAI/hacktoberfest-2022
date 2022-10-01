#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll sum_of_primes_till_N(ll N)
{
  vector<bool> prime(N + 1, true);
  deque<ll> dq;
  for(ll i = 2; i * i <= N; i++)
  {
    if(prime[i])
    {
      for(ll j = i * i; j <= N; j += i) prime[j] = false;
    }
  }

  for(ll i = 2; i <= N; i++)
  {
    if(prime[i]) dq.push_back(i);
  }
  
  // for(auto&u:dq) cout << u << " ";
  
  cout << endl;
  ll sum_of_primes = accumulate(dq.begin(), dq.end(), 0LL);
  return sum_of_primes;
}

int main(){
  ll n;
  cout << "Enter the number till which you want your summation : ";
  cin >> n;
  cout << "Sum of all the primes till "<< n << " is : " << sum_of_primes_till_N(n) << endl;
  return 0;
}
