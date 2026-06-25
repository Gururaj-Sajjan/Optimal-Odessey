#include<iostream>
#include<vector>
#include<string>
using namespace std;
void com(vector<vector<bool>>& need,int n,int m,int i,int j){
    if(!need[i][j]) return;
    need[i][j]=false;
    if(j>0)com(need,n,m,i,j-1);
    if(i>0)com(need,n,m,i-1,j);
    if(i<n-1)com(need,n,m,i+1,j);
    if(j<m-1)com(need,n,m,i,j+1);
    return;
}
int count(vector<vector<bool>>& need, int n, int m){
    int c=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!need[i][j]) continue;
            need[i][j]=false;
            if(i<n-1)com(need,n,m,i+1,j);
            if(j<m-1)com(need,n,m,i,j+1);
            c++;
        }
    }
    return c;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<vector<bool>>need(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='#')need[i].push_back(false);
            else need[i].push_back(true);
        }
    }
    cout<<count(need,n,m)<<endl;
}
