//sgzl

inherit ROOM;

void create ()
{
  set ("short", "瀑布前");
  set ("long", @LONG

只见那股涧水奔流，真个似滚瓜涌溅。顺涧爬山，直至源流之处，
乃是一股瀑布飞泉。但见那：

　　一派白虹起，千寻雪浪飞；海风吹不断，江月照还依。
　　冷气分青嶂，馀流润翠微；潺□名瀑布，真似挂帘帷。
LONG);


  set("exits", ([
            "west"   : __DIR__"shanya",
      ]));
  set("outdoors", 1);

  setup();
}

void init ()
{
  object who = this_player();
      
  add_action("do_jump", "jump");
  add_action("do_wave", "wave");

  if (who && interactive(who))
    call_out ("appearing", 1, who);
}

void appearing (object who)
{
  object me =this_player();
  object where = this_object();
  object houzi;

  if (! who ||
        environment(who) != where)
    return;

  if (! present ("hou zi 4", where))
  {
    houzi = new (__DIR__"npc/hou");
    houzi->move(where);
    message_vision ("树丛中蹿出一只$N。\n",houzi);
  }


}


int do_jump(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "pubu" ) ) return  notify_fail("你往哪儿跳？\n");

        else if ( random(30)+me->query("kar") < 30 )
//        else if ( (random(10)+me->query("kar")+me->query("donation/1000000")) < 40 )
          { 
          message_vision("$N向下一纵，不小心撞在了一块石头上。\n", me);
          me->unconcious();
          }

        else
          {
          message_vision("$N大喝一声：“我去瞧瞧！＂说罢飞身跃入瀑布。\n", me);
          me->move(__DIR__"pubu1");
          }

        return 1;
}

int do_wave(string arg)
{
        object me,who;
        object where = this_object();
        object hb = this_object();

        me = this_player();
        if ( !arg || ( arg != "flag" ) ) return  notify_fail("你想挥舞什么？\n");

        else if (!(hb=present(arg, me))) 
           return notify_fail("你身上没有这东西。\n");
    
        else 
          { 
          message_vision("$N挥舞着起旗子，大喝一声：“大造化！大造化！下面没水！原来是一座铁板桥。桥那边是一座天造地设的家当。兄弟们快去呀！”\n", me);
          call_out("jumping",2,me);
          if(me->query("dntg/huaguo")!="done")  me->set("dntg/huaguo", "allow");
          destruct(hb);
          }

        return 1;
}

void jumping(object who)
{
  object where = this_object();
  object who1 = present ("hou zi 1",where);
  object who2 = present ("hou zi 2",where);
  object who3 = present ("hou zi 3",where);
  object who4 = present ("hou zi 4",where);
  destruct(who1);
  destruct(who2);
  destruct(who3);
  destruct(who4);
  message_vision("猴子们听罢争先恐后的跳下瀑布。\n", who);
}
