#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    int n;
    string a, b;
    cin>>n;
    for (auto i = 0; i < n; i++)
    {
        cin>>a>>b;
        int size=a.size()+b.size();
        int count=0;
        for (auto j = 0; j < b.size(); j++)
        {
            int flag=j;
            for (auto k = 0; k < a.size(); k++)
            {
                if (flag<b.size()&&                                                                                                                                                                                                                                                                                                                   a[k]==b[flag])
                {
                    flag++;   
                }
            }
            size=min(size, (int)a.size()+(int)b.size()-flag+j);
        }
        cout<<size<<endl;
    }
    
    return 0;
}