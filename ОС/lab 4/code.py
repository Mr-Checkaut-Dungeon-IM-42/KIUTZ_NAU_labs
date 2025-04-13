import subprocess

# Функція для виведення всіх запущених процесів
def print_running_processes():
    command = 'tasklist'
    # command = 'ps aux' # for linux
    result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    if result.returncode == 0:
        print("Запущені процеси:")
        print(result.stdout)
    else:
        print("Помилка при виведенні процесів:", result.stderr)

sites = {
    "кіту нау": "kiutz.nau.edu.ua",
    "гіт хаб": "git.hub",
    "гугл": "google.com",
    "лінкедін": "linkedin.com",
}
# Основна програма
if __name__ == "__main__":
    print_running_processes()

    # Запуск пінгування сайту коледжу
    while True:
        print("Введіть назву сайту для пінгування ('q' для виходу), або оберіть один із запропонованих нижче:")
        for site in sites:
            print(f'\t{site}')

        website_input = input("Сайт: ")
        
        if website_input.lower() == 'q':
            break
        elif website_input in sites:
            website = sites[website_input]
        else:
            website = website_input
        
        command = f'ping {website}'
        result = subprocess.run(command, text=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if result.returncode == 0:
            print(f"Пінгування сайту {website} успішне:")
            print(result.stdout)
        else:
            print(f"Помилка при пінгуванні сайту {website}:", result.stderr)
