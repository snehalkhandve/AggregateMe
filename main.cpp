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
        string old_filename = argv[2];
        string new_filename = "copy_" + old_filename;
        
        fout.open(new_filename);
        if(!fin) {
            cout << "\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }
        fin.open("aggregator.txt" , ios::app);
        if(!fout) {
            cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }

        string text;
        bool file_found = false;
        while(getline(fin, text)) {
             if((text.compare(argv[2])==0) && !file_found)
             {
                 file_found = true;
                 while (getline(fin,text))
                 {
                    if(text.compare("//")==0)
                    {
                        break;
                    }
                    else
                    {
                        fout<<text;
                    }   

                 }
                 
             }
        }
        fin.close();
        fout.close();
        
        if(!file_found)
        {
            cout<<"The given file is never copied into aggregator.txt";
        }


    }
    else if((operation.compare("cut")) == 0) {
        string old_filename = argv[2];
        string new_filename = "cut_" + old_filename;
        vector <string> buffer;
        
        fout.open(new_filename);
        if(!fin) {
            cout << "\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }
        fin.open("aggregator.txt" , ios::app);
        if(!fout) {
            cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }

        string text;
        bool file_found = false;
        while(getline(fin, text)) {
             buffer.push_back(text);
             if((text.compare(argv[2])==0) && !file_found)
             {
                 buffer.pop_back();
                 buffer.pop_back();
                 file_found = true;
                 while (getline(fin,text))
                 {
                    if(text.compare("//")==0)
                    {
                        buffer.push_back(text);
                        break;
                    }
                    else
                    {
                        fout<<text;
                    }   

                 }
                 
             }
        }
        fin.close();
        fout.close();

        remove("aggregator.txt");
        fout.open("aggregator.txt");
        if(!fout) {
            cout <<"\n Invalid File Name. \n There is no such File or Directory ...";
            exit(EXIT_FAILURE);
        }
        else
        {
           for(int i=0; i<buffer.size(); i++)
            {
               fout<<buffer[i]<<"\n";
            }
            fout.close();
        }
        

        if(!file_found)
        {
            cout<<"The given file is never copied into aggregator.txt";
        }

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