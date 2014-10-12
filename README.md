Enum
----
Enum is a smarter enum for C++11 that supports conversion to/from string.

Sample usage
------------

```c++
#include "enum.h"

MAKE_ENUM(Fruit, Apple, Banana, Orange)

std::cout << Fruit::as_string(Fruit::Apple) << std::endl;   // -> "Apple"
std::cout << Fruit::as_string(Fruit::Banana) << std::endl;  // -> "Banna"

auto a = Fruit::from_string("Banana");  // -> a == Fruit::Banana
auto b = Fruit::from_string("Cat");     // -> b == Fruit::undefined
```

