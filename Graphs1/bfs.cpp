/*

				Name: Mehul Chaturvedi
				IIT-Guwahati

*/
/*
Given an undirected and connected graph G(V, E), print its BFS traversal.
Here you need to consider that you need to print BFS path starting from vertex 0 only.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Note : Take graph input in adjacency matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next 'E' lines, each have two space-separated integers, 'a' and 'b', denoting that there exists an edge between Vertex 'a' and Vertex 'b'.
Output Format :
BFS Traversal (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
*/

#include <iostream>
#include<queue>
using namespace std;


void printbfs(int **arr,int n,int st,bool *visited){
    visited[st]=true;
    queue <int> q;
    q.push(st);
    while(!q.empty()){
        int sv=q.front();
        q.pop();
        cout<<sv<<" ";
    for(int i=0;i<n;i++){
        if(i==sv)
            continue;
        if(arr[sv][i]==1 && visited[i]==false){
             q.push(i);
            visited[i]=true;
        }
    }
	}
}

int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int** arr=new int*[V];
    for(int i=0;i<V;i++){
        arr[i]=new int[V];
        for(int j=0;j<V;j++){
            arr[i][j]=0;
        }
    }
    //  int k,l;
    //     cin>>k>>l;
    //     arr[k][l]=1;
    //     arr[l][k]=1;
    // int a=k;

    for(int i=0;i<E;i++){
        int k,l;
        cin>>k>>l;
        arr[k][l]=1;
        arr[l][k]=1;
    }
    bool* visited=new bool[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            printbfs(arr,V,i,visited);
        }
    }
    // cout<<0<<endl;
   
  return 0;
}
