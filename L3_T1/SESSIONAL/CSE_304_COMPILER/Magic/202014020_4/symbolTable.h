#include<cstdio>
#include<string.h>
#include<stdio.h>
#include<fstream>   
#include <bits/stdc++.h>

using namespace std;

struct symbolinfo{
    string name;
    string type;
	 
};

class symboltable{
	string n, t;

	FILE *fptr1= fopen("log.txt","a");
	FILE *fptr2= fopen("log_error.txt","a");
    vector <symbolinfo> vec[10];
    public:
    int hashfunction(string name){
        int length=name.length();
        int middle=length/2;
        int m=name[middle];
        return m%10;
    }
    int lookup(string name){
        int hashvalue=hashfunction(name);
       // cout<<"here:"<<hashvalue<<endl;
        vector<symbolinfo> v=vec[hashvalue]; int flag=0;
        for(auto find=v.begin();find!=v.end(); ++find){
          if(find->name==name){
                flag=1;
                break;
            }
        }
        if (flag ==0) return 0;
        else return 1;
    }

    void insert(string name, string type){
        symbolinfo *ob=new symbolinfo();
        ob->name=name;
        ob->type=type;
        int hashvalue=hashfunction(ob->name);
       // cout<<"here:"<<hashvalue<<endl;
        vector<symbolinfo> v=vec[hashvalue]; int flag=0;
        for(auto find=v.begin();find!=v.end(); ++find){
          if(find->name==ob->name && find->type==ob->type){
                flag=1;
                break;
            }
        }
        if(flag==0)
        vec[hashvalue].push_back(*ob);
        else
        {
            cout<<name<<" variable already declared"<<endl;
			fprintf(fptr2,"%s variable already declared\n", name);
        }

    }


    void print(){
        vector<symbolinfo>::iterator it;

        for(int i=0;i<10;i++){
            cout<<i<<"-->";
			fprintf(fptr1,"%d -->",i);
            for(auto it:vec[i]){
				n=it.name;
				t=it.type;
                cout<<"<"<<n<<" "<<t<<"> ";
				fprintf(fptr1,"<%s %s>",n,t);
            }
            cout<<endl;
			fprintf(fptr1,"\n");
        }
    }
    void del(string name, string type){
        int hashvalue=hashfunction(name);
        int flag=0, count=0;
        vector<symbolinfo> find=vec[hashvalue];
        for(auto i=find.begin(); i!=find.end(); ++i){
            count++;
            if(i->name==name && i->type==type){
                flag++;
                break;
            }
        }
        if(flag ==0) cout<<"Not found"<<endl;

        else {
            vec[hashvalue].erase(vec[hashvalue].begin()+count);
        }

    }
	

};

//int main()
//{
//    symboltable s;
//    s.insert("anan", "id");
//    s.insert("var", "id");
//    s.insert("123", "number");
//   s.insert("123", "number");
//    //s.del("1var", "id");
//    s.print();
//}
