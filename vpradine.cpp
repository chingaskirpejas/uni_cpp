#include "my_lib.h"
#include <iomanip>
#include <algorithm>

using namespace std;

vector <Studentas> inputas();
void printas(vector <Studentas> sarasas, string decision);
float vidurkis(vector <int> pazymiai, int egzaminas);
float mediana(vector <int> pazymiai);
void input_loop(Studentas& laik);
void manual_input(Studentas& laik);
void random_input(Studentas& laik);


int main()
{
    vector <Studentas> studentai = inputas();
    string decision;
    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
    cin>>decision;
    printas(studentai, decision);

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
        cout<<"Pasirinkite kaip norite ivesti studento pazymius autogeneracija(rasykite a), rankiniu budu(rasykite r):"<<endl;
        string choice;
        cin>>choice;
        if(choice == "a" || choice == "A")
        {
            random_input(laik);
        }
        else if(choice == "r" || choice == "R")
        {
            manual_input(laik);
        }
        cout<<"Iveskite egzamina: ";
        cin>>laik.egz;
        studentai.push_back(laik);
        laik.paz.clear();
    }

    return studentai;
}
void manual_input(Studentas& laik)
{
        cout<<"Ivedus pazymi paspauskite enter"<<endl;
        cout<<"Pazymiu ivedimui baigti paspauskite q arba enter"<<endl;
        cout<<"Iveskite studento pazymius: ";
        input_loop(laik);
}

void random_input(Studentas& laik)
{
    srand(time(0));
    for(int i=0; i<10; i++) {
        int j = rand() % 10 + 1;
        laik.paz.push_back(j);
    }
}

void input_loop(Studentas& laik)
{
    string paz;
    cin.ignore();
    while(true)
    {
        getline(cin, paz);
        if(paz == "q" || paz.empty())
        {
            break;
        }
        int in = std::stoi(paz);
        if(in<0 || in>10)
        {
            cout<<"Ivedete bloga skaiciu";
            continue;
        }
        laik.paz.push_back(in);
    }
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
    rezultatas = rezultatas + (egzaminas*0.6); // pridedam egzamino svori/dali
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

void printas(vector <Studentas> sarasas, string decision)
{
    if(decision == "v" || decision == "V")
    {
        cout<<"              Vardas               Pavarde       Vid."<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(8)<<vidurkis(stud.paz, stud.egz)<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde    Med."<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(8)<<mediana(stud.paz)<<endl;
        }
    }
    else
    {
        string decision2;
        cout<<"Neteisingas simbolis, bandykite dar karta"<<endl;
        cin>>decision2;
        printas(sarasas, decision2);
    }
}