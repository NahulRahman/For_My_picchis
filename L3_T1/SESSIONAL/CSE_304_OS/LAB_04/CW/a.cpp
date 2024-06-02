#include<iostream>
using namespace std;

int main(){
    int a[3],b[3],c[3],tat[3],w[3];
    for (int i=0;i<3;i++) cin>>a[i];
    for (int i=0;i<3;i++) cin>>b[i];
    for (int i=0;i<3;i++){
        if(i==0) c[i]=a[i]+b[i];
        else c[i]=c[i-1]+b[i];
    }
    for (int i=0;i<3;i++){
        tat[i]=c[i]-a[i];
    }
    for (int i=0;i<3;i++){
        w[i]=tat[i]-b[i];
    }
    for(int i=0;i<3;i++) cout<<c[i]<<" "<<endl;
    for(int i=0;i<3;i++) cout<<tat[i]<<" "<<endl;
    for(int i=0;i<3;i++) cout<<w[i]<<" "<<endl;
}
