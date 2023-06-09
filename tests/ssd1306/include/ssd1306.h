/**
 * @file SSD1306.h
 * @author IotaHydrae (writeforever@foxmail.com)
 * @brief
 * @version 0.1
 * @date 2022-08-01
 *
 * MIT License
 *
 * Copyright 2022 IotaHydrae(writeforever@foxmail.com)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *
 */
#ifndef __SSD1306_H
#define __SSD1306_H

#include "ssd1306_font.h"

#define BIT(x) (1 << x)
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))

#define SSD1306_ADDRESS 0x3c

#define SSD1306_CMD 0x00
#define SSD1306_DATA 0x40

#define SSD1306_HOR_RES_MAX 128
#define SSD1306_VER_RES_MAX 64
#define SSD1306_BUFFER_SIZE ((SSD1306_HOR_RES_MAX * SSD1306_VER_RES_MAX) / 8)
#define SSD1306_PAGE_SIZE (SSD1306_VER_RES_MAX / 8)
#define OLED_COLOR_DEPTH 1
#define OLED_COORD_CHECK

#define OFFSET(p, c) ((p)*128 + (c))
#define GET_PAGE_FROM_BUFFER(i) (i / 128)
#define GET_COL_FROM_BUFFER(i) (i % 128)

#define GET_PAGE(pc) (pc >> 16)
#define GET_COL(pc) (pc & 0xFFFF)
#define PAGE_COL(page, col) ((page << 16) | col)
#define PAGE_COL_GET_X(pc) (GET_COL(pc))
#define PAGE_COL_GET_Y(pc) (GET_PAGE(pc) * 8)

// #define OLED_COORD_CHECK

enum
{
    SSD1306_ADDR_MODE_HORIZONTAL,
    SSD1306_ADDR_MODE_VERTICAL,
    SSD1306_ADDR_MODE_PAGE,
    SSD1306_ADDR_MODE_INVALID,
};

/* structures */
struct ssd1306_config {

};

struct ssd1306_ops {

};

struct ssd1306_handle {
    int fd;

    __u8 font;


};

/**
 * Register Map of SSD1306
 * 0x00 ~ 0xFF
 */

void ssd1306_init(int fd);
int ssd1306_write_data(int fd, __u8 val);

void oled_set_pixel(int fd, __u32 x, __u32 y, __u8 color);
void oled_put_ascii(int fd, __u8 x, __u8 y, __u8 c);
void oled_putascii_string(int fd, __u8 x, __u8 y, __u8 *str);

void oled_flush(int fd);
void oled_clear(int fd);

#endif /* __SSD1306_H */