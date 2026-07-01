
# class node:
#     def __init__  (self):
#         self.childs = {}
#         self.end = False


# class WordDictionary:

#     def __init__(self):
#         self.root = node()
        

#     def addWord(self, word: str) -> None:
#         curr = self.root
#         for char in word:
#             if char not in curr.childs :
#                 curr.childs[char] = node()
#             curr = curr.childs[char]
#         curr.end = True
        

#     def search(self, word: str) -> bool:
#         curr = self.root
#         for char in word:
#             if char not in curr.childs :
#                 return False
#             curr = curr.childs[char]
#         return curr.end


class node:
    def __init__(self):
        self.childs = {}
        self.end = False


class WordDictionary:

    def __init__(self):
        self.root = node()

    def addWord(self, word: str) -> None:
        curr = self.root
        for char in word:
            if char not in curr.childs:
                curr.childs[char] = node()
            curr = curr.childs[char]
        curr.end = True

    def search(self, word: str) -> bool:

        def dfs(curr, i):
            if i == len(word):
                return curr.end

            char = word[i]

            if char == '.':
                for child in curr.childs.values():
                    if dfs(child, i + 1):
                        return True
                return False

            if char not in curr.childs:
                return False

            return dfs(curr.childs[char], i + 1)

        return dfs(self.root, 0)



# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)



def main():
    wd = WordDictionary()

    # Test 1: search before adding anything
    print(wd.search("a"))        # False

    # Test 2: add one word and search it
    wd.addWord("bad")
    print(wd.search("bad"))      # True

    # Test 3: search prefix only (should be False)
    print(wd.search("ba"))       # False

    # Test 4: search word that doesn't exist
    print(wd.search("dad"))      # False

    # Test 5: add multiple words
    wd.addWord("dad")
    wd.addWord("mad")

    print(wd.search("dad"))      # True
    print(wd.search("mad"))      # True
    print(wd.search("bad"))      # True

    # Test 6: similar prefix but different ending
    print(wd.search("badd"))     # False

    # Test 7: empty word
    wd.addWord("")
    print(wd.search(""))         # True


if __name__ == "__main__":
    main()
