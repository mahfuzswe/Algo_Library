#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int n){
    int cnt = 0;
    for(int i=1; i*i<=n; i++){
        if(n%i == 0){
            cnt++;
            if((n/i) != i){
                cnt++;
            }
        }
    }
    if(cnt == 2) return true;
    return false;
}

int N = 1000000;
bool sive[1000001];
void createSive(){
    for(int i=2; i<=N; i++){
        sive[i] = true;
    }

    for(int i=2; i*i<=N; i++){
        if(sive[i] == true){
            for(int j= i*i; j<=N; j+=i){
                sive[j] = false;
            }
        }
    }
}

int main(){
    //O(nlog(log n))
    createSive();
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(sive[n]==true){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
    }
    
    
    return 0;
}

