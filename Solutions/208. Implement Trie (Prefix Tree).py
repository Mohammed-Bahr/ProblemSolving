class TrieNode:
    def __init__(self):
        self.children = {}      # dict: char -> TrieNode
        self.endOfWord = False  # هل الكلمة بتنتهي هنا ولا لأ


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root

        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]

        cur.endOfWord = True

    def search(self, word: str) -> bool:
        cur = self.root

        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]

        return cur.endOfWord

    def startsWith(self, prefix: str) -> bool:
        cur = self.root

        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]

        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


obj = Trie()
obj.insert("apple")
obj.insert("app")

print(obj.search("apple"))     # True
print(obj.search("app"))       # True
print(obj.search("appl"))      # False

print(obj.startsWith("app"))   # True
print(obj.startsWith("apl"))   # False
