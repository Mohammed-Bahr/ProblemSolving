/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if (n === 1 || n === 0 ) return 1;
    let a = 1;
    let b = 2;
    while (n > 2) {
        let temp = a + b;
        a = b;
        b = temp;
        n--;
    }
    return b;
};
console.log(climbStairs(5));

//-----------------------------------
// Top Down Approach
var TopDown_climbStairs = function(n){
    let memo = {};
    function dfs (step){
        if (step in memo ) return memo[step]
        if (step == 1 || step == 0 ) return 1;
        memo[step] = dfs(step-1) + dfs(step-2);
        return memo[step];
    }
    return dfs(n);
}

console.log(TopDown_climbStairs(5));




//-----------------------------------
// Bottom Up Approach
var BottomUp_climbStairs = function(n){
    let dp = new Array(n+1).fill(0);
    dp[1] = 1;
    dp[2] = 2;
    for (let i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
console.log(BottomUp_climbStairs(5));