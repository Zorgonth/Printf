# PRINTF
This project consists in duplicate the behavior of the C function `printf()`. It is not necessary to implement the buffer management of the original function. It must handle the following parameters:

- `char` type variables.
- `string` type variables.
- `int` type variables.
- `unsigned int` type variables.
- hexadecimal `int` type variables (uppercase and lowercase).
- `pointer` type variables.

## USAGE
To compile and use this project, naviagte to the main path and run:
```
$make
```

To use it in your code, simply include it in your header:
```
#include "ft_printf.h"
```

To delete all compiled files, navigate to the main path again and run:
```
$make fclean
```
