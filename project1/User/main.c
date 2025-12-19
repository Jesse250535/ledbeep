#include "smg.h"
#include "lcd1602.h"
#include "ds1302.h"
#include "public.h"
#include <stdio.h>  // 用于 sprintf

// BCD 转十进制宏
#define BCD2DEC(bcd) (((bcd) >> 4) * 10 + ((bcd) & 0x0F))

void main()
{
    u8 ired_buf[3];
    u8 key = 0;
    u8 time_buf[8];
    u8 lcd_str[9]; // 用于构造显示字符串

    ds1302_init();      // 初始化DS1302
    lcd1602_init();     // LCD1602初始化

    // 可选：首次清屏或设置标题
    lcd1602_show_string(1, 0, "Date:2025-12-19"); // 预留空间
//    lcd1602_show_string(2, , "Time:        ");

    while(1)
    {
        ds1302_read_time();

        // === 数码管显示（保持不变）===
        time_buf[0] = gsmg_code[gDS1302_TIME[2] / 16];
        time_buf[1] = gsmg_code[gDS1302_TIME[2] & 0x0f];
        time_buf[2] = 0x40; // '-'
        time_buf[3] = gsmg_code[gDS1302_TIME[1] / 16];
        time_buf[4] = gsmg_code[gDS1302_TIME[1] & 0x0f];
        time_buf[5] = 0x40;
        time_buf[6] = gsmg_code[gDS1302_TIME[0] / 16];
        time_buf[7] = gsmg_code[gDS1302_TIME[0] & 0x0f];
        smg_display(time_buf, 1);

        // === LCD1602 显示日期和时间 ===
        // 第一行：年-月-日 （假设 gDS1302_TIME[6]=年, [4]=月, [3]=日）
//        sprintf((char*)lcd_str, "20%02d-%02d-%02d",
//                BCD2DEC(gDS1302_TIME[6]),
//                BCD2DEC(gDS1302_TIME[4]),
//                BCD2DEC(gDS1302_TIME[3]));
//        lcd1602_show_string(1, 1, lcd_str);

        // 第二行：时:分:秒
//        sprintf((char*)lcd_str, "%02d:%02d:%02d",
//                BCD2DEC(gDS1302_TIME[2]/ 16,gDS1302_TIME[2] & 0x0f),
//                BCD2DEC(gDS1302_TIME[1]),
//                BCD2DEC(gDS1302_TIME[0]));
//        lcd1602_show_string(2, 0, lcd_str);

//        // 延时避免频繁刷新（可选，LCD 刷新快，但减少 CPU 占用）
//        delay_ms(200); // 假设 public.h 中有 delay_ms，否则自己实现
    }
}