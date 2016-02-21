//sgzl

#include <room.h>
inherit ROOM;

int getflag;

void create()
{
set("short", "石房");
set("long", @LONG
    
一座宽大的石房，房内有石窝、石灶、石碗、石盆、石床、
石凳，各种家当。好一座天造地设的安身之所。正中间插着
一杆大旗(flag)，后面还有一张石床(bed)。
LONG );

set("item_desc",(["flag":"
一面迎风招展的三色大旗，在空旷之处迎风挥舞(wave)起来一定煞是好看，但似乎很难拔(ba)动。\n",

   "bed": "一张石床(gosleep,gobed,bed)。 \n", 
]));

set("exits", ([
"west"   : __DIR__"tiebanqiao",
"east"  : __DIR__"dongnei",
]));



set("objects", ([
//__DIR__"obj/flag" : 1,
]));

create_door("west", "石门", "east", DOOR_CLOSED);

setup();
}

void init()
{
   object ob = this_player();
   object houzi;
   object where = this_object();

   getflag=0;

      if(this_player()->query("dntg/huaguo")=="allow")
        {
         message_vision("一群猴子跟着$N蹦蹦跳跳的跑了过来。\n",this_player());
         if (! present ("hou zi 3", where))
           {
            houzi = new (__DIR__"npc/hou1");
            houzi->move(where);
            houzi->move(where);
           }
        }
   add_action("do_bed", "gosleep");
   add_action("do_bed", "gobed" );
   add_action("do_bed", "bed");

   add_action("do_ba", "ba");
}


int do_bed()
{       object me;
        me=this_player();
        message_vision("$N往石床上一躺，准备睡觉了。\n\n", me);
        me->move(__DIR__"shichuang");
            message_vision("\n$N钻到了被窝里。\n", me);
                return 1;
}


int do_ba(string arg)
{
        object me;
        object qi;

        me = this_player();
        if ( !arg || ( arg != "flag" ) ) 
            return notify_fail("你要拔什么？\n");
      if (present("flag",me)) return notify_fail("你不是已经有旗子了吗？\n");
        else if(getflag==1)  
            return notify_fail("大旗已经被别人拔走了，这里只留下一截旗杆。\n");
        else if(me->query("dntg/huaguo")=="done")  
            return notify_fail("你手握大旗，不禁想起自己当年在此称王的快乐时光。\n");
        else if ( random(10) < 5 )
          {
          if (me->query("kee")>200)  me->add("kee",-200); 
          else
            {
            me->unconcious();
            return 1;
            }
          message_vision("$N使尽吃奶的力气也没将大旗拔出来。\n", me);
          }

          else
            { 
            if (me->query("kee")>200)  me->add("kee",-200); 
            else
              {
              me->unconcious();
              return 1;
              }
            qi = new (__DIR__"obj/flag");
            qi->move(me);
            message_vision("$N大喝一声，将大旗拔了下来。\n", me);
            getflag=1;
            }
          return 1;
}

int valid_leave(object me, string dir)
{
 
   object ma;

   me=this_player();

   if (dir == "east" ) 
     {

        {
        if(me->query("dntg/huaguo")!="allow")
        return notify_fail("几只小猴子跑过来冲你喊到：＂我们正在选猴王，没事别来捣乱。＂\n小猴子又急匆匆的走了。\n");
        }



                return ::valid_leave(me,dir);
        }
        return ::valid_leave(me,dir);



}

