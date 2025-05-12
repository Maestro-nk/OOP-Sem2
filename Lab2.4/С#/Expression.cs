using System;

namespace MathLibrary
{
    public class NegativeLogarithmException : Exception
    {
        public NegativeLogarithmException()
            : base("Attempt to calculate logarithm of non-positive number") { }
    }

    public class Expression
    {
        private double a;
        private double b;
        private double c;

        public Expression(double a, double b, double c)
        {
            this.a = a;
            this.b = b;
            this.c = c;
        }

        public double A
        {
            get { return a; }
            set { a = value; }
        }

        public double B
        {
            get { return b; }
            set { b = value; }
        }

        public double C
        {
            get { return c; }
            set { c = value; }
        }

        public double CalculateLogarithm(double value)
        {
            if (value <= 0)
            {
                throw new NegativeLogarithmException();
            }
            return Math.Log(value);
        }

        public double Calculate()
        {
            try
            {
                double logResult = CalculateLogarithm(a);
                return (logResult + b) / c;
            }
            catch (NegativeLogarithmException)
            {
                throw; // Перебрасываем исключение дальше
            }
        }
    }
}