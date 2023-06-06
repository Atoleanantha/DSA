#include<iostream>
using namespace std;

struct node
{
    char name[10];
    node* child[10];
    int number;
};

class Lib
{
    node *root;
    int chapterNo,topicNo,subTopicNo;
    public :
        Lib()
        {
            root = new node;
        }
        void book();
        void display();
        
};

void Lib :: book()
{
    int i,j,k;
    cout<<"\nEnter name of book : ";
    cin>>root->name;
    cout<<"Enter number of chapter in "<<root->name <<" book : ";
    cin>>chapterNo;
    root->number;
    for(i = 0; i < chapterNo ; i++)
    {
        root->child[i] = new node;
        cout<<"Enter name of chapter " << i+1 <<" : ";
        cin>>root->child[i]->name;
        cout<<"Enter number of topic in " << root->child[i]->name <<" chapter : ";
        cin>>topicNo;
        root->child[i]->number=topicNo;
        for(j = 0 ; j < topicNo ; j++)
        {
            root->child[i]->child[j] = new node;
            cout<<"Enter name of Topic " << j+1 <<" : ";
            cin>>root->child[i]->child[j]->name;
            cout<<"Enter number of topic in " << root->child[i]->child[j]->name <<" chapter : ";
            cin>>subTopicNo;
            root->child[i]->child[j]->number=subTopicNo;
            for(k = 0 ; k < subTopicNo ; k++)
            {
                root->child[i]->child[j]->child[k] = new node;
                cout<<"Enter name of sub-topic " << k+1 <<" : ";
                cin>>root->child[i]->child[j]->child[k]->name;
            }
        }
    }
    
}
void Lib :: display()
{
    int i,j,k;
    cout<<"\nBook: "<<root->name;
            for(i=0;i<chapterNo;i++)
            {
                cout<<"\n\tChapter "<<i+1<<" : "<<root->child[i]->name;
                for(j=0;j<topicNo;j++)
                {
                    cout<<"\n\t\tSection "<<j+1<<" : "<<root->child[i]->child[j]->name; 
		    
                    for(k=0;k<subTopicNo;k++)
                    {
                    	cout<<"\n\t\tSub-Section "<<k+1<<" : "<<root->child[i]->child[j]->child[k]->name;  
                    } 
                }
            }
}
int main()
{
    Lib book1;
    book1.book();
    book1.display();
    return 0;
}