CFLAGS = -Wall -Werror -I/usr/local/opt/openssl/include
LDFLAGS = -L/usr/local/opt/openssl/lib -lssl -lcrypto

chunker: chunker.c
	gcc $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f chunker