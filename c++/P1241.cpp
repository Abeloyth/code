#include <bits/stdc++.h>

using namespace std;

stack <char> s;
string s_, b_;

int main()
{
	cin >> s_;
    int len = s_.size();
    for (int i = 0; i < len; i++)
    {
        if (s_[i] == '(') 
		{
		   s.push(i);
		   b_[i] = ')';
		}
		else if (s_[i] == '[') 
		{
			s.push(i);
			b_[i] = ']';
		}
    	else if (s_[i] == ')' || s_[i] == ']')
    	{
			if (s.empty() || b_[s.top()] != s_[i])
				if (s_[i] == ')') 
					b_[i] = '('; 
				else 
					b_[i] = '[';
			
            else b_[s.top()] = ' ';
				s.pop();
		}
    }
    
    for (int i = 0; i < len; i++)
    {
        if (b_[i] == '(' || b_[i] == '[')
            cout << b_[i];
            
        cout << s_[i];
        
        if (b_[i] == ')' || b_[i] == ']') 
		    cout << b_[i];
    }
	
 	return 0;
}

