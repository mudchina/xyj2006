//Cracked by Roath


inherit ROOM;

void create ()
{
  set ("short", "卧室");
  set ("long", @LONG

猎户人家的卧室和别人家的也是不一样，猎户人家经常用一些
动物的毛皮当做被褥，保暖效果比一般的被褥要好的多。

LONG);

  set("exits", ([
        "north" : __DIR__"yard",
      ]));
  setup();

}
void init()
{
  add_action("do_sleep", "sleep");
}
int do_sleep(string arg)
{
  object me=this_player();
      if( me->query_temp("sc_can_sleep"))
  {
  	 message_vision("恍惚地，$N似乎觉得自己到了另一个地方。\n",me); 
  	 me->move("/d/death/zhengtang");
    me->set_temp("can_ask",1);
  	 return 1;
  }
   return 0;
  
}   
