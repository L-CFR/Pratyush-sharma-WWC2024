#include<iostream>
using namespace std;
struct data{
        string name;
        string aoi;
        string section;
        int age;
        float cgpa;
        string dob;
        string hometown;
        string Aim;
        string uid;


    }d1;
int main() {
    cout<<"name:";
    cin>>d1.name;
    cout<<"uid:";
    cin>>d1.uid;
    cout<<"age:";
    cin>>d1.age;
    cout<<"cgpa";
    cin>>d1.cgpa;
    cout<<"aoi:";
    cin>>d1.aoi;
    cout<<"date(dd-mm-yyyy) of birth";
    cin>>d1.dob;
    cout<<"home town:";
    cin>>d1.hometown;
    cout<<"aim:";
    cin>>d1.Aim;
    cout<<"Name: "<<d1.name<<endl;
    cout<<"uid: "<<d1.uid<<endl;
    cout<<"Age: "<<d1.age<<endl;
    cout<<"cgpa: "<<d1.cgpa<<endl;
    cout<<"aoi:"<<d1.aoi;
    cout<<"dob: "<<d1.dob<<endl;
    cout<<"hometown: "<<d1.hometown<<endl;
    cout<<"aim: "<<d1.Aim<<endl;
    return 0;
}