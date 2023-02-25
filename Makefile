chunker: chunker.c
	gcc $< -o $@

clean:
	rm -f chunker