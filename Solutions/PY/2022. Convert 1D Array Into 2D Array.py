class Solution(object):
    def construct2DArray(self, original, m, n):
        """
        :type original: List[int]
        :type m: int
        :type n: int
        :rtype: List[List[int]]
        """
        
        # condition: total elements must match
        if len(original) != m * n:
            return []

        # create empty 2D list
        List_2D = [[] for _ in range(m)]

        # fill the matrix
        index = 0
        for j in range(m):
            for i in range(n):
                List_2D[j].append(original[index])
                index += 1

        return List_2D       
            

def main():
    sol = Solution()

    original = [1, 2, 3, 4]
    m = 2
    n = 2

    result = sol.construct2DArray(original, m, n)
    print("2D Array:", result)


# run main
if __name__ == "__main__":
    main()
    
    
    
    