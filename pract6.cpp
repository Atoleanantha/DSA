#include<iostream>
#include<queue>
using namespace std;

class Graph
{
    int G[10][10];
    char cities[10];
    int visited[10];
    int num;
    public:
        Graph()
        {
            num=0;
            for(int i=0;i<10;i++)
            {
                
                for(int j=0;j<10;j++)
                {
                    G[i][j]=0;
                    visited[i]=0;
                }
            }
        } 
        void createGraph();
        void BFS();
        void display();
        void BFS(char start, char destination);
};

void Graph :: createGraph()
{
    char source,destination,ch;
    int fuel;
    cout<<"\nEnter number of cities : ";
    cin>>num;
    cout<<"Enter List of cities : ";
    for(int i=0;i<num;i++)
    {
        cin>>cities[i];
    }

    do{
        int s=0,d=0,flag1=0,flag2=0;
        cout<<"Enter source city : ";
        cin>>source;
        cout<<"Enter destination city : ";
        cin>>destination;
        cout<<"Enter fuel : ";
        cin>>fuel;
        while(s<num)
        {
            if(source==cities[s])
            {
                flag1=1;
                break;
            }
            s++;
        }
        while(d<num)
        {
            if(destination==cities[d])
            {
                flag2=1;
                break;
            }
            d++;
        }
        if(flag1==1 && flag2==1)
        {
            G[s][d]=G[d][s]=fuel;
        }
        else{
            cout<<"Source or destination city not correct."<<endl;
        }
        cout<<"Do you want to add more routes y/n : ";
        cin>>ch;

    }while(ch=='y');
    
}
void Graph ::BFS(char start, char destination)
    {
        for(int i=0; i<num; i++){
            visited[i] = 0;
        }
        queue<int> q;
        int start_idx = -1;
        for(int i=0; i<num; i++){
            if(cities[i] == start){
                start_idx = i;
                break;
            }
        }
        q.push(start_idx);
        visited[start_idx] = 1;

        while(!q.empty()){
            int current = q.front();
            q.pop();
            cout << cities[current] << " -> ";
            if(cities[current] == destination){
                return;
            }
            for(int i=0; i<num; i++){
                if(G[current][i] != 0 && visited[i] == 0){
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
    }
void Graph:: BFS()
{
    queue<int>q1;
    int flag1=0;
    int s;
    char source,current,destination;
    cout<<"Enter source city : ";
    cin>>source;
    cout<<"Enter destination city : ";
    cin>>destination;
    while(s<num)
    {
        if(source==cities[s])
        {
            flag1=1;
            break;
        }
        s++;
    }

        q1.push(s);
        visited[s]=1;
        while(!q1.empty())
        {
            current=q1.front();
            q1.pop();
            cout<<cities[current]<<",";
            if(cities[current]==destination)
                return;
            for(int i = 0 ; i < num ; i++)
            {
                if(G[current][i]!=0 && visited[i]==0)
                {
                    q1.push(i);
                    visited[i]=1;
                }
            }

        }
    

}


void Graph :: display()
{
    int i,j;
    cout<<"cities\t";

    for(i=0;i<num;i++)
    {
        cout<<cities[i]<<"\t";
    }
    cout<<endl;
    
    for(i=0;i<num;i++)
    {
        cout<<cities[i]<<"\t";
        for(j=0;j<num;j++)
        {
            cout<<G[i][j]<<"\t";;
        }
        cout<<endl;
    }
}
int main()
{
    Graph g;
    g.createGraph();
    g.display();
    cout<<"BFS : "<<endl;
    g.BFS('a','c');
    return 0;
}