CC = gcc
CFlags = -Wall -Wextra -Wpedantic -Wpedantic -std=c18

# Main rule
ALL: maxfinder peakfinder

peakfinder: peakfinder.o util.o stats.o
	$(CC) $^ -o $@ -lm

peakfinder.o: peakfinder.c util.h stats.h
	$(CC) -c $(CFlags) $<

maxfinder: maxfinder.o util.o stats.o
	$(CC) $^ -o $@ -lm

maxfinder.o: maxfinder.c util.h stats.h 
	$(CC) -c $(CFlags) $<

util.o: util.c util.h
	$(CC) -c $(CFlags) $<

stats.o: stats.c stats.h
	$(CC) -c $(CFlags) $<

run: maxfinder
	./maxfinder 
	./peakfinder

.PHONY: clean 

clean:
	$(RM) *.o maxfinder peakfinder