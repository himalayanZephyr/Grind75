#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::unordered_map<char, char> close_to_open = {
            {')','('},
            {'}','{'},
            {']','['}
        };

        std::stack<char> chars;

        for(int i=0; i < s.length(); i++) {
            if (close_to_open.count(s[i])) {
                if ((!chars.empty()) && (chars.top() == close_to_open[s[i]])) {
                    chars.pop();
                }
                else {
                    return false;
                } 
            }
            else {
                chars.push(s[i]);
            }
        }

        return (chars.empty() ? true : false);
    }
};
