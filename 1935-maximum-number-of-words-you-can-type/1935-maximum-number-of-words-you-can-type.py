class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        ans = 0
        for i in text.split():
            temp = True
            for j in i:
                if j in brokenLetters:
                    temp = False
                    break
            
            if temp:
                ans += 1
        return ans
            