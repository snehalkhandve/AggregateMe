#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin1, fin2;
    ofstream fout;
    string file_name1 , file_name2 , file_name3;
    cout<<"\n Enter First File Name with Extension '.txt'    :   ";
    cin >>  file_name1;
    cout<<"\n Enter Second File Name with Extension '.txt'    :   ";
    cin >> file_name2;
    cout<<"\n Enter Aggregate File Name with Extension '.txt'    :   ";
    cin >> file_name3;

    fin1.open(file_name1.c_str());
    fin2.open(file_name2.c_str());

    if(!fin1 || !fin2)
    {
      cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
      exit(EXIT_FAILURE);
    }

    fout.open(file_name3);
    
    if(!fout)
    {
      cout<<"\n Invalid File Name. \n There is no such File or Directory ...";
      exit(EXIT_FAILURE);
    }

    string text;
    
    while (getline (fin1, text)) {
         fout<<text;
    }
    fout << "\n";
    while (getline (fin2, text)) {
         fout<<text;
    }
     
    cout<<"\n Two Files have been Merged into "<<file_name3<<".\n Merged Successfully...!!!\n";
    
    fin1.close();
    fin2.close();
    fout.close();
    
    return 0;
}
