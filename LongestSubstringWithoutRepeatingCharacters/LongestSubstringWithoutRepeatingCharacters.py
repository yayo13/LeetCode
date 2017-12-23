
def lengthOfLongestSubstring(s):
    """
    :type s: str
    :rtype: int
    """
    mp = [-1]*256
    pre = -1
    maxSubLen = 0
    for i in range(len(s)):
        pre =  max(pre, mp[ord(s[i])])
        maxSubLen = max(maxSubLen, (i-pre))
        mp[ord(s[i])] = i
    
    return maxSubLen
    