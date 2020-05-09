#include <bits/stdc++.h>
using namespace std;
void sswap ( int *x, int *y )
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

int main(){
	int n;
	cin >> n;
	int l1[n];
    int l2[n];
    int sum=0;

    char * s1 = new char[n];
    cin>>s1;
    
    char* s2 = new char[n];
    cin>>s2;

    for (int i = 0; i < n; i++)
    {
        l1[i] = s1[i] - '0';
    }
    
    for (int i = 0; i < n; i++)
    {
        l2[i] = s2[i] - '0';
    }


    int swap;
    for (int i = 0; i < n; ++i)
    {
        if( l1[i] != l2[i] ){
            // [i][1]!=[i+1][1] and [i][1]=[i+1][2]
            
            if(((i+1)!=n) && (l1[i] != l1[i+1]) && (l1[i]==l2[i+1]) ){
                sum+=1;//swap
                sswap(&l1[i],&l1[i+1]);
            }

            else{
                sum +=1;
            }                                  
        }	
        else{
            ;
        }

    }

    
    cout<<sum;
    return 0;

}

