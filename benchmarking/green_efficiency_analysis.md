# Green Tech Efficiency Analysis

## Measurement Methodology

The experiments used C programs compiled with GCC and the required flags: `-Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-long-long`. Execution time was measured using the programs' `clock()` calls and converted into seconds using `CLOCKS_PER_SEC`. This provides CPU execution-time measurements rather than direct measurements of electrical energy.

In Task 0, the baseline program executed 100,000,000 iterations three consecutive times. The measured execution times were 0.205157, 0.205114, and 0.205427 seconds. Their average was approximately 0.205233 seconds.

In Task 1, the comparison program was executed three times using an array of 50,000 integers. Both implementations were timed separately in each run. The naive implementation recorded 2.488913, 2.487501, and 2.486187 seconds. The single-pass implementation recorded 0.000097, 0.000097, and 0.000099 seconds. The corresponding averages were approximately 2.487534 and 0.000098 seconds.

In Task 2, timing instrumentation was added around dataset construction, processing, and checksum reduction. The recorded output was: TOTAL 0.000740 seconds, BUILD_DATA 0.000310 seconds, PROCESS 0.000291 seconds, and REDUCE 0.000134 seconds. The total measurement covered all three phases.

## Observed Performance Differences

The baseline measurements were close: the difference between the fastest and slowest runs was 0.000313 seconds. This shows limited variation across these three executions in the recorded environment.

The largest measured difference appeared in Task 1. The naive implementation averaged approximately 2.487534 seconds, while the single-pass implementation averaged approximately 0.000098 seconds. Based on the unrounded averages, the naive execution took approximately 25,470 times longer.

However, the output values were different. The naive implementation returned 625025000, while the single-pass implementation returned 25000. The naive function repeatedly counts even values in every prefix of the array, whereas the single-pass function counts each array element once. Therefore, this timing comparison demonstrates the cost of the provided implementations, but it is not a comparison of two equivalent computations producing the same result.

In Task 2, BUILD_DATA took 0.000310 seconds, PROCESS took 0.000291 seconds, and REDUCE took 0.000134 seconds. Dataset construction was the longest measured phase in this run, followed closely by processing.

## Relation Between Runtime and Energy Consumption

Execution time can help identify computationally expensive operations. The large runtime difference in Task 1 indicates that the naive implementation occupied CPU execution time much longer than the single-pass implementation in these measurements.

However, runtime is only an indirect indicator of potential energy consumption. The experiments did not measure power in watts or energy in joules. Consequently, the results cannot establish the actual energy consumed by any implementation. They provide evidence about execution time, not direct energy savings.

## Limitations of the Experiment

The measurements were collected in one execution environment and may vary on different hardware, under different system loads, or with different compiler configurations. Task 0 and Task 1 used three runs, but Task 2's recorded phase timings came from one execution only. More repetitions would provide stronger evidence about timing variability.

The timer reports six decimal places, which limits the precision visible in the output. In addition, the Task 1 implementations returned different results, so their timings should not be interpreted as a fair comparison of equivalent solutions. No hardware power-monitoring tool was used.

## Practical Engineering Takeaway

These experiments show why engineers should measure execution time, inspect individual processing phases, and verify program outputs before drawing performance conclusions. The Task 1 measurements reveal a substantial runtime difference, while Task 2 identifies dataset construction as the longest phase in its recorded run. Future optimization decisions should preserve required functionality, compare equivalent outputs, repeat measurements, and use direct energy measurements when energy efficiency must be quantified.
