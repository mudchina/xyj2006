// created 4/4/1997 by snowcat
#include <ansi.h>

inherit ITEM;

void create()
{
  set_name("西梁简图", ({ "map" }) );
  set_weight(10);
  setup();
  set("long", @LONG

一线天［终点］
   ＼
    长别亭
     ｜＼
     ｜山坡－迷宫出口…绿迷宫
     ｜
     ｜                  后宫
     ｜                   ｜
     ｜          东侧殿－前宫－西侧殿
     ｜                   ｜
     ｜                王宫大门
     ｜                   ｜
     ｜      安乐巷西－安乐巷中－安乐巷东
     ｜         ｜　　　　｜　　　　｜                         ［起点］
   小路      儿女巷西－儿女巷中－儿女巷东                河东岸－山路
     ｜         ｜　　　　｜　　　　｜                     ｜
     ｜      桑花巷西－桑花巷中－桑花巷东         茅屋   河东岸
     ｜                                  ＼        ｜      ｜
     ｜                                三岔路口－河西岸…河东岸
     ｜                                    ｜
   小路－－－－小路－－－－－－－－－－－解阳山
                                           ｜
                                         聚仙庵
                                           ｜
                                          庵内

LONG
  );

  setup();
}

void init()
{
}

