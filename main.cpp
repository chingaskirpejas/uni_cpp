#include "my_lib.h"
#include "functions.h"

int main()
{
    cout<<"Studentu nuskaitymui is failo spauskite 1"<<endl;
    cout<<"Studnetu rankiniui ivedimui spauskite 2"<<endl;
    int atsakymas;
    cin>>atsakymas;
    if(atsakymas != 1 && atsakymas != 2)
    {
        cout<<"Negalima komanda, prasau patikrinkite ar teisingai irasete skaiciu"<<endl;
        return 0;
    }
    else if(atsakymas == 1)
    {
        cout<<"Kolkas nuskaitymas is failo dar nera galimas"<<endl;
        return 0;
    }
    else
    {
        vector <Studentas> studentai = inputas();
        printas(studentai);
    }

    return 0;
}

vector <Studentas> inputas()
{
    Studentas laik;
    vector <Studentas> studentai;
    int studentu_sk;
    cout<<"Iveskite studentu skaiciu: ";
    cin>>studentu_sk;
    while (studentu_sk < 1)
    {
        cout<<"Studentu skaicius negali buti maziau nulio. Prasau bandykite dar karta: "<<endl;
        cin>>studentu_sk;
    }

    for(int i=0; i<studentu_sk; i++)
    {
        cout<<"Studento vardas ir pavarde: ";
        cin>> laik.vard >> laik.pav;
        cout<<"Pasirinkite kaip norite ivesti studento pazymius: autogeneracija(rasykite a), rankiniu budu(rasykite r):"<<endl;
        string choice;
        cin>>choice;
        if(choice == "a" || choice == "A")
        {
            random_input(laik);

        }
        else if(choice == "r" || choice == "R") {
            manual_input(laik);
            cout<<"Iveskite egzamina: ";
            cin>>laik.egz;
        }
        studentai.push_back(laik);
        laik.paz.clear();
    }

    return studentai;
}