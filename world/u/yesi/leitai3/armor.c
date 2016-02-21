// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "盔甲库");
  set ("long", @LONG

盔甲库里一排镶银檀木架上放着大大小小的标准盔甲护具，比
武的人来这里向巫师领取合适的盔甲护具。巫师可从檀木架子
上拿(take)护具分发给参加大会的赛手。架子上放有：
  铠甲：      armor
  盾牌：      shield
  靴子：      boots
  指套：      finger
  手套：      hands
  头盔：      head
  围脖：      neck
  披风：      surcoat
  腰带：      waist
  护腕：      wrists

LONG);

  set("exits", ([
        "west"   : __DIR__"east",
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
  if (arg == "armor")
    ob = new ("/d/obj/armor/standard/armor");    
  else if (arg == "shield")
    ob = new ("/d/obj/armor/standard/shield");    
  else if (arg == "boots")
    ob = new ("/d/obj/armor/standard/boots");    
  else if (arg == "finger")
    ob = new ("/d/obj/armor/standard/finger");    
  else if (arg == "hands")
    ob = new ("/d/obj/armor/standard/hands");    
  else if (arg == "head")
    ob = new ("/d/obj/armor/standard/head");    
  else if (arg == "neck")
    ob = new ("/d/obj/armor/standard/neck");    
  else if (arg == "surcoat")
    ob = new ("/d/obj/armor/standard/surcoat");    
  else if (arg == "waist")
    ob = new ("/d/obj/armor/standard/waist");    
  else if (arg == "wrists")
    ob = new ("/d/obj/armor/standard/wrists");    
  else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
  return 1;
}



