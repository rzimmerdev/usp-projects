import sys
import os
import signal
import subprocess


def test_case(program_dir, test_dir, case):
    output = subprocess.check_output(
        f"./{program_dir}/{program_dir}.out < {program_dir}/{test_dir}/{case}.in",
        shell=True
    )
    return output


def handler(signum, frame):
    raise TimeoutError


def main(args, executable_extension="out"):

    program_dir = args[0]
    filename = args[1] if len(args) > 1 else "main.cpp"

    if os.system(f"g++ -o {program_dir}/{program_dir}.{executable_extension} {program_dir}/{filename}") == 0:
        print("Worked")
    else:
        print("Failed")

    test_dir = args[2] if len(args) > 2 else "test_cases"
    total_cases = len(os.listdir(f"{program_dir}/{test_dir}")) // 2

    for case in range(1, total_cases + 1):
        print(f"Test case {case}.in:")
        signal.signal(signal.SIGALRM, handler)
        signal.alarm(1)
        try:
            output = test_case(program_dir, test_dir, case)
            if len(output) > 200:
                print(output[:200], "\n")
            else:
                print(output, "\n")
        except TimeoutError:
            print("timeout...\n")


if __name__ == "__main__":
    if not 1 < len(sys.argv) <= 3:
        raise ValueError("Invalid number of parameters. Please define at least the program directory\n"
                         ">> python3 run.py <program_dir> <filename> <test_dir>")
    main(sys.argv[1:])
