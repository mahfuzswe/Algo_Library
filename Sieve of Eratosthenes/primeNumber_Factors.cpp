#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int sieve[N+1];
void createSieve(){
    for(int i=2; i<=N; i++){
        sieve[i] = 1;
    }

    for(int i=2; i*i<=N; i++){
        if(sieve[i] == 1){
            for(int j = i*i; j<=N; j+=i){
                if(sieve[j] != 0){
                    sieve[i]++;
                    sieve[j] = 0;
                }
            }
        }
    }
}

int main(){

    createSieve();

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        //O(1)
        cout<<sieve[n]<<endl;
    }
}