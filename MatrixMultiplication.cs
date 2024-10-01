using System;

class MatrixMultiplication
{
    int[,] a;
    int[,] b;
    int[,] c;
    public int m1, n1, m2, n2;

    public void ReadMatrix()
    {
        Console.Write("\n Enter the number of rows for Matrix 1: ");
        m1 = Convert.ToInt32(Console.ReadLine());
        Console.Write(" Enter the number of columns for Matrix 1: ");
        n1 = Convert.ToInt32(Console.ReadLine());
        a = new int[m1, n1];

        Console.Write("\n Enter the number of rows for Matrix 2: ");
        m2 = Convert.ToInt32(Console.ReadLine());
        Console.Write(" Enter the number of columns for Matrix 2: ");
        n2 = Convert.ToInt32(Console.ReadLine());
        b = new int[m2, n2];

        if (n1 != m2)
        {
            Console.WriteLine("Multiplication not possible. The number of columns in Matrix 1 must equal the number of rows in Matrix 2.");
            Environment.Exit(0);
        }
        else
        {
            Console.WriteLine("\n Enter the elements of Matrix 1:");
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    a[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }

            Console.WriteLine("\n Enter the elements of Matrix 2:");
            for (int i = 0; i < m2; i++)
            {
                for (int j = 0; j < n2; j++)
                {
                    b[i, j] = Convert.ToInt32(Console.ReadLine());
                }
            }
        }
    }

    public void MultiplyMatrix()
    {
        c = new int[m1, n2];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                c[i, j] = 0;
                for (int k = 0; k < n1; k++)
                {
                    c[i, j] += a[i, k] * b[k, j];
                }
            }
        }
    }

    public void PrintMatrix()
    {
        Console.WriteLine("\n Resultant Matrix:");
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                Console.Write("\t" + c[i, j]);
            }
            Console.WriteLine();
        }
    }
}

class Matrices
{
    public static void Main()
    {
        MatrixMultiplication MM = new MatrixMultiplication();
        MM.ReadMatrix();
        MM.MultiplyMatrix();
        MM.PrintMatrix();
    }
}
