#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

// Recursive function to return gcd of a and b
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

// Function to return LCM of two numbers
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int main()
{
    int N;
    int X;

    cin>>N>>X;
    int fn[N]; // funny numbers
    vector<int> aux;
    int n = sizeof(fn) / sizeof(fn[0]);
    sort(fn, fn + n);
    int sum=0;

    bool multofAnother;

    // leemos los numeros divertidos de nuestros amigos y calculamos la suma total de los amigos que podemos hacer reir
    for(int i=0; i<N; i++){
        cin>>fn[i];
        multofAnother = false;
        for(int j=0; j<i; j++){
            if(fn[i]%fn[j]==0) {
                multofAnother=true;
                continue;
            }
        }
        if (!multofAnother){
            sum+=(X/fn[i]);
            aux.push_back(fn[i]);
        }
    }

    int SMCM=0; // Suma de divisiones entre X y minimos comun multiplo desde i -> j
    int mcmofAll=aux[0]; // minimo comun multiplo de todos los elementos del arreglo
    for(int i=0; i<aux.size()-1; i++) {
        mcmofAll = lcm(mcmofAll, aux[i+1]);
        for(int j = i+1; j<aux.size(); j++) {
            int mcm = lcm(aux[i], aux[j]);
            SMCM += X/mcm;
        }
    }
    mcmofAll = X/mcmofAll;

    if (aux.size()<=2) {
        cout<<sum-SMCM<<'\n';
    }else{
        int restaTotal = SMCM-mcmofAll;
        cout<<sum-restaTotal<<'\n';
    }
    return 0;
}