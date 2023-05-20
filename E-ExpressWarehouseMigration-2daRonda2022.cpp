#include <bits/stdc++.h>

using namespace std;
int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    int res=0, residuo;
    cin>>N>>M;
    res = N/M;
    residuo = N%M;
    if (residuo>0) res++;
    cout<<res<<'\n';

    return 0;
}