// create by snowcat.c 12/15/1997

inherit ROOM;

void create ()
{
  set ("short", "洞内");
  set ("long", @LONG

宽敞的洞内雾气腾腾，洞顶上长着粗长的青藤，从头上挂下来。
洞壁插着兽油火把，吱吱地冒着烟，将洞内照亮。洞的地上填
得平平整整，铺着一块一块石板。

LONG);

  set("exits", ([
        "north"   : __DIR__"dongnei2",
        "northeast"   : __DIR__"dongnei3",
      ]));
  set("objects", ([
        __DIR__"npc/yao"   : 2,
        __DIR__"obj/rou"   : 3,
      ]));

  setup();
}

void init ()
{
  add_action ("do_dig","dig");
}

int do_dig (string arg)
{
  object who = this_player ();
  object where = this_object ();
  object sha;

  if (who->is_fighting())
    return notify_fail ("你正在战斗之中，如何挖掘金丹砂？\n");

  if (who->is_busy())
    return notify_fail ("你正在忙着呢。\n");

//  if (where->query("has_digged"))
//  {
//    message_vision ("$N在洞角的土中胡乱扒拉了一番，什么也没有找到。\n",who);  
//    return 1;
//  }

  if (random(10))
  {
    message_vision ("$N在洞角的土中仔细地扒拉了一番，没有找到东西。\n",who);  
    who->start_busy(2);
  }
  else
  {
    sha = new (__DIR__"obj/jindan");
    message_vision ("$N在洞角的泥土中双手一扒，捧出一包东西。\n",who);  
    message_vision ("$N将纸包揭开，取出$n揣在怀里。\n",who,sha);
    sha->move(who);  
    where->set("has_digged",1);
  }
  return 1;
}

