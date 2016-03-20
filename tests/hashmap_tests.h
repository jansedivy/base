#include "../base/hash.h"
#include <assert.h>

void run_hashmap_tests() {
  {
    Hash<int> map;
    hash::set(map, 0, 42);
    assert(hash::get(map, 0, 1) == 42);
  }
  {
    Hash<int> map;
    hash::set(map, 0, 0);
    hash::set(map, 1, 1);
    hash::set(map, 2, 2);
    hash::set(map, 3, 3);
    assert(hash::get(map, 0, 1) == 0);
    assert(hash::get(map, 1, 1) == 1);
    assert(hash::get(map, 2, 1) == 2);
  }
  {
    Hash<int> map;
    hash::set(map, 0, 0);
    assert(hash::has(map, 0));
  }
  {
    Hash<int> map;
    hash::set(map, 0, 0);
    hash::set(map, 0, 1);
    assert(hash::get(map, 0, 1) == 1);
  }
}
