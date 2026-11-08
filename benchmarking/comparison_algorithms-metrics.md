# Algorithmic Efficiency Comparison

## Environment
- Compiler: GCC
- Compilation flags: `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`
- Array size: 50000
- Number of executions: 3

## Execution Results

### Run 1
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.488913 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000097 seconds
```

### Run 2
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.487501 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000097 seconds
```

### Run 3
```text
Naive algorithm result: 625025000
Naive algorithm time: 2.486187 seconds
Single-pass algorithm result: 25000
Single-pass algorithm time: 0.000099 seconds
```

## Average Execution Times

- Naive algorithm average: 2.487534 seconds
- Single-pass algorithm average: 0.000098 seconds

## Relative Performance

The naive implementation is approximately 25383.00 times slower than the single-pass implementation, based on the average measured execution times.

## Conclusion

Both implementations solve the same problem and should produce the same result. The measurements demonstrate the performance difference between the two approaches.
