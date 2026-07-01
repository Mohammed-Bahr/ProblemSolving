class Solution {
public:
    string multiply(string num1, string num2) {
        // If one number is zero
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();

        // Maximum length of result = n + m
        vector<int> result(n + m, 0);

        // Multiply digits from right to left
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int p1 = i + j;       // carry position
                int p2 = i + j + 1;   // current digit position

                int sum = mul + result[p2];

                result[p2] = sum % 10;
                result[p1] += sum / 10;
            }
        }

        // Convert vector to string
        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) {
                ans += (num + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};
