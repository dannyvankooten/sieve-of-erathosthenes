#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(const int argc, const char *argv[static argc]) {
  unsigned limit;
  if (argc == 1) {
    limit = 100;
  } else {
    limit = (unsigned)atoi(argv[1]);
  }

  unsigned char *is_prime = malloc(limit);
  assert(limit);
  unsigned nprimes = 0;

  for (unsigned i = 0; i < limit; i++) {
    is_prime[i] = 1;
  }

  for (unsigned i = 2; i < limit; i++) {
    if (is_prime[i]) {
      printf("%d\n", i);
      nprimes++;
    }

    for (unsigned n = i + i; n < limit; n += i) {
      is_prime[n] = (unsigned char)0;
    }
  }

  free(is_prime);

  printf("\n\n%d primes\n", nprimes);
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  printf("user time: %ld.%lds\n", usage.ru_utime.tv_sec,
         usage.ru_utime.tv_usec);
  printf("sys time: %ld.%lds\n", usage.ru_stime.tv_sec, usage.ru_stime.tv_usec);
  printf("max memory: %ld kB\n", usage.ru_maxrss);
}
