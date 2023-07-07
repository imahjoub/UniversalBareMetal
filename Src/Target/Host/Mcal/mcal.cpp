#include <chrono>
#include <iostream>
#include <thread>

#include <Mcal/mcal.h>

#include <Mcal/mcal_cpu.h>
#include <Mcal/mcal_gpt.h>
#include <Mcal/mcal_irq.h>

extern "C"
void mcal_init(void)
{
  mcal::gpt::init(nullptr);
}

namespace local
{
  auto led_is_on() -> bool&
  {
    static auto my_led_is_on = false;

    return my_led_is_on;
  }

  auto mcal_led_on () -> void { local::led_is_on() = true;  std::cout << "LED0 is: ON"  << std::endl; }
  auto mcal_led_off() -> void { local::led_is_on() = false; std::cout << "LED0 is: OFF" << std::endl; }
}

extern "C"
void mcal_led_toggle(void)
{
  (local::led_is_on() ? local::mcal_led_off() : local::mcal_led_on());

}
