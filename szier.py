import os
import csv

def get_files_with_size(directory):
    files_data = []
    # Walk through the directory and subdirectories
    for root, dirs, files in os.walk(directory):
        for file in files:
            file_path = os.path.join(root, file)
            file_size = os.path.getsize(file_path)
            files_data.append([file_path, file_size])
    return files_data

def write_to_csv(files_data, output_csv):
    with open(output_csv, mode='w', newline='', encoding='utf-8') as file:
        writer = csv.writer(file)
        writer.writerow(["File Path", "File Size (Bytes)"])
        writer.writerows(files_data)

if __name__ == "__main__":
    directory_to_search = r"C:\Users\user\OneDrive - Datagrokr Analytics Private Limited\Repo\cse-material\Notes"
    output_csv_file = "output_files.csv"
    
    # Get list of files with their sizes
    files_data = get_files_with_size(directory_to_search)
    
    # Write to CSV
    write_to_csv(files_data, output_csv_file)

    print(f"File details written to {output_csv_file}")
