import os
import shutil

# Визначаємо шлях до домашньої папки користувача
home_dir = os.path.expanduser("~")

# 1. Створити каталоги AS та AT
as_dir = os.path.join(home_dir, "AS")
at_dir = os.path.join(home_dir, "AT")
os.makedirs(as_dir, exist_ok=True)
os.makedirs(at_dir, exist_ok=True)

# В каталозі AS створити каталог AS1, а в ньому – підкаталоги 1 та 2
as1_dir = os.path.join(as_dir, "AS1")
os.makedirs(as1_dir, exist_ok=True)
os.makedirs(os.path.join(as1_dir, "1"), exist_ok=True)
os.makedirs(os.path.join(as1_dir, "2"), exist_ok=True)

source_dir = "D:/subject"  # Змініть шлях до каталогу subject відповідно до вашого середовища

def copy_files(N, DIRECTORY):
    """Скопіювати файли з папки не довше н символів """
    for filename in os.listdir(source_dir):
        if len(os.path.splitext(filename)[0]) <= N and os.path.isfile(os.path.join(source_dir, filename)):
            shutil.copy(os.path.join(source_dir, filename), DIRECTORY)

# 2. Скопіювати файли з каталогу subject з іменами, які містять не більше 3 символів, в каталог AS
copy_files(3, as_dir)

# Скопіювати текстові файли з каталогу subject з іменами, які містять не більше 4 символів, в каталог AT
copy_files(4, at_dir)

# 3. Копіювання файлів з AT в AS1 та їх перейменування.
at_dir = os.path.join(os.path.expanduser("~"), "AT")
as1_dir = os.path.join(os.path.expanduser("~"), "AS", "AS1")

# Створення каталогу AS1, якщо його не існує
os.makedirs(as1_dir, exist_ok=True)

# Копіювання і перейменування файлів
for filename in os.listdir(at_dir):
    source_path = os.path.join(at_dir, filename)
    dest_path = os.path.join(as1_dir, "renamed_" + filename)  # Перейменований файл
    shutil.copy(source_path, dest_path)

    
# Шлях до каталогу AS1
as1_dir = os.path.join(os.path.expanduser("~"), "AS", "AS1", "1")

# Створення текстового файлу з номером версії Windows
windows_version = os.environ.get('OS', '')
version_file_path = os.path.join(as1_dir, "windows_version.txt")
with open(version_file_path, 'w') as file:
    file.write(windows_version)


def delete_directories(directories):
    for directory in directories:
        if os.path.exists(directory):
            try:
                shutil.rmtree(directory)
                print(f"Каталог {directory} та його вміст були успішно видалені.")
            except Exception as e:
                print(f"Помилка при спробі видалити каталог {directory}: {e}")
        else:
            print(f"Каталог {directory} не існує.")

folders_to_delete = ["AS/AS1", "AS" , "AT"]
delete_directories(folders_to_delete)

print("Операція завершена.")