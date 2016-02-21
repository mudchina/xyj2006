
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create() {
  set("short", "兜率宫");
  set("long", @LONG
    
一间恬淡古雅，高不见顶的宽大宫殿。正中排着张香案，
案上放着朱漆托盘，盘内供着几粒刚炼得的九转金丹。楼
上是太上老君讲道的朱陵丹台，隐隐传来老君清亮爽朗的
声音，但你却找不到上楼的阶梯。西面有一扇竹门，门上
画着一个八卦图案，门内就是老君炼丹的丹房。

LONG );


  set("exits", ([
    "west"   : __DIR__"danfang",
    "out" : __DIR__"gate",
  ]));

  set("objects",([
    __DIR__"obj/jindan": random(2)+1,
    __DIR__"npc/daoshi": 1,
  ]));

  setup();
}

void init() {
  add_action("do_get",({"get","eat"}));
  if (userp(this_player()))   call_out("force_leave",300,this_player());
}

void force_leave(object me) {
  if (environment(me)!=this_object()) return;
  message_vision(HIB"空中传来太上老君的声音：“何人在我兜率宫内喧哗？”\n",me);
  message_vision("$N做贼心虚，吓得魂不附体，转身一溜烟逃回花果山去了。\n"NOR,me);
  me->move("/d/dntg/hgs/flowerfruit");
  if (me->ride()) me->ride()->move(environment(me));
}
int do_get(string arg) {
   object daoshi;
   if (!arg) return 0;
  
   daoshi=present("dao shi",this_object());
   if (daoshi && living(daoshi)) {
      daoshi->command("hmm");
      daoshi->command("waggle "+this_player()->query("id"));
      this_player()->start_busy(1);
      return 1;
   }
   return 0;
}

int valid_leave(object me, string dir) {
    if ( dir == "west")
        {
            if( (string)me->query("family/family_name")!="五庄观" )
                 return notify_fail("你围着八卦门绕了几圈，又回到了原地。\n");
                 return 1 ;
        }   
    return ::valid_leave(me, dir);
}
  
