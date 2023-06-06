#include<iostream>
#include<stack>
using namespace std;
struct node{
    char data;
    node* left,*right;
};
class ExpTree
{

    public:
    node* expTree(char exp[],int len);
    void Delete(node* root);
    void postfix(node* root);

};

node* ExpTree::expTree(char exp[],int len)
    {
        stack<node*> s1;
        int i =len;
        while(i>=0)
        {
            node* nnode = new node;
            nnode->data=exp[i];
            nnode->left=nnode->right=NULL;
            if(exp[i]>=97 && exp[i]<122)
            {
                s1.push(nnode);
            }
            else{
                if(!s1.empty())
                {
                    nnode->left=s1.top();
                    s1.pop();
                    nnode->right=s1.top();
                    s1.pop();
                    s1.push(nnode);
                }
            }
            i--;
        }
        node* temp=s1.top();
        s1.pop();
        return temp;
    }

void ExpTree :: Delete(node* root)
{
    if(root!=NULL)
    {
        Delete(root->left);
        Delete(root->right);
        cout<<root->data<<"\t";
        delete root;
    }
}

void ExpTree:: postfix(node* root)
{
    stack<node*>s1,s2;
    node* temp=root;
    if(root!=NULL)
    {
        s1.push(temp);
        while(!s1.empty())
        {
            node* current =s1.top();
            s1.pop();
            s2.push(current);
            if(current->left!=NULL)
            {
                s1.push(current->left);
            }
            if(current->right!=NULL)
            {
                s1.push(current->right);
            }
        }
        cout<<"Poster order : ";
        while(!s2.empty())
        {
            cout<<s2.top()->data<<"\t";
            s2.pop();
        }
    }
    cout<<"\nDeleted : ";
    Delete(root);
}

int main()
{
    int i=0;
    node* root;
    ExpTree t;
    char exp[10];
    cout<<"Enter expression : ";
    cin>>exp;
    while(exp[i]!='\0')
        i++;
    cout<<i;
    root=t.expTree(exp,i);
    t.postfix(root);
    return 0;
}