class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        set<string> ans = solve(expression, i);
        
        return vector<string>(ans.begin(), ans.end());
    }

private:
    set<string> solve(string &s, int &i) {
        set<string> result;
        result.insert("");

        while (i < s.size() && s[i] != '}') {
            
            if (s[i] == '{') {
                i++; // skip '{'

                set<string> inside;
                
                // Parse first part
                inside = solve(s, i);

                // Handle union parts separated by ','
                set<string> current = inside;

                // solve() stops at '}' or ','
                while (i < s.size() && s[i] == ',') {
                    i++; // skip ','
                    set<string> next = solve(s, i);

                    current.insert(next.begin(), next.end());
                }

                i++; // skip '}'

                // Concatenate current with result
                set<string> temp;

                for (string a : result) {
                    for (string b : current) {
                        temp.insert(a + b);
                    }
                }

                result = temp;
            }
            else if (s[i] == ',') {
                break;
            }
            else {
                // Normal character
                string ch(1, s[i]);
                i++;

                set<string> temp;

                for (string a : result) {
                    temp.insert(a + ch);
                }

                result = temp;
            }
        }

        return result;
    }
};