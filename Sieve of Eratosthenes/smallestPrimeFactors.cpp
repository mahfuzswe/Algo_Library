
// Prime Factorisation

#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N + 1];

void createSieve(){
    for(int i=1; i<=N; i++){
        spf[i] = i;
    }

    for(int i=2; i*i<=N; i++){
        if(spf[i] == i){
            for(int j = i*i; j<=N; j+=i){
                if(spf[j] == j){
                    spf[j] = i;
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
        //print prime factorisation

        // O(log n)
        while(n!=1){
            cout<<spf[n]<<" ";
            n = n/spf[n];
        }
        cout<<endl;
    }

    return 0;
}

