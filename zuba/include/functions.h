
#ifndef UNI_CPP_FUNCTIONS_H
#define UNI_CPP_FUNCTIONS_H


struct Studentas {
    string vard, pav;
    vector <int> paz;
    int egz;
    float rez;

    string get_string();
};

list<Studentas> list_inputas();
vector <Studentas> inputas();
void printas(vector <Studentas>& sarasas);
void printas_list(list<Studentas>& sarasas);
float vidurkis(vector <int> pazymiai, int egzaminas);
float mediana(vector <int> pazymiai);
void input_loop(Studentas& laik);
void manual_input(Studentas& laik);
void random_input(Studentas& laik);
void read_file(string filename);
void parse_file(string const& filename);
bool pagal_varda(Studentas& a, Studentas& b);

#endif //UNI_CPP_FUNCTIONS_H
