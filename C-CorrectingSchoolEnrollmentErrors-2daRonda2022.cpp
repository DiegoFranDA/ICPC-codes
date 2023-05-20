#include <bits/stdc++.h>

using namespace std;
map<int, vector<int>> d1;
map<int, vector<int>> d2;
long long int idmin = 100000007;
long long int idmax = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N,M;
    cin>>N>>M;
    for(int i=0; i<N; i++) {
        vector<int> reqs;
        int id, nreq;
        cin>>id>>nreq;
        for(int j=0; j<nreq; j++){
            int x;
            cin>>x;
            reqs.push_back(x);
        }
        sort(reqs.begin(), reqs.end());
        d1[id]=reqs;
        if (id<idmin) idmin = id;
        if (id>idmax) idmax = id;
    }

    for(int i=0; i<M; i++) {
        vector<int> given;
        int id, ngiv; // n given
        cin>>id>>ngiv;
        for(int j=0; j<ngiv; j++){
            int x;
            cin>>x;
            given.push_back(x);
        }
        sort(given.begin(), given.end());
        d2[id]=given;
        if (id<idmin) idmin = id;
        if (id>idmax) idmax = id;
    }
    if(d1==d2){
        cout<<"GREAT WORK! NO MISTAKES FOUND!"<<'\n';
    }else{
        int mistd = 0; // mistakes in students
        int notReq = 0; // Not requested
        int missed = 0;

        for(int id=idmin; id<=idmax; id++){

            if(d1.find(id)!=d1.end() && d2.find(id)==d2.end()){
                vector<int> a = d1[id];
                mistd++;
                cout<<id<<" ";
                for(int j=0; j<a.size(); j++){
                    cout<<"+"<<a[j]<<" ";
                    missed++;
                }
                cout<<'\n';
            }
            else if (d2.find(id)!=d2.end() && d1.find(id)==d1.end()){
                vector<int> a = d2[id];
                mistd++;
                cout<<id<<" ";
                for(int j=0; j<a.size(); j++){
                    cout<<"-"<<a[j]<<" ";
                    notReq++;
                }
                cout<<'\n';
            }else if (d1.find(id)!=d1.end() && d2.find(id)!=d2.end()) {
                vector<int> a = d1[id];
                vector<int> b = d2[id];
                bool error=false;
                int i1=0;
                int i2=0;
                int f1=a.size();
                int f2=b.size();
                cout<<id<<" ";
                while(i1 < f1 && i2 < f2){
                    if (a[i1] == b[i2]){
                        i1++;
                        i2++;
                    }else if(b[i2] < a[i1]){
                        cout<<"-"<<b[i2]<<" ";
                        i2++;
                        notReq++;
                        error = true;
                    }else if(a[i1] < b[i2]){
                        cout<<"+"<<a[i1]<<" ";
                        i1++;
                        missed++;
                        error = true;
                    }
                }
                while(i1 < f1){
                    cout<<"+"<<a[i1]<<" ";
                    i1++;
                    missed++;
                    error = true;
                }
                while(i2 < f2){
                    cout<<"-"<<b[i2]<<" ";
                    i2++;
                    notReq++;
                    error = true;
                }
                if(error) mistd++;
                cout<<'\n';
            }
        }
        cout<<"MISTAKES IN "<<mistd<<" STUDENTS: "<<notReq<<" NOT REQUESTED, "<<missed<<" MISSED"<<'\n';
    }

    return 0;
}