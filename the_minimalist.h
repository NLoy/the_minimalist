/* Copyright 2020 QMK
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

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The first section contains all of the arguments as on the physical keyboard
// The second converts the arguments into the 2-D scanned array



#define LAYOUT( \
         KC_1A,   KC_1B,   KC_1C,           KC_1D,   KC_1E,   KC_1F,   KC_1G,   KC_1H,   KC_1I,   KC_1J,   KC_1K,   KC_1L,   KC_1M,   KC_1N,   KC_1O,   KC_1P,   KC_1Q,   KC_1R,           KC_1S,   KC_1T,   KC_1U,           KC_1V,   KC_1W,   KC_1X,   KC_1Y,  \
         KC_2A,   KC_2B,   KC_2C,           KC_2D,   KC_2E,   KC_2F,   KC_2G,   KC_2H,   KC_2I,   KC_2J,   KC_2K,   KC_2L,   KC_2M,   KC_2N,   KC_2O,   KC_2P,   KC_2Q,   KC_2R,           KC_2S,   KC_2T,   KC_2U,           KC_2V,   KC_2W,   KC_2X,   KC_2Y,  \
         KC_3A,   KC_3B,   KC_3C,           KC_3D,   KC_3E,   KC_3F,   KC_3G,   KC_3H,   KC_3I,   KC_3J,   KC_3K,   KC_3L,   KC_3M,   KC_3N,   KC_3O,   KC_3P,   KC_3Q,   KC_3R,           KC_3S,   KC_3T,   KC_3U,           KC_3V,   KC_3W,   KC_3X,   KC_3Y,  \
         KC_4A,   KC_4B,   KC_4C,           KC_4D,   KC_4E,   KC_4F,   KC_4G,   KC_4H,   KC_4I,   KC_4J,   KC_4K,   KC_4L,   KC_4M,   KC_4N,   KC_4O,   KC_4P,   KC_4Q,   KC_4R,           KC_4S,   KC_4T,   KC_4U,           KC_4V,   KC_4W,   KC_4X,   KC_4Y,  \
\
         KC_5A,   KC_5B,   KC_5C,           KC_5D,   KC_5E,   KC_5F,   KC_5G,   KC_5H,   KC_5I,   KC_5J,   KC_5K,   KC_5L,   KC_5M,   KC_5N,   KC_5O,   KC_5P,            KC_5R,           KC_5S,   KC_5T,   KC_5U,           KC_5V,   KC_5W,   KC_5X,   KC_5Y,  \
         KC_6A,   KC_6B,   KC_6C,           KC_6D,   KC_6E,   KC_6F,   KC_6G,   KC_6H,   KC_6I,   KC_6J,   KC_6K,   KC_6L,   KC_6M,   KC_6N,   KC_6O,   KC_6P,            KC_6R,           KC_6S,   KC_6T,   KC_6U,           KC_6V,   KC_6W,   KC_6X,   KC_6Y,  \
         KC_7A,   KC_7B,   KC_7C,           KC_7D,   KC_7E,   KC_7F,   KC_7G,   KC_7H,   KC_7I,   KC_7J,   KC_7K,   KC_7L,   KC_7M,   KC_7N,   KC_7O,   KC_7P,                             KC_7S,   KC_7T,   KC_7U,           KC_7V,   KC_7W,   KC_7X,           \
         KC_8A,   KC_8B,   KC_8C,           KC_8D,            KC_8F,   KC_8G,   KC_8H,   KC_8I,   KC_8J,   KC_8K,   KC_8L,   KC_8M,   KC_8N,   KC_8O,   KC_8P,                             KC_8S,   KC_8T,   KC_8U,           KC_8V,   KC_8W,   KC_8X,   KC_8Y,  \
         KC_9A,   KC_9B,   KC_9C,           KC_9D,   KC_9E,   KC_9F,                              KC_9J,                              KC_9N,   KC_9O,   KC_9P,            KC_9R,           KC_9S,   KC_9T,   KC_9U,           KC_9V,            KC_9X,           \
                                                    KC_WHI,  KC_YEL,  KC_GRN,  KC_RED,  KC_BLU                                                                                                                                                                   \
    ) \
    { \
      {  KC_1A,   KC_1B,   KC_1C,           KC_1D,   KC_1E,   KC_1F,   KC_1G,   KC_1H,   KC_1I,   KC_1J,   KC_1K,   KC_1L,   KC_1M,   KC_1N,   KC_1O,   KC_1P,   KC_1Q,   KC_1R,           KC_1S,   KC_1T,   KC_1U,           KC_1V,   KC_1W,   KC_1X,   KC_1Y}, \
      {  KC_2A,   KC_2B,   KC_2C,           KC_2D,   KC_2E,   KC_2F,   KC_2G,   KC_2H,   KC_2I,   KC_2J,   KC_2K,   KC_2L,   KC_2M,   KC_2N,   KC_2O,   KC_2P,   KC_2Q,   KC_2R,           KC_2S,   KC_2T,   KC_2U,           KC_2V,   KC_2W,   KC_2X,   KC_2Y}, \
      {  KC_3A,   KC_3B,   KC_3C,           KC_3D,   KC_3E,   KC_3F,   KC_3G,   KC_3H,   KC_3I,   KC_3J,   KC_3K,   KC_3L,   KC_3M,   KC_3N,   KC_3O,   KC_3P,   KC_3Q,   KC_3R,           KC_3S,   KC_3T,   KC_3U,           KC_3V,   KC_3W,   KC_3X,   KC_3Y}, \
      {  KC_4A,   KC_4B,   KC_4C,           KC_4D,   KC_4E,   KC_4F,   KC_4G,   KC_4H,   KC_4I,   KC_4J,   KC_4K,   KC_4L,   KC_4M,   KC_4N,   KC_4O,   KC_4P,   KC_4Q,   KC_4R,           KC_4S,   KC_4T,   KC_4U,           KC_4V,   KC_4W,   KC_4X,   KC_4Y}, \
\
      {  KC_5A,   KC_5B,   KC_5C,           KC_5D,   KC_5E,   KC_5F,   KC_5G,   KC_5H,   KC_5I,   KC_5J,   KC_5K,   KC_5L,   KC_5M,   KC_5N,   KC_5O,   KC_5P, _______,   KC_5R,           KC_5S,   KC_5T,   KC_5U,           KC_5V,   KC_5W,   KC_5X,   KC_5Y}, \
      {  KC_6A,   KC_6B,   KC_6C,           KC_6D,   KC_6E,   KC_6F,   KC_6G,   KC_6H,   KC_6I,   KC_6J,   KC_6K,   KC_6L,   KC_6M,   KC_6N,   KC_6O,   KC_6P, _______,   KC_6R,           KC_6S,   KC_6T,   KC_6U,           KC_6V,   KC_6W,   KC_6X,   KC_6Y}, \
      {  KC_7A,   KC_7B,   KC_7C,           KC_7D,   KC_7E,   KC_7F,   KC_7G,   KC_7H,   KC_7I,   KC_7J,   KC_7K,   KC_7L,   KC_7M,   KC_7N,   KC_7O,   KC_7P, _______, _______,           KC_7S,   KC_7T,   KC_7U,           KC_7V,   KC_7W,   KC_7X, _______}, \
      {  KC_8A,   KC_8B,   KC_8C,           KC_8D, _______,   KC_8F,   KC_8G,   KC_8H,   KC_8I,   KC_8J,   KC_8K,   KC_8L,   KC_8M,   KC_8N,   KC_8O,   KC_8P, _______, _______,           KC_8S,   KC_8T,   KC_8U,           KC_8V,   KC_8W,   KC_8X,   KC_8Y}, \
      {  KC_9A,   KC_9B,   KC_9C,           KC_9D,   KC_9E,   KC_9F, _______, _______, _______,   KC_9J, _______, _______, _______,   KC_9N,   KC_9O,   KC_9P, _______,   KC_9R,           KC_9S,   KC_9T,   KC_9U,           KC_9V, _______,   KC_9X, _______}, \
      {_______, _______, _______,         _______,  KC_WHI,  KC_YEL,  KC_GRN,  KC_RED,  KC_BLU, _______, _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______,         _______, _______, _______, _______}  \
    }
