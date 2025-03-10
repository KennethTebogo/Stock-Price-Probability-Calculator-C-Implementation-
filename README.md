# Stock Price Probability Calculator (C Implementation)

This C program calculates the probability that a stock price will be higher after **M** weeks, assuming a **lognormal price evolution**. The calculation is based on the mean growth rate (μ), volatility (σ), and the number of weeks (M).

## Features
- Computes the **Z-score** for stock price movement.
- Uses a **manual approximation of the error function (erf)** to compute the **normal cumulative distribution function (CDF)**.
- Accepts user input for **μ (mean growth rate)**, **σ (volatility)**, and **M (weeks).**
- Outputs the computed **Z-score** and probability.

## Requirements
- GCC or any C compiler supporting `math.h` functions.

## Project Structure
```
stock-price-probability/
│
├── stock_price_probability.c
├── README.md
```

## Installation
Clone the repository and navigate to the project directory:

```sh
git clone https://github.com/yourusername/stock-price-probability.git
cd stock-price-probability
```

## Compilation and Execution
1. **Compile the program:**
   ```sh
   gcc stock_price_probability.c -o stock_price_probability -lm
   ```
   *(The `-lm` flag links the math library required for `exp()` and `sqrt()` functions.)*

2. **Run the program:**
   ```sh
   ./stock_price_probability
   ```

## Example Usage
```
Enter the value of Mu μ: 0.0165
Enter the value of Sigma σ: 0.073
Enter the number of Weeks: 2
Z-score: 0.238843
Probability P(F(M) > F(0)): 0.594428
```

## How It Works
- The program calculates the **Z-score** using:
  ```c
  Z = sqrt(M) * (μ / σ);
  ```
- The **normal CDF** is computed manually using the error function approximation:
  ```c
  Φ(x) = 0.5 * (1 + erf(x / sqrt(2)));
  ```

## License
This project is open-source and available under the [MIT License](LICENSE).

---

### Contributing
Feel free to fork the repository and submit pull requests with improvements or bug fixes!

### Author
[Kenneth Tebogo](https://github.com/KennethTebogo)

