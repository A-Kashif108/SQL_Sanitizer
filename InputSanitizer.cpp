#include <bits/stdc++.h>
using namespace std;


bool isSanitized(string value){
    vector<string> a = {"\'", "\"","%," , "#",  ";", ")", "{" ,"}", "[", "]",
    "(", "=","+", " ","SELECT","WHERE", "DROP","AND","UNION","--","\\n","\\t"  };
    for(string x:a) {
        for (int i = 0; i < value.size(); i++)
        {
            if(value.size() -i<x.size()){
                break;
            }
            string sub = value.substr(i,x.size());
            if(sub==x){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    string username;
    string pass;
    cin>>username>>pass;
    bool unSan = isSanitized(username);
    bool passSan = isSanitized(pass);
    if(unSan&&passSan){
        cout<<"Both Username and Password is valid"<<endl;
    }else if(!unSan&&passSan){
        cout<<"Username is invalid please enter valid username"<<endl;
    }else if(unSan&&!passSan){
        cout<<"password is invalid please enter valid password"<<endl;
    }else{
        cout<<"Both Username and Password is invalid please valid username and password"<<endl;
    }
    return 0;
}
