class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;

        for (auto &asteroid: asteroids){
            if (result.empty() || asteroid > 0){
                result.push_back(asteroid);
                continue;
            }

            if (result.back() < 0 && asteroid < 0){
                result.push_back(asteroid);
                continue;
            }

            if (asteroid < 0 && result.back() > 0){
                bool isBroken = false;
                while (!result.empty() && result.back() > 0){
                    if (result.back() < -asteroid){
                        result.pop_back();
                    } else if (result.back() == -asteroid){
                        isBroken = true;
                        result.pop_back();
                        break;
                    } else {
                        isBroken = true;
                        break;
                    }
                }

                if ((result.empty() && !isBroken) || !isBroken){
                    result.push_back(asteroid);
                    continue;
                }
            }
        }

        return result;
    }
};