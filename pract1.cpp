#include<iostream>
#include<cstring>
#define max 10
using namespace std;

struct record
{
    char name[10];
    long int telephone;
};
class dict
{
    record hash_arr[max];
    public:
        dict()
        {
            for(int i = 0 ; i<max ; i++)
            {
                hash_arr[i].telephone=0;
                strcpy(hash_arr[i].name,"none");
            }
        }
        void insert(char name[],long int tele);
        int hash_Address(char name[]);
        void quadratic_Insert(char name[],long int tele);
        void linear_Delete(char name[]);
        void quadratic_Delete(char name[]);
        void quadratic_Search(char name[]);
        void linear_Search(char name[]);
        void display();
};

int dict :: hash_Address(char name[])
{
    int address=0,i=0;
    while(name[i]!='\0')
    {
        address=(int)name[i]+address;
        i++;
    }
    address=address%max;
    return address;
}

void dict :: insert(char name[],long int tele)
{
    // cout<<"\nEnter name: ";
    // cin>>name;
    int address = hash_Address(name),flag=0;
    int i=address;
    for(int j=0;j<max;j++)
    {
         i=(i+j)%max;
        if(hash_arr[i].telephone == 0)
        {
            hash_arr[i].telephone=tele;
            strcpy(hash_arr[i].name,name);
            flag=1;
            break;
        }   
    }
    if(flag==0)
    {
        cout<<"\nSpace not available in linear table.";
    }
}

void dict:: quadratic_Insert(char name[],long int tele)
{
    int address = hash_Address(name),flag=0;
    int i=address;
    for(int j=0;j<max;j++)
    {
        i=(i+j*j)%max;
        if(hash_arr[i].telephone == 0)
        {
            hash_arr[i].telephone=tele;
            strcpy(hash_arr[i].name,name);
            flag=1;
            break;
        }
        
    }
    if(flag==0)
    {
        cout<<"\nSpace not available in quadratic table."<<endl;
    }

}

void dict::linear_Delete(char name[])
{
    int address = hash_Address(name);
    int flag=0, hk=address;
    for(int i = 0 ; i < max ; i++)
    {
        hk=(hk+i)%max;
        if(strcmp(hash_arr[hk].name,name)==0)
        {
            cout<<"\nDeleted record :"<<endl;
            cout<<"Name : "<<hash_arr[hk].name<<endl;
            cout<<"Telephone : "<<hash_arr[hk].telephone<<endl;
            hash_arr[hk].telephone=0;
            strcpy(hash_arr[hk].name,"none");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord not available.";
    }

}

void dict :: quadratic_Delete(char name[])
{
    int address = hash_Address(name);
    int flag=0, hk=address;
    for(int i = 0 ; i < max ; i++)
    {
        hk=(hk+i*i)%max;
        if(strcmp(hash_arr[hk].name,name)==0)
        {
            cout<<"\nDeleted record :"<<endl;
            cout<<"Name : "<<hash_arr[hk].name<<endl;
            cout<<"Telephone : "<<hash_arr[hk].telephone<<endl;
            hash_arr[hk].telephone=0;
            strcpy(hash_arr[hk].name,"none");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"\nRecord not available.";
    }

}

void dict :: linear_Search(char name[])
{
    int address = hash_Address(name);
    int flag=0, hk=address;
    for(int i = 0 ; i < max ; i++)
    {
        hk=(hk+i)%max;
        if(strcmp(hash_arr[hk].name,name)==0)
        {
            cout<<"In linear table Record found !!:"<<endl;
            cout<<"Name : "<<hash_arr[hk].name<<endl;
            cout<<"Telephone : "<<hash_arr[hk].telephone<<endl;
            cout<<"Number of itteration : " << i+1<<endl;
            flag=1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"In linear table Record not found !!"<<endl;
    }

}

void dict :: quadratic_Search(char name[])
{
    int address = hash_Address(name);
    int flag=0, hk=address;
    for(int i = 0 ; i < max ; i++)
    {
        hk=(hk+i*i)%max;
        if(strcmp(hash_arr[hk].name,name)==0)
        {
            cout<<"In quadratic table Record found !!:"<<endl;
            cout<<"Name : "<<hash_arr[hk].name<<endl;
            cout<<"Telephone : "<<hash_arr[hk].telephone<<endl;
            cout<<"Number of itteration : " << i+1<<endl;
            flag=1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"In quadratic table Record not found !!"<<endl;
    }
}

void dict :: display()
{
    cout<<"---------------------------------------------------------";
    cout<<"\n|\tIndex \t|\t Name \t|\t Telephone \t|"<<endl;
    cout<<"---------------------------------------------------------"<<endl;
    for(int i=0; i < max ; i++)
    {
        cout<<"|\t"<<i<<"\t|\t"<<hash_arr[i].name<<"\t|\t"<<hash_arr[i].telephone<<"\t|"<<endl;
    }
    cout<<"---------------------------------------------------------"<<endl;
}

int main()
{
    dict linear,quadratic;
    int ch,n;
    long int tele;
    char name[10];
    do{
        cout<<"\n1) Insert \n2) Display Table \n3) Delete \n4) Search \n0) Exit"<<endl;
        cout<<"\nEnter choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter Number of record: ";
                    cin>>n;
                    for(int i =0; i<n ; i++)
                    {
                        cout<<"\nEnter Name: ";
                        cin>>name;
                        cout<<"\nEnter Telephone : ";
                        cin>>tele;
                        linear.insert(name,tele);
                        quadratic.quadratic_Insert(name,tele);
                    }
                    break;
            case 2:
                    cout<<"\nLinear Table: "<<endl;
                    linear.display();
                    cout<<"\nQuadratic Table: "<<endl;
                    quadratic.display();
                    break;
            case 3:
                    cout<<"Enter Name : ";
                    cin>>name;
                    linear.linear_Delete(name);
                    quadratic.quadratic_Delete(name);
                    break;
            case 4:
                    cout<<"Enter Name : ";
                    cin>>name;
                    linear.linear_Search(name);
                    quadratic.quadratic_Search(name);
                    break;
            default:
                    if(ch==0){cout<<"\nExit successfully."<<endl;}
                    else{cout<<"\nInvalid choice!!"<<endl;}
        }
    }while(ch!=0);
    return 0;
}