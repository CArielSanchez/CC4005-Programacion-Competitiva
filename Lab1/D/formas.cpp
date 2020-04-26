#include<bits/stdc++.h>
using namespace std;
     
     
int main(void)
{
    int n;
    int formas=0;

    cin>>n;
    vector<int> a(n);
    vector<int> sumaAcum(n);
    vector<int> dosKIndices;
    for(int i=0; i < n ;i++){
        cin >> a[i];
        if(i == 0){
            sumaAcum[0] = a[0];
        }else{
            //cout<<"a[i]: "<<a[i]<<" sumaAcum{i-1]: "<<sumaAcum[i-1]<<"\n";
            sumaAcum[i] = a[i] + sumaAcum[i-1];
        }
    }

    // for (size_t i = 0; i < n; i++)
    // {
    //     cout<<sumaAcum[i]<<" ";
    // }
    // cout<<"aa\n";

    if (sumaAcum[n-1] % 3 == 0)
    {
        int saco = sumaAcum[n-1] / 3;

        for (size_t i = 0; i < n; i++)
        {
            if(sumaAcum[i] == 2*saco && i != n-1){
                dosKIndices.push_back(i);
            }
        }

        // for (size_t i = 0; i < dosKIndices.size(); i++)
        // {
        //     cout<<dosKIndices[i]<<" ";
        // }
        // cout<<"\n";
        

        for (size_t i = 0; i < n; i++)
        {
            if(sumaAcum[i] == saco){
                for (size_t j = 0; j < dosKIndices.size(); j++)
                {
                    if( dosKIndices[j] > i){
                        formas++;
                    }
                }
                
            }
        }
    }
    cout<<formas;
}