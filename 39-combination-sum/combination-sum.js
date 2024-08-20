/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    const result = [];
    function rev(start, sum, path) {
        if (sum === target) {
            result.push([...path]);
            return;
        }
        if (sum > target) {
            return;
        }
        for (let i = start; i < candidates.length; i++) {
            path.push(candidates[i]);
            rev(i, sum + candidates[i], path);
            path.pop();
        }
    }
    rev(0, 0, []);
    return result;
};