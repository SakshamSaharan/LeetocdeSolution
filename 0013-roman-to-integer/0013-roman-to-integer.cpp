class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int>mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            auto it = mp.find(s[i]);
            sum += it->second;
            if(it->first == 'V' || it->first == 'X'){
                if(i > 0){
                    auto it2 = mp.find(s[i-1]);
                    if(it2->first == 'I'){
                        sum-= 2*it2->second;
                    }
                }
            }
            else if(it->first == 'L' || it->first == 'C'){
                if(i > 0){
                    auto it2 = mp.find(s[i-1]);
                    if(it2->first == 'X'){
                        sum-= 2*it2->second;
                    }
                }
            }
            else if(it->first == 'D' || it->first == 'M'){
                if(i > 0){
                    auto it2 = mp.find(s[i-1]);
                    if(it2->first == 'C'){
                        sum-= 2*it2->second;
                    }
                }
            }
        }
        return sum;
    }
};