#include<bits/stdc++.h>
using namespace std;
string GetHTMLLabel(string s){
    string lb;
    for(int i=0;s[i]!=' ';i++){
        if(s[i]=='<'){
            continue;
        }
        lb.push_back(s[i]);
    }
    //cout<<lb<<' ';
    return lb;
}
string GetHTMLflag(string s,string flag){
    string lb;
    int i,j=0;
    while(s[i]!='>'){
        for(i=0;s[i]!=' ';i++);
        i++;
        for(;s[i]!='=';i++){
            lb.push_back(s[i]);
        }
        if(flag==lb){
            string nr;
            i+=2;
            for(;s[i]!='"';i++){
                nr.push_back(s[i]);
            }
            return nr;
        }
    }
    return "error";
}
string html_to_wd(string s){
    string tmp="";
    bool f=0,one_f=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='<'&&s[i+1]!='/'){
            f=1;//start
        }else if(s[i]=='>'&&s[i-1]=='/'){
            tmp.push_back(s[i]);
            f=0;//end
            //cout<<tmp<<' '<<f<<' ';
            i++;
            tmp="";
        }else if(s[i]=='>'&&!one_f){
            one_f=1;
        }else if(s[i]=='>'&&one_f){
            tmp.push_back(s[i]);
            one_f=0;
            f=0;//end
            //cout<<tmp<<' '<<f<<' ';
            cout<<GetHTMLflag(tmp,"href")<<endl;
            i++;
            tmp="";
        }
        if(f){
            tmp.push_back(s[i]);
        }
    }
    return "";
}
int main(int argc,char** argv){
    //ifstream fin (argv[1]);
    string s;
    while(1/*getline(fin,s)*/){
        getline(cin,s);
        cout<<html_to_wd(s)<<endl;
    }
    return 0;
}
/*
<a href="https://netboard.wikidot.com/">奈版</a>
*/
