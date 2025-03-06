#include <iostream>
#include <random>

// Function to generate a biased random number within a specified range
int BCF(int minimum, int maximum, int favoredNum, int oStrictness) {

    // Ensure strictness is within the valid range [1, 10]
    if (oStrictness < 1) {
        oStrictness = 1;
    }
    else if (oStrictness > 10) {
        oStrictness = 10;
    }

    // Validate the input range and favored number
    if (minimum < 0 || maximum < 0 || minimum > favoredNum || maximum < favoredNum) {
        return -1;
    }

    float range_ = maximum - minimum; // Calculate the range
    float strictness = (range_ / 10) * oStrictness; // Scale the strictness value with range
    int tryVal, favoritismMeter, diffValue;

    // Loop to generate a biased random number
    while (true) {
        tryVal = std::rand() % (static_cast<int>(range_) + 1) + minimum; // Generate a random number within the range
        favoritismMeter = std::rand() % (static_cast<int>(range_) + 1); // Generate a random favoritism meter value
        diffValue = std::abs(tryVal - favoredNum); // Calculate the difference from the favored number

        // Check if the generated number is within the strictness range. If not, run while loop again.
        if ((strictness - diffValue) >= favoritismMeter) {
            return tryVal;
        }
    }
}


// Same as the first function but without the conditional checks.
int _bcf_genvec_pycall(int minimum, int maximum, int favoredNum, int oStrictness) {
    float range_ = maximum - minimum;
    float strictness = (range_ / 10) * oStrictness;
    int tryVal, favoritismMeter, diffValue;

    while (true) {
        tryVal = std::rand() % (static_cast<int>(range_) + 1) + minimum;
        favoritismMeter = std::rand() % (static_cast<int>(range_) + 1);
        diffValue = std::abs(tryVal - favoredNum);

        if ((strictness - diffValue) >= favoritismMeter) {
            return tryVal;
        }
    }
}
