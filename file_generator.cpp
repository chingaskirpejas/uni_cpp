#include "file_generator.h"
#include "my_lib.h"
#include "functions.h"


void generate_files()
{
    cout<<"Kiek pazymiu tures mokinys?"<<endl;
    string paz_ans;
    cin>>paz_ans;
    try{
        int l = stoi(paz_ans);
    }
    catch (std::invalid_argument)
    {
        cout << "Iveskite skaiciu o ne raide. Programa baigia darba.";
    }

    cout<<"Kokio dydzio faila sugeneruoti? 1k | 10k | 100k | 1m | 10m"<<endl;
    cout<<"                                 1    2     3     4     5"<<endl;
    string answ;
    cin>>answ;
    try{
        int ans = stoi(answ);
        if (ans != 1  && ans != 2  && ans != 3  && ans != 4  && ans != 5)
        {
            cout << "Negalima komanda, prasau patikrinkite ar teisingai irasete skaiciu" << endl;
        }
        else if(ans == 1){create_x(1000, stoi(paz_ans));}
        else if(ans == 2){create_x(10000, stoi(paz_ans));}
        else if(ans == 3){create_x(100000, stoi(paz_ans));}
        else if(ans == 4){create_x(1000000, stoi(paz_ans));}
        else {create_x(10000000, stoi(paz_ans));}

    }
    catch (std::invalid_argument)
    {
        cout << "Iveskite skaiciu o ne raide. Programa baigia darba.";
    }

}

void create_x(int amount, int paz_kiek)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(1, 10);

    string kiek = to_string(amount);
    ofstream outfile(kiek+"d.txt");
    outfile<<"Vardas   Pavarde ";
    for(int i=0; i<paz_kiek; i++)
    {
        outfile<<"ND"<<i+1<<" ";
    }
    outfile<<"EGZ"<<endl;

    for(int i=0; i<amount; i++)
    {
        outfile<<"Vardas"+ to_string(i+1)+" "<<"Pavarde"+to_string(i+1)<<" ";
        for(int j=0; j<paz_kiek+1; j++)
        {
            outfile<<dist(engine)<<" ";
        }
        outfile<<to_string(dist(engine))<<endl;
    }
    outfile.close();
}


vector <string> read_names()
{
    ifstream file("vardai.txt");
    while(file.is_open())
    {
        vector<string> vardai;
        string vardas;
        while(getline(file, vardas))
        {
            vardai.push_back(vardas);
        }
        file.close();
        return vardai;
    }
}


vector <string> read_surenames()
{
    ifstream file("pavardes.txt");
    while(file.is_open())
    {
        vector <string> pavardes;
        string pavarde;
        while(getline(file, pavarde))
        {
            pavardes.push_back(pavarde);
        }
        file.close();
        return pavardes;
    }
}