#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"container size : ";
    cin>>n;
    int ar[n+1];
    int i;
    for(i=0;i<n;i++) cin>>ar[i];
    cout<<"Enter the search item : ";
    int find;
    cin>>find;
    for(i=0;i<n;i++)
    {
        if(ar[i]==find){ cout<<endl<<"found";return 0;}
    }
    cout<<"Not found"<<endl;
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int bs(int ar[],int l,int r,int item)
{
    while(l<=r){
    int mid=l+((r-l)/2);
    if(ar[mid]==item) return mid;
    if(ar[mid]<item) l=mid+1;
    else r=mid-1;
    }
    return -4;
}
int main()
{
    int n;
    cout<<"container size : ";
    cin>>n;
    int ar[n+1];
    int i;
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar,ar+n);
    int find;
    cout<<"search item : ";
    cin>>find;
    int check=bs(ar,0,n-1,find);
    if(check==-4) cout<<"not found";
    else cout<<"found";
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"container size : ";
    cin>>n;
    int ar[n+1];
    int i,j;
    for(i=0;i<n;i++) cin>>ar[i];
    int mnindx;
    for(i=0;i<n-1;i++)
    {
        mnindx=i;
        for(j=i+1;j<n;j++)
        {
            if(ar[j]<ar[mnindx]) mnindx=j;
        }
        swap(ar[mnindx],ar[i]);
    }
    for(i=0;i<n;i++) cout<<ar[i]<<" ";
    cout<<endl;
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"container size : ";
    cin>>n;
    int ar[n+1];
    int i,j;
    for(i=0;i<n;i++) cin>>ar[i];
    int key;
    for(i=1;i<n;i++)
    {
        key=ar[i];
        j=i-1;
        while(j>=0 && ar[j]>key)
        {
            ar[j+1]=ar[j];
            j--;
        }
        ar[j+1]=key;
    }
    for(i=0;i<n;i++) cout<<ar[i]<<" ";
    return 0;
}