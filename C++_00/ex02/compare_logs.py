import difflib
import sys

def compare_logs(file1, file2, output_file):
    with open(file1, 'r') as f1, open(file2, 'r') as f2:
        lines1 = f1.readlines()
        lines2 = f2.readlines()

    lines1 = [line.split('] ', 1)[1] for line in lines1]
    lines2 = [line.split('] ', 1)[1] for line in lines2]

    d = difflib.Differ()
    diff = list(d.compare(lines1, lines2))

    with open(output_file, 'w') as output:
        for line in diff:
            if line.startswith('- ') or line.startswith('+ '):
                output.write(line[2:] + '\n')

if __name__ == "__main__":
    if len(sys.argv) != 4:
        print("Usage: python compare_logs.py log1.txt log2.txt output_diff.txt")
        sys.exit(1)

    file1 = sys.argv[1]
    file2 = sys.argv[2]
    output_file = sys.argv[3]

    compare_logs(file1, file2, output_file)
    print(f"Differences written to {output_file}")
