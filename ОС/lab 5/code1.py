import os
import subprocess
import socket

def check_installed_programs():
    os.system('wmic product get name,version')

def check_antivirus_status():
    ps_command = "Get-MpComputerStatus"
    
    try:
        result = subprocess.run(['powershell', '-Command', ps_command], capture_output=True, text=True, check=True)
        output = result.stdout.strip()
        if output:
            print("Antivirus status:")
            print(output)
        else:
            print("No antivirus information found.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while checking antivirus status: {e}")

def check_spyware():
    ps_command = "Start-MpScan -ScanType FullScan"
    
    try:
        result = subprocess.run(['powershell', '-Command', ps_command], capture_output=True, text=True, check=True)
        output = result.stdout.strip()
        print("Spyware scan initiated. Check Windows Defender for detailed results.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while starting spyware scan: {e}")

def check_encryption_status():
    ps_command = "Get-BitLockerVolume"
    
    try:
        result = subprocess.run(['powershell', '-Command', ps_command], capture_output=True, text=True, check=True)
        output = result.stdout.strip()
        if output:
            print("BitLocker encryption status:")
            print(output)
        else:
            print("No BitLocker volumes found.")
    except subprocess.CalledProcessError as e:
        print(f"An error occurred while checking BitLocker status: {e}")

def check_backup_system():
    backup_path = os.getenv('SystemRoot') + '\\System32\\sdclt.exe'
    
    if os.path.isfile(backup_path):
        print("Backup system is available.")
    else:
        print("Backup system is not available.")

def check_network_connection():
    try:
        socket.create_connection(("8.8.8.8", 53), timeout=5)
        print("Network connection is active.")
    except OSError:
        print("Network connection is inactive.")

def check_firewall():
    os.system('netsh advfirewall show allprofiles')

def check_auto_updates():
    os.system('reg query HKEY_LOCAL_MACHINE\Software\Policies\Microsoft\Windows\WindowsUpdate\AU /v AUOpitons')

def check_os_version():
    subprocess.call('systeminfo | findstr /B /C:"OS Name" /C:"OS Version"', shell=True)

def check_security_updates():
    os.system('powershell Get-Hotfix')

def check_uac_config():
    os.system('reg query HKEY_LOCAL_MACHINE\Software\Microsoft\Windows\CurrentVersion\Policies\System /v EnableLUA')

if __name__ == "__main__":
    print("Checking antivirus status...")
    check_antivirus_status()
    print("\nChecking spyware...")
    check_spyware()
    # print("\nChecking encryption status...")
    # check_encryption_status()
    # print("\nChecking backup status...")
    # check_backup_system()
    # print("\nChecking network connection...")
    # check_network_connection()
    # print("\nChecking installed programs...")
    # check_installed_programs()
    # check_backup_system()
    # print("\nChecking firewall...")
    # check_firewall()
    # print("\nChecking auto updates...")
    # check_auto_updates()
    # print("\nChecking os versions...")
    # check_os_version()
    # print("\nChecking security updates...")
    # check_security_updates()
    # print("\nChecking uac configuration...")
    # check_uac_config()