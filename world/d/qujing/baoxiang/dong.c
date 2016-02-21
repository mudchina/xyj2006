// created by snowcat.c 10/14/1997
// room: /d/qujing/baoxiang/dong.c

inherit ROOM;

void create ()
{
  set ("short", "波月洞");
  set ("long", @LONG

洞内湿气环绕，阴森逼人。向外看，洞口苔藓斑斑；向里看，不
知深浅，隐约可听见滴水之声。好一个倒木横担，枯藤挂峰，不
知是妖境还是仙境。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"dongwai",
      ]));
  set("objects", ([ 
      __DIR__"npc/shanyao" : 6,
      __DIR__"npc/huangpao" : 1,
      __DIR__"npc/baihua" : 1,
      ]));

  setup();
}

