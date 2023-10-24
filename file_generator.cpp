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
    cout<<"Generuojami failai"<<endl;
    create_x(1000, stoi(paz_ans));
    create_x(10000, stoi(paz_ans));
    create_x(100000, stoi(paz_ans));
    create_x(1000000, stoi(paz_ans));
    create_x(10000000, stoi(paz_ans));

}


void run_test(int amount, int paz_kiek)
{
    auto start = std::chrono::high_resolution_clock::now();

    create_x(amount, paz_kiek);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Failo kurimas uztruko" << duration.count() <<endl;


    vector <Studentas> vargsiukai;
    vargsiukai.reserve(amount);
    vector <Studentas> kietekai;
    kietekai.reserve(amount);

    read_file(amount, paz_kiek, vargsiukai, kietekai);

}


void create_x(int amount, int paz_kiek)
{
    std::random_device rd;
    std::mt19937 engine(rd());
    std::uniform_int_distribution<> dist(1, 10);

    string kiek = to_string(amount);
    ofstream outfile(kiek+".txt");
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

void read_file(int kiekis, int nd_dydis, vector <Studentas>& daugiau, vector <Studentas>& maziau)
{

    ifstream file(to_string(kiekis) + ".txt");
    string line;

    vector <Studentas> visi_stud;
    visi_stud.reserve(kiekis);

    if(file.is_open())
    {
        while(getline(file, line))
        {
            Studentas laik;
            istringstream iss(line);
            string stulp;
            vector <string> stulpeliai;
            while (iss>>stulp)
            {
                stulpeliai.push_back(stulp);
            }

            laik.vard = stulpeliai[0];
            laik.pav = stulpeliai[1];
            for(int i=2; i<nd_dydis; i++)
            {
                laik.paz.push_back(stoi(stulpeliai[i]));
            }
            laik.egz = stoi(stulpeliai[stulpeliai.size()-1]);
            laik.paz.clear();
        }
        file.close();
    }
    else
    {
        cout<<"Could not open the file"<<endl;
    }

}

