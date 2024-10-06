class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n <= 3) return 1; // since "122" has one '1'

        vector<int> magical = {1, 2, 2};  // Start with "122"
        int idx = 2; // The position where we look at to determine how many times to repeat
        int num = 1; // The next number to append (1 or 2)
        
        // Build the magical string up to n characters
        while (magical.size() < n) {
            int repeat = magical[idx];
            for (int i = 0; i < repeat; i++) {
                magical.push_back(num);
            }
            num = (num == 1) ? 2 : 1; // Switch between 1 and 2
            idx++;
        }

        // Count how many 1's in the first n characters
        return count(magical.begin(), magical.begin() + n, 1);
    }
};
