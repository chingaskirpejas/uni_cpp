#include "my_lib.h"
#include <iomanip>
#include <algorithm>

using namespace std;


float vidurkis(vector <int> pazymiai, int egzaminas);
int mediana(vector <int> pazymiai);
void printas(vector <Studentas> sarasas);

int main()
{
    Studentas laik;
    vector <Studentas> studentai;
    int studentu_sk;
    cout<<"Iveskite studentu skaiciu: ";
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

    printas(studentai);

    return 0;
}

// funkcija apskaiciuojanti vidurki ir grazinanti ji
float vidurkis(vector <int> pazymiai, int egzaminas)
{
    float rezultatas=0;
    for (auto &a: pazymiai)
    {
        rezultatas += a;
    }
    rezultatas = (rezultatas/pazymiai.size())*0.4; // pazymiu vidurkis
    rezultatas += egzaminas*0.4; // pridedam egzamino svori/dali?
    return rezultatas;
}

// funkcija grazinanti mediana
int mediana(vector <int> pazymiai)
{
    int mediana;
    sort(pazymiai.begin(), pazymiai.end());
    size_t size = pazymiai.size();
    if (size % 2 == 0)
    {
        mediana = (pazymiai[size / 2 - 1]+pazymiai[size / 2 + 1]) / 2;
    }
    else
    {
        mediana = pazymiai[size / 2];
    }

    return mediana;
}

void printas(vector <Studentas> sarasas)
{
    cout<<"Vardas         Pavarde    Vid.    Med."<<endl;
    cout<<"-----------------------------------------"<<endl;
    for(auto &stud:sarasas)
    {
        cout<<stud.vard<<" "<<stud.pav<<" "<<setprecision(2)<<vidurkis(stud.paz, stud.egz)<<" "<<mediana(stud.paz)<<endl;
    }

}