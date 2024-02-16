CC := gcc
CFLAGS := -Wall -Werror

src_files = p1.c p2.c p3.c p4.c
obj_files = p1 p2 p3 p4

all: $(obj_files)
.PHONY: all

% : %.c
	$(CC) -o $@ $(CFLAGS) $<

clean:
	rm -f $(obj_files)
