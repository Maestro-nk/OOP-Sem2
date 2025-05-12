public class StringLine
{
    private string text;

    public StringLine(string text)
    {
        this.text = text;
    }

    public string Text => text;

    public string GetKeyFromFirstLetters()
    {
        return string.Join("",
            text.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)
                .Select(word => word.Length > 0 ? word[0].ToString() : ""));
    }

    public void CapitalizeFirstLetters()
    {
        text = string.Join(" ",
            text.Split(' ')
                .Select(word => word.Length > 0
                    ? char.ToUpper(word[0]) + word.Substring(1).ToLower()
                    : ""));
    }
}