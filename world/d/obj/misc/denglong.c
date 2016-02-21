// created 4/5/1997 by snowcat
#include <ansi.h>
#include <dbase.h>
#include <armor.h>
#include <weapon.h>

inherit STICK;

string *names = ({
  "莲花灯",
  "桔花灯",
  "青龙灯",
  "金凤灯",
  "麒麟灯",
  "翡翠灯",
  "玉兔灯",
  "兰花灯",
  "朝阳灯",
  "走马灯",
  "梦幻灯",
  "云雾灯",
});

void create()
{
  seteuid(getuid());

  set_name(names[random(sizeof(names))], ({ "deng long", "deng", "long"})); 
  set_weight(900);
  set("long","一杆紫竹把儿的"+query("name")+"。\n");
  set("unit", "个");
  set("armor_prop/armor", 1);
  set("armor_prop/personality", 1);
  set("armor_type", "lamp");
  set("wear_msg", "\n$N将灯笼挑过头顶。\n");
  set("wield_msg", "\n$N将灯笼挑过头顶。\n");
  set("unequip_msg", "$N将灯笼放下来。\n");
  set("unwield_msg", "$N将灯笼放下来。\n");
  setup();
  init_stick(1);
}

int init ()
{
  add_action ("do_wear", "wear");
  //add_action ("do_wear", "wield");
  add_action ("do_remove", "remove");
  //add_action ("do_remove", "unwield");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object denglong = this_object();
  int i;
  int j = 0;
  string people = "";
  object *obs = all_inventory(environment(me));

  if (! arg)
    return 0;
  if (present (arg,me) != denglong)
    return 0;

  i = sizeof (obs);
  while (i--)
  {
    if (living (obs[i]) && obs[i]!=me)
    {
      j++;
      people = people + obs[i]->name();
    }
  }
  message_vision ("$N手一扬，悠起一杆$n，用火点亮。\n",me,denglong);
  remove_call_out ("reacting");
  call_out ("reacting",1+random(3),me,people,j);
  return 0;
}

void reacting (object me, string people, int j)
{
  if (j == 0)
    return;

  if (j == 1)
    message_vision (people+"忍不住叫道：好灯！好灯！\n",me);
  else
    message_vision (people+"等人忍不住齐声叫道：好灯！好灯！\n",me);
}

int do_remove (string arg)
{
  object me = this_player();
  object denglong = this_object();

  if (! arg)
    return 0;
  if (present (arg,me) != denglong)
    return 0;

  message_vision ("$N嘴巴凑近$n，噗地轻轻一吹。\n",me,denglong);
  return 0;
}

