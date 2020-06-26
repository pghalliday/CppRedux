# pragma once

#include <functional>
#include "../src/BurpRedux/Subscriber/Interface.hpp"

namespace BurpReduxTest {

  template <class State>
  class Subscriber : public BurpRedux::Subscriber::Interface<State> {

    public:

      using f_cb = std::function<void()>;

      const State * state;
      unsigned int count;

      Subscriber() :
        state(nullptr),
        count(0),
        _cb(nullptr)
      {}

      void setup(const State * initial) override {
        state = initial;
      }

      void onPublish(const State * next) override {
        count++;
        state = next;
        if (_cb) {
          f_cb cb = _cb;
          _cb = nullptr;
          cb();
        }
      }

      void callbackOnce(f_cb cb) {
        _cb = cb;
      }

    private:

      f_cb _cb;

  };

}
