public static class PythagoreanTriplet
{
    public static IEnumerable<(int a, int b, int c)> TripletsWithSum(int sum)
    {
        //var candidate = (a: 1, b: 2, c: 3);

        for (var i = 1; i < sum; i++)
        {
            for (var j = i + 1; j < sum; j++)
            {
                if (i + j >= sum)
                {
                    break;
                }

                for (var k = j + 1; k < sum; k++)
                {
                    if (i + j + k > sum)
                    {
                        break;
                    }

                    if (i < j && j < k)
                    {
                        if (DoesSatisfySum((i, j, k), sum) && DoesSatisfyPythagorean((i, j, k)))
                        {
                            yield return (i, j, k);
                        }
                    }
                }
            }
        }
    }

    public static bool DoesSatisfyPythagorean((int a, int b, int c) triplet) =>
        triplet.a * triplet.a + triplet.b * triplet.b == triplet.c * triplet.c;

    public static bool DoesSatisfySum((int a, int b, int c) triplet, int targetSum) =>
        triplet.a + triplet.b + triplet.c == targetSum;
}