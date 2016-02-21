//standroom.c used by weiqi...others may hate this format:D
//xueshan1.c

inherit ROOM;

void create ()
{
  set ("short", "茫茫雪峰");
  set ("long", @LONG

北风呼啸，飞雪茫茫。西北两面望去均是绵延不尽的雪峰，再往前走便要
将生迹抛在身后了。东南方向亦是群山起伏，只是冰雪已部分消融，要走
出大雪山是成功在望了。
LONG);

  set("outdoors", "xueshan");
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"xueshan3",
  "south" : __DIR__"xueshan1",
]));


  set("objects", ([ /* sizeof() == 4 */
  "/d/xueshan/npc/wuya-guai" : 1,
]));

  setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "northwest" && objectp(present("wuya xiansheng", environment(me)))) 
      {
      if ( me->query_temp("to_xueshan") !=1 ) 
         {
         return
         notify_fail("乌鸦先生喝道：干嘛的？(answer ０．巡山的　１．过路的　２．捣乱的)\n");
         }
      }
      else 
         { 
         return 
         ::valid_leave(me, dir); 
         }
      return 1;
}



