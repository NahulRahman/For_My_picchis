#include<bits/stdc++.h>
#include <vector>
using namespace std;
class SymbolTable;
class SymbolInfo
{
	string symbol, token_name;
	friend class SymbolTable;
public:
	string code;
	SymbolInfo(){
		 symbol="";
		 token_name="";
		 code="";
	 }
	SymbolInfo(string n, string c){
		 symbol=n;
		 token_name=c;
		 code="";
	}
	void show(){
		 cout<<"<";
		 cout<<symbol<<" , "<<token_name;
		 cout<<">  ";
	}
	string getSymbol(){ return symbol;}
	string getToken(){return token_name;}
};


class SymbolTable{
	vector<SymbolInfo>TABLE[10];
public:
	int hashfunction(string s){
		int len=s.size();
		int sum=0;
		for(int i=0;i<len;i++){
			if(i%2==0){
				int r=s[i];
				int d=r<<2;
				sum=sum+d;
			}
		}
		int mod=sum%10;
		return mod;
	}

	void INSERT(string sym, string tk){
		if(LookUp(sym)==-1){
			int index=hashfunction(sym);
			SymbolInfo obj(sym,tk);
			TABLE[index].push_back(obj);
			int col_index=TABLE[index].size()-1;
			cout<<"Inserted at position "<<index<<", "<<col_index<<endl;
		}
		else{
			cout<<sym<<" already exists in the Symbol Table"<<endl;
		}
	}

	int LookUp(string sym){
			int found=-1;
			int index=hashfunction(sym);

			for(int j=0;j<TABLE[index].size();j++){
				if(TABLE[index][j].symbol==sym){
					found=j;
					break;
				}
			}

			return found;
	}

	int DELETE(string sym){
			int found=-1;
			int index=hashfunction(sym);
			int col=LookUp(sym);
			auto it=TABLE[index].begin()+col;
			TABLE[index].erase(it);
			return col;
	}

	void print(){
        freopen("table.txt","w",stdout);
		for(int i=0;i<10;i++)
		{
			 cout<<i<<" -> ";
			 for(int j=0;j<TABLE[i].size();j++)
			 {
				 TABLE[i][j].show();
			 }
			 cout<<endl;
		}
		 return;
	}

};

/*int main()
{

     SymbolTable obj;
    
     obj.INSERT("+","OP","PLUS");
     obj.INSERT("-","OP","MINUS");
     obj.INSERT("123","NUM"," ");
     obj.INSERT("A","ID"," ");
     obj.INSERT("A","ID"," ");

  

     obj.print();
	 
	 obj.TABLE[0][0].show();
	 obj.TABLE[6][0].show();
	 obj.TABLE[0][2].show();

}*/

