// created by snowcat.c 10/21/1997
// room: /d/qujing/chechi/sanqing.c

inherit ROOM;

void create ()
{
  set ("short", "三清殿");
  set ("long", @LONG

殿内左有大鼓右有铜钟，中间是一石案，上面是五色花瓶和青
石烛台，供有不少丰盛斋宴。四壁功德悬挂，殿心分别是元始
天尊，灵宝道君和太上老君。

LONG);

  set("exits", ([
        "south"        : __DIR__"dianmen",
        "north"        : __DIR__"houdian",
        "northeast"    : __DIR__"xiang1",
      ]));
  set("objects",([
        __DIR__"npc/yuanshi" : 1,
        __DIR__"npc/lingbao" : 1,
        __DIR__"npc/taishang" : 1,
        __DIR__"obj/zhengsu" : 1,
      ]));
  setup();
}

void daoshi_appear(object who)
{
  remove_call_out ("daoshi_appearing");
  call_out ("daoshi_appearing",3,who);
}

void daoshi_appearing(object who)
{
  object shi;
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("\n道士走了过来。\n",who);
  message_vision ("道士见状，喝道：“哪里来的草贼，竟敢偷吃供品！”\n",who);
  message_vision ("道士紧紧地跟上$N，大叫一声往死里打将起来！\n",who);
  shi = new("/d/qujing/chechi/npc/daoshi");
  shi->move(where);
  shi->set_leader(who);
  shi->kill_ob(who);
}

void daotong_appear(object who)
{
  remove_call_out ("daotong_appearing");
  call_out ("daotong_appearing",3,who);
}

void daotong_appearing(object who)
{
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("\n道童走了过来。\n",who);
  message_vision ("道童见状，唬得慌乱大声一道：“师父！圣象显灵了！”\n",who);
  message_vision ("只见道童一步一跌，向后殿奔去。\n\n",who);
  remove_call_out ("three_appearing");
  call_out ("three_appearing",3,who);
}

void three_appearing(object who)
{
  object yangli = new (__DIR__"npc/yangli");
  object huli = new (__DIR__"npc/huli");
  object luli = new (__DIR__"npc/luli");
  object where = this_object();

  if (where != environment(who))
    return;

  message_vision ("虎力大仙扬尘出现。\n",who);
  message_vision ("鹿力大仙闻声而来。\n",who);
  message_vision ("羊力大仙披着法衣赶来。\n",who);
  yangli->move(where);
  huli->move(where);
  luli->move(where);
}
