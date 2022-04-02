​time : O(log n)

​space : O(1)

​key point 1: 

            use the thought of problem33, we use the nums[0] to check what sorted array now point(nums[mid]), 
            and use the target = lowest(-5000) - 1 = -5001 to move the l or r, however speed is too slow(unwanted)
            
 ​key point 2: 
 
            the final answer is check whether the l and r in same order(beacuse impossible l and r move to large sorted array) ==> if yes, the answer is nums[l]
            if no, according the mid to move l or r to lower sorted array
