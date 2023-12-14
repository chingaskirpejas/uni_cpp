#include "my_lib.h"
#include "functions.h"


void read_file(string filename)
{
    parse_file(filename);
}

void parse_file(string const& filename)
{

    ifstream file(filename);
    string line;
    int nd_dydis;
    if(file.is_open())
    {
        vector <Studentas> studentai;
        // read first line to determine how many ND a student has
        if(getline(file, line))
        {
            istringstream iss(line);
            string stulp;
            vector <string> stulpeliai;

            while (iss>>stulp)
            {
                stulpeliai.push_back(stulp);
            }

            nd_dydis = stulpeliai.size()-3;
        }
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
            studentai.push_back(laik);
            laik.paz.clear();
        }
        file.close();
        printas(studentai);
    }
    else
    {
        cout<<"Could not open the file";
    }

}


