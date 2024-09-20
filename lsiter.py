import os

def list_txt_and_srt_files(folder_path):
    # List to store the file paths
    file_list = []

    # Walk through the directory recursively
    for dirpath, dirnames, filenames in os.walk(folder_path):
        for file in filenames:
            # Check if the file ends with .txt or .srt
            if file.endswith('.md'): 
                file_list.append(os.path.join(dirpath, file))
    
    return file_list

# Specify the folder path
folder_path = r'C:\Users\user\OneDrive - Datagrokr Analytics Private Limited\Repo\cse-material'

# Get the list of files
files = list_txt_and_srt_files(folder_path)
file1 = open("LIST.txt", "w")
for file in files:
    file1.write(os.path.basename(file)[:-3]+"\n")

file1.close()