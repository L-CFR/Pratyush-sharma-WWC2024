#include<iostream>
using namespace std;
int  main(){
    int n;
    cin>>n;
    int count=0;
    for(int i=(n-(n-2));i<n;i++){
        if(n%i==0){
            count=+1;
        }
    }
    if (count==0){
        cout<<"prime";
    }
    else{
        cout<<"not prime";
    }
    return 0;
}