chunker: chunker.c
	gcc -O2 $< -o $@

clean:
	rm -f chunker