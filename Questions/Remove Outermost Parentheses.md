```cpp
string removeOuterParentheses(string s)
{
    int opencount = 0, closedcount = 0;
    int l = 0, r = 0, n = s.size();
    string temp = "";
    while (r < n)
    {
        if (s[r] == '(')
            opencount++;
        else
            closedcount++; 
        if (opencount == closedcount)
        // this means a string with paired brackets is found
        {
            temp += s.substr(l + 1, r - l - 1);
            // r - l + 1 - 2 to have range minus 2 outermost parantheses
            l = r + 1; // reset pointer for new substring
            opencount = 0;
            closedcount = 0;
        }
        r++;
    }
    return temp;
}
```