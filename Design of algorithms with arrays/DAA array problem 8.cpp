#include <cstring>
#include <iostream>
using namespace std;

class MaximumBalances
{
public:
	int check(string s)
    {
        if(!s.size())
            return 0;
     	int o = 0, ans = 0;
     	cout<<s<<endl;
        for(int i=0;i<s.length();++i)
        {
         	if(s[i] == '(')
                o++;
            else
            {
                o--;
                if(o < 0)
                    return 0;
                ans++;
            }
        }
        return o == 0;
   	};

    int solve(string s)
    {
        int ans = 0;
     	for(int i=0;i<s.length();++i)
        {
        	for(int j=0;j<s.length();++j)
                ans+=check(s.substr(i, j-i+1));
        }
        return ans;
    }
};
int main()
{
    MaximumBalances a;
    cout<<a.solve("((((");
}
