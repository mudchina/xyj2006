//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.3
//  /d/qujing/heifeng/shanlu1.c

inherit ROOM;

void create ()
{
  set ("short", "平台");
  set ("long", @LONG

这是山上的一个比较平坦的地方，经常有人坐在这休息，坐在
这，山上的景色尽收眼底，白云，山川，河流，真乃人间仙境。

LONG);

  set("exits", ([
        "northwest"  : __DIR__"road3",
        "south"      : __DIR__"road5",
      ]));
  set("objects",([
        __DIR__"npc/baiyi":1,
        __DIR__"npc/dahan":1,
        __DIR__"npc/lingxu":1,
        __DIR__"npc/xiaoyao":1,
        ]));
  set("outdoors","hf");
  setup();

}
int valid_leave(object me, string dir)
{

        if ( dir =="south" ) {

        if( objectp(present("baiyi xiushi", environment(me))))
        return notify_fail("白衣秀士伸手拦住了你！\n");
        if( objectp(present("xiao yao", environment(me)))
         && !me->query_temp("fired") 
         && !me->query("obstacle/hf") )

        return notify_fail("忽然小妖挡住你的去路。\n");
        
       if (! me->query_temp("apply/name") ||
        me->query_temp("apply/name")[0] != "金池长老")
        return notify_fail("忽然小妖挡住你的去路。\n");
       
         }
        return ::valid_leave(me, dir);
}
