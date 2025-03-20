import os
import pandas as pd
from datetime import datetime

def get_files_in_directory(output_csv):
    directory = os.getcwd()  # Scan the current working directory (GitHub Actions workspace)
    file_data = []

    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                file_size = os.path.getsize(file_path)
                if file_size == 0:
                    file_data.append([file_path, file_size])

    # Load existing CSV if it exists
    if os.path.exists(output_csv):
        df = pd.read_csv(output_csv)
        # Remove the last row if it contains a timestamp (assumption: timestamp row has only 1 column)
        if df.shape[1] == 1 or "Timestamp" in df.columns:
            df = df.iloc[:-1]  # Drop last row

    else:
        df = pd.DataFrame(columns=["File Path", "Size (Bytes)"])

    # Append new data
    if file_data:
        new_df = pd.DataFrame(file_data, columns=["File Path", "Size (Bytes)"])
        df = pd.concat([df, new_df], ignore_index=True)

    # Append current timestamp
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    timestamp_df = pd.DataFrame([[timestamp]], columns=["Timestamp"])
    df = pd.concat([df, timestamp_df], ignore_index=True)

    # Save the updated CSV
    df.to_csv(output_csv, index=False, encoding='utf-8')
    print(f"CSV file saved at: {output_csv} with {len(file_data)} new entries. Timestamp updated.")

# Example usage
output_csv_file = "file_list.csv"
get_files_in_directory(output_csv_file)

