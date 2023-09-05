#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        int _min =a[i];
        for(int j=i;j<n;j++)
        {
            if(a[j]<_min)
            _min=a[j];
        }
        for(int j=i;j<n;j++)
        {
            if(a[j]==_min)
            {
                int tmp;
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}
