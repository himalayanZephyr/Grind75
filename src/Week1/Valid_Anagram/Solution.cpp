#include <string>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> smap;

        for (int i=0; i < s.length(); i++) {
            if (smap.count(s[i])){
                smap[s[i]] += 1;
            }
            else{
                smap[s[i]] = 1;
            }
        }

        for (int j=0; j < t.length(); j++){
            if (smap.count(t[j])){
                if(smap[t[j]] > 1){
                    smap[t[j]] -= 1;
                }
                else{
                    smap.erase(t[j]);
                }
            }
            else {
                return false;
            }
        }

        return smap.empty() ? true : false;
        
    }
};