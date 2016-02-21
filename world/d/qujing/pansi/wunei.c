// created by snowcat 11/16/1997

inherit ROOM;

void create ()
{
  set ("short", "屋内");
  set ("long", @LONG

石屋里清雅闲静，佛光笼罩，气氛极为祥和安宁。屋子中央有
一佛榻，左边有一紫竹供桌放着瓷盘玉盏，右边有一青铜鼎，
燃着缭绕香火。

LONG);

  set("exits", ([
        "out"    : __DIR__"shiwu",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

void init ()
{
  object who = this_player();

  remove_call_out("daogu_appearing");
  if (who->query_temp("obstacle/pansi_bixi") &&
      who->query("combat_exp") >= 10000 &&
      ! present("xiuhua zhen",who))
  {
    call_out("daogu_appearing",600,who,this_object());
  }
}

void daogu_appearing (object who, object where)
{
  object daogu;
  if (! who)
    return;

  if (environment(who) != where)
    return;

  daogu = new ("/d/qujing/pansi/npc/daogu");
  daogu->move(where);
  message_vision ("$N慢慢地在屋里显形……\n",daogu);
  remove_call_out("daogu_giving");
  call_out("daogu_giving",10,daogu,who,where);
}

void daogu_giving (object daogu, object who, object where)
{
  object needle;
  if (! who ||
      environment(who) != where)
  {
    remove_call_out("daogu_disappearing");
    call_out("daogu_disappearing",3,daogu);
    return;
  }

  needle = new ("/d/qujing/pansi/obj/needle");
  needle->move(daogu);
  daogu->command_function ("give "+who->query("id")+" xiuhua zhen");
  remove_call_out("daogu_disappearing");
  call_out("daogu_disappearing",3,daogu);
}

void daogu_disappearing (object daogu)
{
  message_vision ("$N慢慢地在屋里烟一般消失……\n",daogu);
  destruct(daogu);
}
