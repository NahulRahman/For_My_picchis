#include<bits/stdc++.h>

using namespace std;

int main()
{

    string line, s;
    int l=1;

    ifstream input("in.txt");
    fstream MyFile;

    while(getline(input, line))
    {
        //for keyword

        for(int i=0; i<line.size(); i++)
        {
            string st="";

            if(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]=='_')
            {
                 while(line[i]>='A'&&line[i]<='Z'||line[i]>='a'&&line[i]<='z'||line[i]>='0'&&line[i]<='9'||line[i]=='_')
                 {
                     st=st+line[i];

                    i++;

                 }

            }

            if("if"==st || "else"==st || "for"==st || "while"==st || "break"==st || "int"==st || "char"==st || "main"==st || "printf"==st || "scanf"==st || "return"==st)
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

            if('&'==line[i] || '|'==line[i])
            {
              st=st+line[i];
                i++;
              if('&'==line[i] || '|'==line[i])
              {
                st=st+line[i];
                cout<<st<<" is operator "<<l<<endl;
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
               // i++;
                if('='==line[i] )
                {
                 st=st+line[i];
                cout<<st<<" is operator "<<l<<endl;
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

        }

        l++;





}



    return 0;
}
