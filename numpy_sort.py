import numpy as np
import time

def read_input_file(filename):
    try:
        with open(filename, 'r') as file:
            numbers = [float(num) for num in file.readline().strip().split()]
            return numbers
    except FileNotFoundError:
        print("File not found.")
        return None

def sort_and_measure_time(numbers):
    if numbers is None:
        return
    start_time = time.time()
    sorted_numbers = np.sort(numbers)
    end_time = time.time()
    return sorted_numbers, end_time - start_time

def main():
    filename = "testcase/testcase_10.input"
    numbers = read_input_file(filename)
    if numbers:
        sorted_numbers, time_taken = sort_and_measure_time(numbers)
        print("Time taken to sort:", time_taken, "seconds")

if __name__ == "__main__":
    main()