#include "my_lib.h"
#include "functions.h"

int main()
{
    cout<<"Studentu nuskaitymui is failo spauskite 1"<<endl;
    cout<<"Studentu rankiniui ivedimui spauskite 2"<<endl;
    string atsakymas;
    cin>>atsakymas;
    try {
        if (stoi(atsakymas) != 1  && stoi(atsakymas) != 2 && stoi(atsakymas) != 3){
            cout << "Negalima komanda, prasau patikrinkite ar teisingai irasete skaiciu" << endl;
            return 0;
        } else if (stoi(atsakymas) == 1) {
            cout << "Kokio dydzio faila nuskaityti?" << endl;
            cout << "1 - 10k | 2 - 100k | 3 - 1mil" << endl;
            string atsakymas2;
            cin >> atsakymas2;
            try {
                if (stoi(atsakymas2) != 1 && stoi(atsakymas2) != 2 && stoi(atsakymas2) != 3) {
                    cout << "Ivedete neteisinga skaiciu";
                    return 0;
                }
                else if(stoi(atsakymas2) == 1) {read_file(1);}
                else if(stoi(atsakymas2) == 2) {read_file(2);}
                else if(stoi(atsakymas2) == 3) {
                    cout<<"Milijoninis failas buvo per didelis kad ikelt i GitHub.";
                    read_file(2);
                }
            }
            catch (std::invalid_argument) {
                cout << "Iveskite skaiciu o ne raide. Programa baigia darba.";
            }
        } else if (stoi(atsakymas) == 2) {
            vector<Studentas> studentai = inputas();
            printas(studentai);
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