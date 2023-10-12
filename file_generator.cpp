#include "file_generator.h"
#include "my_lib.h"
void generate_files()
{
    vector <string> vardai = read_names();
    vector <string> pavardes = read_surenames();
    create_x(100, vardai, pavardes);
}

void create_x(int amount, const vector <string> &var, const vector <string> &pav)
{
    string kiek = to_string(amount);
    ofstream outfile(kiek+".txt");
    srand(static_cast<unsigned>(time(nullptr)));
    for(int i=0; i<amount; i++)
    {
        cout<<var[rand()%var.size()]<<" "<<pav[rand()%pav.size()];
    }
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