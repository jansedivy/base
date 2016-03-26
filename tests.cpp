#include "tests/array_tests.h"
#include "tests/hashmap_tests.h"
#include "tests/queue_tests.h"

int main() {
  run_array_tests();
  run_hashmap_tests();
  run_queue_tests();
}
