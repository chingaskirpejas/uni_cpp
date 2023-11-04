#include "list_test.h"


void run_list_test(int amount, int paz_kiek)
{
    cout<<"Testuojamas failas" << amount << ".txt"<<endl;

    //      FAILO KURIMAS
    auto start = std::chrono::high_resolution_clock::now();

    create_x(amount, paz_kiek);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout << "Failo kurimas uztruko " << duration.count() << " ms" <<endl;


    //     FAILO NUSKAITYMAS
    auto start1 = std::chrono::high_resolution_clock::now();
    vector <Studentas> visi_studentai = read_file(amount, paz_kiek);
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout << "Failo nuskaitymas uztruko " <<duration1.count() << " ms" << endl;


    //      FAILO RUSIAVIMAS
    auto start2 = std::chrono::high_resolution_clock::now();

    vector <Studentas> vargsiukai;
    vargsiukai.reserve(amount);
    vector <Studentas> kietekai;
    kietekai.reserve(amount);

    atrinkimas(visi_studentai, vargsiukai, kietekai);
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Masyvo rusiavimas uztruko "<< duration2.count() << " ms"<< endl;


    //      RASYMAS I FAILUS
    auto start3 = std::chrono::high_resolution_clock::now();

    write_to_file(amount, vargsiukai, kietekai);

    auto stop3 = std::chrono::high_resolution_clock::now();
    auto duration3 = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    cout<<"Rasymas i failus uztruko "<< duration3.count() << " ms" << endl;
    cout<<endl;
}