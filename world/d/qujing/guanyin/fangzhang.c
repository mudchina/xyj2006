inherit ROOM;

void create ()
{
  set ("short", "方丈室");
  set ("long", @LONG

这里是方丈平时学习佛法的地方，房间里放满了
经书。
LONG);

        set("objects", 
        ([ //sizeof() == 3
                __DIR__"npc/yuanzhu" : 1,
                __DIR__"npc/guangzhi" : 1,
        ]));
  set("exits", ([
         "east" : __DIR__"langdao3",
      ])); 

  setup();
}

