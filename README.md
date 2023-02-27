# Fixed Size Chunker (FSC)

Efficiency-first implementation of the FSC algorithm for scientific analyses.
This program will take the target chunk size and a byte stream as arguments
and output for each next chunk an 8-byte fingerprint (using a fast non-cryptographic function) and the chunk's size in CSV format.
This program was done for performance measurements on the algorithm itself and will never actually write anything to disk.

## Usage

```
cat somefile.txt | ./chunker 4096
```

**Example Output:**

```
4a5564c8bcafa54b,4096
34ae13701af441f9,4096
91c63e920e5e525b,4096
0bd92be7339c1112,4096
1f1482633489ddf6,2863
```
