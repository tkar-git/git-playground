import os
import pytest
from src import plotxy as processor
from pathlib import Path

# Path to the input and output directories
DATA_DIR = Path(__file__).resolve().parent.parent / ".."/"data"
INPUT_DIR = DATA_DIR / "input"
OUTPUT_DIR = DATA_DIR / "output"

# Test input file from the input directory
input_file = INPUT_DIR / "sample.csv"

# Ensure the input file exists for the test
@pytest.fixture(scope="module")
def check_input_file():
    assert input_file.exists(), f"Input file {input_file} does not exist."
    return input_file

# Ensure the output directory exists for saving the plot
@pytest.fixture(scope="module")
def check_output_dir():
    OUTPUT_DIR.mkdir(parents=True, exist_ok=True)
    return OUTPUT_DIR

def test_read_csv(check_input_file):
    x, y = processor.read_csv(check_input_file)
    assert len(x) == 4 and len(y) == 4
    assert x[0] == 1 and y[0] == 2

def test_plot_data(check_input_file, check_output_dir):
    # Prepare the output file path in the output directory
    output_file = check_output_dir / "xy.png"
    x, y = processor.read_csv(check_input_file)
    saved_file = processor.plot_data(x, y, output_file)
    
    # Check that the plot file is created
    assert os.path.exists(saved_file), f"Plot file {saved_file} was not created."
    
    # Optionally print the file path for inspection
    print(f"Plot saved at {saved_file}")