#include<bits/stdc++.h>
using namespace std;
#define MAX 256
class node
{
    node *suff[MAX];//array of object pointers
    list<int> *index; //list of indexes to each suffix's first element
    public:
    node() // create a list for each suff element, each of those is a list initself
    {
        index = new list<int>;//create list
        for(int i=0; i<MAX;i++)//initialize all to NULL initially
            suff[i] = NULL;

    }

    void addsuffix(string suffix,int sindex);//add a suffix string, and store its starting index in suffindex
    list<int>* searchpattern(string pattern);//search for pattern and return the pattern as a list
};

void node::addsuffix(string suffix, int sindex)
{
    index->push_back(sindex); // add the address of the suffix's list's first letter into index list
   if(suffix.size()>0)
    {
        char cindex = suffix[0];
        printf("cindex=%d",cindex);
        if(suff[cindex]==NULL)
        {
            suff[cindex] = new node();
        }
        suff[cindex]->addsuffix(suffix.substr(1),sindex+1);

    }

}
list<int>* node::searchpattern(string pattern)
{

    if(pattern.size()==0)
    {
        return index;
    }
        if(suff[pattern[0]]!=NULL)
        return (suff[pattern[0]])->searchpattern(pattern.substr(1));
    else
        return NULL;
}

class trie
{
    node root;
    public:
    trie(string mainstring)
    {
        for(int i=0;i<mainstring.length();i++)
        {
            root.addsuffix(mainstring.substr(i),i);
        }
    }
    void searchpat(string pattern, int *locarray,int *index);

};

void trie::searchpat(string pattern,int *locarray,int *index)
{

    list<int> *res = root.searchpattern(pattern);

    if(res!=NULL)
    {
        list<int>::iterator it;
        int patternlength = pattern.length();
        for(it=res->begin();it!=res->end();it++)
        {
            (*index)++;
            locarray[(*index)] = *it-patternlength;
        }
    }
}

int main()
{
    string mainstring;
    string pattern;
    cin>>mainstring;
    cin>>pattern;
    int locarray[mainstring.size()];
    int index=-1;
    trie newtrie(mainstring);
    newtrie.searchpat(pattern,locarray,&index);

    for(int i=0;i<=index;i++)
    {
        printf("found at %d,",locarray[i]);
    }
}
