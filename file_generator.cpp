#include "file_generator.h"
#include "my_lib.h"
#include "functions.h"


void generate_files()
{
    cout<<"Kiek pazymiu tures mokinys?"<<endl;
    string paz_ans;
    cin>>paz_ans;
    int l;
    try{
        l = stoi(paz_ans);
    }
    catch (std::invalid_argument)
    {
        cout << "Iveskite skaiciu o ne raide. Programa baigia darba.";
        return;
    }

    run_test(1000, stoi(paz_ans));
    run_test(10000, stoi(paz_ans));
    run_test(100000, stoi(paz_ans));
    run_test(1000000, stoi(paz_ans));
    run_test(10000000, stoi(paz_ans));

}


void run_test(int amount, int paz_kiek)
{
    cout<<"Testuojamas failas" << amount << ".txt"<<endl;

    //      FAILO KURIMAS
    auto start = std::chrono::high_resolution_clock::now();

    create_x(amount, paz_kiek);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Failo kurimas uztruko " << duration.count() <<endl;



    //     FAILO NUSKAITYMAS
    auto start1 = std::chrono::high_resolution_clock::now();
    vector <Studentas> visi_studentai = read_file(amount, paz_kiek);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout << "Failo nuskaitymas uztruko " <<duration1.count() << endl;


    //      FAILO RUSIAVIMAS
    auto start2 = std::chrono::high_resolution_clock::now();

    vector <Studentas> vargsiukai;
    vargsiukai.reserve(amount);
    vector <Studentas> kietekai;
    kietekai.reserve(amount);

    atrinkimas(visi_studentai, vargsiukai, kietekai);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout<<"Masyvo rusiavimas uztruko "<< duration2.count() << endl;


    //      RASYMAS I FAILUS
    auto start3 = std::chrono::high_resolution_clock::now();

    write_to_file(amount, vargsiukai, kietekai);

    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    cout<<"Rasymas i failus uztruko "<< duration3.count() << endl;
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

vector <Studentas> read_file(int kiekis, int nd_dydis)
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
            laik.rez = vidurkis(laik.paz, laik.egz);
            visi_stud.push_back(laik);
            laik.paz.clear();
        }
        file.close();
        return visi_stud;
    }
    else
    {
        cout<<"Could not open the file"<<endl;
    }

}


void atrinkimas(vector <Studentas>& visi_studentai, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai)
{
    for(const auto& studentas: visi_studentai)
    {
        if (studentas.rez < 5.0)
        {
            vargsiukai.push_back(studentas);
        } else
        {
            kietekai.push_back(studentas);
        }
    }
}

void write_to_file(int kiekis, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai)
{
    string kiek = to_string(kiekis);

    ofstream outfile(kiek+"out1.txt");
    outfile<<"Vardas     Pavarde   Galutinis";

    for(const auto& studentas: vargsiukai)
    {
        outfile<<studentas.vard<<studentas.pav<<studentas.rez<<endl;
    }
    outfile.close();


    ofstream outfile2(kiek+"out1.txt");
    outfile2<<"Vardas     Pavarde   Galutinis";

    for(const auto& studentas: kietekai)
    {
        outfile2<<studentas.vard<<studentas.pav<<studentas.rez<<endl;
    }
    outfile2.close();
}


