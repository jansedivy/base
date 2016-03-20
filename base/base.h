#pragma once

#include <stdint.h>

namespace Base {
  uint32_t hash_string(char *wstring, uint32_t hash) {
    while (*string != '\0') {
      char c = *string++;
      if ((c >= 'a') && (c<= 'z')) {
        c = (c - 'a') + 'A';
      }

      hash += c;
      hash += (hash << 10);
      hash ^= (hash >> 6);
    }

    return hash;
  }
};
