class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for (char c : s)
            mp[c]++;
        
        int n=s.size();
        for(auto it : mp ){
            if (it.second>(n+1)/2)
            return  "";
        }
        priority_queue<pair<int,char>> pq;
        for (auto it = mp.begin();it!=mp.end();it++){
            pq.push({it->second, it->first});
        }
        string res =  "";
        int seats=0;
        while (!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            if (seats==0||res[seats-1]!=p.second){
                res.push_back(p.second);
                p.first--;
                seats++;
                if (p.first>0)
                pq.push(p);
            }else{
                if (pq.empty())
                return  "";
                pair<int,char> q=pq.top();
                pq.pop();
                res.push_back(q.second);
                q.first--;
                seats++;
                if (q.first>0)
                pq.push(q);

               pq.push(p);

        }
    }
    return res;
    
    }
};