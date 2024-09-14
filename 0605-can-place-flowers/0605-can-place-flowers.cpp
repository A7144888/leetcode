#include <vector>

class Solution {
public:
    bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        
        // 如果 flowerbed 的大小小於 1，則無法進行任何操作
        if (size == 0) return n <= 0;

        // 當 flowerbed 大小為 1 的特殊情況
        if (size == 1) {
            if (flowerbed[0] == 0) {
                n -= 1;
            }
            return n <= 0;
        }

        // 檢查花壇的開頭
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n -= 1;
        }

        // 檢查中間的元素
        for (int i = 1; i < size - 1; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                n -= 1;
            }
        }

        // 檢查花壇的結尾
        if (flowerbed[size - 1] == 0 && flowerbed[size - 2] == 0) {
            flowerbed[size - 1] = 1;
            n -= 1;
        }

        return n <= 0;
    }
};
