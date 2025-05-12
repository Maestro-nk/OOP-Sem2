public class TextContainer : IKeyGenerator
{
    private readonly List<StringLine> lines = new List<StringLine>();

    public void AddLine(StringLine line) => lines.Add(line);

    public void RemoveLine(int index)
    {
        if (index >= 0 && index < lines.Count)
            lines.RemoveAt(index);
    }

    public void Clear() => lines.Clear();

    public string GenerateKeyFromFirstLetters() =>
        string.Join("", lines.Select(line => line.GetKeyFromFirstLetters()));

    public void CapitalizeAllFirstLetters()
    {
        foreach (var line in lines)
        {
            line.CapitalizeFirstLetters();
        }
    }

    public int CountLinesOfLength(int length) =>
        lines.Count(line => line.Text.Length == length);

    public void DisplayAllLines()
    {
        for (int i = 0; i < lines.Count; i++)
        {
            Console.WriteLine($"{i}: {lines[i].Text}");
        }
    }

    public int LineCount => lines.Count;
}