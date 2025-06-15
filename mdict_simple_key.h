/*
 * Copyright (c) 2020-2025
 * All rights reserved.
 *
 * This code is licensed under the BSD 3-Clause License.
 * See the LICENSE file for details.
 */

#ifndef mdict_simple_key_item_h
#define mdict_simple_key_item_h

#include <stdint.h>

typedef struct simple_key_list_item {
  uint64_t record_start;  // Supports files >4GB
  char* key_word;
} simple_key_item;

#endif
