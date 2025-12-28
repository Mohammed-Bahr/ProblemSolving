class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n1 = len(s1)
        n2 = len(s2)

        if n1 > n2:
            return False

        s1_freq = {}

        for c in s1:
            s1_freq[c] = s1_freq.get(c, 0) + 1

        left = 0
        right = n1 - 1

        while right < n2:
            res = {}

            for i in range(left, right + 1):
                res[s2[i]] = res.get(s2[i], 0) + 1

            # compare maps
            if res == s1_freq:
                return True

            left += 1
            right += 1

        return False



def main():
    s1 = "ab"
    s2 = "eidbaooo"
    
    sol = Solution()
    print (sol.checkInclusion(s1 , s2))
    
    
  
if __name__ == "__main__":
    main()
