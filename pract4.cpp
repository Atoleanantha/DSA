#include<iostream>

using namespace std;

struct node
{
    int data;
    node *left, *right;
};

class BST
{
    int mirrorFlag;
    node* root;
    node* createNode(int data)
    {
        node *nnode = new node;
        nnode->left=nnode->right=NULL;
        nnode->data=data; 
        return nnode;
    }
    int height(node* root);
    void inorder(node* root);
    void mirror(node* root);
    public:
        BST()
        {
            root=new node;
            root=NULL;
            mirrorFlag=0;
        }
        void insert(int data);
        void search(int data);
        void Inorder()
        {
            node *temp=root;
            inorder(temp);
        }
        void Height();
        void Mirror();
        void minNode();
};

void BST :: insert(int data)
{
    if(root==NULL)
    {
        root=createNode(data);
    }
    else
    {
        node *temp=root;
        while(1)
        {
            if(temp->data>data)
            {
                if(temp->left==NULL)
                {
                    temp->left=createNode(data);
                    break;
                }
                else{
                    temp=temp->left;
                }
            }
            else
            {
                if(temp->right ==NULL)
                {
                    temp->right=createNode(data);
                    break;
                }
                else{
                    temp=temp->right;
                }
            }
        }
    }
}

void BST :: inorder(node* root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<root->data<<"\t";
            inorder(root->right);
        }
        
    }

 int BST :: height(node* root)
    {
        int h1,h2;
        if(root==NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 0;
        h1=height(root->left);
        h2=height(root->right);
        if(h1>h2)
            return h1+1;
        else
            return h2+1;
    }
 void BST :: Height()
 {
    node *temp=root;
    cout<<"Number of node in langest path : "<<height(temp)<<endl;
 }

void BST :: search(int data)
{
    node* temp=root;
    int flag=0;
    if(temp==NULL)
        cout<<"Null Tree"<<endl;
    else{
        while(1)
        {
            if(data<temp->data)
            {
                    if(data==temp->data)
                    {
                        flag=1;
                        cout<<"Node found!"<<endl;
                        break;
                    }
                    else{
                        if(temp->left==NULL)
                        {
                            break;
                        }
                        else
                            temp=temp->left;
                    }
            }
            else
            {
                if(data==temp->data)
                {
                    flag=1;
                    cout<<"Node found!"<<endl;
                    break;
                }
                else
                {
                    if(temp->right==NULL)
                    {
                        break;
                    }
                    else
                        temp=temp->right;
                }
            }
        }
        if(flag==0)
        {
            cout<<"Node not found!"<<endl;
        }
    }
}

void BST:: mirror(node* root)
    {
        node* temp;
        if(root!=NULL)
        {
            mirror(root->left);
            mirror(root->right);
            temp=root->left;
            root->left=root->right;
            root->right=temp;
        }
        if(mirrorFlag==0)
            mirrorFlag=1;
        else
            mirrorFlag=0;
    }
void BST :: Mirror()
{
    mirror(root);
}

void BST :: minNode()
{
    node* temp=root;
    if(temp == NULL)
        return;
    if(mirrorFlag==1)
    {
        while(temp->right!=NULL)
            temp=temp->right;
    }
    else{
        while(temp->left!=NULL)
            temp=temp->left;
    }
    
    cout<<"Minimum node : "<<temp->data;
}


int main()
{
    BST t;
    int ch;
    int n,data;
    do{
        cout<<"\n1)Insert \n2)Inorder \n3)No. of node in longest path \n4)Search \n5)Mirror \n6)Minimun node value \n0)exit "<<endl;
        cout<<"Enter choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                    cout<<"Enter number of nodes : ";
                    cin>>n;
                    cout<<"Enter data : "<<endl;
                    for(int i = 0; i<n;i++)
                    {
                        cin>>data;
                        t.insert(data);
                    }
                    break;
            case 2:
                    cout<<"Data : ";
                    t.Inorder();
                    break;
            case 3:
                    t.Height();
                    break;
            case 4:
                    cout<<"Enter data which you want to search : ";
                    cin>>data;
                    t.search(data);
                    break;
            case 5:
                    t.Mirror();
                    break;
            case 6:
                    t.minNode();
                    break;
            default:
                    if(ch==0)
                    {
                        cout<<"Successful Exit."<<endl;
                    }
                    else{cout<<"Invalid choice!!"<<endl;}
                    break;
        }
    }while(ch!=0);

}
