// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "山坡");
  set ("long", @LONG

山坡上长着古树青藤，路上枯枝落叶遍地，坡边高高低低长着
灌木蒿草，夹杂着一些大大小小的岩石。坡下幽幽深深，不时
可见沟渠洞穴。

LONG);

  set("exits", ([
        "west"   : __DIR__"shanpo13",
        "east"   : __DIR__"shanpo15",
      ]));
  set("outdoors", __DIR__);

  setup();
}

void init ()
{
  object who = this_player();
      
  if (who && interactive(who))
    call_out ("appearing", 1, who);
}

void appearing (object who)
{
  object where = this_object();
  object jing;

  if (! who ||
        environment(who) != where)
    return;

  if (! present ("tu jing 5", where))
  {
    jing = new (__DIR__"npc/tu");
    jing->move(where);
    message_vision ("路边嗖地一声$N蹿了过来。\n",jing);
  }
}


