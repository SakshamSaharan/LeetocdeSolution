class Solution {
public:
    vector<string> assignUmbrella(vector<int>& rain) {
        int acount = 0;
        int bcount = 0;
        int n = rain.size();
        vector<string>ans;
        for(int i=0;i<n-1;i++){
            if(rain[i] == rain[i+1] && rain[i] == 1){
                if(acount <= bcount){
                    ans.push_back("Alice");
                    acount++;
                }
                else{
                    ans.push_back("Bob");
                    bcount++;
                }
            }
            else if(rain[i] == 1){
                ans.push_back("Bob");
                bcount++;
            }
            else{
                ans.push_back("None");
            }
        }
        rain[n-1] == 1 ? ans.push_back("Bob") : ans.push_back("None");;
        return ans;
    }
};