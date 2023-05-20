#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::cin.tie(0);
    std::ios_base::sync_with_stdio(0);

    int n;
    int alturas[500005];
    int flechas[1000005]={0};
    cin>>n;

    for(int i=1; i<=n; i++){
        cin>>alturas[i];
    }
    int res = 0;// numero minimo de flechas que tengo que crear para ponchar todos los globos
    for(int i=1; i<=n; i++) {
      flechas[alturas[i]-1]++;
      if (flechas[alturas[i]]>0) flechas[alturas[i]]--;
    }
    for(int i=0; i<1000005; i++) res+=flechas[i];
    cout<<res<<'\n';

    return 0;
}