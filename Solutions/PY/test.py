def divide_by_repeated_subtraction(dividend: int, divisor: int) -> tuple[int, int]:
    """
    Performs integer division (dividend // divisor) using the method of 
    repeated subtraction.
    Args:
        dividend: The number to be divided (the numerator).
        divisor: The number that is dividing (the denominator).
    Returns:
        A tuple containing (quotient, remainder).
    
    Raises:
        ValueError: If the divisor is zero.
    """
    if divisor == 0:
        raise ValueError("Cannot divide by zero.")
    # Handle the signs for correct logic flow
    # We'll work with absolute values for the core subtraction loop
    absolute_dividend = abs(dividend)
    absolute_divisor = abs(divisor)
    
    # Initialize quotient and remainder
    quotient = 0
    remainder = absolute_dividend
    # Core logic: While the remainder is greater than or equal to the divisor,
    # subtract the divisor and increment the count (quotient).
    while remainder >= absolute_divisor:
        remainder = remainder - absolute_divisor
        quotient = quotient + 1
        
    # Adjust the signs of the final quotient and remainder based on the original inputs
    
    # 1. Sign of the Quotient: 
    # - If the dividend and divisor have different signs, the quotient is negative.
    if (dividend < 0) ^ (divisor < 0):
        final_quotient = -quotient
    # 2. Sign of the Remainder: 
    # - The mathematical remainder usually shares the sign of the dividend, 
    #   but since this algorithm is based on positive subtraction, we return 
    #   the mathematical remainder definition: sign of the dividend.
    if dividend < 0:
        final_remainder = -remainder
    else:
        final_remainder = remainder
    return (final_quotient, final_remainder)
# --- Testing the Function ---
print("--- Test Case 1: Positive Division (10 / 3) ---")
q, r = divide_by_repeated_subtraction(10, 3)
print(f"Quotient: {q} (Expected: 3), Remainder: {r} (Expected: 1)")
print("-" * 30)
print("--- Test Case 2: Negative Dividend (-10 / 3) ---")
# Mathematically: -10 = 3 * (-3) + (-1) OR -10 = 3 * (-3) + 2 (depends on definition)
# Standard Python % (Remainder) has the sign of the divisor.
# Using the simple subtraction model (positive remainder logic):
q, r = divide_by_repeated_subtraction(-10, 3)
# In this simplified model, the quotient will be -3, and the remainder will track the positive difference.
print(f"Quotient: {q} (Expected: -3), Remainder: {r} (Expected: -1)") 
print("-" * 30)
print("--- Test Case 3: Negative Divisor (10 / -3) ---")
q, r = divide_by_repeated_subtraction(10, -3)
print(f"Quotient: {q} (Expected: -3), Remainder: {r} (Expected: 1)")
print("-" * 30)
print("--- Test Case 4: Zero/Perfect Division (12 / 4) ---")
q, r = divide_by_repeated_subtraction(12, 4)
print(f"Quotient: {q} (Expected: 3), Remainder: {r} (Expected: 0)")
print("-" * 30)
print("--- Test Case 5: Division by Self (7 / 7) ---")
q, r = divide_by_repeated_subtraction(7, 7)
print(f"Quotient: {q} (Expected: 1), Remainder: {r} (Expected: 0)")
print("-" * 30)
# Test case that will throw an error
try:
    divide_by_repeated_subtraction(5, 0)
except ValueError as e:
    print(f"Successfully caught expected error: {e}")