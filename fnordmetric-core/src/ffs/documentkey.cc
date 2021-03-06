/**
 * This file is part of the "FnordMetric" project
 *   Copyright (c) 2011-2014 Paul Asmuth, Google Inc.
 *
 * FnordMetric is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License v3.0. You should have received a
 * copy of the GNU General Public License along with this program. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include "documentkey.h"

namespace fnordmetric {

DocumentKey::DocumentKey(uint64_t key) : is_string_(false) {
  key_.int_key = key;
}

DocumentKey::DocumentKey(const std::string& key) : is_string_(true) {
  key_.string_key = new std::string((key));
}

DocumentKey::DocumentKey(const DocumentKey& copy) :
    is_string_(copy.is_string_) {
  if (is_string_) {
    key_.string_key = new std::string(*copy.key_.string_key); // FIXPAUL!
  } else {
    key_.int_key = copy.key_.int_key;
  }
}

DocumentKey::~DocumentKey() {
  if (is_string_) {
    delete key_.string_key;
  }
}

bool DocumentKey::isIntKey() const {
  return !is_string_;
}

bool DocumentKey::isStringKey() const {
  return is_string_;
}

uint64_t DocumentKey::getIntKey() const {
  assert(is_string_ == false);
  return key_.int_key;
}

const std::string* DocumentKey::getStringKey() const {
  assert(is_string_ == true);
  return key_.string_key;
}

}
