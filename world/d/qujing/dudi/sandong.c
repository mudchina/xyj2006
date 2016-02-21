// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "三洞门");
  set ("long", @LONG

三洞门里气氛严肃，戒备森严，一群大小妖精聚在一起守候在
门边。门的左边有一高大的石鼓，右边是一面铜花锣。东南边
通向里面的洞厅。

LONG);

  set("exits", ([
        "north"   : __DIR__"erdong",
        //"southeast"   : __DIR__"dongting",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 5,
      ]));

  setup();
}

int valid_leave (object who, string dir)
{
  object yao = present ("yao jing", this_object());

  if (yao && 
      living (yao) &&
      dir == "southeast")
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
    if (! this_object()->query("exits/southeast"))
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
    this_object()->set("exits/southeast", __DIR__"dongting");
    remove_call_out ("close");
    call_out ("close",60);
  }
  return 1;
}

void close ()
{
  if (this_object()->query("exits/southeast"))
    tell_room (this_object(),"乓地一声门又关死了！\n");
  this_object()->delete("exits/southeast");
}

