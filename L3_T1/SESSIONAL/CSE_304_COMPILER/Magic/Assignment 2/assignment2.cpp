#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

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
    vector<SymbolInfo> arr[100];
public:

    void insert(SymbolInfo var)
    {
        ofstream outf;
        outf.open("output.txt",ios::app);
        int index = hashFunc(var);
        int position= lookup(var,index);
        if(position!=-1)
        {
            cout<<"Already inserted in symbol table"<<endl;
            outf << var.name << " already in Symbol Table" << endl;
        }
        else
        {
            arr[index].push_back(var);
            int position = arr[index].size()-1;
            cout << "Inserted at position " << index << "," << position <<endl;
            outf << var.name << " inserted at (" << index << " , " << position << ")" << endl;
        }

        outf.close();
    }

    int hashFunc(SymbolInfo var)
    {

        int sum=0;
        int n=7; //202014017
        for(int i=0; i<var.name.length(); i++)
        {
            sum=sum +(var.name[i] << n);
            return sum %100;
        }
    }

    int lookup(SymbolInfo var, int index)
    {
        for (int i=0; i<arr[index].size(); i++)
        {
            if (var.name == arr[index][i].name)
                return i;
        }
        return -1;
    }

    void delete_(SymbolInfo var)
    {
        int index = hashFunc(var);
        int position = lookup(var, index);
        if (position == -1)
        {
            cout << "Not found" << endl;
        }
        else
        {
            arr[index].erase(arr[index].begin()+position);
            cout << "Deleted from " << index << " , " << position << endl;
        }

    }

    void print()
    {
        for (int index=0; index<100; index++)
        {
            cout << index << " -> ";
            for (int pos=0; pos<arr[index].size(); pos++)
            {
                cout << "< " << arr[index][pos].name << " , " <<  arr[index][pos].type << " > ";
            }
            cout << endl;
        }
    }
    void appendToFile(string line)
    {
        ofstream outfile ("output.txt", ios::app);
        if (outfile.is_open())
        {
            outfile << line << endl;

        }
        else
        {
            cout << "unable to append to file" << endl;
        }

        outfile.close();
    }



};

bool isFunction(string lexeme)
{
    int last = lexeme.size()-1;
    if(lexeme[last] == '(' || lexeme[last] == ')')
        return true;
    else
        return false;
}

int main()
{
    string line, s;
    int l=0;
    string le;
    ifstream input("in.txt");
    ofstream MyFile("output.txt");

    while(getline(input, line))
    {
        ++l;

        //for keyword

        for(int i=0; i<line.size(); i++)
        {
            string st="";

            if(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]=='_')
            {
                while(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]>='0'&&line[i]<='9'||line[i]=='_')
                {
                    st=st+line[i];
                    le = line[i];
                    i++;

                }

            }

            if("if"==st || "else"==st || "for"==st || "while"==st || "auto"==st ||"do"==st || "break"==st || "int"==st ||"void"==st || "float"==st ||"double"==st  ||"continue"==st || "union"==st || "return"==st || "include"==st)
            {
                cout<<st<<" is keyword "<<l<<endl;
                MyFile.open("keyword.txt", ios::app);
                if(MyFile.is_open())
                {
                    MyFile<<st<<" "<<l<<endl;
                    MyFile.close();
                }
            }
            else if(st!="")
            {
                cout<<st<<" is identifier "<<l<<endl;
                MyFile.open("identifier.txt", ios::app);
                if(MyFile.is_open())
                {
                    MyFile<<st<<" "<<l<<endl;
                    MyFile.close();
                }
            }

        }

        //for operator

        for(int i=0; i<line.size(); i++)
        {
            string st="";

            if('& &'==line[i] || '| |'==line[i] || '!'==line[i])
            {
                st=st+line[i];
                i++;
                if('&&'==line[i] || '||'==line[i] || '!'==line[i])
                {
                    st=st+line[i];
                    cout<<st<<" is Logical operator "<<l<<endl;
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }
            }
            else if('+'==line[i] || '-'==line[i] || '*'==line[i] || '%'==line[i] )
            {
                st=st+line[i];
                // i++;
                if('+'==line[i] )
                {
                    st=st+line[i];
                    cout<<st<<" is Arithmetic operator "<<l<<endl;
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }

                 else if('<='==line[i] || '>='==line[i] || '<'==line[i] || '>'==line[i] )
            {
                st=st+line[i];
                // i++;
                if('<='==line[i] )
                {
                    st=st+line[i];
                    cout<<st<<" is Relational operator "<<l<<endl;
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }

                 else if('='==line[i] || '-='==line[i] || '*='==line[i] || '%='==line[i] )
            {
                st=st+line[i];
                // i++;
                if('+'==line[i] )
                {
                    st=st+line[i];
                    cout<<st<<" is Assignment operator "<<l<<endl;
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }


                else
                {
                    cout<<st<<" is operator "<<l<<endl;
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }

            }


            for(int i=0; i<line.size(); i++){
                string st="";

              if('{'==line[i] || '}'==line[i] || '['==line[i] || ']'==line[i]  || '('==line[i] || ')'==line[i] )
            {
                st=st+line[i];
                // i++;
                if('['==line[i] )
                {
                    st=st+line[i];
                    cout<<st<<" is parenthesis "<<l<<endl;
                    MyFile.open("parenthesis.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }

        }

            }

        //l++;





    }

            }
        }
    }
    isFunction(le);
    cout << le;

    MyFile.close(), input.close();
    return 0;
}
