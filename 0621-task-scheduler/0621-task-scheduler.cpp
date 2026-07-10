class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int s = tasks.size();
        unordered_map<char,int> free;
        unordered_map<char,int> freq;

        for (int i = 0; i < s; i++) {
            freq[tasks[i]]++;
            free[tasks[i]] = 1;
        }

        priority_queue<pair<int,char>> pq;
        for (auto i : freq) {
            pq.push({i.second, i.first});
        }

        int seat = 1;
        while (!pq.empty()) {
            vector<pair<int,char>> pulled;
            bool scheduled = false; // NEW: track if we've placed a task THIS seat

            while (!pq.empty()) {// check if task can be scheduled //ye wala while loop check karege ka ki baithalna hai ki khali chod dena hai
                pair<int,char> p = pq.top();
                pq.pop();
                int child = p.second;

                if (!scheduled && free[child] <= seat) {
                    // schedule this ONE task in this seat
                    if (p.first > 1) {
                        pq.push({p.first - 1, p.second});
                    }
                    free[child] = seat + n + 1;
                    scheduled = true;   // NEW: block any further scheduling this seat
                } else {
                    pulled.push_back(p);
                }
            }

            for (int i = 0; i < pulled.size(); i++) {
                pq.push(pulled[i]);
            }

            seat++; // moved to end: only advance seat after processing it
        }

        return seat - 1; // adjust since seat now counts one past the last used seat
    }
};