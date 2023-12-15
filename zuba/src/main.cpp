#include "my_lib.h"
#include "functions.h"
#include "file_generator.h"

int main()
{
    cout<<"Studentu nuskaitymui is failo spauskite 1"<<endl;
    cout<<"Studentu rankiniui ivedimui spauskite 2"<<endl;
    cout<<"Studentu failu su vector ir list tipo konteineriais spauskite 3"<<endl;
    string atsakymas;
    cin>>atsakymas;
    try {
        if (stoi(atsakymas) != 1  && stoi(atsakymas) != 2 && stoi(atsakymas) != 3){
            cout << "Negalima komanda, prasau patikrinkite ar teisingai irasete skaiciu" << endl;
            return 0;
        }
        else if (stoi(atsakymas) == 1) {
            cout << "Iveskita pavadinima failo kuri norite nsukaityti" << endl;
            string atsakymas2;
            cin >> atsakymas2;
            while(atsakymas2 != "1000.txt" && atsakymas2 != "10000.txt" && atsakymas2 != "100000.txt" &&
                    atsakymas2 != "1000000.txt" && atsakymas2 != "10000000.txt")
            {
                cout<<"Neteisingai ivestas pavadinimas, bandykite dar karta"<<endl;
                cin>>atsakymas2;
            }
            read_file(atsakymas2);
        }
        else if (stoi(atsakymas) == 2){
            cout<<"Naudoti list(1) ar vector(2)?"<<endl;
            string ats;
            cin>>ats;
            if(ats != "1" && ats != "2"){cout << "Neteisinga ivesti"; return 0;}
            else if(ats == "1") {vector<Studentas> studentu_vector = inputas(); printas(studentu_vector);}
            else {list<Studentas> studentu_list = list_inputas(); printas_list(studentu_list);}
        }
        else if (stoi(atsakymas) == 3){
            generate_files();
        }
    }
    catch(std::invalid_argument)
    {
      cout << "Iveskite skaiciu o ne raide. Programa baigia darba.";
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

list<Studentas> list_inputas()
{
    Studentas laik;
    list<Studentas> studentai;
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