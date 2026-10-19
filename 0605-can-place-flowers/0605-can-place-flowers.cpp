class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int total = 0;

        int counter = 0;
        for (auto& num: flowerbed){
            if (num == 1){
                if (counter > 0) counter -= 1;

                total += max((counter + 1) / 2, 0);

                counter = -1;
            } else {
                counter++;
            }
        }

        total += max((counter + 1) / 2, 0);
        
        return total >= n;
    }
};