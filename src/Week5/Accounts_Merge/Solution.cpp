#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;



class UnionFind {

public:

    UnionFind(int n) {
        for(int i=0; i<n; i++) {
            parent.push_back(i);
            rank.push_back(1);
            connected_components[i] = {};
        }
    }

    void update_connected_components(int parent_index, int child_index){

        for(auto grand_child_index: connected_components[child_index]){ //i.e. in case child_index was also a parent to other indices
            connected_components[parent_index].push_back(grand_child_index);
        }

        connected_components[parent_index].push_back(child_index);

        connected_components.erase(child_index);
    }

    const unordered_map<int, vector<int>>& get_connected_components() {
        return connected_components;
    }

    void _union(int x, int y) {
        int parent_x = find(x);
        int parent_y = find(y);

        if(parent_x == parent_y) {
            return;
        }
        else {
            if(rank[parent_x] > rank[parent_y]) {
                parent[parent_y] = parent_x;
                update_connected_components(parent_x, parent_y);
            }
            else if(rank[parent_y] > rank[parent_x]) {
                parent[parent_x] = parent_y;
                update_connected_components(parent_y, parent_x);
            }
            else {
                parent[parent_y] = parent_x;
                rank[parent_x]++;
                update_connected_components(parent_x, parent_y);
            }
        }
    }

    int find(int x) {
        if(x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

private:
    vector<int> parent;
    vector<int> rank;
    unordered_map<int,vector<int>> connected_components;
};


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();
        UnionFind uf = UnionFind(n);

        vector<vector<string>> results;
        
        //Email to account id mapping
        unordered_map<string, int> email_to_account_mapping;
        
        for(int i=0; i<n; i++) {
            
            for(int j=1; j< accounts[i].size(); j++) {
                string email = accounts[i][j];

                if(email_to_account_mapping.count(email))
                {
                    uf._union(i,email_to_account_mapping[email]);
                }
                else {
                    email_to_account_mapping[email] = i;
                }
            }

        }

        unordered_map<int,vector<int>> connected_accounts = uf.get_connected_components();

        for(const auto& [parent_account_id, child_account_ids] : connected_accounts) {
            vector<string> result = vector<string>(accounts[parent_account_id].begin(), accounts[parent_account_id].end());
            
            for(int child_account_id : child_account_ids) {
                std::copy(accounts[child_account_id].begin()+1, accounts[child_account_id].end(), std::back_inserter(result));
            }

            std::sort(result.begin()+1, result.end());
            
            //De-deduplicate
            result.erase(std::unique(result.begin()+1, result.end()), result.end());

            results.push_back(result);
        }

        return results;

    }
};