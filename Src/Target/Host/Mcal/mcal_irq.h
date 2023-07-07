///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2023.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MCAL_IRQ_2023_07_02_H
  #define MCAL_IRQ_2023_07_02_H

  namespace mcal
  {
    namespace irq
    {
      using config_type = void;

      inline auto init(const config_type*) noexcept -> void { }
    }
  }

#endif // MCAL_IRQ_2023_07_02_H
