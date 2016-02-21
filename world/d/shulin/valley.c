// /d/shulin/valley.c藏风灵珠的地方
inherit ROOM;
int do_out();
void create()
{
        set("short", "树林");
        set("long", "这是一个山谷，到处是桃树，结满了桃子。\n");
        set("objects", ([
             __DIR__"npc/shuyao" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_out","out");
}
int do_out()
{
 object room;
 object who = this_player();
  message_vision("$N试着往洞里爬，突然一股寒风吹来，$N全身都被冻僵了！\n",who);
  who->recieve_damage(who->query("kee")/5);
  who->recieve_wound(who->query("max_kee")/5);
  who->start_busy(5);
  who->move("/d/shulin/lin8");
  return 1;
}
