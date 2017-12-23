int lengthOfLongestSubstring(string s) {
	int map_[256];
	memset(map_, -1, 256*sizeof(int));

	int pre = -1, maxSubLen = 0;
	for(int i=0; i<s.length(); i++){
		pre = max(pre, map_[s[i]]);
		maxSubLen = max(maxSubLen, i-pre);
		map_[s[i]] = i;
	}
	return maxSubLen;
}

/*
参考 http://blog.csdn.net/u013575812/article/details/50198905

mp<char, int> 存储某个字符最近一次出现的位置
pre           遍历到 str[i] 时，以str[i-1]结尾的情况下最长无重复子串开始的前一个位置
maxSubLen     当前字符结尾的情况下，最长无重复子串长度

*/