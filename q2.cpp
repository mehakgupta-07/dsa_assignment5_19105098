// 2) Wrire a separate function to implement Breadth First Search
// 19105098

#include <iostream>
#include<queue>
#include<algorithm>
using namespace std;


void printBFS(int**arr, int v , bool*visited , queue<int>*q)
{
    if(q->empty())
    {
        return ;
    }
    
    int ans=q->front();
    
    q->pop();
    cout<<ans<<" ";
    
    
    
    for(int i=0 ;i<v ; i++)
    {
        if(visited[i]==true)
        {
            continue;
        }
        
        if(arr[ans][i]==1)
        {
            q->push(i);
            visited[i]=true;
        }
        
    }
    printBFS(arr , v ,visited , q);
    
}


int main() {
    int V, E;
    cin >> V >> E;

    int **arr= new int *[V];
    for(int i=0 ; i<V ; i++)
    {
        arr[i]=new int [V];
        for(int j=0 ;j<V ; j++)
        {
            arr[i][j]=0;
        }
    }
    
    for(int i=0 ; i<E ; i++)
    {
        int a , b;
        cin>>a>>b;
     
        arr[a][b]=1;
        arr[b][a]=1;
    }
    
    bool *visited=new bool[V];
    for(int i=0 ; i<V ; i++)
    {
        visited[i]=false;
    }
    queue<int>*q=new queue<int>;
    int i=0;
    while(i!=V)
    {
        if(visited[i]==false)
        {
            q->push(i);
    visited[i]=true;
            printBFS(arr , V  , visited ,q );
        }
         
        i++;
    
    }    

  return 0;
}