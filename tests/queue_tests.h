#include "../base/queue.h"
#include <assert.h>

void run_queue_tests() {
  {
    Queue<int> queue;
    queue::push_back(queue, 1);
    assert(queue::pop_front(queue) == 1);
  }
}
