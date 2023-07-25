#include <string>
#include <tuple>
#include <utility>

using namespace std;

class Solution {

public:

    pair<int, int> get_palindrome(int l, int r, string s) {
        while(l >= 0 and r < s.size() and (s[l] == s[r])) {
            l--;
            r++;
        }
        return {l+1, r-1};
    }

    string longestPalindrome(string s) {
        
        int L = 0;
        int R = 0;

        for(int i=0; i<s.size(); i++){

            auto [l, r] = get_palindrome(i,i,s);
            if((r-l) > (R-L)){
                L = l;
                R = r;
            }
            
            std::tie(l, r) = get_palindrome(i,i+1,s);
            if((r-l) > (R-L)){
                L = l;
                R = r;
            }            
        }

        return s.substr(L, R-L+1);

    }
};
