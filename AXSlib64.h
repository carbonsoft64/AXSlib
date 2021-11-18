#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include<string>
#include<functional>
using namespace std;
int nsd(int a, int b)
{
    while(b!=0)
    {
        a%=b;
        swap(a, b);
    }
    return a;
}
int nsk(int a, int b)
{
    a=a/nsd(a, b)*b;
    return a;
}
int scl(string s)
{

    int n=s.size(), k=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
        {
            k++;
            while(s[i+1]=='a' || s[i+1]=='e' || s[i+1]=='i' || s[i+1]=='o' || s[i+1]=='u')
            {
                i++;
            }
        }
    }
    return k;
}
int charNum(string s, char c)
{
    int n=s.size(), k=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]==c) k++;
    }
    return k;
}
string fixNum(string s, char c, int n, char r)
{
    if(r=='l') reverse(s.begin(), s.end());
    while(s.size()<n)
    {
        s+=c;
    }
    if(r=='l') reverse(s.begin(), s.end());
    return s;
}
int xin()
{
    int n;
    scanf("%d", &n);
    return n;
}
int xout(int n)
{
       printf("%d", n);
}
long long lxin()
{
    long long n;
    scanf("%lld", &n);
    return n;
}
long long fact(long long n)
{
    if(n==1) return 1;
    else return n*fact(n-1);
}
int mx(int a, int b)
{
    if(a>b) return a;
    else return b;
}
int mn(int a, int b)
{
    if(a<b) return a;
    else return b;
}
int comparison(int a, int b)
{
    if(a>b) return 1;
    if(a<b) return 2;
    if(a==b) return 0;
}
bool parity(int n)
{
    if(n&1)return false;
    return true;
}
long long deg(long long a, long long n)
{
    long long res=1;
    int m=1000000007;
    while(n!=0)
    {
        if(n%2==0)
        {
            //a*=a;
            a=((a%m)*(a%m))%m;
            n/=2;
        }
        else
        {
            res=(res%m)*(a%m)%m;
            n--;
        }
    }
    return res;
}
int digitsNum(int n)
{

    int res=0;
    if(n==0) return 0;
    else
    {
        res=1+digitsNum(n/10);
        return res;
    }
}
int simple(int x)
{
    if(x==1) return 0;
    int k=2;
    int t=sqrt(x);
    for(int i=2; i<=t; i++)
    {
        if(x%i==0)
        {
            k++;
            break;
        }
    }
    return k==2;
}
long long fib(long long n)
{
    long long f1=1, f2=1, fn;
    if(n==1 || n==2) return 1;
    else
    {for(long long i=0; i<n; i++)
    {
        fn=f1+f2;
        f1=f2;
        f2=fn;
    }
    return fn;
    }
}
string toBits(int n)
{
    string s="";
    if(n==2) return "10";
    while(n!=0)
    {
        char c;
        c=n%2+48;
        s+=c;
        n/=2;
    }
    reverse(s.begin(), s.end());
    return s;
}
void masIn(int n, int a[])
{
      for(int i=0; i<n; i++) a[i]=xin();
}
void masOut(int n, int a[])
{
      for(int i=0; i<n; i++) printf("%d ", a[i]);
}
bool ifStepOfDoubleBeta(int x)
{
    if(x & (x-1)==0) return true;
    return false;
}
int toASCII(string s)
{
    int n=s.size(), ic=0, r=0;
    //reverse(s.begin(), s.end());
    //for(int i=0; i<n; i++)
    for(int i=0; i<n; i++)
    {
        if(s[i]==1)
        {
            ic=i;
            break;
        }
    }
    for(int i=ic; i<n; i++) r=r*2+s[i]-48;
    return r;
}
long long f(long long n)
{
    long long res;
    if(n%4==1) res=1;
    if(n%4==2) res=1^n;
    if(n%4==3) res=0;
    return res;
}
string nonce(string hashs, string noncehave)
{
    string nonce, hashr, hashres;
    int noncei=0001;
    size_t hash0=hash<string>()(hashs), hash1;
    //long long hashi=hash;
    while(hashres.find(noncehave)!=0)
    {
    hashr=hashs;
        noncei++;
        int noncec=noncei;
        while(noncec!=0)
        {
        char c=noncec%10;
        hashr+=c;
        noncec/=10;
        }
        hash0=hash<string>()(hashr);
        hash1=hash0;
        hashres="";
        while(hash0!=0)
        {
        char c=hash0%10;
        hashres+=c+48;
        hash0/=10;
        }
        reverse(hashres.begin(), hashres.end());
        //printf("%s\n", hashres);
        //cout<<hashres<<"\n";
    }
    string hashh="";
    while(noncei!=0)
        {
        char c=noncei%10;
        hashh+=c;
        noncei/=10;
        }
    //reverse(hashh.begin(), hashh.end());
    return hashh;
}