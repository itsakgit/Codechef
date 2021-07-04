#include <bits/stdc++.h>
#define ll long long int
#define MAX 100000
using namespace std;
const ll MOD = 1e9 + 7;

ll multiply(ll x, ll res[], ll res_size) {
ll carry = 0;
for (ll i = 0; i < res_size; i++) {
    ll prod = res[i] * x + carry;
    res[i] = prod % 10;
    carry = prod / 10;
}
while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}
string power(ll x, ll n)
{
string s = ""; 
if(n == 0 ){
    s=1;
   return s;
}
ll res[MAX];
ll res_size = 0;
ll temp = x;
while (temp != 0) {
    res[res_size++] = temp % 10;
    temp = temp / 10;
}
for (ll i = 2; i <= n; i++)
    res_size = multiply(x, res, res_size);
for (ll i = res_size - 1; i >= 0; i--)
     s = s + to_string(res[i]);
return s;     
}
string multiplyc(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
    return s;
}
ll powerLL(ll x, ll n)
{
    ll result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}
ll powerStrings(string sa, string sb)
{
    ll a = 0, b = 0;
    for (int i = 0; i < sa.length(); i++)
        a = (a * 10 + (sa[i] - '0')) % MOD;
    for (int i = 0; i < sb.length(); i++)
        b = (b * 10 + (sb[i] - '0')) % (MOD - 1);
    return powerLL(a, b);
}
ll revf(ll num)
{
    ll rev,result;
    ll count=0;
    ll arr[1000];
    ll i=0;
    while(num>0)    
    {    
     rev = num%10; 
     arr[i]=rev;
     num = num/10; 
      count++;
      i++;
    } 
    reverse(arr,arr+count);
    ll b=0;
    string s="";
    string s1="";
    if(count%2==0)
    {
      arr[count]=arr[0];
      for(ll i=0;i<=count;i++)
      {
        s += to_string(arr[i]);   
      }
      ll a = stoi(s);
      s.clear();
      return a;
    }
    else
    {
      for(ll i=0;i<count;i++)
      {
        s1 += to_string(arr[i]);   
      }
      ll b = stoi(s1);
      s1.clear();
      return b;
    }
}
int main() {
	ll q;
	cin>>q;
	while(q--)
	{
	ll l,r;
	cin>>l>>r;
	string product="1";
	string s3="1000000007";
	for(ll i=l+1;i<=r;i++)
	{
	   string s2=power(l,revf(i)); 
	   product = multiplyc(product,s2);
	}
	cout<<powerStrings(product,s3)<<endl;
	}
	return 0;
}                                                                                       
