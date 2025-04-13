import os
import shutil
from pathlib import Path

# Print current working directory
print("Current working directory:", os.getcwd())

# Create directory structure as specified
def create_directories():
    os.makedirs("Aa/AA", exist_ok=True)
    os.makedirs("Aa/BB/1", exist_ok=True)
    os.makedirs("Aa/BB/2", exist_ok=True)
    print("Directories created")

# Copy files as specified
def copy_files():
    src_system32 = Path("C:\\Windows\\System32")
    src_windows = Path("C:\\Windows")
    dst_A1 = Path("Aa/A1")
    dst_AA = Path("Aa/AA")
    dst_BB = Path("Aa/BB")

    dst_A1.mkdir(parents=True, exist_ok=True)

    # Copy 2 arbitrary files from SYSTEM32 to Aa/A1
    system32_files = list(src_system32.iterdir())
    copied_files = 0
    for file in system32_files:
        if copied_files >= 2:
            break
        try:
            shutil.copy(file, dst_A1)
            copied_files += 1
        except PermissionError:
            continue

    # Copy 3 arbitrary executable files from WINDOWS to Aa/AA
    windows_files = [f for f in src_windows.iterdir() if f.suffix == '.exe']
    copied_files = 0
    for file in windows_files:
        if copied_files >= 3:
            break
        try:
            shutil.copy(file, dst_AA)
            copied_files += 1
        except PermissionError:
            continue

    # Copy files from SYSTEM32 to Aa/BB with names not more than 5 characters and starting with 'X'
    for file in system32_files:
        if len(file.stem) <= 5 and file.stem.lower().startswith('x'):
            try:
                shutil.copy(file, dst_BB)
            except PermissionError:
                continue
    print("Files copied")

# Create text files with schedule and concatenate them
def create_and_concatenate_text_files():
    schedule_wednesday = "Math: 9:00-10:30\nPhysics: 11:00-12:30\n"
    schedule_thursday = "Chemistry: 9:00-10:30\nBiology: 11:00-12:30\n"

    with open("Aa/BB/1/schedule_wednesday.txt", "w") as file:
        file.write(schedule_wednesday)
    
    with open("Aa/BB/1/schedule_thursday.txt", "w") as file:
        file.write(schedule_thursday)

    with open("Aa/BB/2/combined_schedule.txt", "w") as outfile:
        with open("Aa/BB/1/schedule_wednesday.txt") as infile:
            outfile.write(infile.read())
        with open("Aa/BB/1/schedule_thursday.txt") as infile:
            outfile.write(infile.read())

    print("Text files created and concatenated")

# View the directory tree structure
def view_directory_tree(root_dir):
    for root, dirs, files in os.walk(root_dir):
        level = root.replace(root_dir, '').count(os.sep)
        indent = ' ' * 4 * (level)
        print('{}{}/'.format(indent, os.path.basename(root)))
        subindent = ' ' * 4 * (level + 1)
        for f in files:
            print('{}{}'.format(subindent, f))

# Clean up created directories and files
def clean_up(root_dir):
    shutil.rmtree(root_dir, ignore_errors=True)
    print("Directories and files cleaned up")

# Create the required directories
create_directories()

# Copy the specified files
copy_files()

# Create and concatenate the text files
create_and_concatenate_text_files()

# View the directory tree
print("Directory tree before cleanup:")
view_directory_tree("Aa")

# Clean up the created files and directories
clean_up("Aa")
