def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype List[int]
    """
    for index in range(len(nums)):
            to_find = target - nums[index]
            if to_find in nums[index+1:]:
                return(index, nums[index+1:].index(to_find)+index+1)
    
    return ()