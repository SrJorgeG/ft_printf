# ft_printf

> A re-implementation of printf in C, packaged as libftprintf.a.

## What it does
Variadic `ft_printf` built on `stdarg.h`, written for the 42 curriculum.

## What I learned
- Variadic functions (`va_list`)
- Format parsing and number-to-base conversion

## Tech stack
C, Make

## Build & run
```bash
make   # builds libftprintf.a (cc -Wall -Wextra -Werror)
```

## Usage
```bash
cc main.c libftprintf.a && ./a.out
```

## Structure
`ft_printf.c`, `ft_printf_utils.c`, `ft_printf.h`.

---
*Built at 42 Madrid by jgomez-d (Jorge Gomez De Oliveira).*
