
#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
#define N 10
#include <fstream>


class Symbolinfo{
  string symbol, type;
  public:
    Symbolinfo(string symbol, string type){
        this->symbol=symbol;
        this->type=type;
    }
    string getsymbol(){
          return symbol;
    }
    string gettype(){
        return type;
    }
    void display(){
        cout << "<" << symbol << ", " << type << "> ";
    }

};


int hashid(string something){
    return (something.length()*49)%10;
}

//MUJHE KYA KARNA HAIN KUCH SAMAJH NAHI AA RAHA



class Symboltable{
    map<int,vector<Symbolinfo> > Table;
public:
    Symboltable(){
         for(int i=0; i<N; i++){
            Table[i]=vector<Symbolinfo>();
        }
    }

    void insert(Symbolinfo Info){
        int id= hashid(Info.getsymbol());
        Table[id].push_back(Info);
        cout << "Inserted at ("<<id<<","<< Table[id].size()-1<<")"<<endl;
    }


    void print(){
        for(auto x:Table){
            cout << x.first << "-> ";
            for(Symbolinfo y:x.second){
                y.display();
            } cout << endl;
        }
    }

    int findid(int id, string x){
        for(int i=0; i<Table[id].size(); i++){
            if(Table[id][i].getsymbol() == x){
                return i;
            }
        }return -1;
    }

    void deletesymbol(string x){
        int id= hashid(x);
        int pos = findid(id, x);
        if(pos == -1){
            cout << "Not found\n";
            return;
        }
        Table[id].erase(Table[id].begin()+pos);
        cout << "Deleted from (" << id << "," << pos << ")"<<endl;
    }



};





int main(){// PANIC FIRST

    //freopen("a.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    Symboltable Table;
    while(1){
        cout<<"Enter your option : "<<endl;
        string x;
        cin>>x;
        if(x=="I"){
            //Insert
            string symbol, type;
            cin>>symbol>>type;
            Symbolinfo Symbolinfo(symbol,type);
            Table.insert(Symbolinfo);
        }

        else if(x=="D"){
            //deletion
            string x;
            cin >> x;
            Table.deletesymbol(x);
        }

        else if(x=="P"){ //print
            cout << "Symbol Table:"<<endl;
            Table.print();
            cout <<endl;
        }

        else if(x=="L"){ //search
            string x;
            cin >> x;
            int id = hashid(x);
            int pos = Table.findid(id,x);
            if(pos == -1) cout << "Not found\n";
            else cout << "found at (" << id << "," << pos << ")" <<endl;
        }

        else {
            cout<<"Invalid!"<<endl;
        }

    }
    return 0;
}



























/*



*/
