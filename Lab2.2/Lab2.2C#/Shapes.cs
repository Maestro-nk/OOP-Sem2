using System;

namespace ShapesLibrary
{
    public abstract class Shape
    {
        public abstract double CalculateArea();
        public abstract double CalculatePerimeter();
        public abstract string GetName();
    }

    public class Square : Shape
    {
        private double x1, y1, x2, y2, x3, y3, x4, y4;

        public Square(double x1, double y1, double x2, double y2,
                     double x3, double y3, double x4, double y4)
        {
            this.x1 = x1; this.y1 = y1;
            this.x2 = x2; this.y2 = y2;
            this.x3 = x3; this.y3 = y3;
            this.x4 = x4; this.y4 = y4;
        }

        public override double CalculateArea()
        {
            double side = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
            return side * side;
        }

        public override double CalculatePerimeter()
        {
            double side = Math.Sqrt(Math.Pow(x2 - x1, 2) + Math.Pow(y2 - y1, 2));
            return 4 * side;
        }

        public override string GetName()
        {
            return "Square";
        }
    }

    public class Circle : Shape
    {
        private double radius;

        public Circle(double radius)
        {
            if (radius <= 0)
                throw new ArgumentException("Radius must be positive");

            this.radius = radius;
        }

        public override double CalculateArea()
        {
            return Math.PI * radius * radius;
        }

        public override double CalculatePerimeter()
        {
            return 2 * Math.PI * radius;
        }

        public override string GetName()
        {
            return "Circle";
        }
    }
}