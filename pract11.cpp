#include<iostream>
#include<fstream>
using namespace std;
class Data
{
    
    char Name[10],Division;
    public:
    int Roll;
    void getData()
    {
        cout<<"Enter Roll number : ";
        cin>>Roll;
        cout<<"Enter name : ";
        cin>>Name;
        cout<<"Enter division : ";
        cin>>Division;

    }
    void putData()
    {
        cout<<Roll<<"\t";
        cout<<Name<<"\t";
        cout<<Division;
    }
};
int main()
{
    Data d;
    int ch;
    do{
        cout<<"\n1)Write data \n2)Read data \n3)Add data \n4)Search data \n0)Exit";
        cout<<"\nEnter Choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1: {fstream fout;
                    int n;
                    fout.open("data.txt",ios::out);
                    cout<<"Enter number of student : ";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        d.getData();
                        fout.write((char *)&d,sizeof(d));   
                    }
                    fout.close();
                    break;}
            case 2: {
                    fstream fin;
                    fin.open("data.txt",ios::in);
                    Data d1;
                    cout<<"\nRoll \t Name \t Division\n";
                    while(fin.read((char *) &d1 , sizeof(d1)))
                    {
                        d1.putData();
                        cout<<endl;
                    }
                    fin.close();
                    break;}
            case 3:{
                    fstream fout;
                    fout.open("data.txt",ios::app);
                    int n;
                    cout<<"Enter number of student : ";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        d.getData();
                        fout.write((char *)&d,sizeof(d));   
                    }
                    fout.close();
                    break;
                    }
            case 4 :
                    {
                        fstream fin;
                        fin.open("data.txt",ios::in);
                        int roll,flag=0;
                        cout<<"\nEnter roll number : ";
                        cin>>roll;
                        cout<<"\nRoll \t Name \t Division\n";
                        while(fin.read((char *)&d,sizeof(d)))
                        {
                            if(roll==d.Roll)
                            {
                                cout<<"\nData found !!"<<endl;
                                flag=1;
                                d.putData();
                            }
                        }
                        if(flag==0)
                        {
                            cout<<"Record not fount!"<<endl;
                        }
                        fin.close();
                        break;
                    }
            case 5:
                    {
                        fstream fin,fout;
                        fin.open("data.txt",ios::in);
                        fout.open("dataCopy.txt",ios::out);
                        int roll,flag=0;
                        cout<<"\nEnter roll number : ";
                        cin>>roll;
                        cout<<"\nRoll \t Name \t Division\n";
                        while(fin.read((char *)&d,sizeof(d)))
                        {
                            if(roll==d.Roll)
                            {
                                cout<<"\nData Deleted !!"<<endl;
                                flag=1;
                                d.putData();
                            }
                            else{
                                fout.write((char *)&d,sizeof(d));
                            }
                        }
                        if(flag==0)
                        {
                            cout<<"Record not fount!"<<endl;
                        }
                        fin.close();
                        remove("data.txt");
                        rename("data.txt","dataCopy.txt");
                        fout.close();
                        break;
                    }
            default: if(ch==0){cout<<"Exit successfully! ";}
                        else{
                            cout<<"Inalid choice !!";
                        }
        }
    }while(ch!=0);
}