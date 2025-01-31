# Taylor Series Approximation of Elementary Functions in C

This project implements **sine**, **cosine**, **exponential**, and **square root** functions using **Taylor series expansion** in **C**. The computed values are compared against **C's built-in math functions**, and the errors are visualized using **Matplotlib** in Python.

## Running:

In the terminal, set execute permission for the shell script.

```bash 
chmod +x scripts/plot.sh
```

Then, run it with the following command:

```bash
./scripts/plot.sh
```

This will:
1. Compile the C code.
2. Execute the compiled C program.
3. Run the Python script to generate error plots.