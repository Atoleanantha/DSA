#include<iostream>
#include<queue>
using namespace std;

class obst
{
    string k[10];
    float P[10];
    float Q[11];
    int W[10][10];
    int C[10][10];
    int R[10][10];
    int Nk;
    public:
        void getData()
        {
            cout<<"\nNumber of Keys : ";
            cin>>Nk;
            for(int i=0;i<Nk;i++)
            {
                cin>>k[i];
            }
            cout<<"\nEnter successful probability : ";
            for(int i=1;i<=Nk;i++)
            {
                cin>>P[i];
            }
            cout<<"\nEnter unsuccessful probability : ";
            for(int i=0;i<=Nk;i++)
            {
                cin>>Q[i];
            }
            for(int i = 0 ;i<=Nk;i++)
            {
                W[i][i]=Q[i];
                C[i][i]=0;
                R[i][i]=0;
                if(i+1<=Nk)
                {
                    W[i][i+1]=P[i+1]+Q[i+1]+W[i][i];
                    C[i][i+1]=W[i][i+1];
                    R[i][i+1]=i+1;
                }
            }
            for(int d = 2 ;d<=Nk ; d++)
            {
                
                for(int i = 0; i<=Nk ; i++)
                {
                    int j= i+d;
                    W[i][j]=P[j]+Q[j]+W[i][j-1];
                    C[i][j]=99999;
                    for(int k=i+1;k<=j;k++)
                    {
                        int cost = C[i][k-1]+C[k][j];
                        if(cost<C[i][j])
                        {
                            C[i][j]=cost;
                            R[i][j]=k;
                        }
                    }
                    C[i][j]=C[i][j]+W[i][j];
			
			        cout<<"\nCost and root for diff "<<d<<"="<<C[i][j]<<"\t"<<R[i][j];
                }
            }
        }
}