#include <bits/stdc++.h>
using namespace std;

string main_file = "aggregator.txt";
ifstream fin;
ofstream fout;

void add(string file_name) {
    fin.open(file_name);
    if(!fin) {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    fout.open(main_file , ios::app);
    if(!fout) {
        cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    string text;
    fout << "//" << "\n";
    fout << file_name << "\n";
    while(getline(fin , text))
         fout << text;
    fout << "\n\n";
    remove(file_name.c_str());
    cout << "File added successfully!!!\n";
    fin.close();
    fout.close();
}

void copy(string old_filename) {
    string new_filename = "copy_" + old_filename;
    
    fout.open(new_filename);
    if(!fin) {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }

    fin.open(main_file , ios::app);
    if(!fout) {
        cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }

    string text;
    bool file_found = false;
    while(getline(fin, text)) {
        if((text.compare(old_filename) == 0) && !file_found) {
            file_found = true;
            while (getline(fin,text)) {
                if(text.compare("//") == 0)
                    break;
                else
                    fout << text;
            } 
        }
    }
    fin.close();
    fout.close();
    
    if(!file_found)
        cout << "The given file is never copied into aggregator.txt\n";
}

void cut(string old_filename) {
    string new_filename = "cut_" + old_filename;
    vector <string> buffer;
    
    fout.open(new_filename);
    if(!fin) {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    fin.open(main_file , ios::app);
    if(!fout) {
        cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }

    string text;
    bool file_found = false;
    while(getline(fin, text)) {
        buffer.push_back(text);
        if((text.compare(old_filename) == 0) && !file_found) {
            buffer.pop_back();
            buffer.pop_back();
            file_found = true;
            while (getline(fin,text)) {
                if(text.compare("//") == 0) {
                    buffer.push_back(text);
                    break;
                }
                else
                    fout << text;
            }
             
        }
    }
    fin.close();
    fout.close();

    remove(main_file.c_str());

    fout.open(main_file);

    if(!fout) {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    else {
       for(int i = 0 ; i < buffer.size() ; i++)
           fout << buffer[i] << "\n";
        fout.close();
    }
    
    if(!file_found) {
        cout << "The given file is never copied into aggregator.txt";
    }
}

void display_list() {
    fin.open(main_file);
    string file_start = "//" , text;
    while(getline(fin , text)) {
        if(text.compare(file_start) == 0) {
            getline(fin , text);
            cout << text << "\n";
        }
    }
}

int main(int argc , char* argv[]) {
    if(argc < 2) {
        cout << "Invalid command!\n";
        return 0;
    }
    string operation = argv[1];
    if((operation.compare("add")) == 0)
        add(argv[2]);
    else if((operation.compare("copy")) == 0)
        copy(argv[2]);
    else if((operation.compare("cut")) == 0)
        cut(argv[2]);
    else if((operation.compare("list")) == 0)
        display_list();
    return 0;
}