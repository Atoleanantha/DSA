#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct node
{
    int key;
    char value[10];
    int chain;
};

class hasttable
{
    node hash_arr[max];
    public :
        hasttable()
        {
            for(int i = 0 ; i < max ; i++)
            {
                hash_arr[i].key = -1;
                hash_arr[i].chain = -1;
                strcpy(hash_arr[i].value , "NULL");
            }
        }

        inline int hash_Address(int key)
        {
            return key%max;
        }
        void insert(int key, char value[]);
        void Search(int key);
        void display();
};

void hasttable :: insert(int key, char value[])
{
    int address = hash_Address(key);
    int hk;
    if(hash_arr[address].key == -1)
    {
        hash_arr[address].key = key;
        strcpy(hash_arr[address].value,value);
    }
    else{
        hk = address;
        int temp=address,i=address;
        while(i<max)
        {
            if((hash_arr[i].key)%max == key%max)
            {
                temp = i;
            }
            hk=(i+1)%max;
            i++;
        }
        for(i = 0 ; i < max ; i++)
        {
            hk=(address+i)%max;
            if(hash_arr[hk].key == -1)
            {
                hash_arr[hk].key=key;
                strcpy(hash_arr[hk].value ,value);
                hash_arr[temp].chain = hk;
                break;
            }
        }
    }
}

void hasttable :: Search(int key)
{
    int address = hash_Address(key);
    int hk=address;
    int flag = 0;
    int it=1;
    for(int i = 0; i < max ; i++)
    {
        hk = (address + i )%max;
        if(address == hash_arr[hk].key % max)
        {
            if(hash_arr[hk].key == key)
            {
                cout<<"Record found !"<<endl;
                cout<<"\nNumber of itteration : "<<it<<endl;
                cout<<"Key : "<<hash_arr[address].key<<endl;
                cout<<"Value : "<<hash_arr[address].value<<endl;
                flag = 1;
                break;
            }
            it++;
            if(hash_arr[hk].chain != -1)
                hk = hash_arr[hk].chain;
        }
    }
    if(flag == 0)
        cout<<"Record not found."<<endl;
}
    
void hasttable :: display()
{
    cout<<"-------------------------------------------------------------------";
    cout<<"\n|\tIndex \t|\t Name \t|\t Telephone \t|\tChain \t|"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    for(int i=0; i < max ; i++)
    {
        cout<<"|\t"<<i<<"\t|\t"<<hash_arr[i].key<<"\t|\t"<<hash_arr[i].value<<"\t|\t"<<hash_arr[i].chain<<"\t|"<<endl;
    }
    cout<<"-------------------------------------------------------------------"<<endl;
}

int main()
{
    hasttable linear;
    int ch,n;
    int key;
    char value[10];
    do{
        cout<<"\n1) Insert \n2) Display Table \n3) Search \n0) Exit"<<endl;
        cout<<"\nEnter choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter Number of record: ";
                    cin>>n;
                    for(int i =0; i<n ; i++)
                    {
                        cout<<"\nEnter Key: ";
                        cin>>key;
                        cout<<"\nEnter Value : ";
                        cin>>value;
                        linear.insert(key,value);
                
                    }
                    break;
            case 2:
                    cout<<"\nLinear Table: "<<endl;
                    linear.display();
                    
                    break;
            case 3:
                    cout<<"Enter Key : ";
                    cin>>key;
                    linear.Search(key);
                    
                    break;
            default:
                    if(ch==0){cout<<"\nExit successfully."<<endl;}
                    else{cout<<"\nInvalid choice!!"<<endl;}
        }
    }while(ch!=0);
    return 0;
}