class Solution(object):
    def nextGreatestLetter(self, letters, target):
        """
        :type letters: List[str]
        :type target: str
        :rtype: str
        """
        
        targetInt = ord(target)
        res_char = ''
        for ch in letters:
            if ord(ch) > targetInt :
                res_char = ch
                break
        
        if not res_char :
            return letters[0]
def main():
    sol = Solution()

    letters = ["x","x","y","y"]
    target = 'z'
 

    result = sol.nextGreatestLetter(letters, target)
    print(result)


# run main
if __name__ == "__main__":
    main()
    
    
    
    