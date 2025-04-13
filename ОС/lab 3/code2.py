import os
import shutil

class DirectoryManager:
    def __init__(self, main_directory):
        self.main_directory = main_directory

    def create_directories(self):
        try:
            # Створення каталогу А1
            os.mkdir(self.main_directory)
            os.chdir(self.main_directory)
            
            # Створення каталогу B1
            os.mkdir('B1')
            os.chdir(os.path.join(self.main_directory, 'B1'))
            
            # Створення каталогу C1 та C2
            os.mkdir('C1')
            os.mkdir('C2')
            
            print("Каталоги успішно створені.")
            
        except OSError:
            print("Помилка: Створення каталогів неможливе.")

    def copy_files(self):
        try:
            # Копіювання двох довільних файлів з SYSTEM32 у каталог С1
            system32_path = os.path.join(os.environ['SystemRoot'], 'System32')
            files_to_copy = ['notepad.exe', 'calc.exe']  # довільні файли
            for file in files_to_copy:
                source = os.path.join(system32_path, file)
                destination = os.path.join(self.main_directory, 'B1', 'C1', file)
                shutil.copyfile(source, destination)
            
            # Створення копій файлів з розширенням .ВАК у каталозі С2
            for file in files_to_copy:
                source = os.path.join(self.main_directory, 'B1', 'C1', file)
                destination = os.path.join(self.main_directory, 'B1', 'C2', os.path.splitext(file)[0] + '.ВАК')
                shutil.copyfile(source, destination)

            # Копіювання виконуваних файлів оболонки FAR у каталог B1
            far_directories = ['/usr/bin', '/usr/local/bin', '/opt/far']  
            for dir_path in far_directories:
                if os.path.isdir(dir_path):
                    far_files = [file for file in os.listdir(dir_path) if file.startswith('far') and file.endswith('.exe')]
                    for far_file in far_files:
                        source_far = os.path.join(dir_path, far_file)
                        destination_far = os.path.join(self.main_directory, 'B1', far_file)
                        shutil.copyfile(source_far, destination_far)

            print("Файли успішно скопійовано.")
            
        except OSError as e:
            print(f"Помилка: {e}")

    def create_command_file(self, file_path):
        try:
            # Відкриваємо файл для запису
            with open(file_path, 'w') as file:
                # Записуємо послідовність команд у файл
                file.write('@echo off\n')  # Вимикаємо виведення команд у командному вікні
                file.write('cls\n')         # Очищаємо екран командного вікна
                file.write('prompt $T$H$H\n')  # Змінюємо вигляд запрошення командного рядка
                file.write(f'start /B notepad.exe "{file_path}"\n')  # Відкриваємо файл у фоновому режимі
            print("Файл команд створено успішно.")
        except Exception as e:
            print(f"Помилка при створенні файлу команд: {e}")

    def remove_directories(self):
        try:
            # Видалення головної директорії та її вмісту
            shutil.rmtree(self.main_directory)
            print(f"Директорія {self.main_directory} та її вміст були успішно видалені.")
        except Exception as e:
            print(f"Помилка при видаленні директорії {self.main_directory}: {e}")

# Створення екземпляру класу DirectoryManager
directory_manager = DirectoryManager('D:\\A1')

# Виклик методів для створення каталогів, копіювання файлів, створення файлу команд та видалення директорій
directory_manager.create_directories()
directory_manager.copy_files()

# Шлях до файлу команд
command_file_path = 'D:\\A1\\commands.bat'

# Викликаємо метод для створення файлу команд
directory_manager.create_command_file(command_file_path)

# Виклик методу для видалення директорій
directory_manager.remove_directories()