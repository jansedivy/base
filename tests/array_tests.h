#include "../base/array.h"
#include <assert.h>

void run_array_tests() {
  {
    Array<int> array;
    assert(array.data == 0);
    assert(array.capacity == 0);
    assert(array.size == 0);
    assert(array::empty(array));
  }
  {
    Array<int> array;
    array::push_back(array, 42);
    assert(array.size == 1);
    assert(array[0] == 42);
    assert(!array::empty(array));
  }
  {
    Array<int> array;
    assert(!array::any(array));
    array::push_back(array, 42);
    assert(array::any(array));
  }
  {
    Array<int> array;
    array::reserve(array, 10);
    assert(array.capacity == 10);
    array::reserve(array, 0);
    assert(array.capacity == 10);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    assert(array.data != 0);
    assert(array.capacity == 8);
    assert(array.size == 1);

    array::push_back(array, 2);
    assert(array.capacity == 8);
    assert(array.size == 2);

    array::push_back(array, 3);
    array::push_back(array, 4);
    array::push_back(array, 5);
    array::push_back(array, 6);
    array::push_back(array, 7);
    array::push_back(array, 8);
    assert(array.size == 8);
    assert(array.capacity == 8);

    array::push_back(array, 9);
    assert(array.size == 9);
    assert(array.capacity == 24);
  }
  {
    Array<int> array;
    assert(array::begin(array) == array::end(array));
    array::push_back(array, 1);
    assert(array::begin(array) != array::end(array));
    assert(array::end(array) - array::begin(array) == 1);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    array::push_back(array, 2);
    array::push_back(array, 3);
    assert(array.size == 3);
    array::clear(array);
    assert(array.size == 0);
    assert(array.capacity == 8);
  }
  {
    Array<int> array;
    array::set_capacity(array, 20);
    assert(array.size == 0);
    assert(array.capacity == 20);
  }
  {
    Array<int> array;
    array::set_capacity(array, 20);
    assert(array.capacity == 20);
    array::set_capacity(array, 2);
    assert(array.capacity == 2);
  }
  {
    Array<int> array;
    array::set_capacity(array, 10);
    int *old = array.data;
    array::set_capacity(array, 10);
    assert(array.data == old);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    array::push_back(array, 2);
    array::push_back(array, 3);
    array::set_capacity(array, 2);
    assert(array.capacity == 2);
    assert(array.size == 2);
  }
  {
    Array<int> array;
    array::set_capacity(array, 20);
    assert(array.capacity == 20);
    array::push_back(array, 1);
    array::push_back(array, 2);
    array::push_back(array, 3);
    assert(array.capacity == 20);
    array::trim(array);
    assert(array.capacity == 3);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    array::push_back(array, 2);
    array::push_back(array, 3);
    assert(array.size == 3);
    array::pop_back(array);
    assert(array.size == 2);
    array::pop_back(array);
    assert(array.size == 1);
    array::pop_back(array);
    assert(array.size == 0);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    Array<int> array_2;
    array_2 = array;
    array::push_back(array_2, 2);

    assert(array.data != array_2.data);
    assert(array.size == 1);
    assert(array_2.size == 2);
  }
  {
    Array<int> array;
    for (int i=0; i<1000; i++) {
      array::push_back(array, i);
    }
    assert(array.size == 1000);
    assert(array.capacity == 1016);
  }
  {
    Array<int> array;
    array::reserve(array, 1000);
    for (int i=0; i<1000; i++) {
      array::push_back(array, i);
    }
    assert(array.size == 1000);
    assert(array.capacity == 1000);
  }
  {
    Array<int> array;
    array::push_back(array, 1);
    array::set_capacity(array, 0);
  }
}
