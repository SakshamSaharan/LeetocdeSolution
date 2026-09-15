class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;

        for(int i = 0; i < asteroids.size(); i++) {

            if(asteroids[i] > 0) {
                s.push(asteroids[i]);
            }
            else {
                bool destroyed = false;

                while(!s.empty() && s.top() > 0 &&
                      s.top() <= abs(asteroids[i])) {

                    if(s.top() == abs(asteroids[i])) {
                        s.pop();
                        destroyed = true;
                        break;
                    }

                    s.pop();
                }

                if(!destroyed) {
                    if(s.empty() || s.top() < 0) {
                        s.push(asteroids[i]);
                    }
                }
            }
        }

        int x = s.size();
        vector<int> vec(x);

        for(int i = x - 1; i >= 0; i--) {
            vec[i] = s.top();
            s.pop();
        }

        return vec;
    }
};