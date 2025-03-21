import os
import pandas as pd
from datetime import datetime


def get_files_in_directory(output_csv):
    directory = os.getcwd()
    file_data = []

    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                file_size = os.path.getsize(file_path)
                x = file_path.split("/")
                z = x[5:]
                z = "/".join(z)
                if file_size == 0:
                    file_data.append([z[:-3], file_size])
    df = pd.DataFrame(file_data, columns=["File Path", "Size (Bytes)"])
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    timestamp_df = pd.DataFrame([[timestamp]], columns=["Timestamp"])
    df = pd.concat([df, timestamp_df], ignore_index=True)
    df.to_csv(output_csv, index=False, encoding='utf-8')
    print(
        f"CSV file saved at: {output_csv} with {len(file_data)} new entries. Timestamp updated.")


output_csv_file = "file_list.csv"
get_files_in_directory(output_csv_file)
