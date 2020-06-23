# pragma once

#include <functional>
#include "../src/BurpRedux/Subscriber/Interface.hpp"

namespace BurpReduxTest {

  template <class State>
  class Subscriber : public BurpRedux::Subscriber::Interface<State> {

    public:

      using f_cb = std::function<void(const State * state)>;

      Subscriber() :
        _cb(nullptr)
      {}

      void onPublish(const State * state) override {
        if (_cb) {
          f_cb cb = _cb;
          _cb = nullptr;
          cb(state);
        }
      }

      void callbackOnce(f_cb cb) {
        _cb = cb;
      }

    private:

      f_cb _cb;

  };

}
