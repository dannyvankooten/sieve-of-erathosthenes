# Sieve of Erathosthenes

C implementation of the [sieve of Erathosthenes](https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes).

![Visualization of the Sieve of Erathosthenes](https://upload.wikimedia.org/wikipedia/commons/9/94/Animation_Sieve_of_Eratosth.gif)

- [naive.c](naive.c) contains a simple implementation using a byte array to store whether a number is prime or not.
- [main.c](main.c) uses a bitset, reducing memory footprint by a factor 8.

> This is just an experiment for learning purposes. Don't use this, use the implementation in your stdlib of choice or [kimwalisch/primesieve](https://github.com/kimwalisch/primesieve) instead.

## Usage

```
make all
./main 100
./naive 100
```

There is a further optimization dubbed segmented sieve, but this implementation doesn't use that.

## License

[UNLICENSE](LICENSE)
