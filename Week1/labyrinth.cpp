#define push_back pb 
#include<iostream>
#include<vector>
#include<string>
using namespace std;
string find(int i1,int j1,int i2,int j2,int n,int m,int y,bool& uni,int x,string s){
    
}
bool ans(vector<vector<bool>>& need,int n,int m,int i1,int j1,int i2,int j2,vector<char>& p,int& x,bool& uni){
     int y=0;
     string s,s1,s2,s3,s4;
     if(i1-1==i2 && j1==j2){
        x=1;
        return true;}
     if(i1+1==i2 && j1==j2){
        x=1;
        return true;
     }
     if(i1==i2 && j1-1==j2){
        x=1;
        return true;
     }
     if(i1==i2 && j1+1==j2){
        x=1;
        return true;
     }
     if(i1<n-1 && need[i1+1][j1]) s1=find(i1+1,j1,i1,j2,n,m,y+1,uni,x,s+'D');
     if(i1>0 && need[i1-1][j1]) s2=find(i1-1,j1,i1,j2,n,m,y+1,uni,x,s+'U');
     if(j1<m-1 && need[i1][j1+1]) s3=find(i1,j1+1,i1,j2,n,m,y+1,uni,x,s+'R');
     if(j1>0 && need[i1][j1-1]) s4=find(i1,j1-1,i1,j2,n,m,y+1,uni,x,s+'L');
     return uni;
}
int main(){
    int n,m,i1=0,i2=0,j1=0,j2=0;
    cin>>n>>m;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<bool>>need(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#')need[i].pb(false);
            else if(s[i][j]=='.')need[i].pb(true);
            else if(s[i][j]=='A'){
                i1=i;
                j1=j;
            }
            else{
                i2=i;
                j2=j;
            }
        }
    }
    vector<char>p;
    int x=0;
    bool uni=false;
    bool f=ans(need,n,m,i1,j1,i2,j2,p,x,uni);
    if(f){
        cout<<"YES"<<endl;
        cout<<x<<endl;
    }
    else{cout<<"NO"<<endl;}
}