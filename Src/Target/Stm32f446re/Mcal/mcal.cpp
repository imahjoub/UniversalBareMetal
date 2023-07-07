#include <Mcal/mcal.h>
#include <Mcal/mcal_gpt_arm_sys_tick.h>
#include <Mcal/mcal_reg.h>

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

extern "C"
void mcal_init(void)
{
  mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, mcal::reg::rcc_ahb1enr, static_cast<std::uint32_t>(UINT8_C(1))>::reg_or();

  mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder, static_cast<std::uint32_t>((1U << (5U * 2U)))>::reg_or();
  mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, mcal::reg::gpioa_moder, static_cast<std::uint32_t>(~(1U << ((5U * 2U) + 1U)))>::reg_and();

  mcal::gpt::init(nullptr);

  // Enable global interrupts.
  asm volatile("cpsie i");
}

extern "C"
void mcal_led_toggle(void)
{
  // toggle PortA.5
  mcal::reg::reg_access_static<std::uint32_t, std::uint32_t, mcal::reg::gpioa_odr, static_cast<std::uint32_t>(UINT8_C(5))>::bit_not();
}
