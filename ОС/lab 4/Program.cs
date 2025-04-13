using System.Diagnostics;

class Program
{
    static void PingWebsite()
    {
        Console.Write("Введіть назву сайту для пінгування: ");
        string website = Console.ReadLine();

        // Створення об'єкту ProcessStartInfo для виконання команди ping
        ProcessStartInfo psi = new ProcessStartInfo
        {
            FileName = "ping",
            Arguments = website,
            RedirectStandardOutput = true,
            UseShellExecute = false
        };

        // Створення процесу для виконання команди ping
        Process p = Process.Start(psi);
        if (p != null)
        {
            // Очікування завершення процесу
            p.WaitForExit();

            // Отримання результатів пінгування
            string output = p.StandardOutput.ReadToEnd();
            Console.WriteLine($"Успішна відправка запиту на адресу {website}:");
            Console.WriteLine(output);
        }
    }

    static void Main(string[] args)
    {
        PingWebsite();

        // Отримати всі поточні процеси
        Process[] processes = Process.GetProcesses();

        // Вивести інформацію про кожен процес
        foreach (Process process in processes)
        {
            Console.WriteLine($"Ідентифікатор: {process.Id}, Назва: {process.ProcessName}");
        }
    }
}