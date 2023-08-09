#include <string>

using namespace std;

class Solution {
public:

    bool canConstruct(string ransomNote, string magazine) {
        int char_counts[26] = {0};

        const int A_val = int('a');
        
        for(char c: ransomNote){
            char_counts[int(c) - A_val]++;
        }     
        
        for(char c: magazine){
            char_counts[int(c) - A_val]--;
        }    

        for(auto char_count : char_counts) {
            if(char_count > 0) {
                return false;
            }
        }

        return true;
    }
};