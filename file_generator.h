#include "my_lib.h"
#include "functions.h"
#ifndef ZUBA_FILE_GENERATOR_H
#define ZUBA_FILE_GENERATOR_H
vector <string> read_surenames();
vector <string> read_names();
void generate_files();
void create_x(int amount, int paz_kiek);
void run_test(int amount, int paz_kiek);
vector <Studentas> read_file(int kiekis, int nd_dydis);
void atrinkimas(vector <Studentas>& visi_studentai, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai);
void write_to_file(int kiekis, vector <Studentas>& vargsiukai, vector <Studentas>& kietekai);
#endif //ZUBA_FILE_GENERATOR_H