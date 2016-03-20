#pragma once

#include <stdint.h>

namespace Base {
  uint32_t hash_string(char *string, uint32_t hash=0) {
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

template <typename F> struct ScopeExit {
  ScopeExit(F f) : f(f) {
  }
  ~ScopeExit() {
    f();
  }
  F f;
};

template <typename F> ScopeExit<F> MakeScopeExit(F f) {
  return ScopeExit<F>(f);
};

#define STRING_JOIN2(arg1, arg2) DO_STRING_JOIN2(arg1, arg2)
#define DO_STRING_JOIN2(arg1, arg2) arg1##arg2
#define defer(code) auto STRING_JOIN2(scope_exit_, __LINE__) = MakeScopeExit([=]() { code; })
