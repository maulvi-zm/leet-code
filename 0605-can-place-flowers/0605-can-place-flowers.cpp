class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int total = 0;

        for (int i = 0; i < size; i++) {
            bool isLeftEmpty = (i == 0) || flowerbed[i - 1] == 0;
            bool isRightEmpty = (i == size - 1) || flowerbed[i + 1] == 0;

            if (flowerbed[i] == 0 && isLeftEmpty && isRightEmpty) {
                flowerbed[i] = 1;
                total++;

                if (total == n) {
                    return true;
                }
            };
        }

        return total >= n;
    }
};
