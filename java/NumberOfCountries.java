import java.util.*;
public class NumberOfCountries {

    public int getKey(int i, int j, int nRows, int nColumns) {
        return i * nColumns + j ;
    }

    public static <T> void printMatrix(T [][] A) {
        int nRows = A.length;
        int nColumns = A[0].length;
        System.out.println("nRows = " + nRows + "  nColumns = " + nColumns);
        for (int i = 0; i < A.length; ++i){
            for (int j = 0; j < A[0].length; ++j) {
                System.out.print(A[i][j] + " ");
            }
            System.out.println();
        }
    }

    public void run() {
    
/*
        Integer [][] A = {{5,4,5},
                      {5,5,2},
                      {2,5,4},
                      {2,2,4}};
        Integer [][]A = {
            {5,4,4},
            {4,3,4},
            {3,2,4},
            {2,2,2},
            {3,3,4},
            {1,4,4},
            {4,1,1}
        };
*/
Integer [] [] A = {
            {3,3,4},
            {3,4,4},
            {2,3,4},
            {4,4,4}
        };
        int nRows = A.length;
        int nColumns = A[0].length;
        System.out.println("nRows = " + nRows + "  nColumns = " + nColumns);
        Character [][] paint =  new Character[nRows][nColumns];

        NumberOfCountries.<Character>printMatrix(paint);
        System.out.println("********");
        NumberOfCountries.<Integer>printMatrix(A);

        int colour = 64;
        for (int i = 0; i < A.length; ++i){
            for (int j = 0; j < A[0].length; ++j) {
                //System.out.print(A[i][j] + " : " + getKey(i,j,nRows,nColumns) + " ") ;
                int key= getKey(i,j,nRows, nColumns);
                if (paint[i][j] == null) {
                    // use next character
                    char newColour = (char)++colour;
                    paint[i][j] = newColour;
                    //updateNeighbours
                    if (i+1 < nRows && A[i+1][j] == A[i][j] && paint[i+1][j] == null) {
                        paint[i+1][j] = newColour;
                    }
                    if (j+1 < nColumns && A[i][j+1] == A[i][j] && paint[i][j+1] == null) {
                        paint[i][j+1] = newColour;
                    }
                    if (i+1 < nRows && j-1 >=0 && A[i+1][j-1] == A[i][j] && A[i][j] == A[i+1][j] && paint[i+1][j-1] == null) {
                        paint[i+1][j-1] = newColour;
                    }
                    if (i+1 < nRows && j+1 < nColumns && A[i+1][j+1] == A[i][j] && A[i][j] == A[i+1][j] && paint[i+1][j+1] == null) {
                        paint[i+1][j+1] = newColour;
                    }
                } else {
                    char newColour = paint[i][j];
                    if (i+1 < nRows && A[i+1][j] == A[i][j] && paint[i+1][j] == null) {
                        paint[i+1][j] = newColour;
                    }
                    if (j+1 < nColumns && A[i][j+1] == A[i][j] && paint[i][j+1] == null) {
                        paint[i][j+1] = newColour;
                    }
                    if (i+1 < nRows && j-1 >=0 && A[i+1][j-1] == A[i][j] && A[i][j] == A[i+1][j] && paint[i+1][j-1] == null) {
                        paint[i+1][j-1] = newColour;
                    }
                    if (i+1 < nRows && j+1 < nColumns && A[i+1][j+1] == A[i][j] && A[i][j] == A[i+1][j] && paint[i+1][j+1] == null) {
                        paint[i+1][j+1] = newColour;
                    }
                }
            }
        }

        for (int i = 0; i < A.length; ++i){
            for (int j = 0; j < A[0].length; ++j) {
                if (j-1 >= 0 && A[i][j] == A[i][j-1] ) {
                    paint[i][j-1] = paint[i][j];
                }
            }
        }

        HashMap<Character,Integer> testMap = new HashMap<Character,Integer>();
        for (int i = 0; i < A.length; ++i){
            for (int j = 0; j < A[0].length; ++j) {
                testMap.put(paint[i][j], 1);
            }
        }

        NumberOfCountries.<Character>printMatrix(paint);

        System.out.printf("Number of countries : %d\n", testMap.size());
    }
    public static void main(String a[]) {
        
        NumberOfCountries noc = new NumberOfCountries();
        noc.run();
    }
}
