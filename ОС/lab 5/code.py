import os
import subprocess
import platform

# 1 Виконано у графічному інтерфейсі Microsoft Security

# 3
def check_bitlocker_status():
    try:
        # Виконання команди для перевірки статусу BitLocker
        result = subprocess.run(['manage-bde', '-status'], capture_output=True, text=True)
        
        # Перевірка наявності шифрування BitLocker
        if "Fully Encrypted" in result.stdout:
            print("BitLocker encryption is enabled.")
            return True
        else:
            print("BitLocker encryption is not enabled.")
            return False
    except FileNotFoundError:
        print("manage-bde tool is not found. BitLocker might not be available.")
        return False
    except Exception as e:
        print(f"An error occurred: {e}")
        return False
# Перевірка статусу BitLocker
check_bitlocker_status()

# 4
def check_firewall():
    os.system('netsh advfirewall show allprofiles')
print("Завдання 4", check_firewall())

# 5
def check_auto_updates():
    path = 'HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\WindowsUpdate\AU'
    os.system(f'reg query {path} /v AUOptions')
    subprocess.call(f'reg query {path} /v AUOptions', shell=True)
print("Завдання 5: ", check_auto_updates())

# 6
def check_service_status(service_name):
    try:
        # Виконання команди для перевірки статусу служби
        result = subprocess.run(['sc', 'query', service_name], capture_output=True, text=True)
        
        # Перевірка, чи служба працює
        if "RUNNING" in result.stdout:
            print(f"The service '{service_name}' is running.")
            return True
        else:
            print(f"The service '{service_name}' is not running.")
            return False
    except Exception as e:
        print(f"An error occurred: {e}")
        return False
def check_file_history_status():
    try:
        # Виконання команди для перевірки статусу File History
        result = subprocess.run(['fhmanagew.exe', '-getstatus'], capture_output=True, text=True)
        
        # Перевірка статусу File History
        if "is on" in result.stdout:
            print("File History is on.")
            return True
        else:
            print("File History is off.")
            return False
    except Exception as e:
        print(f"An error occurred: {e}")
        return False
def check_backup_systems():
    wbengine_status = check_service_status('wbengine')
    file_history_status = check_file_history_status()
    
    if wbengine_status or file_history_status:
        print("At least one backup system is active.")
    else:
        print("No backup systems are active.")
# Перевірка наявності системи резервного копіювання
check_backup_systems()

# 7
def get_os_version():
    return platform.platform()
print("Завдання 7. Версія операційної системи: ", get_os_version())

# 8
def check_security_updates():
    os.system('powershell Get-Hotfix')
print("Завдання 8:", check_security_updates())

# 9
def check_uac_config():
    path = "HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\System"
    command = f"reg query {path} /v EnableLUA"
    subprocess.call(command, shell=True)
print("Завдання 9: ")
check_uac_config()

# 10
def check_installed_programs():
    os.system('wmic product get name,version')
    subprocess.call('wmic product get name,version', shell=True)
print("Завдання 10: ", check_installed_programs())

# 11
def check_folder_permissions(path):
    if os.path.exists(path):
        access_rights = oct(os.stat(path).st_mode)[-3:]
        if access_rights == "777":
            print("Маєте повний доступ до файлу чи папки.")
        elif access_rights == "000":
            print("Нема доступу")
        else:
            print("Обмежений доступ")
    else:
        print("Файл чи папку не знайдено.")
print(check_folder_permissions("C:/Users/Ivan/Cookies"))