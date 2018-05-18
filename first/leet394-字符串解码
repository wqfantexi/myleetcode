class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for (string::iterator iter = s.begin(); iter != s.end(); ++iter)
        {
            if (*iter != ']') //不是右括号的话，先入栈
            {
                st.push(*iter);
            }
            else
            {
                string tmp;
                //先找到左括号
                char c;
                while (true)
                {
                    c = st.top();
                    st.pop();
                    if (c == '[')
                    {
                        break;
                    }
                    else
                    {
                        tmp.push_back(c);
                    }
                }
                reverse(tmp.begin(), tmp.end());
                //再找到数字

                string snum;
                while (true && !st.empty())
                {
                    c = st.top();
                    if (isdigit(c))
                    {
                        snum.push_back(c);
                        st.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                reverse(snum.begin(), snum.end());
                int num = atoi(snum.c_str());
                for (int i = 0; i < num; ++i)
                {
                    for (int j = 0; j < tmp.size(); ++j)
                    {
                        st.push(tmp[j]);
                    }
                }
            }
        }
        string result;
        result.reserve(st.size());
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());

        return result;
    }
};
