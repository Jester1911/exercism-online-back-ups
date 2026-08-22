public static class PythagoreanTriplet
{
    public static IEnumerable<(int a, int b, int c)> TripletsWithSum(int sum)
    {
        //var candidate = (a: 1, b: 2, c: 3);

        for (var i = 1; i < sum / 3; i++)
        {
            for (var j = i + 1; j < sum / 2; j++)
            {
                if (i + j >= sum)
                {
                    break;
                }

                var c = sum - i - j;
                if (j >= c)
                {
                    continue;
                }

                if (DoesSatisfySum((i, j, c), sum) && DoesSatisfyPythagorean((i, j, c)))
                {
                    yield return (i, j, c);
                }
            }
        }
    }

    public static bool DoesSatisfyPythagorean((int a, int b, int c) triplet) =>
        triplet.a * triplet.a + triplet.b * triplet.b == triplet.c * triplet.c;

    public static bool DoesSatisfySum((int a, int b, int c) triplet, int targetSum) =>
        triplet.a + triplet.b + triplet.c == targetSum;
}