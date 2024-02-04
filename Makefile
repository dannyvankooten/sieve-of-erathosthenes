CFLAGS+= -std=c17 -Wall -Wextra -Wpedantic  \
-Wundef -Winline -Wimplicit-fallthrough -Wformat=2  \
-Wconversion

ifndef RELEASE
CFLAGS+= -D_FORTIFY_SOURCE=2 -D_GLIBCXX_ASSERTIONS  \
	-fsanitize=address -fsanitize=undefined -g        \
	-fstack-protector-strong -fstrict-aliasing
else
CFLAGS+= -O2 -march=native -mtune=native
endif

.PHONY: clean

all: main naive

main: main.c
naive: naive.c

clean:
	rm -rf main naive
