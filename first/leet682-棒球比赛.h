class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> score;
        for(vector<string>::const_iterator iter = ops.begin();
           iter != ops.end();
           ++iter)
        {
            const string &str = *iter;
            if ("+" == str)
            {
                if (score.size() >= 2)
                {
                    int first = score.top();
                    score.pop();
                    int tmp = score.top() + first;
                    score.push(first);
                    score.push(tmp);
                }
            }
            else if ("D" == str)
            {
                if (!score.empty())
                {
                    score.push(score.top() * 2);
                }
            }
            else if ("C" == str)
            {
                if (!score.empty())
                {
                    score.pop();
                }
            }
            else
            {
                score.push(atoi(str.c_str()));
            }
        }
        int result = 0;
        while(!score.empty())
        {
            result += score.top();
            score.pop();
        }
        return result;
    }
};
