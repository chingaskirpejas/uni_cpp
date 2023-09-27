#include "my_lib.h"

int main()
{
    Studentas laik;
    vector <Studentas> studentai;
    int studentu_sk;
    cin>>studentu_sk;
    for(int i=0; i<studentu_sk; i++)
    {
        cout<<"Studento vardas ir pavarde: ";
        cin>> laik.vard >> laik.pav;
        cout<<"Kiek pazymiu turi studentas? ";
        int n;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            int k;
            cout<<"Iveskite "<<j+1<<" pazymi: ";
            cin>>k;
            laik.paz.push_back(k);
        }
        cout<<"Iveskite egzamina: ";
        cin>>laik.egz;
        studentai.push_back(laik);
        laik.paz.clear();
    }
    for (auto &a: studentai)
    {
        int tarp;
        for(auto &paz: a.paz)
        {
            tarp+= paz;
        }
        a.rez = (tarp/a.paz.size())*0.4 + a.egz*0.6;
        cout<<a.vard<<a.pav<<a.rez;
    }
}