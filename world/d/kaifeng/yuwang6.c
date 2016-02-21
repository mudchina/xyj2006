//Cracked by Roath
inherit ROOM;

void create ()
{
  set ("short", "禹王林");
  set ("long", @LONG

禹王林浓密浩瀚如海，远风吹过，林涛阵阵。雾从脚下生，有如一望
无际万里的纱帐飘渺似烟波海上。

LONG);

  set("exits", ([
        "west" : __DIR__"yuwang5",
      ]));
  set("no_fight",1);
  set("no_magic",1);
  set("no_mieyao",1); // mon 7/9/99
  set("alternative_die",1);
  set("outdoors", __DIR__);

  setup();
}

void alternative_die(object who)
{
  if (! userp(who) ||
      ! who->query_temp("ymdh/entered") ) {
    set("alternative_die",0);
    who->die();
    set("alternative_die",1);
    return;
  }
  __DIR__"yuwang5"->die(who);
}
void die(object who)
{
    alternative_die(who);
}

void init()
{
    // so can't leave immediately. prevent possible
    // another death if move out of this room.
this_player()->delete_temp("last_fainted_from");
    this_player()->start_busy(2);
}

