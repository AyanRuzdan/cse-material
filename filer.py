import os
import pandas as pd

def get_files_in_directory(directory, output_csv):
    file_data = []
    
    if not os.path.exists(directory):
        print(f"Error: Directory '{directory}' does not exist.")
        return
    
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                file_size = os.path.getsize(file_path)
                if file_size == 0:
                    file_data.append([file_path, file_size])
    
    if not file_data:
        print("No markdown (.md) files found.")
    else:
        df = pd.DataFrame(file_data, columns=["File Path", "Size (Bytes)"])
        df.to_csv(output_csv, index=False, encoding='utf-8')
        print(f"CSV file saved at: {output_csv} with {len(file_data)} entries.")

# Example usage
directory_to_scan = r"/home/ruzdan/For Ayan/cse-material"
output_csv_file = "file_list.csv"
get_files_in_directory(directory_to_scan, output_csv_file)
