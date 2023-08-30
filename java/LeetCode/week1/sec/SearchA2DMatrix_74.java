package LeetCode.week1.sec;

public class SearchA2DMatrix_74 {
    public boolean searchMatrix(int[][] matrix, int target) {

        int row = 0;
        int col = 0;

        while(row < matrix.length && col < matrix[0].length) {
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][matrix[0].length - 1] < target) {
                row++;
            }
            else col++;
        }
        return false;
    }

    public static void main(String[] args) {
        SearchA2DMatrix_74 s = new SearchA2DMatrix_74();
        System.out.println(s.searchMatrix(new int[][]{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 3));
        System.out.println(s.searchMatrix(new int[][]{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}}, 13));
    }
}
