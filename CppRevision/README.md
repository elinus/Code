## Type casting
- static_cast
    - 0. Compile time casting.
    - 1. It performs implicit conversions between types.
    - NOTE: C-Style cast is hard to find in code
    - 2. Use static_cast when conversion between types is provided through
       conversion operator or conversion constructor.
    - 3. static_cast is more restrictive than C-Style
    - 4. static_cast avoid cast from derived to private base pointer.
    - 5. Use for all upcast, but never used for confused downcast.
    - 6. static_cast should be prefered when converting to void* or from void*.
