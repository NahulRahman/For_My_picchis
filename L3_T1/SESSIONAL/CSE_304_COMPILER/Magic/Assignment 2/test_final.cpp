#include<bits/stdc++.h>

using namespace std;

vector<string> table {};
// int ind = 0;

// declaring SymbolInfo
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


// declaring symbol Table
class SymbolTable
{
public:
    vector <SymbolInfo> ST[100];
    void insert(SymbolInfo var)
    {
            int inde = hashFunc(var);
            ST[inde].push_back(var);
            int position = ST[inde].size()-1;
            cout << "Inserted at position " << inde << "," << position <<endl;
    }
    int hashFunc(SymbolInfo var)
    {

        int sum=0;
        int n=7; //202014017
        for(int i=0; i<var.name.length(); i++)
        {
            sum=sum +(var.name[i] << n);
            
        }
        return sum %100;

    }
    void print()
    {
        for (int inde=0; inde<100; inde++)
        {
            cout << inde << " : ";
            for (int pos=0; pos<ST[inde].size(); pos++)
            {
                cout << "< " << ST[inde][pos].name << " , " <<  ST[inde][pos].type << " > ";
            }
            cout << endl;
        }
    }

    

};


int main()
{

    string line;
    int l=1;
    SymbolTable T;
    ifstream input("in.txt");
    fstream MyFile;

    int lookup(string f);

    while(getline(input, line))
    {
        //for keyword & number & function

        for(int i=0; i<line.size(); i++)  
        {
            string st=""; //keyword & function & identifier
            string nst=""; //number

            if(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]=='_') // identifier A-Z a-z _
            {
                 while(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]>='0'&&line[i]<='9'||line[i]=='_') // untill identifies A-Z a-z 0-9 _
                 {
                     st=st+line[i]; // concating new character with previous identified string

                    i++;

                 }

            }
            else if(line[i]>='0' &&line[i]<='9') //number
            {
                 while(line[i]>='0'&& line[i]<='9')
                 {
                     nst=nst+line[i];

                    i++;

                 }
            cout<<nst<<" is number "<<l<<endl;
            if(lookup(nst) == 1) // checks if already declared
            {
                cout<<nst<<" already declared"<<endl;
            }
            else
            {
                table.push_back(nst); //inserts to table if not previously declared
                //inserting into symbol table
                SymbolInfo var1(nst, "Number");
                T.insert(var1);
            }
            
            MyFile.open("numbers.txt", ios::app);
            if(MyFile.is_open())
            {
                MyFile<<nst<<" "<<l<<endl;
                MyFile.close();
            }

            }
            
            if( line[i] == '(' && line[i+1] == ')') // checks if function
                {
                    while(line[i] != ')')
                    {
                        st=st+line[i];
                        i++; 
                    }
                    st=st+line[i];
                    cout<<st<<" is function "<<l<<endl;
                    if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                    else
                    {
                        table.push_back(st);
                        //inserting into symbol table
                        SymbolInfo var1(st, "Function");
                        T.insert(var1);
                    }

                    MyFile.open("function.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }
                }
            else if("if"==st || "else"==st || "for"==st || "while"==st || "break"==st || "int"==st || "char"==st || "main"==st || "printf"==st || "scanf"==st || "return"==st)
            {
                cout<<st<<" is keyword "<<l<<endl;
                if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Keyword");
                        T.insert(var1);
                    }
                MyFile.open("keyword.txt", ios::app);
                if(MyFile.is_open())
                {
                    MyFile<<st<<" "<<l<<endl;
                    MyFile.close();
                }
            }
            else if(st!="") //all other than function and keyword are identifier
            {
              cout<<st<<" is identifier "<<l<<endl;
                if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Identifier");
                        T.insert(var1);
                    }
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

            if('&'==line[i] || '|'==line[i])
            {
              st=st+line[i];
                i++;
              if('&'==line[i] || '|'==line[i]) //checks if && or ||
              {
                st=st+line[i];
                cout<<st<<" is operator "<<l<<endl;
                if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Operator");
                        T.insert(var1);
                    }
                MyFile.open("operator.txt", ios::app);
                if(MyFile.is_open())
                {
                    MyFile<<st<<" "<<l<<endl;
                    MyFile.close();
                }

              }
            }
            else if('+'==line[i] || '-'==line[i] || '='==line[i] ||'*'==line[i] || '/'==line[i] || '%'==line[i] || '!'==line[i] )
            {
                st=st+line[i];
               
                if('='==line[i] ) //checks if += -= /= *=
                {
                 st=st+line[i];
                cout<<st<<" is operator "<<l<<endl;
                if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Operator");
                        T.insert(var1);
                    }
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
                    if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                    else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Operator");
                        T.insert(var1);
                    }
                    MyFile.open("operator.txt", ios::app);
                    if(MyFile.is_open())
                    {
                        MyFile<<st<<" "<<l<<endl;
                        MyFile.close();
                    }

                }

            }
            else if(line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == '[' || line[i] == ']') //checks parethesis
            {
                st=st+line[i];
                cout<<st<<" is parenthesis "<<l<<endl;
                if(lookup(st) == 1)
                    {
                        cout<<st<<" already declared"<<endl;
                    }
                else
                    {
                        table.push_back(st);
                        SymbolInfo var1(st, "Parenthesis");
                        T.insert(var1);
                    }
                MyFile.open("parenthesis.txt", ios::app);
                if(MyFile.is_open())
                {
                    MyFile<<st<<" "<<l<<endl;
                    MyFile.close();
                }
            }

        }

        l++;





}
T.print();
    


    return 0;
}

    int lookup(string f) //function to check tokens if already declared
    {
        int flag = 0;
        for ( string s : table)
        {
            if ( s == f )
            {
                flag = 1;
            }
        }
        return flag;
    }
