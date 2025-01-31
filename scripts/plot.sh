SRC_DIR="./src"
PLOT_DIR="./plot"

# 1. Compile the C code
echo "Compiling C code..."
gcc -static -Wall -Wextra $SRC_DIR/*.c -o $SRC_DIR/a.out -lm

if [ $? -eq 0 ]; then
    echo "C code compiled successfully!"
else
    echo "Compilation failed!"
    exit 1
fi

# 2. Execute the compiled C code
echo "Executing C code..."
$SRC_DIR/a.out

# 3. Execute the Python script
echo "Executing Python script..."
python3 $PLOT_DIR/plot.py

echo "Process completed."
