import numpy as np
import matplotlib.pyplot as plt
from pathlib import Path
import argparse

# Set up the data and output paths
DATA_DIR = Path(__file__).resolve().parent.parent / ".." / "data"
csv_file = DATA_DIR / "input/sample.csv"
out_file = DATA_DIR / "output/xy.png"

def read_csv(file_path):
    """Reads a CSV file and returns x and y columns."""
    data = np.genfromtxt(file_path, delimiter=",", skip_header=1)
    return data[:, 0], data[:, 1]

def plot_data(x, y, out_file):
    """Plots the data and saves the figure."""
    plt.figure()
    plt.plot(x, y, marker="o")
    plt.title("Simple Line Plot")
    plt.xlabel("x")
    plt.ylabel("y")
    plt.savefig(out_file)
    return out_file

def main():
    """Main function to read CSV, plot data, and save output."""
    # Argument parsing for custom paths
    parser = argparse.ArgumentParser(description="Plot data from CSV file.")
    parser.add_argument('--input', type=str, default=csv_file, help="Path to the input CSV file.")
    parser.add_argument('--output', type=str, default=out_file, help="Path to save the output plot.")
    args = parser.parse_args()

    # Read the CSV file
    x, y = read_csv(args.input)
    
    # Plot the data and save to file
    plot_data(x, y, args.output)
    print(f"Plot saved to {args.output}")
    
# ensures that the main() function is 
# only called when the script is executed directly 
# (not when it’s imported as a module).
if __name__ == "__main__":
    main()
