#include "Instance.hpp"

namespace BurpTree {
  namespace State {

    Instance::Instance(const Uid uid) :
      _uid(uid)
    {}

    const Instance::Uid Instance::getUid() const {
      return _uid;
    }

  }
}