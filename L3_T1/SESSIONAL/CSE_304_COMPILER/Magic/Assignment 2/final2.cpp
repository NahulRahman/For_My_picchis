#include<iostream>
#include<sys/types.h>
#include<unistd.h>
#include<fstream>
#include<vector>
#include<map>
using namespace std;

map <string,int> keywords;
map <string,int> operators;

class SymbolInfo
{
    string name;
    string type;
public:
    SymbolInfo(string name, string type)
    {
        this->name = name;
        this->type = type;
    }

    friend class SymbolTable;
};

class SymbolTable
{
    vector<SymbolInfo> table[7];
public:
    void insert(SymbolInfo var)
    {
        ofstream outf;
        outf.open("output.txt",ios::app);
        if(lookup(var.name) == -1){
            int index = hash(var.name);
            table[index].push_back(var);
            int position = table[index].size() - 1;
            cout << var.name << " inserted at (" << index << " , " << position << ")" << endl;
            outf << var.name << " inserted at (" << index << " , " << position << ")" << endl;
        }
        else{
            cout << var.name << " already in Symbol Table" << endl;
            outf << var.name << " already in Symbol Table" << endl;
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

    void printTable()
    {
        ofstream outf;
        outf.open("output.txt",ios::app);
        for(int i=0 ; i<7 ; i++)
        {
            cout << i << " -> ";
            outf << i << " -> ";
            for(int j=0 ; j<table[i].size() ; j++)
            {
                cout << "<" << table[i][j].name << " , " << table[i][j].type << ">";
                outf << "<" << table[i][j].name << " , " << table[i][j].type << ">";
                if(j+1 != table[i].size()){
                    cout << " -> ";
                    outf << " -> ";
                }
            }
            cout << endl;
            outf << endl;
        }
    }

//    int hash(string name)
//    {
//        int hash_value = 0;
//        if(name.size() < 3){
//            for(int i=0 ; i<name.size() ; i++)
//            {
//                hash_value += int(name[i]);
//            }
//
//        }
//        else{
//            for(int i=0 ; i<3 ; i++)
//            {
//                hash_value += int(name[i]);
//            }
//        }
//        hash_value = hash_value * 90;
//        return hash_value % 7;
//    }

     int hash(SymbolInfo var)
    {

        int sum=0;
        int n=7; //202014017
        for(int i=0; i<var.name.length(); i++)
        {
            sum=sum +(var.name[i] << n);
            return sum %100;
        }
    }
};
bool isAlphaNumeric(char c)
{
    if((int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122) || (int(c) >= 48 && int(c) <= 57))
        return true;
    else
        return false;
}
bool isFunction(string lexeme)
{
    int last = lexeme.size()-1;
    if(lexeme[last] == '(' || lexeme[last] == ')')
        return true;
    else
        return false;
}
bool isNumber(string lexeme)
{
    bool flag = false;
    for(int i=0 ; i<lexeme.size() ; i++)
    {
        char c = lexeme[i];
        if(int(c) >= 48 && int(c) <= 57){
            flag = true;
            continue;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
}

bool isIdentifier(string lexeme)
{
    bool flag = false;
    char c = lexeme[0];
    if(!((int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122))){
        return false;
    }
    for(int i=0 ; i<lexeme.size() ; i++)
    {
        char c = lexeme[i];
        if((int(c) >= 65 && int(c) <= 90) || (int(c) >= 97 && int(c) <= 122) || (int(c) >= 48 && int(c) <= 57) || c=='_'){
            flag = true;
            continue;
        }
        else{
            flag = false;
            break;
        }
    }
    return flag;
}

SymbolTable T;

void scanner()
{
    ifstream in;
    in.open("in.txt");
    string line;
    int line_no = 1;

    ofstream kout,oout,fout,nout,iout;
    kout.open("Keywords.txt",ios::app);
    oout.open("Operators.txt",ios::app);
    nout.open("Numbers.txt",ios::app);
    fout.open("Functions.txt",ios::app);
    iout.open("Identifiers.txt",ios::app);

    while(in.peek() != EOF)
    {
        getline(in,line);
        string lexeme = "";
        for(int i=0 ; i<line.size() ; i++)
        {
            char c = line[i];
            string str = "";
            str += c;
            if(c == ' ' || c == '\t' || c == '\n' || !isAlphaNumeric(c)){

                // LITERAL CHECK
                if(c == '"'){
                    string literal = "";
                    int j = i+1;
                    while(true)
                    {
                        char l = line[j];
                        if(l == '"')
                            break;
                        literal += l;
                        i++;
                        j++;
                    }
                    i++;
                    literal = '"' + literal + '"';
                    cout << line_no << " " << literal << " LITERAL" << endl;

                }
                // OPERATOR CHECK
                char cnext = line[i+1];
                string lex1 = "" , lex2 = "",lex3 ="";
                lex1 += c;
                lex2 += c;
                lex2 += cnext;
                lex3 += cnext;

                if(operators[lex2] != 0){
                    oout << line_no << " " << lex2 << endl;
                    SymbolInfo token = SymbolInfo(lex2 , "OPERATOR");

                    i++;
                }
                else{
                    if(operators[lex1] != 0){
                        oout << line_no << " " << lex1  << endl;
                        SymbolInfo token = SymbolInfo(lex1 , "OPERATOR");

                    }
                    // else if(operators[lex3] !=0 ){
                    //     cout << lex3 << " OPERATOR" <<endl;
                    // }
                }

                if(lexeme == ""){
                    // DO NOTHING
                    continue;
                }
                else{
                    if(keywords[lexeme] == 1){
                        kout << line_no << " " << lexeme << endl;
                        SymbolInfo token = SymbolInfo(lexeme,"KEYWORD");
                    }
                    else if(isNumber(lexeme)){
                        nout << line_no << " " << lexeme << endl;
                        SymbolInfo token = SymbolInfo(lexeme,"NUMBER");
                    }
                    else if(isIdentifier(lexeme)){
                        if(c == '('){
                            fout << line_no << " " << lexeme << endl;
                            SymbolInfo token = SymbolInfo(lexeme,"FUNCTION");
                            T.insert(token);
                            T.printTable();
                        }
                        else{
                            iout << line_no << " " << lexeme << endl;
                            SymbolInfo token = SymbolInfo(lexeme,"IDENTIFIER");
                            T.insert(token);
                            T.printTable();
                        }
                    }
                    else{
                        cout << "LEXICAL ERROR" << endl;
                    }
                    lexeme = "";
                    lex1 = "";
                    lex2 = "";
                }
            }
            else{
                lexeme += c;
            }
        }
        line_no++;
    }
}

void keywordInitializer()
{
    keywords["if"] = 1;
    keywords["else"] = 1;
    keywords["else if"] = 1;
    keywords["for"] = 1;
    keywords["while"] = 1;
    keywords["do"] = 1;
    keywords["break"] = 1;
    keywords["int"] = 1;
    keywords["char"] = 1;
    keywords["float"] = 1;
    keywords["double"] = 1;
    keywords["unsigned"] = 1;
    keywords["return"] = 1;
    keywords["include"] = 1;
}

void operatorInitializer()
{
    operators["+"] = 1;     // ARITHOP
    operators["-"] = 1;
    operators["*"] = 1;
    operators["/"] = 1;
    operators["%"] = 1;

    operators["&&"] = 2;    // LOGOP
    operators["||"] = 2;

    operators["=="] = 2;    // RELOP
    operators["!="] = 2;
    operators[">"] = 2;
    operators["<"] = 2;
    operators["<="] = 2;
    operators[">="] = 2;

    operators["&"] = 3;     // BITOP
    operators["|"] = 3;
    operators["<<"] = 3;
    operators[">>"] = 3;

    operators["="] = 4;     // ASSIGNOP
    operators["+="] = 4;
    operators["-="] = 4;
    operators["/="] = 4;
    operators["%="] = 4;

}

int main()
{
    keywordInitializer();
    operatorInitializer();
    scanner();
}

