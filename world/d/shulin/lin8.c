 // Room: /shulin/lin8.c
inherit ROOM;
int do_enter(string arg);
void create()
{
        set("short", "树林");
        set("long", @LONG
终于走出了树林，你不禁长长的松了口气。和煦的阳光照在你
的身上，使你感到无比的温暖。南边是一座高耸的石山，山上郁郁
苍苍，生满树木。山下似乎有个小洞(cave)。
LONG );
        set("outdoors", "xiakedao");
        set("exits", ([
              "north" : __DIR__"lin7",
        ]));
        set("no_clean_up", 0);
        setup();
}
void init()
{
 add_action("do_enter","enter");
}
int do_enter(string arg)
{
 object room;
 object who = this_player();
 if(!arg || arg != "cave")
    return notify_fail("你要进哪里？\n");
if(random(who->query_kar())>25 && who->query("max_mana")>1000)
 {
  if(!( room = find_object(__DIR__"valley")) )
                room = load_object(__DIR__"valley");
                if(objectp(room))
             {
              message_vision("$N钻出了小洞，眼前豁然一亮，原来是个开满鲜花的小山谷！\n",who);
              who->move(room);
             }
         return 1;
     }
     else
{
message_vision("$N试着往洞里爬，突然一股寒风吹来，$N全身都被冻僵了！\n",who);
who->recieve_damage(who->query("kee")/5);
who->recieve_wound(who->query("max_kee")/5);
who->start_busy(5);
return 1;
}
}
