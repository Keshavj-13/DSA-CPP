# converter_script.py
import os

def convert_cpp_to_txt():
    """
    Finds all .cpp files in the current directory and converts them to .txt files.
    """
    # Get the current directory path
    current_directory = os.getcwd()
    
    print(f"Searching for .cpp files in: {current_directory}\n")
    
    # List all files in the directory
    for filename in os.listdir(current_directory):
        # Check if the file has a .cpp extension
        if filename.endswith(".cpp"):
            # Create the full path to the C++ file
            cpp_filepath = os.path.join(current_directory, filename)
            
            # Create the new .txt filename by replacing the extension
            base_name = os.path.splitext(filename)[0]
            txt_filename = f"{base_name}.txt"
            txt_filepath = os.path.join(current_directory, txt_filename)
            
            try:
                # Read the content from the .cpp file
                with open(cpp_filepath, 'r', encoding='utf-8') as cpp_file:
                    content = cpp_file.read()
                
                # Write the same content to the new .txt file
                with open(txt_filepath, 'w', encoding='utf-8') as txt_file:
                    txt_file.write(content)
                
                print(f"Successfully converted '{filename}' to '{txt_filename}'")
                
            except Exception as e:
                print(f"Error converting '{filename}': {e}")

if __name__ == "__main__":
    convert_cpp_to_txt()
    print("\nConversion process finished.")