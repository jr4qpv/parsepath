sample	:	sample1.c _parsepath.c
	gcc -o $@ $^

clean	:
	rm -f sample
