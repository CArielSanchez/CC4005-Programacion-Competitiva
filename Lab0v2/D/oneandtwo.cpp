#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    cin>>cases;

    string sttr[cases];

    for (size_t i = 0; i < cases; i++)
    {
        cin>>sttr[i];
    }

    string substring = "";
    string s;
    vector<vector<int>> result;
    int j;

    for (size_t i = 0; i < cases; i++)
    {
        s = sttr[i];
        //cout<<s<<"\n";
        j = 0;
        vector<int> pos;

        while (j <= s.length() - 3)
        {   
            //string z = string(1,'a') + string(1,'b'); // (otra forma)
            substring = "";
            substring += s[j];
            substring += s[j+1];
            substring += s[j+2];

            //cout<<"substring: "<<substring<<" \n";

            if(substring == "two"){
                
                if(s.length() >= 5 && j <= s.length() - 5){
                    //cout<<j<<" <= len-5\n";
                    string a = substring;
                    a+= s.at(j+3);
                    a+= s.at(j+4);


                    if(a == "twone"){
                        //cout<<"twone detected\n";
                        pos.push_back(j+2);
                        j+=5;
                    }else{
                        pos.push_back(j+1);
                        j+=3;
                    }
                }else{
                    //cout<<"two detected\n";
                    pos.push_back(j+1);
                    j+=3;
                }
            }else if(substring == "one")
            {
                //cout<<"one detected\n";
                pos.push_back(j);
                j+=3;
            }else{
                j++;
            }
            //cout<<j<<"\n";
            //cout<<s.length() - 3<<"\n";
        }
        result.push_back(pos);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i].size()<<"\n";

        for (int j = 0; j < result[i].size(); j++)
        {
            cout<<result[i][j]<<" ";
        }
        cout<<"\n";
    }
    
    return 0;
}