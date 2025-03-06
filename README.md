# Probabilistic-Biased-Number-Generator
### An algorithm that generates a random integer within a specified range, favoring a particular number within that range. It incorporates a "favoritism" factor to determine how closely the generated value should gravitate toward the favored number.


## Functions:
- BCF(minimum, maximum, favoredNum, oStrictness)
- BCF_Vector(minimum, maximum, favoredNum, oStrictness, length)
- _bcf_genvec_pycall(minimum, maximum, favoredNum, oStrictness)
    - *_Same as BCF() but without the parameter condition checks_*


## Main Parameters
- **minimum** (int): The minimum value of the desired range (inclusive).
- **maximum** (int): The maximum value of the desired range (inclusive).
- **favoredNum** (int): The number that the function should favor.
- **oStrictness** (int): A parameter controlling how strictly the function adheres to the favored number. It ranges from 1 (most strict) to 10 (least strict).
- **length** (int): Only for BCF_Vector(), controls how many BCF numbers to return in an array.

## Other Details
The Time Complexity of BCF() is probabilistic **O(1/P)**, where **P** is the average probability that the exit condition passes during the internal while loop. This can be directly influenced by the **minimum**, **maximum**, and **oStrictness** parameters.

The Time Complexity of BCF_Vector() is semi-deterministic **O(n * 1/P)**, where **n** is the desired length of the array, and **P** is the average probability that the exit condition passes during the internal while loop.

This algorithm is implemented using both C++ and Python/Cython.

