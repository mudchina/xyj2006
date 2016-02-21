//sgzl


#include <room.h>
inherit ROOM;
inherit "/d/dntg/hell/hell_sleep.c";
//the starting point of passing dntg_hell

void create()
{
set("short", "铁板桥");
set("long", @LONG
    
你欠身上桥头，再走再看，却似有人家住处一般，真个好所在。但见那：

　　翠藓堆蓝，白云浮玉，光摇片片烟霞。虚窗静室，滑凳板生花。乳窟
　　龙珠倚挂，萦回满地奇葩。又见那一竿两竿修竹，三点五点梅花。几
    树青松常带雨，浑然相个人家。

看罢多时，跳过桥中间，左右观看，只见正当中有一石碣(shi jie)。
LONG );

set("item_desc",(["shi jie":"
　□□□　　　　□□□
　□水□　　　　□花□　　　　
　□帘□　　　　□果□　　　　　
　□洞□　　　　□山□　　　　
　□洞□　　　　□福□　　　　
　□天□　　　　□地□　　　　
　□□□　　　　□□□
　\n"
]));



set("exits", ([
"east"   : __DIR__"shifang",
]));


set("objects", ([
]));


create_door("east", "石门", "west", DOOR_CLOSED);


setup();
}

void init ()
{
  object who = this_player();
  ::init();
      
  add_action("do_jump", "jump");

}

int do_jump(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "bridge" ) ) return  notify_fail("你往哪儿跳？\n");

//        else if ( (random(10)+me->query("kar")+me->query("donation/1000000")) < 40 )
        else if ( random(30)+me->query("kar") < 30 )
          { 
          message_vision("$N奋力向上一跃，又从半空中摔了下来。\n", me);
          me->unconcious();
          }

        else
          {
          message_vision("$N从桥上飞身纵出瀑布。\n", me);
          me->move(__DIR__"pubu");
          }

        return 1;
}

