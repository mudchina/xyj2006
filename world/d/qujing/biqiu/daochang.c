// created by snowcat 11/21/1997

inherit ROOM;

string *msgs = ({
  "求经者，万缘都罢。",
  "了性者，诸法皆空。",
  "大智闲闲，澹泊在不生之内。",
  "真机默默，消遥于寂灭之中。",
  "三界空而百端治，六根净而千种穷。",
  "若乃坚诚知觉，须当识心。",
  "心净则孤明独照，心存则万境皆清。",
  "真容无欠亦无余，生前可见。",
  "幻相有形终有坏，分外何求。",
  "行功打坐，乃为入定之原。",
  "布惠施恩，诚是修行之本。",
  "大巧若拙，还知事事无为。",
  "善计非筹，必须头头放下。",
  "但使一心不动，万行自全。",
  "若云采阴补阳，诚为谬语，服饵长寿，实乃虚词。",
  "只要尘尘缘总弃，物物色皆空。",
  "素素纯纯寡爱欲，自然享寿永无穷。",
});

void create ()
{
  set ("short", "佛道场");
  set ("long", @LONG

佛道场为一大厅堂，由十二根黄杨木柱子撑起。两面有通光明
窗南北向开设，地上一排排铺着蒲团，有一些佛家道客坐在一
起讲佛论道。东边有一门通向大街。

LONG);

  set("exits", ([
        "east"    : __DIR__"jie11",
      ]));
  setup();
}

void init ()
{
  add_action ("do_zuochan", "zuochan");
}

int do_zuochan ()
{
  object who = this_player();
  int size = sizeof(msgs);
  int i = who->query_temp("obstacle/biqiu_zuochan");
  int j;

  if (who->is_busy())
    return notify_fail ("你正忙着呢！\n");

  message_vision ("$N盘膝而坐，合掌闭目。\n",who);
  if (i >= size)
  {
    message_vision ("\n$N沉思少顷，觉得禅意似乎已尽。\n",who); 
  }  
  else
  {
    j = i*18+10;
    who->start_busy (j,j);
    call_out ("start_zhuochan",5,who,i);
    call_out ("finish_zhuochan",j,who);
  }
  return 1;
}

void start_zhuochan (object who, int i)
{
  message_vision ("\n$N念道："+msgs[i]+"\n",who); 
  message_vision ("\n片刻，$N开始低首坐禅。\n",who); 
  who->set_temp("obstacle/biqiu_zuochan",i+1);
}

void finish_zhuochan (object who)
{
  object where = environment(who);

  who->interrupt_me ();
  message_vision ("\n$N坐禅完毕，起身。\n",who); 
  // much slower than normal speed, just a symbolic reward
  where->add("times",1);
  if (where->query("times") < 200)
  {
    who->add("potential",random(3)+1);
    tell_object(who,"你的潜能又增长了！\n");
  }
}
