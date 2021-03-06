/*******************************************************************************
 *
 * Copyright (C) 2012 Jorge Aparicio <jorge.aparicio.r@gmail.com>
 *
 * This file is part of libstm32pp.
 *
 * libstm32pp is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * libstm32pp is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with libstm32pp. If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/

#pragma once

// DO NOT INCLUDE THIS FILE ANYWHERE. THIS DEMO IS JUST A REFERENCE TO BE USED
// IN YOUR MAIN SOURCE FILE.

#include "device_select.hpp"
#include "peripheral/gpio.hpp"
#include "peripheral/rcc.hpp"

// TODO Test GPIO demo on STM32F1XX

int main()
{
#ifdef STM32F1XX
  RCC::enableClocks<
      rcc::registers::apb2enr::bits::IOPA
  >();

  PA0::setMode<
      gpio::registers::cr::states::GP_PUSH_PULL_10MHZ
  >();

#else
  RCC::enableClocks<
  rcc::registers::ahb1enr::bits::GPIOA
  >();

  PA0::setMode<
  gpio::registers::moder::states::OUTPUT
  >();
#endif

  while (true) {
    PA0::setLow();
    PA0::setHigh();
  }
}
