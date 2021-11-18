# Prime factorization.
#
# Invoke:
#    PyPrime.py [testNumber]
#
# Code history:
#   2021/Nov/18 S.Yamamoto  Original

import sys
import math

# Get argument
args = sys.argv
if len(args) > 1:
    testNumber = int(args[1])
else:
    testNumber = 11211109003

# Print headline.
print( "Testing prime factor of ", testNumber )

# Calculate square root.
# print() is just for confirmation of math calculation.
print( "Square root of testNumber is ", int(math.sqrt(testNumber)))

# Loop
while True:
    # Default not found.
    status = False
    q, mod = divmod( testNumber, 2 )
    if( mod == 0 ):
        # testNumber is even.
        print( 2 )
        testNumber = q
        status = True    # Found prime factor
        continue

    for t in range( 3, int(math.sqrt(testNumber))+1, 2 ):
        q, mod = divmod( testNumber, t )
        if( mod == 0 ):
            # Find prime factor.
            print( t )
            testNumber = q
            status = True   # Found prime factor
            break

    if( status == False ):
        # No prime factor. This is a prime number.
        print( testNumber )
        break

