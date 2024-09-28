#include<bits/stdc++.h>
using namespace std;
class SymbolInfo
{
    string name="";
    string type;
public:
    SymbolInfo(char *temp,string type)
    {
        //this->name = name;
        for(int i=0;i<strlen(temp);i++){
            name+=temp[i];
        }
        this->type = type;
    }
    
    friend class SymbolTable;
};

class SymbolTable
{
    vector<SymbolInfo> table[7];
public:
    void insert(FILE *outlog,SymbolInfo var)
    {
        //ofstream outf;
        //outf.open("sample_log1.txt",ios::app);
        
        if(lookup(var.name) == -1){
            int index = hash(var.name);
            table[index].push_back(var);
            int position = table[index].size() - 1;
            //cout << var.name << " inserted at (" << index << " , " << position << ")" << endl;
            //outf << var.name << " inserted at (" << index << " , " << position << ")" << endl;
            
            printTable(outlog);
        }
        else{
            //cout << var.name << " already in Symbol Table" << endl;
            fprintf(outlog,"%s variable already exists in symbol table \n",var.name.c_str());
        }
    }

    int lookup(string name)
    {
        int index = hash(name);
        for(int i=0 ; i<table[index].size() ; i++)
        {
            if(table[index][i].name == name)
                return i;
        }
        return -1;
    }

    void remove(string name)
    {
        ofstream outf;
        outf.open("output.txt",ios::app);
        int index = hash(name);
        int position = lookup(name);
        if(position != -1){
            table[index].erase(table[index].begin() + position);
            cout << name << " removed from (" << index  << " , " << position  << ")" << endl;
            outf << name << " removed from (" << index  << " , " << position  << ")" << endl;
        }
        else
            cout << name << " Not Found. Deletion aborted" << endl;
            outf << name << " Not Found. Deletion aborted" << endl;   
    }

    void printTable(FILE *outlog)
    {      
        //outf.open("output.txt",ios::app);
        for(int i=0 ; i<7 ; i++)
        {
            //cout << i << " -> ";
            //outf << i << " -> ";
            fprintf(outlog,"%d --> ",i);
            for(int j=0 ; j<table[i].size() ; j++)
            {
                //cout << "<" << table[i][j].name << " , " << table[i][j].type << ">";
                //outf << "<" << table[i][j].name << " , " << table[i][j].type << ">";
                fprintf(outlog,"< %s %s >",table[i][j].name.c_str(),table[i][j].type.c_str());
                if(j+1 != table[i].size()){
                    //cout << " -> ";
                    //outf << " -> ";
                    fprintf(outlog," -> ");
                }
            }
            //cout << endl;
            //outf << endl;
            fprintf(outlog,"\n");
        }
    }

    int hash(string name)
    {
        int hash_value = 0;
        if(name.size() < 3){
            for(int i=0 ; i<name.size() ; i++)
            {
                hash_value += int(name[i]);
            }    
        }
        else{
            for(int i=0 ; i<3 ; i++)
            {
                hash_value += int(name[i]);
            }
        }
        hash_value = hash_value * 17;
        return hash_value % 7;
    }
};

