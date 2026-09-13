using System.Runtime;

public static class SaddlePoints
{
    public static IEnumerable<(int, int)> Calculate(int[,] matrix)
    {
        // Rule: Want biggest in row, smallest in column
        // [row, column]
        // Not a square matrix, so cannot run diagonals.
        
        List<(int,int)> largestInRowCoords = [];
        List<(int,int)> smallestInColumnCoords = [];

        // Row traversal
        for (int r = 0; r < matrix.GetLength(0); r++)
        {
            var largest = LargestValueInRow(matrix, r);
            for (int c = 0; c < matrix.GetLength(1); c++)
            {
                if (matrix[r, c] == largest)
                {
                    largestInRowCoords.Add((r + 1,c + 1));
                }
            }
        }
        
        // Column traversal
        for (int c = 0; c < matrix.GetLength(1); c++)
        {
            var smallest = SmallestValueInColumn(matrix, c);
            for (int r = 0; r < matrix.GetLength(0); r++)
            {
                if (matrix[r, c] == smallest)
                {
                    smallestInColumnCoords.Add((r + 1, c + 1));
                }
            }
        }
        
        var saddlePoints = largestInRowCoords.ToArray().Intersect(smallestInColumnCoords.ToArray()).ToArray();
        
        foreach (var coord in largestInRowCoords)
        {
            Console.WriteLine("");
            Console.Write("Largest:"  + coord + "    ");
        }
        
        foreach (var coord in smallestInColumnCoords)
        {
            Console.WriteLine("");
            Console.Write("Smallest:"  + coord + "    ");
        }
        
        return saddlePoints;
    }

    private static int SmallestValueInColumn(int[,]matrix, int c)
    {
        int smallest = matrix[0, c];
        for (int r = 0; r < matrix.GetLength(0); r++)
        {
            if (matrix[r, c] < smallest)
            {
                smallest = matrix[r, c];
            }
        }
        return smallest;
    }

    private static int LargestValueInRow(int[,] matrix, int r)
    {
        int largest = matrix[r, 0];
        for (int c = 0; c < matrix.GetLength(1); c++)
        {
            if (matrix[r, c] > largest)
            {
                largest = matrix[r, c];
            }
        }
        return largest;
    }
}
