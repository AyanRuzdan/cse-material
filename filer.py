import os
import pandas as pd
from datetime import datetime


def get_files_in_directory():
    directory = os.getcwd()
    notes_data = []
    questions_data = []

    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".md"):
                file_path = os.path.join(root, file)
                file_size = os.path.getsize(file_path)
                relative_path = os.path.relpath(file_path, directory)
                if file_size < 1000:
                    if "Notes" in relative_path:
                        notes_data.append([relative_path[:-3], file_size])
                    elif "Questions" in relative_path:
                        questions_data.append([relative_path[:-3], file_size])

    # Create DataFrames
    notes_df = pd.DataFrame(notes_data, columns=["File Path", "Size (Bytes)"])
    questions_df = pd.DataFrame(questions_data, columns=[
                                "File Path", "Size (Bytes)"])

    # Append timestamp
    timestamp = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    timestamp_df = pd.DataFrame([[timestamp]], columns=["Timestamp"])

    notes_df = pd.concat([notes_df, timestamp_df], ignore_index=True)
    questions_df = pd.concat([questions_df, timestamp_df], ignore_index=True)

    # Save to separate CSV files
    notes_df.sort_values(by=['Size (Bytes)','File Path']).to_csv(
        "notes.csv", index=False, encoding='utf-8')
    questions_df.sort_values(by=['Size (Bytes)','File Path']).to_csv(
        "questions.csv", index=False, encoding='utf-8')

    print(
        f"CSV files saved: notes.csv ({len(notes_data)} entries), questions.csv ({len(questions_data)} entries). Timestamp updated."
    )


get_files_in_directory()
