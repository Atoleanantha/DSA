#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;

struct node{
    string name;
    node *next;
};

class graph
{
    node* head[10];
    int n;
    public:
    graph()
    {
        // head=new node;
        for(int i=0;i<10;i++)
        {
            head[i]=NULL;
        }
    }
    int findINdex(string name)
    {
        int i;
        for(i=0;i<n;i++)
        {
            if(head[i]->name==name)
            {
                break;
            }
        }
        return i;
    }
    void createGraph();
    void BFS();
    void DFS();
    
};

void graph:: createGraph()
    {
        node* temp=NULL;
        cout<<"Enter number of dept : ";
        int adj;
        cin>>n;
        
        for(int i=0 ;i<n;i++)
        {
            node* nnode =new node;
            nnode->next=NULL;
            cout<<"Enter Name of root depts : ";
            cin>>nnode->name;
            head[i]=nnode;
            cout<<"Number of adjcent depts of "<<nnode->name <<" : ";
            cin>>adj;
            temp=head[i];
            for(int j=0;j<adj;j++)
            {
                node* adjNode = new node;
                adjNode->next=NULL;
                cout<<"Enter name of adjcent dept of "<<" : ";
                cin>>adjNode->name;
                temp->next=adjNode;
                temp=adjNode;
            }
        }
    }

void graph :: BFS()
{
    queue<string>q1;
    string current;
    bool visited[10];
    for(int i=0;i<10;i++)
    {
        visited[i]=false;
    }
    //strting vertex
    int i;
    node * temp=head[0];
    q1.push(temp->name);
    visited[0]=true;
    while(!q1.empty())
    {
        current=q1.front();
        cout<<current<<"\t";
        q1.pop();
        i=findINdex(current);
        temp=head[i];
        while(temp!=NULL)
        {
            i=findINdex(temp->name);
            if(visited[i]==false)
            {
                q1.push(temp->name);
                visited[i]=true;
            }
            temp=temp->next;
        }
    }

}

void graph :: DFS()
{
    int i;
    stack<string>s1;
    string current;
    bool visited[10];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    node *temp=head[0];
    s1.push(temp->name);
    cout<<temp->name<<"\t";
    visited[0]=true;
    while(temp!=NULL)
    {
            i=findINdex(temp->name);
            if(head[i]==false)
            {
                s1.push(temp->name);
                cout<<temp->name<<"\t";
                visited[i]=true;
                temp=head[i];
            }
            temp=temp->next;
    }
    while(!s1.empty())
    {
        current=s1.top();
        s1.pop();
        i=findINdex(current);
        temp=head[i];
        while(temp!=NULL)
        {
            i=findINdex(temp->name);
            if(visited[i]==false)
            {
                s1.push(temp->name);
                cout<<temp->name<<"\t";
                visited[i]=true;
            }
            temp=temp->next;
        }
    }
}

int main()
{
    graph g;
    g.createGraph();
    cout<<"\nBFS : ";
    g.BFS();
    cout<<"\nDFS : ";
    g.DFS();
    
    return 0;
}