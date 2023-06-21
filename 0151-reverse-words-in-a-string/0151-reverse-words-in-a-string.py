class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join([i.strip() for i in s.strip().split(' ') if i != ""][::-1])