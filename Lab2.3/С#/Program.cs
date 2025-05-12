class Program
{
    static void Main()
    {
        var container = new TextContainer();
        int choice;

        do
        {
            DisplayMenu();
            int.TryParse(Console.ReadLine(), out choice);

            switch (choice)
            {
                case 1:
                    AddLine(container);
                    break;
                case 2:
                    RemoveLine(container);
                    break;
                case 3:
                    container.Clear();
                    Console.WriteLine("All lines have been deleted.");
                    break;
                case 4:
                    container.CapitalizeAllFirstLetters();
                    Console.WriteLine("First letters have been capitalized.");
                    break;
                case 5:
                    Console.WriteLine($"Key: {container.GenerateKeyFromFirstLetters()}");
                    break;
                case 6:
                    CountLinesOfLength(container);
                    break;
                case 7:
                    container.DisplayAllLines();
                    break;
                case 8:
                    Console.WriteLine("Exiting...");
                    break;
                default:
                    Console.WriteLine("Invalid choice!");
                    break;
            }

            Console.WriteLine("Press Enter to continue...");
            Console.ReadLine();
            Console.Clear();

        } while (choice != 8);
    }

    static void DisplayMenu()
    {
        Console.WriteLine("=== Text Container ===");
        Console.WriteLine("1. Add line");
        Console.WriteLine("2. Remove line");
        Console.WriteLine("3. Clear container");
        Console.WriteLine("4. Capitalize first letters");
        Console.WriteLine("5. Generate key from first letters");
        Console.WriteLine("6. Count lines of specified length");
        Console.WriteLine("7. Show all lines");
        Console.WriteLine("8. Exit");
        Console.Write("Choose an action: ");
    }

    static void AddLine(TextContainer container)
    {
        Console.Write("Enter a line: ");
        var line = Console.ReadLine();
        container.AddLine(new StringLine(line));
        Console.WriteLine("Line added.");
    }

    static void RemoveLine(TextContainer container)
    {
        container.DisplayAllLines();
        Console.Write("Enter line index to remove: ");
        if (int.TryParse(Console.ReadLine(), out int index))
        {
            container.RemoveLine(index);
            Console.WriteLine("Line removed.");
        }
        else
        {
            Console.WriteLine("Invalid index!");
        }
    }

    static void CountLinesOfLength(TextContainer container)
    {
        Console.Write("Enter line length: ");
        if (int.TryParse(Console.ReadLine(), out int length))
        {
            var count = container.CountLinesOfLength(length);
            Console.WriteLine($"Lines found: {count}");
        }
        else
        {
            Console.WriteLine("Invalid length!");
        }
    }
}