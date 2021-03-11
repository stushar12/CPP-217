#include <bits/stdc++.h>
using namespace std;

int main()
{
   int street_lights,ps_house;
    cin>>street_lights>>ps_house;

    int position,power;
    int arr[ps_house+1];

    fill(arr,arr+ps_house+1,0);

    for(int i=0;i<street_lights;i++)
    {
        cin>>position>>power;

        if(position-power>=0)
        arr[position-power]++;

        else
        arr[0]++;


        if(position+power+1<=ps_house)
        arr[position+power+1]--;

    }


    int count=0,maxcount=0;
    
    for(int i=1;i<=ps_house;i++)
    {
        arr[i]+=arr[i-1];
    }

    for(int i=0;i<=ps_house;i++)
    {
        if(arr[i]!=1)
        count++;

        else
        {
            maxcount=max(maxcount,count);
            count=0;
        }
    }

    cout<<max(maxcount,count);

}
