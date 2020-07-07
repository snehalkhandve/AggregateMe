#include <bits/stdc++.h>
using namespace std;

int main(int argc , char* argv[]) {
    ifstream fin;
    ofstream fout;
    if(argc < 2) {
        cout << "Invalid command!\n";
        return 0;
    }
    string operation = argv[1];
    if((operation.compare("add")) == 0) {
        string fname = argv[2];
        fin.open(argv[2]);
        if(!fin) {
            cout << "\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }
        fout.open("aggregator.txt" , ios::app);
        if(!fout) {
            cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }
        string text;
        fout << "//" << "\n";
        fout << argv[2] << "\n";
        while(getline(fin, text)) {
             fout << text;
        }
        fout << "\n\n";
        remove(argv[2]);
        cout << "File added successfully!!!\n";
    }
    else if((operation.compare("copy")) == 0) {

    }
    else if((operation.compare("cut")) == 0) {

    }
    else if((operation.compare("list")) == 0) {
        fin.open("aggregator.txt");
        string file_start = "//" , text;
        while(getline(fin, text)) {
            if(text.compare(file_start) == 0) {
                getline(fin , text);
                cout << text << "\n";
            }
        }
    }
    
    fin.close();
    fout.close();
    
    return 0;
}