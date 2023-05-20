#include <bits/stdc++.h>

using namespace std;

int main()
{
  map<string, int> comb;

  int n,c;
  cin>>n>>c;
  string palabra;
  for(int i=0; i<n; i++){
    cin>>palabra;
    int pos;
    for(int j=0; j<palabra.size(); j++){
      if(palabra[j]=='*'){
        pos = j;
        break;
      }
    }
    for(int j='a'; j<='z'; j++){
      char letra = j;
      palabra[pos] = letra;
      comb[palabra]++;
    }
  }
  string resp;
  int mayor = 0;
  for(auto p: comb){
    if(p.second > mayor){ // el map nos ordena las llaves lexicographicamente y en esta condicion agarramos la primer palabra con el mayor numero de ocurrencias
      mayor  = p.second;
      resp = p.first;
    }
  }

  cout<<resp<<" "<<mayor<<'\n';
  return 0;
}