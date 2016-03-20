#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <memory>

template<typename T> struct Array {
  Array() : capacity(0), size(0), data(0) {}
  ~Array() {
    free(data);
  }

  T &operator[](uint32_t index);
  const T &operator[](uint32_t index) const;
  Array &operator=(const Array &other);

  uint32_t capacity;
  uint32_t size;
  T *data;
};

namespace array {
  template<typename T> inline T* begin(Array<T> &array) { return array.data; }
  template<typename T> inline const T* begin(const Array<T> &array) { return array.data; }
  template<typename T> inline T* end(Array<T> &array) { return array.data + array.size; }
  template<typename T> inline const T* end(const Array<T> &array) { return array.data + array.size; }

  template<typename T> inline bool empty(const Array<T> &array) { return array.size == 0; }
  template<typename T> inline bool any(const Array<T> &array) { return array.size != 0; }

  template<typename T> void set_capacity(Array<T> &array, uint32_t new_capacity) {
    if (new_capacity == array.capacity) {
      return;
    }

    if (new_capacity < array.size) {
      array.size = new_capacity;
    }

    T *data = 0;
    if (new_capacity > 0) {
      data = (T *)malloc(sizeof(T) * new_capacity);
      memcpy(data, array.data, sizeof(T) * array.size);
    }
    free(array.data);
    array.data = data;
    array.capacity = new_capacity;
  }

  template<typename T> inline void trim(Array<T> &array) {
    set_capacity(array, array.size);
  }

  template<typename T> inline void reserve(Array<T> &array, uint32_t new_capacity) {
    if (new_capacity > array.capacity) {
      set_capacity(array, new_capacity);
    }
  }

  template<typename T> void grow(Array<T> &array, uint32_t min_capacity) {
    uint32_t new_capacity = array.capacity * 2 + 8;
    if (new_capacity < min_capacity) {
      new_capacity = min_capacity;
    }
    set_capacity(array, new_capacity);
  }

  template <typename T> void resize(Array<T> &array, uint32_t new_size) {
    if (new_size > array.capacity) {
      grow(array, new_size);
    }

    array.size = new_size;
  }

  template<typename T> inline void push_back(Array<T> &array, T value) {
    if (array.size + 1 > array.capacity) {
      grow(array, array.size + 1);
    }

    array.data[array.size++] = value;
  }

  template<typename T> inline void pop_back(Array<T> &array) {
    array.size -= 1;
  }

  template<typename T> inline void clear(Array<T> &array) {
    array.size = 0;
  }
};

template<typename T> inline T &Array<T>::operator[](uint32_t index) {
  return data[index];
}

template<typename T> const T &Array<T>::operator[](uint32_t index) const {
  return data[index];
}

template<typename T> Array<T> &Array<T>::operator=(const Array<T> &other) {
  array::set_capacity(*this, other.size);
  size = other.size;
  memcpy(data, other.data, sizeof(T) * other.size);
  return *this;
}
