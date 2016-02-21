// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "一洞门");
  set ("long", @LONG

一个天然形成的石头门，门上的石桥上有藤蔓挂下来，门的两
边长着奇松怪柏，从里面漫出一股股浓烈的兽妖气，使人有点
头昏目眩。

LONG);

  set("exits", ([
        "out"   : __DIR__"dongkou",
        //"southwest"   : __DIR__"erdong",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 4,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object yao = present ("yao jing", this_object());

  if (yao && 
      living (yao) &&
      dir == "southwest")
    return notify_fail (yao->query("name")+"拉拉扯扯揪住你不放。\n");
  return ::valid_leave(who, dir);
}

void init ()
{
  add_action ("do_break", "break");
  add_action ("do_break", "za");
}

int do_break ()
{
  object who = this_player ();
  object weapon = who->query_temp("weapon");

  if (! weapon)
  {
    message_vision ("$N赤膊上阵捏着拳头往石门上一砸！\n",who);
    message_vision ("乓地一声$N只觉得骨头都震碎了！\n",who);
    who->unconcious();
  }
  else
  {
    message_vision ("$N运气自丹田，高举$n往门上一砸！\n",who,weapon);
    if (! this_object()->query("exits/southwest"))
      message_vision ("乓地一声门开了！\n",who);
    else
      message_vision ("乓地一声砸在已经打开的门上！\n",who);
    if (who->query("force") <= 200 ||
        who->query("mana") <= 200)        
      who->unconcious();
    else
    {
      who->add("force",-200);
      who->add("mana",-200);
    }
    this_object()->set("exits/southwest", __DIR__"erdong");
    remove_call_out ("close");
    call_out ("close",60);
  }
  return 1;
}

void close ()
{
  if (this_object()->query("exits/southwest"))
    tell_room (this_object(),"乓地一声门又关死了！\n");
  this_object()->delete("exits/southwest");
}
