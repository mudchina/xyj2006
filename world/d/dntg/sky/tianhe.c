//sgzl

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "天河");
set("long", @LONG
    
无数星星汇合成了这条宽广的银河，据说这是当年王母娘娘
用她头上的银簪划出的，在这美丽的银河之畔，不知发生了
多少动人的故事。
LONG );


set("exits", ([
]));


set("objects", ([
]));



setup();
}

void init()
{
  object who = this_player();
  add_action("do_swim", "swim");
  add_action("do_xiayu", "xiayu");
  if(who->query("dntg/bmw")=="fight") call_out ("fight_river",3,who);
}

int do_swim()
{
object who = this_player();
object horse = who->query_temp("ridee");
if(who->is_busy()||who->query_temp("pending/exercising")
||who->is_fighting()
          ||who->query_temp("pending/meditating"))
return notify_fail("你正忙着,不怕淹死?\n");

if (! horse) 
  {
  message_vision(HIY "$N纵身跳出天河。\n" NOR, who);
  who->move(__DIR__"dadao1");
  }
else 
  {
  message_vision(HIY "$N"+horse->query("ride/msg")+"着"+horse->name()+"跳出天河。\n" NOR, who,horse);
  who->move(__DIR__"dadao1");
  horse->move(__DIR__"dadao1");
  }
return 1;
}

int do_xiayu()
{
object who = this_player();
object fu;
if ( present("feng ling fu", this_player()) 
     && present("yun ling fu", this_player()) 
     && present("lei ling fu", this_player()) 
     && present("dian ling fu", this_player()) 
    )
  {
  message_vision(HIY "$N伸手一指，天空中飘过一朵乌云。\n" NOR, who);
  fu=present("feng ling fu", this_player());
  destruct(fu);
  fu=present("yun ling fu", this_player());
  destruct(fu);
  fu=present("lei ling fu", this_player());
  destruct(fu);
  fu=present("dian ling fu", this_player());
  destruct(fu);
  call_out ("get_rain",3,who);
  }
else 
  {
  message_vision("$N还是凑齐＂风＂，＂云＂，＂雷＂，＂电＂四张灵符再来下雨吧。\n", who);
  }
return 1;
}

void get_rain (object who)
{
  object horse = who->query_temp("ridee");

  message_vision(HIY "转瞬间，天空中电闪雷鸣，下起了飘泼大雨。\n" NOR, who);
  if ((who->query("dntg/bmw") == "allow")  && (horse) )
    {
    if ((horse->query("kee")>200) && (horse->query("id")=="ma ju"))
          call_out ("become_horse",3,who);
    }
}

void become_horse (object who)
{
  object horse = who->query_temp("ridee");
  message_vision("小马驹在雨中高兴的长鸣一声。\n", who);
  message_vision(HIY "小马驹长大了！\n" NOR, who);
  destruct(horse);
  horse = new ("/d/dntg/bmw/npc/horse");
  horse->move(environment(who));
  who->command("mount horse");
  who->set("dntg/bmw","fight");
  call_out ("fight_river",3,who);
}

void fight_river (object who)
{
  object fighter;

  fighter=new("/d/dntg/sky/npc/tianpeng");
  fighter->move(environment(who));
  message_vision("忽然天蓬元帅急急忙忙赶来，对你大喝道：敢来天河造次，反了不成？\n", who);
  fighter->command("follow " + who->query("id"));
  fighter->command("kill " + who->query("id"));
  who->fight_ob(fighter);
  
}
