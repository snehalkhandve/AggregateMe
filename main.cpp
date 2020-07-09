#include <bits/stdc++.h>
using namespace std;
/**
 * To avoid change of file name in multiple places in code, it is stored in a variable 
*/
string main_file = "aggregator.txt";

ifstream fin;
ofstream fout;

void add(string file_name) {
    /**
     * To keep track of total lines in the file to be added
    */
    long long int total_lines = 0;

    fin.open(file_name);
    if(!fin) {
        cout << "\n Invalid File Name. \n There is no such File or Directory ...";
        exit(EXIT_FAILURE);
    }
    fout.open(main_file , ios::app);
    if(!fout) {
        cout <<"\n Error while opening "<<main_file;
        exit(EXIT_FAILURE);
    }
    string text;
    /**
     * '//' is added as a sign indicating start of a new file in aggregator.txt
    */
    fout << "//" << "\n";
    fout << file_name << "\n\nContent:\n";

    fin.seekg(0, ios::end);
    long long int file_size = fin.tellg();    
    fin.seekg(0, ios::beg);

    while(getline(fin , text))
    {
        fout << text;
        total_lines++;
    }
    fout<<"\n\nMetadata:\n";

    /**
     * current date/time based on current system
     */ 
    time_t now = time(0);

    /**
     * convert now to string form
     */
    char* dt = ctime(&now);

    

    fout << "This file is added on time: " << dt;
    fout << "Total lines: "<< total_lines<<"\n";
    fout<<"Size of the file is"<<" "<< file_size<<" "<<"bytes";
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
        cout <<"\n Error while opening "<<main_file;
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
        cout <<"\n Error while opening "<<main_file;
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
        cout <<"\n Error while opening "<<main_file;
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
    if(!fin) {
        cout <<"\n Error while opening "<<main_file;
        exit(EXIT_FAILURE);
    }
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