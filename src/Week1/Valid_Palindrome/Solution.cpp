#include <cctype>
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int l = 0;
        int r = s.length();

        while (l < r){
            if (std::isalnum(s[l]) && std::isalnum(s[r])) {
                if(std::tolower(s[l]) == std::tolower(s[r])) {
                    l += 1;
                    r -= 1;
                }
                else{
                    return false;
                }
            }
            else if(std::isalnum(s[l])){
                r -= 1;
            }
            else if(std::isalnum(s[r])){
                l += 1;
            }
            else{
                l += 1;
                r -= 1;
            }
        }

        return true;   
    }
};