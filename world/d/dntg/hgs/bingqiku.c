//sgzl

#include <room.h>
inherit ROOM;

void create()
{
set("short", "兵器库");
set("long", @LONG
    
这里是傲来国的兵器库，里面各种兵器(bingqi)：刀、枪、
剑、戟、斧、钺、毛、镰、鞭、钯、挝、锏、弓、弩、叉、
矛，件件俱备。整整齐齐的堆放着，几个威武的武士在这
里保守着。
LONG );

set("item_desc",(["bingqi":"
各种各样的兵器，看来想拿走不方便，得捆(kun)一下才好拿。\n"
]));

set("exits", ([
  "north"   : __DIR__"fight_room",
]));


set("objects", ([
  __DIR__"npc/pianjiang" : 4,
]));


set("no_magic", 1);

setup();
}


void init()
{
   add_action("do_kun", "kun");
   add_action("do_ji", "ji");
}


int do_kun(string arg)
{
  object me=this_player();
  object bingq;

  if ( !arg || ( arg != "bingqi" ) ) 
      return notify_fail("你要捆什么？\n");

  if(objectp(present("pian jiang", environment(me)))) 
     {
     return notify_fail("偏将大喝道：敢动我国兵器库里的东西，反了不成？\n",me);
     }

  else
    {
    if (me->is_busy())
      return notify_fail ("你正在忙着呢。\n");

    else if (me->query("kee")<50)  me->unconcious(); 

    else
      {
      me->add("kee",-50);
      message_vision ("$N急急忙忙收拾起一堆兵器，捆了捆，背了起来，又撒了一些。\n",me);
      bingq = new ("/d/dntg/hgs/obj/bingqi");
      bingq->move(me);
      me->start_busy(5,5);

      return 1;
      }
    }
    return 1;
}


int do_ji(string arg)
{
        object who;
        object where = this_object();
        object hb = this_object();
        object me = this_player();

        if ( !arg || ( arg != "feng ling fu" ) ) return  notify_fail("你想祭什么？\n");

        else if (!(hb=present(arg, me)) || userp(hb))  // prevent using "bian"
           return notify_fail("你身上没有这东西。\n");
    
        else if (me->query("mana")+random(500)<1000)
          {
          message_vision("$N拿出风灵符，大喝一声：“风来！”\n", me);
          message_vision("但什么也没有发生。”\n", me);
          destruct(hb);
          }
        else
          { 
          message_vision("$N拿出风灵符，大喝一声：“风来！”\n", me);
          call_out("away",2,me);
          destruct(hb);
          call_out("go_back",60,me);
          }

        return 1;
}

void away(object who)
{
  object where = this_object();
  object who1 = present ("pian jiang 1",where);
  object who2 = present ("pian jiang 2",where);
  
  if(!who1) return;

  destruct(who1);
  destruct(who2);
  tell_object(where,
	  "只见一股狂风刮过，吹得人们都挣不开眼，几个偏将哭嚎着跑了出去。\n");
}

void go_back(object who)
{
  object who1,who2;
  object where = this_object();

  // mon 3/24/99
  // prevent getting too many pian jiang by go_back.
  // at most 4.
  if(present ("pian jiang 4",where)) return;

  who1 = new (__DIR__"npc/pianjiang");
  who2 = new (__DIR__"npc/pianjiang");
  who1->move(where);
  who2->move(where);
  tell_object(where,"偏将们揉着眼睛走回兵器库。\n");
}


