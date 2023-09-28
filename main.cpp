#include "my_lib.h"
#include <iomanip>
#include <algorithm>



using namespace std;

vector <Studentas> inputas();
void printas(vector <Studentas> sarasas);
float vidurkis(vector <int> pazymiai, int egzaminas);
float mediana(vector <int> pazymiai);



int main()
{
    vector <Studentas> studentai = inputas();

    printas(studentai);

    return 0;
}


//inputo funkcija
vector <Studentas> inputas()
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

    return studentai;
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
float mediana(vector <int> pazymiai)
{
    float mediana;
    sort(pazymiai.begin(), pazymiai.end());
    size_t size = pazymiai.size();
    if (size % 2 == 0)
    {
        mediana = static_cast<float>(pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2;
    }
    else
    {
        mediana = pazymiai[size / 2];
    }

    return mediana;
}

void printas(vector <Studentas> sarasas)
{
    cout<<"              Vardas               Pavarde    Vid.    Med."<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for(auto &stud:sarasas)
    {
        cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(8)<<vidurkis(stud.paz, stud.egz)<<" "<<setprecision(2)<<setw(8)<<mediana(stud.paz)<<endl;
    }

}