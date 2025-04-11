## Python Example structure
```bash
examples
├── data
│   ├── input
│   │   └── sample.csv
│   └── output
└── python_example
    ├── README.md
    ├── setup.py
    ├── src
    │   ├── __init__.py
    │   └── plotxy.py
    └── tests
        ├── __init__.py
        └── test_plotxy.py
```
## Dependencies
1. python3
2. numpy, matplotlib
3. pytest

## installation
```bash
cd ./examples/python_example
pip install -e .
mkdir -p ../data/output
```
Here `.` should specify the path of the setup.py file

## Running the code
```bash
python3 src/plotxy.py --input ../data/input/sample.csv --output ../data/output/sample.png

pytest tests/test_plotxy.png
```
