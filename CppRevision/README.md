## Type casting
- static_cast
    - Compile time casting.
    - It performs implicit conversions between types.
    - [NOTE] C-Style cast is hard to find in code
    - Use static_cast when conversion between types is provided through
       conversion operator or conversion constructor.
    - static_cast is more restrictive than C-Style
    - static_cast avoid cast from derived to private base pointer.
    - Use for all upcast, but never used for confused downcast.
    - static_cast should be prefered when converting to void* or from void*.

- const_cast
    -  Used to change the const or volatile qualifiers of pointers or
    references
    - When the actual referred object/variable is not const.
    - When need to call some 3rd party library where it is taking variable/object
    as non-const but not changing that.
