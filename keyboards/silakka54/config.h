/* Copyright 2024 Juho T. (@Squalius-cephalus)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP0
#define SERIAL_USART_RX_PIN GP1

// Mouse movement settings - less aggressive acceleration
#define MOUSEKEY_DELAY 10              // Delay before movement starts (ms)
#define MOUSEKEY_INTERVAL 20             // Time between movement reports (ms)
#define MOUSEKEY_TIME_TO_MAX 30          // Time to reach max speed (increase for slower acceleration)
#define MOUSEKEY_MAX_SPEED 3             // Maximum cursor speed (lower = slower max speed)
#define MOUSEKEY_WHEEL_DELAY 10         // Delay before wheel movement starts
#define MOUSEKEY_WHEEL_INTERVAL 100       // Time between wheel reports (higher = slower scroll)
#define MOUSEKEY_WHEEL_TIME_TO_MAX 80    // Time for wheel to reach max speed
#define MOUSEKEY_WHEEL_MAX_SPEED 2       // Maximum wheel speed (lower = smaller scroll steps)

#define USB_MAX_POWER_CONSUMPTION 100

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17

#define TAPPING_TERM 150
#define FLOW_TAP_TERM 150
