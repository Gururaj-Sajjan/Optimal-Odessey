#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
void visit(int b,vector<vector<int>>& roads,vector<bool>& tf){
    if(tf[b]) return;
    tf[b]=true;
    for(int i=0;i<roads[b].size();i++){
        visit(roads[b][i],roads,tf);
    }
    return;
}
void find(vector<vector<int>>& roads,vector<bool>& tf){
    for(int j=0;j<roads[1].size();j++){
        visit(roads[1][j],roads,tf);
    }
    return;
}
void change(vector<vector<int>>& roads, vector<pair<int,int>>& nroads,vector<bool>& tf){
    for(int i=2;i<tf.size();i++){
        if(tf[i]) continue;
        roads[1].push_back(i);
	    roads[i].push_back(1);
        nroads.push_back({1,i});
        visit(i,roads,tf);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    int a,b;
    vector<pair<int,int>>nroads;
    vector<vector<int>>roads(n+1);
    vector<bool>tf(n+1);
    tf[0]=false;
    tf[1]=true;
    for(int i=0;i<n+1;i++){
	    tf[i]=false;
	}
    for(int i=0;i<m;i++){
        cin>>a>>b;
        roads[a].push_back(b);
        roads[b].push_back(a);
    }
    find(roads,tf);
    change(roads,nroads,tf);
    cout<<nroads.size()<<endl;
    for(int i=0;i<nroads.size();i++){
        cout<<nroads[i].first<<" "<<nroads[i].second<<endl;
    }
}