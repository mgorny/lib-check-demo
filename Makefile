all: both abi32 abi64

both: main.c libtime32.so libtime64.so
	$(CC) $(CFLAGS) -o $@ -Wl,-rpath,. $^

abi32: main.c libtime32.so
	$(CC) $(CFLAGS) -o $@ -Wl,-rpath,. $^

abi64: main.c libtime64.so
	$(CC) $(CFLAGS) -o $@ -Wl,-rpath,. $^

libtime32.so: lib.c
	$(CC) $(CFLAGS) -fPIC $< -o $@ -shared

libtime64.so: lib.c
	$(CC) $(CFLAGS) -fPIC -D_FILE_OFFSET_BITS=64 -D_TIME_BITS=64 $< -o $@ -shared

