///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_GPT_2011_10_20_H
  #define MCAL_GPT_2011_10_20_H

  #if defined(__cplusplus)
  extern "C"
  {
  #endif

  #include <cstdint>

  #include <Mcal/Gpt.h>
  #include <Mcal/Systick.h>

  // Forward declaration of the util::timer template class.
  namespace util
  {
    template<typename unsigned_tick_type>
    class timer;
  }

  namespace mcal
  {
    namespace gpt
    {
      using arm_sys_tick_type = arm_sys_tick<static_cast<std::uint32_t>(UINT16_C(168))>;

      using config_type = void;
      using value_type  = typename arm_sys_tick_type::value_type;

      inline auto init(const config_type*) noexcept -> void;

      struct secure final
      {
        static auto get_time_elapsed() -> value_type { return static_cast<value_type>(arm_sys_tick_type::get_time_elapsed()); }
      };
    }
  }

  inline auto mcal::gpt::init(const config_type*) noexcept -> void { SysTick_Init(); }

  #if defined(__cplusplus)
    }
  #endif

#endif // MCAL_GPT_2011_10_20_H
