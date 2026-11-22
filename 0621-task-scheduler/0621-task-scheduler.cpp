class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time = 0;
        vector<int>freq(26,0);
        for(char ch : tasks){
            freq[ch-'A']++;
        }
        priority_queue<int>pq;
        for(int i : freq){
            if(i > 0) pq.push(i);
        }
        while(! pq.empty()){
            vector<int>temp;
            for(int i=1;i<=n+1;i++){
                if(! pq.empty()){
                int frequency = pq.top();
                pq.pop();
                frequency--;
                temp.push_back(frequency);
                }
            }
            for(int i : temp){
                if(i > 0) pq.push(i);
            }

            if(pq.empty()) time += temp.size();
            else time += n+1;
        }
        return time;
    }
};