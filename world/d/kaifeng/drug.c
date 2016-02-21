//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "御药库");
  set ("long", @LONG

御药库里有一汉白玉案台，上有各类名贵药丸药丹药粉，比武
的人来这里向巫师领取治伤的药物。巫师可从台上拿(take)药
分发给参加大会的赛手。台子上放有：
  金创药：          jinchuang
  混元丹：          hunyuan
  九转还魂丹：      dan
  还阳丹：          huanyang

LONG);

  set("exits", ([
        "north"   : __DIR__"south",
      ]));

  setup();
}

void init ()
{
  add_action ("do_take","take");
  add_action ("do_take","na");
}

int do_take (string arg)
{
  object who = this_player();
  object ob;

  if (! wizardp(who))
    return notify_fail ("对不起，请让巫师替您来拿东西。\n");

  if (! arg)
    return notify_fail ("您要拿什么？\n");
  if (arg == "jinchuang")
    ob = new ("/d/obj/drug/jinchuang");    
  else if (arg == "hunyuan")
    ob = new ("/d/obj/drug/hunyuandan");    
  else if (arg == "dan")
    ob = new ("/d/obj/drug/dan");    
  else if (arg == "huanyang")
    ob = new ("/d/obj/drug/huanyang");    
  else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从台上拿起$n。\n",who,ob);
  ob->move(who);
  return 1;
}



