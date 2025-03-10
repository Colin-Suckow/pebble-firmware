/*
 * Copyright 2024 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

///////////////////////////////////////
// Implements:
//   void *memcpy(void *s1, const void *s2, size_t n);
//   void *memmove(void *s1, const void *s2, size_t n);
///////////////////////////////////////
// Exports to apps:
//   memcpy, memmove

#include <stddef.h>
#include <stdint.h>
#include <pblibc_assembly.h>
#include <pblibc_private.h>

#if !MEMCPY_IMPLEMENTED_IN_ASSEMBLY
void *memcpy(void * restrict s1, const void * restrict s2, size_t n) {
  char *dest = (char*)s1;
  const char *src = (const char*)s2;
  while (n--) {
    *dest++ = *src++;
  }
  return s1;
}
#endif

void *memmove(void * restrict s1, const void * restrict s2, size_t n) {
  char *dest = (char*)s1;
  const char *src = (const char*)s2;
  if (dest <= src) {
    while (n--) {
      *dest++ = *src++;
    }
  } else {
    while (n--) {
      dest[n] = src[n];
    }
  }
  return s1;
}
