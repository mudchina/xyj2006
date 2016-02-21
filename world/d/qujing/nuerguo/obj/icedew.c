// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#define NAME "冰露珠项链"

inherit NECK;

void create()
{
  set_name(HIB NAME NOR, ({ "icedew lace", "icedew" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","一串透明的冰露珠项链，为西梁国的珍宝。\n");
    set("unit", "串");
    set("material", "icedew");
    set("armor_prop/armor", 1);
  }
  set("no_drop", "这是个价值连城的珠宝，哪能随便丢弃呢。\n");
  set("no_give", "这是个价值连城的珠宝，哪能随便丢弃呢。\n");
  set("no_sell", "这是个价值连城的珠宝，哪能随便丢弃呢。\n");
  set("is_monitored",1);
  setup();
  call_out ("autodestruct",60);
}

void init ()
{
  add_action ("do_wear", "wear");
}

void autodestruct ()
{
  object lace = this_object();
  object where = this_player();
  if (! where)
    where = environment (lace);

  if(where)   //mon 8/14/97
    message_vision ("只见"+NAME+"融化为一串亮晶晶的水珠不见了。\n",where);
  destruct (lace);
}

void disappear_fail (object me)
{
  object lace;
  lace = present("icedew lace",me);

  if (!lace)
    lace = present("icedew lace",environment(me));
  
  if (!lace)
    return;
  
  message_vision ("只见"+NAME+"在$N手中融化为一串亮晶晶的水珠，"+
                  "滴在地上不见了。\n",me);
  tell_object (me,"真可惜！\n");
  
  destruct (lace);
}

void disappear_success (object me)
{
  string dir;
  object queen;
  object lace;
  lace = present("icedew lace",me);

  if (!lace)
    lace = present("icedew lace",environment(me));

  if (!lace)
    return;

  message_vision ("$N戴上一串"+NAME+"。\n"+
                  "只见"+NAME+"变成一道银色的雾光，围着$N飞舞了几圈"+
                  "直向西空斜飞而去！\n",me);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  queen = new (dir+"npc/queen");
  queen->announce_success (me,"找到了"+NAME);
  destruct (queen);
  destruct (lace);
}

int do_wear (string arg)
{
  string dir;
  object queen;
  object me;
  me = this_player();

  if (arg != "icedew lace" &&
      arg != "icedew" &&
      arg != "all")
    return 0; // wearing something else

  if (me->query("obstacle/nuerguo") == "done")
  {
/*
    dir = __DIR__;
    dir[strlen(dir)-4] = 0;
*/
    dir = "/d/qujing/nuerguo/";
    queen = new (dir+"npc/queen");
    queen->refuse_player (me);
    destruct (queen);
    disappear_fail (me); 
    return 1;
  }  

  if (me->query("obstacle/nuerguo") == "stomachache")
  {
    disappear_fail (me);
    return 1;
  }  

  if (me->query("combat_exp")<2000)
  {
    disappear_fail (me);
    return 1;
  }  

  if (random(5) == 0)
    disappear_success (me);
  else
    disappear_fail (me); 
 
  return 1;
}
