#include "my_lib.h"
#include "functions.h"

//inputo funkcija

bool pagal_varda(Studentas& a, Studentas& b)
{
    return a.vard<b.vard;
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
    laik.egz = rand() % 10 + 1;
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

void printas(vector <Studentas> sarasas)
{
    sort(sarasas.begin(), sarasas.end(), pagal_varda);
    string decision;
    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
    cin>>decision;
    while(decision != "V" && decision != "v" && decision != "m" && decision != "M")
    {
        cout<<"Neteisingai ivestas simbolis, bandykite dar karta: "<<endl;
        cin>>decision;
    }

    if(decision == "v" || decision == "V")
    {
        cout<<"              Vardas               Pavarde        Vid."<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(10)<<vidurkis(stud.paz, stud.egz)<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde        Med."<<endl;
        cout<<"---------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(10)<<mediana(stud.paz)<<endl;
        }
    }
}


void printas_list(list<Studentas>& sarasas)
{
    sarasas.sort(pagal_varda);
    string decision;
    cout<<"Iveskite M kad rodytu mediana, V kad rodytu vidurki"<<endl;
    cin>>decision;
    while(decision != "V" && decision != "v" && decision != "m" && decision != "M")
    {
        cout<<"Neteisingai ivestas simbolis, bandykite dar karta: "<<endl;
        cin>>decision;
    }

    if(decision == "v" || decision == "V")
    {
        cout<<"              Vardas               Pavarde        Vid.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(10)<<vidurkis(stud.paz, stud.egz)<<" "<<&stud<<endl;
        }
    }
    else if(decision == "m" || decision == "M")
    {
        cout<<"              Vardas               Pavarde        Med.       Memory Address"<<endl;
        cout<<"---------------------------------------------------------------------------"<<endl;
        for(auto &stud:sarasas)
        {
            cout<<setw(20)<<stud.vard<<" "<<setw(20)<<stud.pav<<" "<<setprecision(2)<<setw(10)<<mediana(stud.paz)<<" "<<&stud<<endl;
        }
    }
}