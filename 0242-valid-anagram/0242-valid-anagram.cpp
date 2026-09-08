class Solution {
public:
    bool isAnagram(string s, string t) {
             int arr[26]={0};
     bool isanagram=true;
    if(s.length() != t.length()){
        isanagram=false;
    }
    else {
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
              arr[t[i]-'a']--;
                   if(arr[t[i] - 'a'] < 0){
                isanagram=false;
                 break;
        }
    }
}
    return isanagram;
    }
};