// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "二洞门");
  set ("long", @LONG

二洞门比一洞门略小一点，洞门里是犬牙交错的怪石，从洞顶
上倒垂下来。东北方向有一通道引向一洞门，南边有入口通向
洞里。

LONG);

  set("exits", ([
        "northeast"   : __DIR__"yidong",
        //"south"   : __DIR__"sandong",
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
      dir == "south")
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
    if (! this_object()->query("exits/south"))
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
    this_object()->set("exits/south", __DIR__"sandong");
    remove_call_out ("close");
    call_out ("close",60);
  }
  return 1;
}

void close ()
{
  if (this_object()->query("exits/south"))
    tell_room (this_object(),"乓地一声门又关死了！\n");
  this_object()->delete("exits/south");
}
