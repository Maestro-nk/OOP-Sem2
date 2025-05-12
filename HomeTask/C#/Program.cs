using System;

class CharMatrix
{
    private char[,] matrix;
    private int vowelCount;

    public CharMatrix(int rows, int cols)
    {
        matrix = new char[rows, cols];
        vowelCount = 0;
    }

    public string this[int diagonal]
    {
        get
        {
            if (diagonal != 0 && diagonal != 1)
                throw new IndexOutOfRangeException("Diagonal must be 0 (main) or 1 (anti)");

            int size = Math.Min(matrix.GetLength(0), matrix.GetLength(1));
            char[] result = new char[size];

            if (diagonal == 0)
            {
                for (int i = 0; i < size; i++)
                    result[i] = matrix[i, i];
            }
            else
            {
                for (int i = 0; i < size; i++)
                    result[i] = matrix[i, size - 1 - i];
            }

            return new string(result);
        }
    }

    public int VowelCount
    {
        get { return vowelCount; }
    }

    public void FillMatrix()
    {
        Random rnd = new Random();
        for (int i = 0; i < matrix.GetLength(0); i++)
        {
            for (int j = 0; j < matrix.GetLength(1); j++)
            {
                matrix[i, j] = (char)rnd.Next('a', 'z' + 1);
                if (IsVowel(matrix[i, j]))
                    vowelCount++;
            }
        }
    }

    private bool IsVowel(char c)
    {
        char lower = char.ToLower(c);
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }
}

class Program
{
    static void Main(string[] args)
    {
        CharMatrix cm = new CharMatrix(5, 5);
        cm.FillMatrix();

        Console.WriteLine("Main diagonal: " + cm[0]);
        Console.WriteLine("Anti diagonal: " + cm[1]);
        Console.WriteLine("Vowel count: " + cm.VowelCount);
    }
}