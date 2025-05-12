using System;
using ShapesLibrary;

class Program
{
    static void PrintShapeInfo(Shape shape)
    {
        Console.WriteLine($"Shape: {shape.GetName()}");
        Console.WriteLine($"Area: {shape.CalculateArea()}");
        Console.WriteLine($"Perimeter: {shape.CalculatePerimeter()}");
        Console.WriteLine("------------------------");
    }

    static void Main()
    {
        Square square = new Square(0, 0, 2, 0, 2, 2, 0, 2);

        Circle circle = new Circle(3);

        Shape[] shapes = { square, circle };

        foreach (Shape shape in shapes)
        {
            PrintShapeInfo(shape);
        }
    }
}