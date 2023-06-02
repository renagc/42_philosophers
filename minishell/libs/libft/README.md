# Libft

It is a project that bundles a bunch of utility functions.
It is used in other projects of the 42 school.

---

## Installation

*It is better to use this as a submodule of your project.*

```bash
git submodule add git@github.com:MM1212/42-libft.git libs/libft
git submodule update --init --recursive
```

---

## Usage

### Bash
```bash
# Compile
make
# Cleanup
make clean/fclean
# Recompile
make re
```

---

### Makefile
```Makefile
LIBFT_PATH = libs/libft
LIBFT_BIN = $(addprefix $(LIBFT_PATH)/,bin)
LIBFT_INCLUDES = $(addprefix $(LIBFT_PATH)/,includes/)
LIBFT_ARCH = $(addprefix $(LIBFT_BIN)/,libft.a)

$(LIBFT_ARCH):
  @make -C $(LIBFT_PATH)
```
