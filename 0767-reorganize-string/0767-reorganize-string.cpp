class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;

        for(int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }

        int n = s.size();
        for(auto it : mp) {
            if(it.second > (n + 1) / 2)
                return "";
        }

        priority_queue<pair<int,char>> pq;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->second, it->first});
        }

        string res = "";

        while(!pq.empty()) {

            pair<int,char> p = pq.top();
            pq.pop();

            if(res.empty() || res.back() != p.second) {

                res.push_back(p.second);
                p.first--;

                if(p.first > 0)
                    pq.push(p);
            }
            else {

                if(pq.empty())
                    return "";

                pair<int,char> p2 = pq.top();
                pq.pop();

                res.push_back(p2.second);
                p2.first--;

                if(p2.first > 0)
                    pq.push(p2);

                pq.push(p);
            }
        }

        return res;        
    }
};