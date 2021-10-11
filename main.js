/** 
 * @NOTE: practice JS with algorithm & data structures
*/

const s1 = 'GXTXAYB';
const s2 = 'AGGTAB';
const dp = [];

const n = 100;

//* Create array 2D
for (let i = 0; i <= n; i++) {
    dp[i]= [];
}

const resolve = () => {
    const n = s1.length;
    const m = s2.length;

    for (let i = 0; i <= n; i++) {
        for (let j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j <= m; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

console.log(resolve());