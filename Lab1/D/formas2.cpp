#include<bits/stdc++.h>
using namespace std;
typedef long long ull;
     
int main(void)
{
    int n;
    int formas=0;

    cin>>n;
    vector<ull> a(n);
    vector<ull> sumaAcum(n);
    vector<ull> dosKIndices(n, 0);
    vector<ull> suma2kfinal(n, 0);
    for(ull i=0; i < n ;i++){
        cin >> a[i];
        if(i == 0){
            sumaAcum[0] = a[0];
        }else{
            sumaAcum[i] = a[i] + sumaAcum[i-1];
        }
    }

    if (sumaAcum[n-1] % 3 == 0)
    {
        ull saco = sumaAcum[n-1] / 3;

        for (ull i = 0; i < n; i++)
        {
            if(sumaAcum[i] == 2*saco ){ // && i != n-1
                dosKIndices[i] = 1;
            }
        }

        for (size_t i = 0; i < n; i++)
        {
            cout<<dosKIndices[i]<<" ";
        }
        cout<<"\n";

        suma2kfinal[n-1] = dosKIndices[n-1];
        for (ull j = n-2; j >= 0; j--)
        {
            suma2kfinal[j] = dosKIndices[j] + suma2kfinal[j+1];
        }

        for (int i = 0; i < n; i++)
        {
            cout<<suma2kfinal[i]<<" ";
        }
        cout<<"\n";

        for (ull i = 0; i < n-2; i++)
        {
            if(sumaAcum[i] == saco){
                formas += suma2kfinal[i+i];
            }
        }
        
    }
    cout<<formas;
}