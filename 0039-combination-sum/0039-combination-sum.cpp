class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int sum =0;
        vector<int> diary;
        vector<vector<int>>res;
        int idx=0;
        fun (candidates,n,0,sum,diary,res,target);
         return res;
    }

    void fun (vector<int>& candidates,int n,int idx,int sum ,vector<int>&diary,vector<vector<int>>&res, int target){
       if (idx==n){
        if (sum == target)
        res.push_back(diary);
        return;
       }
// nahi lena hai 
fun (candidates,n,idx+1,sum,diary,res,target);

//lena hai
if (candidates[idx]+sum<=target){
    diary.push_back(candidates[idx]);
    sum+=candidates[idx];
    fun (candidates,n,idx,sum,diary,res,target);
    diary.pop_back();
    sum-=candidates[idx];

}
return;
    }
};/*CALL fun(idx=0, sum=0, diary=[])
  idx(0) ≠ n(2), so we make a decision on candidates[0]=2

  ┌─ FIRST: try SKIP (don't use 2 anymore) ─────────────────────
  │  CALL fun(idx=1, sum=0, diary=[])
  │    idx(1) ≠ n(2), decision on candidates[1]=3
  │
  │    ┌─ SKIP (don't use 3) ─────────────────
  │    │  CALL fun(idx=2, sum=0, diary=[])
  │    │    idx==n(2) → check: sum(0)==target(6)? NO → ❌ discard
  │    │  RETURN
  │    └──────────────────────────────────────
  │
  │    ┌─ TAKE 3 (0+3=3 ≤ 6, allowed) ─────────
  │    │  diary=[3], sum=3
  │    │  CALL fun(idx=1, sum=3, diary=[3])
  │    │    idx(1) ≠ n(2), decision on candidates[1]=3 again (same idx!)
  │    │
  │    │    ┌─ SKIP ─────────────────
  │    │    │  fun(idx=2, sum=3, diary=[3])
  │    │    │    idx==n → sum(3)==6? NO → ❌ discard
  │    │    └────────────────────────
  │    │
  │    │    ┌─ TAKE 3 again (3+3=6 ≤ 6, allowed) ─
  │    │    │  diary=[3,3], sum=6
  │    │    │  fun(idx=1, sum=6, diary=[3,3])
  │    │    │    decision on candidates[1]=3 AGAIN
  │    │    │
  │    │    │    ┌─ SKIP ─────
  │    │    │    │  fun(idx=2, sum=6, diary=[3,3])
  │    │    │    │    idx==n → sum(6)==6? YES → ✅ SAVE [3,3]
  │    │    │    └────────────
  │    │    │
  │    │    │    ┌─ TAKE 3 again? (6+3=9 ≤ 6?) NO → skip this branch
  │    │    │
  │    │    │  diary pops back to [3] after this call returns
  │    │    └──────────────────────────────────────
  │    │
  │    │  diary pops back to [] after this call returns
  │    └──────────────────────────────────────────
  │
  │  RETURN (back to root)
  └────────────────────────────────────────────────────────────

  ┌─ SECOND: now try TAKE 2 (0+2=2 ≤ 6, allowed) ───────────────
  │  diary=[2], sum=2
  │  CALL fun(idx=0, sum=2, diary=[2])
  │    idx(0) ≠ n(2), decision on candidates[0]=2 AGAIN (same idx)
  │
  │    ┌─ SKIP (move on to 3's) ──────────────
  │    │  fun(idx=1, sum=2, diary=[2])
  │    │    decision on candidates[1]=3
  │    │    ┌─ SKIP ─── fun(idx=2,sum=2,[2]) → sum≠6 → ❌ discard
  │    │    ┌─ TAKE(2+3=5≤6) ─── diary=[2,3], sum=5
  │    │    │    fun(idx=1,sum=5,[2,3])
  │    │    │      SKIP → fun(idx=2,sum=5,[2,3]) → sum≠6 → ❌ discard
  │    │    │      TAKE(5+3=8≤6?) NO → skip only
  │    │    │    diary pops back to [2]
  │    └──────────────────────────────────────
  │
  │    ┌─ TAKE 2 again (2+2=4 ≤ 6, allowed) ──
  │    │  diary=[2,2], sum=4
  │    │  fun(idx=0, sum=4, diary=[2,2])
  │    │    decision on candidates[0]=2 AGAIN
  │    │
  │    │    ┌─ SKIP ────────────────
  │    │    │  fun(idx=1,sum=4,[2,2])
  │    │    │    decision on candidates[1]=3
  │    │    │    SKIP → fun(idx=2,sum=4,[2,2]) → sum≠6 → ❌ discard
  │    │    │    TAKE(4+3=7≤6?) NO → skip only
  │    │    └────────────────────────
  │    │
  │    │    ┌─ TAKE 2 again (4+2=6 ≤ 6, allowed) ─
  │    │    │  diary=[2,2,2], sum=6
  │    │    │  fun(idx=0, sum=6, diary=[2,2,2])
  │    │    │    decision on candidates[0]=2 AGAIN
  │    │    │
  │    │    │    ┌─ SKIP ──────
  │    │    │    │  fun(idx=1,sum=6,[2,2,2])
  │    │    │    │    decision on candidates[1]=3
  │    │    │    │    SKIP → fun(idx=2,sum=6,[2,2,2])
  │    │    │    │       idx==n → sum(6)==6? YES → ✅ SAVE [2,2,2]
  │    │    │    │    TAKE(6+3=9≤6?) NO → skip only
  
  │    │    │    └─────────────
  │    │    │
  │    │    │    ┌─ TAKE 2 again? (6+2=8≤6?) NO → skip this branch
  │    │    │
  │    │    │  diary pops back to [2,2]
  │    │    └──────────────────────────────────
  │    │
  │    │  diary pops back to [2]
  │    └──────────────────────────────────────
  │
  │  diary pops back to []
  └───────────────────────────────────────────────────────────

DONE.
res = [ [3,3], [2,2,2] ]


fun(0,0,[])
                    ┌───SKIP 2────────────┴────────TAKE 2 (sum=2)────────┐
              fun(1,0,[])                                          fun(0,2,[2])
           ┌──SKIP 3───┴───TAKE 3(sum=3)                    ┌──SKIP 2───┴───TAKE 2(sum=4)
      fun(2,0,[])      fun(1,3,[3])                    fun(1,2,[2])          fun(0,4,[2,2])
      sum≠6 ❌      ┌─SKIP─┴─TAKE 3(sum=6)          ┌SKIP┴TAKE 3(sum=5)   ┌SKIP───┴───TAKE 2(sum=6)
                fun(2,3,[3])  fun(1,6,[3,3])   fun(2,2,[2])  fun(1,5,[2,3]) fun(1,4,[2,2])  fun(0,6,[2,2,2])
                sum≠6 ❌   ┌SKIP┴TAKE(9>6✗)    sum≠6 ❌    ┌SKIP┴TAKE(8>6✗) ┌SKIP┴TAKE(7>6✗) ┌SKIP──┴──TAKE(8>6✗)
                     fun(2,6,[3,3])                  fun(2,5,[2,3])   fun(2,4,[2,2])   fun(1,6,[2,2,2])
                     sum=6 ✅ SAVE                    sum≠6 ❌         sum≠6 ❌      ┌SKIP┴TAKE(9>6✗)
                     "[3,3]"                                                    fun(2,6,[2,2,2])
                                                                                 sum=6 ✅ SAVE
                                                                                 "[2,2,2]"*/