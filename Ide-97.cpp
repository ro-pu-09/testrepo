#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
vector <bool> visited;
stack <int> st;
void explore(vector<int> adj[],int x)
{
               visited[x]=true;
               for (int i=0;i<adj[x].size();i++)
               {
                              int l=adj[x][i];
                              if(visited[l]==false)explore(adj,l);
               }
               st.push(x);
}
void explorerev(vector<int> adj[],int x)
{
               visited[x]=true;
               //cout<<x<<"-->"<<adj[x].size()<<endl;
               for (int i=0;i<adj[x].size();i++)
               {
                              int l=adj[x][i];
                              
                              if(visited[l]==false)explorerev(adj,l);
               }
              // st.push(x);
}

int main() {
               int v,e;
               cin>>v>>e;
               vector<int> adj[v+1];
               vector<int> adjrev[v+1];
               visited.resize(v+1);
               for (int i=0;i<e;i++)
               {
                              int m,n;
                              cin>>m>>n;
                              adj[m].push_back(n);
                              visited[m]=false;
                              visited[n]=false;
               }
               for (int i=1;i<=v;i++)
               {       //cout<<i<<endl;
                    if(!visited[i])   explore(adj,i);       
               }
               for (int i=1;i<=v;i++)
               {
                              visited[i]=false;
               }
               for(int i=1;i<=v;i++)
               {
                              for (int j=0;j<adj[i].size();j++)
                              {
                                             int l=adj[i][j];
                                             adjrev[l].push_back(i);
                              }
               }
               int count=0;
               
	while(st.size()!=0)
	{
	              int l=st.top();
	              //cout<<l<<endl;
	              st.pop();
	              if(visited[l]==false)count++;
	              explorerev(adjrev,l);
	}
	cout<<count<<endl;
	return 0;
}
