using System;
using MathLibrary;

class Program
{
    static void Main()
    {
        Expression[] expressions = new Expression[]
        {
            new Expression(1, 2, 3),
            new Expression(4, 5, 6),
            new Expression(-1, 2, 3) // Это вызовет исключение
        };

        for (int i = 0; i < expressions.Length; i++)
        {
            try
            {
                double result = expressions[i].Calculate();
                Console.WriteLine($"Expression {i + 1}: " +
                    $"(ln({expressions[i].A}) + {expressions[i].B}) / " +
                    $"{expressions[i].C} = {result}");
            }
            catch (NegativeLogarithmException e)
            {
                Console.WriteLine($"Error in expression {i + 1}: {e.Message}");
            }
        }

        // Взаимодействие с пользователем
        try
        {
            Console.WriteLine("\nEnter values for a new expression (a b c):");
            double a = double.Parse(Console.ReadLine());
            double b = double.Parse(Console.ReadLine());
            double c = double.Parse(Console.ReadLine());

            Expression userExpr = new Expression(a, b, c);
            try
            {
                double result = userExpr.Calculate();
                Console.WriteLine($"Result: {result}");
            }
            catch (NegativeLogarithmException e)
            {
                Console.WriteLine($"Calculation error: {e.Message}");
            }
        }
        catch (FormatException)
        {
            Console.WriteLine("Invalid input format. Please enter numbers.");
        }
        catch (Exception e)
        {
            Console.WriteLine($"Unexpected error: {e.Message}");
        }
    }
}