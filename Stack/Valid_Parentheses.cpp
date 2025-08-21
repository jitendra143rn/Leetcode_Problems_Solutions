class Solution {
public:

    bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
       
   } 

    bool isValid(string s) {
        stack<char> s1;

        for(char ch : s)
    {
        if( ch == '(' || ch == '{' || ch == '[' )
        {
            s1.push(ch);
            
        }
        else if(ch == ')' || ch == '}' || ch == ']')
        {
            if(s1.empty() || !isMatchingPair(s1.top(), ch))
            {
                return false;
                
            }
            s1.pop();
        }
    }
    
    return s1.empty();
    }
};
