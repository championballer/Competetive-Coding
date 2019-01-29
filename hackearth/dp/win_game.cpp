/*
// Sample code to perform I/O:

cin >> name;                            // Reading input from STDIN
cout << "Hi, " << name << ".\n";        // Writing output to STDOUT

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/

// Write your code here
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int r,g;
        cin>>r>>g;
        
        int total = r+g;
        if(total==r || total==g)
        {
            cout<<fixed<<setprecision(6)<<1.0<<endl;
        }
        
        else
        {
            float total_prob = (float(r)/total);
            float green_prob = 1;
            for(int i=2;i<=g;i+=2)
            {
                for(int j=0;j<2;j++)
                {
                    green_prob*=(float((g-i)+j+1)/(((total-i)+j+1)));
                }
                total_prob+=green_prob*(float(r)/(total-i));
            }
            cout<<fixed<<setprecision(6)<<total_prob<<endl;
        }
    }
}