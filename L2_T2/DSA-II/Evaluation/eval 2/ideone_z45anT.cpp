#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int EoW;
    Node *children[26];
    Node()
    {
        EoW=0;
        for(int i=0; i<26; i++)
        {
            this->children[i]=NULL;
        }
    }
};
void trie_insert(Node *root, string s)
{
    Node *u = root;
    for(int k = 0; k < s.size(); k++)
    {
        int r = s[k] - 65;
        if(u->children[r] == NULL)
            u-> children[r] = new Node;
        u = u-> children[r];
    }
    u->EoW = u->EoW + 1;
}
int trie_search(Node *root, string s,int k=0) //k is the index
{
    Node *u = root;
    for(int k = 0; k < s.size(); k++)
    {
        int r = s[k] - 65;
        if(u->children[r] == NULL)
            return 0;
        u = u-> children[r];
    }
    return u->EoW;
}
void printTRIE(Node *root, string s="") //lexicographical sort
{
    Node *cur=root;
    if(cur->EoW>=1)
    {
        cout<<s<<" "<<cur->EoW<<endl;
    }
    for(int i=0; i<26; ++i)
    {
        if(cur->children[i]!=NULL)
        {
            char c=char(i+65);
            printTRIE(cur->children[i],s+c);
        }
    }
}
void printRevTRIE(Node *root, string s="") //lexicographical sort
{
    Node *cur=root;
    for(int i=25; i>=0; --i)
    {
        if(cur->children[i]!=NULL)
        {
            char c=char(i+65);
            printRevTRIE(cur->children[i],s+c);
        }
    }
    if(cur->EoW>=1)
    {
        for(int i=0; i<cur->EoW; ++i)
        {
            cout<<s<<endl;
        }
    }
}
void printDup(Node *root, string s="") //lexicographical sort
{
    Node *cur=root;
    if(cur->EoW>1)
    {
        cout<<s<<endl;
    }
    for(int i=0; i<26; ++i)
    {
        if(cur->children[i]!=NULL)
        {
            char c=char(i+65);
            printDup(cur->children[i],s+c);
        }
    }
}
bool isLeaf(Node *root)
{
    for(int i=0; i<26; ++i)
    {
        if(root->children[i]!=NULL)
            return false;
    }
    return true;
}
bool isJunction(Node *root)
{
    int c=0;
    for(int i=0; i<26; ++i)
        if(root->children[i]!=NULL)
            c++;
    if(c>1 or root->EoW>0)
        return true;
    return false;
}
void delEdge(Node *root,char c, int d)
{
    if(!d)
        return ;
    int r=c-65;
    // Node *n=root->children[r];
    root->children[r]=NULL;
    //delete n;
}
int delTRIE(Node *root,string s,int k)
{
    Node *cur=root;
    if(cur==NULL)
        return 0;
    if(k==s.size())
    {
        if(cur->EoW==0)
            return 0;
        if(!isLeaf(cur))
        {
            cur->EoW--;
            return 0;
        }
        else
        {
            cur->EoW--;
            return 0;
        }
    }
    int r=s[k]-65;
    int d=delTRIE(cur->children[r],s,k+1);
    int j=0;
    if(isJunction(cur))
        j=1;
    delEdge(cur,s[k],d);
    if(j)
        d=0;
    return d;
}
Node * findptr(string s, Node *root)
{
    Node *u = root;
    for(int k = 0; k < s.size(); k++)
    {
        int r = s[k] - 65;
        u = u-> children[r];
    }
    return u;
}
int main()
{
    Node *root=new Node();

    while(1)
    {
        cout<<"1. Insert    2. Search    3. Delete   4. Lexicographical Sorting  5. Display Strings  6. Reverse Sort 7. Print String Appears more than 1. 8. Print String with a specific prefix. 9. End"<<endl<<endl;
        int choice;
        string x;
        cin>>choice;
        if(choice==1)
        {
            cout<<"Insert String: ";
            cin>>x;
            trie_insert(root,x);
            cout<<x<<" is inserted in the trie"<<endl;
        }
        else if(choice==2)
        {
            cout<< "Enter string to search: ";
            cin>>x;
            if(trie_search(root,x)>0)
                cout<<x<<" FOUND "<<endl;
            else
                cout<<x<<" NOT FOUND "<<endl;
        }
        else if(choice==3)
        {
            cout<<"Enter string to delete: ";
            cin>>x;
            delTRIE(root,x,0);
        }
        else if(choice==4)
        {
            printTRIE(root);
        }
        else if(choice==5)
        {
            printTRIE(root);
        }
        else if(choice==6)
        {
            printRevTRIE(root);
        }
        else if(choice==7)
        {
            printDup(root);
        }
        else if(choice ==8)
        {
            cout<<"Enter the Prefix"<<endl;
            cin>>x;
            Node *u=findptr(x,root);
            printTRIE(u,x);
        }
        else if(choice==9)
        {
            break;
        }
        else
        {
            cout<<"Invalid Choice"<<endl;
            break;
        }
        cout<<endl;
    }

}
/*inputs:

1 MIST
1 MIT
1 CSE
1 CSE
1 CE
1 MISTCSE
1 ME
1 EECE
1 ABC
1 ABC
1 AB

*/
