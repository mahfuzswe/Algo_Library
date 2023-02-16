#include<bits/stdc++.h>
using namespace std;

const int N = 1000000;
int sieve[N+1];

void createSieve(){
    for(int i=2; i<=N; i++){
        sieve[i] = true;
    }

    for(int i=2; i*i<=N; i++){
        if(sieve[i] == 1){
            for(int j = i*i; j<=N; j++){
                sieve[j] = false;
            }
        }
    }
}

vector<int>generatePrimes(int N){
    vector<int>ds;
    for(int i=2; i<=N; i++){
        if(sieve[i] == true){
            ds.push_back(i);
        }
    }
    return ds;
}


int main(){
    // O(10^6)
    createSieve();

    int t; cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        //step 1: generate all primes till sqrt(r)
        // O(10^6)
        vector<int> primes = generatePrimes(sqrt(r));

        //step 2: create a dummy array of size r - l + 1 and make everyone as 1
        // O(10^6)
        int dummy[r - l + 1];
        for(int i=0; i<r-l+1; i++){
            dummy[i] = 1;
        }

        //step 3: for all prime number
        // mark its multiple as false
        for(auto pr: primes){
            int firstMultiple = (l/pr) * pr;
            if(firstMultiple < l) firstMultiple += pr;
            for(int j = max(firstMultiple,pr*pr); j<=r; j+=pr){
                dummy[j-l] = 0;
            }
        }

        //step 4: get all the primes
        for(int i=l; i<=r; i++){
            if(dummy[i-l] == 1){
                cout<<i<<" ";
            }
        }
        cout<<endl;

    }

    return 0;
}