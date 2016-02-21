// by snowcat oct 15 1997
#include <armor.h>

inherit SURCOAT;

void create()
{
  set_name("兽皮披风", ({"shoupi pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件兽皮披风。\n");
    set("material", "leather");
    set("unit", "件");
    set("value", 700);
    set("armor_prop/armor", 35);
  }
  setup();
}

void init ()
{
  call_out("creating",2,this_object());
}

void equalize_attr (object who)
{
  int i;
// the second and thrid are too persimistic
// only enable the first formula to test
// note that need to test attr with different npcs
  i = who->query("per")-15+
      30-who->query("str")+
      who->query("cps")-10+
      who->query("kar")-10;
  if (i - who->query_temp("apply/courage") > 10)
    who->set_temp("apply/courage",i+i+random(3));
  environment(this_object())->set_temp("apply/courage",i*i+random(3));
/*
  i = who->query("int")-20+
      30-who->query("con")+
      who->query("cor")-15+
      who->query("spi")-15;
  if (i - who->query_temp("apply/composure") > 10)
    who->set_temp("apply/composure",i+random(3));
  environment(this_object())->set_temp("apply/composure",i+random(3));

  i = who->query("cor")-20+
      25-who->query("kar")+
      who->query("per")-10+
      who->query("int")-25;
  if (i - who->query_temp("apply/spirituality") > 10)
    who->set_temp("apply/spirituality",i+random(3));
  environment(this_object())->set_temp("apply/spirituality",i+random(3));
*/
}

object *obs;
void creating (object me)
{
  object who = environment(me);
  int i;

  if (! who)
    return;

  if (! who->is_fighting())
    return;

  if (who->query_temp("already_ready"))
    return;

  if (interactive(who))
    return;

  obs = who->query_enemy();
  i = sizeof (obs);
  while (i--)
  {
    equalize_attr(obs[i]);
  }
}

void remove()
{
  int i;

  i = sizeof (obs);
  while (i--)
  {
    if (obs[i])
      obs[i]->set_temp("apply/courage",0);
   }
}

