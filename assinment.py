import os
import subprocess

def run_assignment(assignment_no, folder="."):
    output_file = f"LA-{assignment_no}_output.txt"

    with open(output_file, "w", encoding="utf-8") as out_f:
        # find all cpp files for this assignment
        files = [f for f in os.listdir(folder) if f.startswith(f"LA-{assignment_no}_q") and f.endswith(".cpp")]
        files.sort()

        for file in files:
            question_no = file.split("_q")[-1].replace(".cpp", "")
            out_f.write(f"========== Question {question_no} ==========\n\n")

            # write code
            out_f.write("--- Code ---\n")
            with open(os.path.join(folder, file), "r", encoding="utf-8") as code_f:
                for line in code_f:
                    out_f.write(line)
            out_f.write("\n")

            # compile
            exe_file = os.path.join(folder, "temp_exe")
            compile_cmd = ["g++", os.path.join(folder, file), "-o", exe_file]

            try:
                subprocess.run(compile_cmd, check=True, capture_output=True, text=True)

                # run and write output directly
                out_f.write("\n--- Output ---\n")
                result = subprocess.run(exe_file, capture_output=True, text=True, timeout=5)
                out_f.write(result.stdout)
                if result.stderr:
                    out_f.write("\nErrors:\n" + result.stderr)
                out_f.write("\n\n")

            except subprocess.CalledProcessError as e:
                out_f.write("\nCompilation Error:\n")
                out_f.write(e.stderr + "\n\n")
            except subprocess.TimeoutExpired:
                out_f.write("\nRuntime Error: Program took too long.\n\n")
            except Exception as e:
                out_f.write(f"\nError running program: {e}\n\n")

            # remove exe
            if os.path.exists(exe_file):
                os.remove(exe_file)

    print(f"✅ Output saved to {output_file}")


if __name__ == "__main__":
    assignment_no = input("Enter assignment number: ").strip()
    run_assignment(assignment_no)
