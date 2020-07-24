#include <bits/stdc++.h>
using namespace std;

int main(){
  	
    int t; // n test
    cin>>t;
    for (int z = 0; z < t; z++)
    {
    	int na,np;
    	cin>>na>>np;
    	int a[na];
	    int ap[na];//guarda la posicion de los p, para intercambio
		for (int i = 0; i < na; i++)
		{
			a[i] = 0;
			ap[i] = 0;
		}

    	for (int i = 0; i < na; i++)
    	{
    		cin>>a[i];
    	}
	    for (int i = 0; i < np; i++)
    	{
  			int pi;
    		cin>>pi;
    		ap[pi]=1;
    	}
		
    	for (int i = 0; i < na; i++)
    	{
    		for (int j = 0; j < na-1; j++)
    		{
    			if (a[j]>a[j+1] && ap[j+1]==1 )
    			{
    				swap(a[j],a[j+1]);
    			}
    		}	
    	}
		// for (int i = 0; i < na; i++)
		// {
		// 	cout<<a[i]<<" ";
		// }
		bool order = true;
		for (int i = 0; i < na-1; i++)
		{
			if(a[i]>a[i+1] ){
				order = false;
				cout<<"NO\n";
				break;
			}
		}
		if(order){
			cout<<"YES\n";
		}	

    }
     return 0;
    }