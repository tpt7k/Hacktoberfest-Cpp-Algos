//recursive call of p i..j

#include<bits/stdc++.h>
using namespace std;
void parent(int n,vector<vector<int>> p,int i,int j){
    if(p[i][j]+1!=0){
        parent(n,p,i,p[i][j]);
        cout<<p[i][j]+1<<" ";
        parent(n,p,p[i][j],j);
        return;
    }
    else return;
}

void shortPath(){
    int n;
    cout<<"Nodes: ";
    cin>>n;
    int d[n][n];
    //taking input
    cout<<"Enter edge weight (if not, input 0) "<<endl;
    vector<vector<int>> p;
    for(int i=0;i<n;i++){
        vector<int> t;
        for(int j=0;j<n;j++){
            if(i==j){
                d[i][j]=0;
            }

            else{
                int temp;
                cout<<"From edge i["<<i+1<<"] to j["<<j+1<<"]: ";
                cin>>temp;
                if(temp!=0) d[i][j]=temp;
                else d[i][j]=INT_MAX;
            }
            t.push_back(-1);
        }
        p.push_back(t);
    }

    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][j]>(d[i][k] + d[k][j]) &&(d[k][j]!=INT_MAX && d[i][k]!=INT_MAX)){
                     d[i][j]=d[i][k]+d[k][j];
                     p[i][j]=k;
                 }
            }
        }
    }

    // shortest path
    cout<<"\nShortest Path :"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"\n"<<i+1<<" -> "<<j+1<<" is ";
            cout<<i+1<<" ";
            parent(n,p,i,j);
            cout<<j+1<<" ";
            cout<<"\n Weight: " <<d[i][j];
        }
        cout<<endl;
    }
}
int main(){
    shortPath();
    return 0;
}
