#include <stdio.h>
#include <stdlib.h>

// binsearch: find x in v[0] <= v[1] <= ... <= v[n-1]
int binsearch(int x, int v[], int n)
{
  int low = 0;
  int high = n - 1;
  int mid;
  while (low <= high)
  {
    mid = (low + high) / 2;
    if (x < v[mid])
    {
      high = mid - 1;
    }
    else if (x > v[mid])
    {
      low = mid + 1;
    }
    else
    {
      return mid;
    }
  }
  return -1;
}

// Exercise 3-1.
int binsearch_2(int x, int v[], int n)
{
  int low = 0;
  int high = n;
  int mid = (low + high) / 2;
  while (mid != low)
  {
    if (x < v[mid])
    {
      high = mid;
    }
    else
    {
      low = mid;
    }
    mid = (low + high) / 2;
  }
  return (x == v[mid]) ? mid : -1;
}

int main(void)
{
  static const int n = 10000;
  int *v = malloc(n * sizeof(*v));
  for (int i = 0; i < n; ++i)
  {
    v[i] = i;
  }

  for (int x = -10; x <= n + 10; ++x)
  {
    (void) binsearch(x, v, n);
  }
  free(v);
}
