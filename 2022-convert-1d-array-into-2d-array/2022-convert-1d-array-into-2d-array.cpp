class Solution {
public:

    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // 1차원 배열의 크기가 m * n과 일치하지 않으면 빈 배열 반환
        if (original.size() != m * n) {
            return {};
        }

        // 2차원 배열 생성
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = original[i * n + j];
            }
        }

        return result;
    }
};