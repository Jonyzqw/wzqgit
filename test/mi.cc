//求a^b的最后三位是多少
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int normalPower(ll a , ll b){
    ll res=1;
    while(b>0){
        if(b%2==0){
            b = b/2;
            a = a*a%1000;
        }else{
            b = b-1;
            b = b/2;
            res = res*a%1000;
            a = a*a%1000;
        }
    }
    // int res =1;
    // for(int i=0;i<b;i++){
    //     res *= a;
    //     res %= 1000;
    // }
    return res;
}
int main(){
    clock_t t1,t2;
    ll a = 2;
    ll b = 10;
    t1 = clock();
    cout<<normalPower(a, b)<<endl;
    t2 = clock();
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;
    // cout<<typeid(t2).name()<<" "<<typeid(t1).name()<<endl;
}