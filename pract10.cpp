#include<iostream>
using namespace std;
class HeapSort
{
    public:
    void heapSort(int marks[],int n);
    void heapify(int marks[],int n, int i);

};

void HeapSort :: heapSort(int marks[],int n)
{
    int temp;
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(marks,n,i);
    }
    //delete heap
    for(int i=n-1;i>=0;i--)
    {
        temp=marks[i];
        marks[i]=marks[0];
        marks[0]=temp;
        heapify(marks,i,0);    
    }
    
}

void HeapSort :: heapify(int marks[],int n, int i)
{
    int largest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;
    if(left < n && marks[left]>marks[largest])
        largest=left;
    if(right<n && marks[right]>marks[largest])
        largest=right;
    if(largest != i)
    {
        int temp=marks[i];
        marks[i]=marks[largest];
        marks[largest]=temp;
        heapify(marks,n,largest);
    }
}
int main()
{
    HeapSort h;
    int marks[10];
    int n;
    cout<<"\nEnter number of studdents : ";
    cin>>n;
    cout<<"\nEnter marks : ";
    for(int i =0 ;i<n ; i++)
    {
        cin>>marks[i];
    }
    h.heapSort(marks,n);
    cout<<"\nMarks : ";
    for(int i =0 ;i<n ; i++)
    {
        cout<<marks[i]<<"\t";
    }
    return 0;
}