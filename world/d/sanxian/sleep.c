inherit ROOM;
#include <ansi.h>
void create()
{
        set("short","小屋");
        set("long", @LONG

一间小屋，堆放了些柴木和细草，在这里勉强可以打个盹。
LONG
        );

        set("sleep_room",1);
        set("if_bed",1);

set("objects", ([
      
      
//        __DIR__"jiandao_book":1,
     ]) );  
        set("exits", ([
                "south" : __DIR__"huating",
"west" :  __DIR__"jianzhong",
        ]));

        setup();
}
void init()

{

add_action("do_search", "search");

}

int do_search(string arg)

{

int kar;

object book;

if(!arg) {

kar = this_player()->query("kar");

if(random(kar+20) < kar && query("research")) {

message_vision("在柴木和细草中$N细细摸索，突然$N触到了一块什么东西。\n", this_player());

message_vision("$N立刻拿起纳入怀中。\n", this_player());

book = new(__DIR__"jiandao_book");

book->move(this_player());
if(!this_player()->query("m_success/剑道遗篇"))
        {
                this_player()->set("m_success/剑道遗篇",1);
                this_player()->add("potential",200+random(200));
        }


set("research",0);

return 1;

}

}

return notify_fail("你在柴木和细草中细细摸索，却甚麽都没发现。\n");

}

void reset()

{

if(!random(10)) set("research",1);

}
