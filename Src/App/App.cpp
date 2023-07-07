#include <cstdint>

#include <Mcal/mcal.h>
#include <Util/util_time.h>

namespace local
{
  using timer_type = util::timer<std::uint32_t>;

  constexpr auto one_sec =
    static_cast<std::uint32_t>
    (
      timer_type::seconds(static_cast<unsigned>(UINT8_C(1)))
    );
}

auto main() -> int;

auto main() -> int
{
  mcal_init();

  for(;;)
  {
    mcal_led_toggle();

    local::timer_type::blocking_delay(local::one_sec);
  }
}
