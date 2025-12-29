    
class NaiveSolution:
    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        left = 0
        right = 1
        freq = {}
        res = 1

        while right < n:
            freq.clear()

            for i in range(left, right + 1):
                freq[s[i]] = freq.get(s[i], 0) + 1

            maxFreq = max(freq.values())
            windowLens = (right - left) + 1
            if windowLens - maxFreq <= k :
                res = windowLens 
            else:
                left += 1

            right += 1
            
        return res



  
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        freq = {}
        left = 0
        maxFreq = 0
        res = 0

        for right in range(len(s)):
            freq[s[right]] = freq.get(s[right], 0) + 1
            maxFreq = max(maxFreq, freq[s[right]])

            windowLen = right - left + 1
            if windowLen - maxFreq > k:
                freq[s[left]] -= 1
                left += 1
            
            res = max(res, right - left + 1)

        return res

def main():
    sol = Solution()
    s = "AABABBA"
    k = 1
    result = sol.characterReplacement(s , k)
    print(result)
    
if __name__ == "__main__":
    main()
    
    
    