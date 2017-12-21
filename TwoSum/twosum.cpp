vector<int> twoSum(vector<int> &numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;
	for (int i = 0; i < numbers.size(); i++) {
		int numberToFind = target - numbers[i];

		if (hash.find(numberToFind) != hash.end()) {
			result.push_back(hash[numberToFind]);
			result.push_back(i);			
			return result;
		}

		hash[numbers[i]] = i;
	}
	return result;
}

/*
最简单的方式是两层循环，但这种计算复杂度为 n^2
上述方法将内循环用查找代替，为了提高查找效率，使用 unsorted_map 

与 map 不同，unsorted_map 不对key排序
*/