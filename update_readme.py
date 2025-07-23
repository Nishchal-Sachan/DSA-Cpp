import os
import re

def count_cpp_files(base_dir):
    total = 0
    for folder in os.listdir(base_dir):
        folder_path = os.path.join(base_dir, folder)
        if os.path.isdir(folder_path) and folder not in [".git", ".github"]:
            cpp_files = [f for f in os.listdir(folder_path) if f.endswith(".cpp")]
            total += len(cpp_files)
    return total

def update_readme(readme_path, new_count):
    with open(readme_path, 'r', encoding='utf-8') as f:
        content = f.read()

    # Update badge
    updated_content = re.sub(
        r'Problems%20Solved-\d+',
        f'Problems%20Solved-{new_count}',
        content
    )

    # Update text version
    updated_content = re.sub(
        r'Total Problems Solved:\*\* `\d+\+`',
        f'Total Problems Solved:** `{new_count}+`',
        updated_content
    )

    with open(readme_path, 'w', encoding='utf-8') as f:
        f.write(updated_content)

if __name__ == "__main__":
    base_dir = '.'  # current directory
    total = count_cpp_files(base_dir)
    update_readme("README.md", total)
    print(f"✅ Updated README with {total} problems solved.")
