//Problem Link: https://leetcode.com/problems/permutations/
class Solution {
    static void swap(int[] nums, int a, int b){
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    public static void getPermutations(int ind, int[] nums, List<List<Integer>> ans){
        if(ind >= nums.length){
            List<Integer> res = new ArrayList<>();
            for(int i=0; i<nums.length; i++) res.add(nums[i]);
            ans.add(res); return;
        }

        for(int i=ind; i<nums.length; i++){
            swap(nums, ind, i);
            getPermutations(ind+1, nums, ans);
            swap(nums, ind, i);
        }

        return;
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        getPermutations(0, nums, ans);
        return ans;
    }
}