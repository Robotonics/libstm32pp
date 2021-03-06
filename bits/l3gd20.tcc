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

namespace l3gd20 {
  template<
      i2c::address::E I,
      address::E A
  >
  template<
      l3gd20::registers::ctrl_reg1::bits::xen::states::E XEN,
      l3gd20::registers::ctrl_reg1::bits::yen::states::E YEN,
      l3gd20::registers::ctrl_reg1::bits::zen::states::E ZEN,
      l3gd20::registers::ctrl_reg1::bits::pd::states::E PD,
      l3gd20::registers::ctrl_reg1::bits::bw_odr::states::E DR_BW,
      l3gd20::registers::ctrl_reg4::bits::sim::states::E SIM,
      l3gd20::registers::ctrl_reg4::bits::fs::states::E FS,
      l3gd20::registers::ctrl_reg4::bits::ble::states::E BLE,
      l3gd20::registers::ctrl_reg4::bits::bdu::states::E BDU
  >
  void Gyroscope<I, A>::configure()
  {
    i2c::Standard<I>::writeSlaveRegister(
        A,
        registers::ctrl_reg1::ADDRESS,
        PD + DR_BW + XEN + YEN + ZEN);
    i2c::Standard<I>::writeSlaveRegister(
        A,
        registers::ctrl_reg4::ADDRESS,
        SIM + FS + BLE + BDU);
  }

  /**
   * @brief Reads the low byte of the X axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readXLow()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_x_l::ADDRESS);
  }

  /**
   * @brief Reads the high byte of the X axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readXHigh()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_x_h::ADDRESS);
  }

  /**
   * @brief Reads the low byte of the Y axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readYLow()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_y_l::ADDRESS);
  }

  /**
   * @brief Reads the high byte of the Y axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readYHigh()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_y_h::ADDRESS);
  }

  /**
   * @brief Reads the low byte of the Z axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readZLow()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_z_l::ADDRESS);
  }

  /**
   * @brief Reads the high byte of the Z axis magnetic field.
   */
  template<i2c::address::E I, address::E A>
  u8 Gyroscope<I, A>::readZHigh()
  {
    return i2c::Standard<I>::readSlaveRegister(
        A,
        registers::out_z_h::ADDRESS);
  }

}  // namespace l3gd20
