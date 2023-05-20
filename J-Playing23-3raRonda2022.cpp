#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int nr=0; // n rondas
    int cj[2]; // cartas juan
    int cm[2]; // cartas maria
    int cc[10]; // cartas comunes
    int disponible[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //
    int sumIniJ = 0; // suma inicial de juan
    int sumIniM = 0; // suma inicial de maria

    cin>>nr;

    // sumas iniciales
    for(int i=0; i<2; i++){
        cin>>cj[i];
        if (cj[i]>10) sumIniJ+=10;
        else sumIniJ += cj[i];
        disponible[cj[i]]+=1;
    }
    for(int i=0; i<2; i++){
        cin>>cm[i];
        if (cm[i]>10) sumIniM+=10;
        else sumIniM += cm[i];
        disponible[cm[i]]+=1;
    }
    // sumas iniciales aumentadas
    for(int i=0; i<nr; i++){
        cin>>cc[i];
        if(cc[i]>10){
            sumIniJ+=10;
            sumIniM+=10;
        }else{
            sumIniJ+=cc[i];
            sumIniM+=cc[i];
        }
        disponible[cc[i]]++;
    }

    int cuantopaquepierdajuan = 24 - sumIniJ;
    int cuantopaqueganemaria = 23 - sumIniM;

    bool disponibleganemaria = false;
    bool disponiblepierdajuan = false;

    for(int i=cuantopaquepierdajuan; i<11; i++){
        if(disponible[i] < 4 && (sumIniM+i)<=23) {
            disponiblepierdajuan = true;
            cuantopaquepierdajuan = i;
            break;
        }
    }

    for(int i=cuantopaqueganemaria; i<11; i++){
        if(disponible[i] < 4 && (sumIniM+i)<=23) {
            disponibleganemaria = true;
            cuantopaqueganemaria = i;
            break;
        }
    }

    if(disponibleganemaria && !disponiblepierdajuan) {
        cout<<cuantopaqueganemaria<<'\n';
    }else if(disponiblepierdajuan && !disponibleganemaria) {
        cout<<cuantopaquepierdajuan<<'\n';
    }else if(disponibleganemaria && disponiblepierdajuan) {
        if(cuantopaqueganemaria < cuantopaquepierdajuan) {
            cout<<cuantopaqueganemaria<<'\n';
        }else{
            cout<<cuantopaquepierdajuan<<'\n';
        }
    }else{
        cout<<-1<<'\n';
    }

    return 0;
}