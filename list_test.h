#include "my_lib.h"
#include "functions.h"
#include "file_generator.h"
#ifndef ZUBA_LIST_TEST_H
#define ZUBA_LIST_TEST_H




void run_list_test(int amount, int paz_kiek);
list<Studentas> read_file_list(int kiekis, int nd_dydis);
void list_atrinkimas(list<Studentas>& visi_studentai, list<Studentas>& vargsiukai, list<Studentas>& kietekai);
void write_list_to_file(int kiekis, list<Studentas>& vargsiukai, list<Studentas>& kietekai);

#endif //ZUBA_LIST_TEST_H
