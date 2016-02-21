//Cracked by Roath
// create by snowcat.c 2/8/1997

inherit ROOM;

void create ()
{
  set ("short", "兵器库");
  set ("long", @LONG

兵器库里一排绘金檀木架上放着各种各样的标准兵器，比武的
人来这里向巫师领取称手的兵器。巫师可从檀木架子上拿(take)
武器分发给参加大会的赛手。架子上放有：
  大板斧：    axe
  钢刀：      blade
  钢叉：      fork
  熟铜锏：    mace
  钢耙：      rake
  长枪：      spear
  禅杖：      staff
  镔铁棍：    stick
  长剑：      sword
  飞璜石：    throwing
  皮鞭：      whip
  匕首：      dagger
  铁锤：      hammer

LONG);

  set("exits", ([
        "east"   : __DIR__"west",
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
  if (arg == "axe")
    ob = new ("/d/obj/weapon/standard/axe");    
  else if (arg == "blade")
    ob = new ("/d/obj/weapon/standard/blade");    
  else if (arg == "dagger")
    ob = new ("/d/obj/weapon/standard/dagger");    
  else if (arg == "fork")
    ob = new ("/d/obj/weapon/standard/fork");    
  else if (arg == "hammer")
    ob = new ("/d/obj/weapon/standard/hammer");    
  else if (arg == "mace")
    ob = new ("/d/obj/weapon/standard/mace");    
  else if (arg == "rake")
    ob = new ("/d/obj/weapon/standard/rake");    
  else if (arg == "spear")
    ob = new ("/d/obj/weapon/standard/spear");    
  else if (arg == "staff")
    ob = new ("/d/obj/weapon/standard/staff");    
  else if (arg == "stick")
    ob = new ("/d/obj/weapon/standard/stick");    
  else if (arg == "sword")
    ob = new ("/d/obj/weapon/standard/sword");    
  else if (arg == "throwing")
    ob = new ("/d/obj/weapon/standard/throwing");    
  else if (arg == "whip")
    ob = new ("/d/obj/weapon/standard/whip");    
  else
    return notify_fail ("您要拿什么？\n");
  message_vision ("$N从架子上拿起$n。\n",who,ob);
  ob->move(who);
  return 1;
}



