#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_BACKUP;
inherit F_DAMAGE;

string inputstr,verb;

int query_autoload()
{ return 1; }
void create()
{
  seteuid(getuid());

set("long",@LONG
    ÕâÊÇÒ»¿ÅÉñÆæµÄÄ§·¨[1;32mĞÇĞÇ[2;37;0m£¬ËüÊÇÓÉ¾ÅÇ§¾Å°Ù¾ÅÊ®¾Å¿ÅÇéÈËµÄÑÛÀáµÎÖÆ¶ø³É£¬Íò·ÖÕä¹ó¡£

    ¼üÈë<help star>ÒÔ»ñµÃ¸ü¶àµÄÄ§·¨¡£

LONG
);

  set("unit","¿Å");
  set("value", 10000);
  set("material", "ring");
  set("armor_prop/armor", 100);
  set("armor_type", "cape");
  set("light",1);
  set("unequip_msg","$N½«[1;32m¡î¡î[2;37;0mÇáÇáµØÕªÏÂÀ´¡­¡­¡£\n");
  set("wear_msg", "$N´÷ÉÏ[1;32m¡î¡î[2;37;0m£¬¶ÃÎïË¼ÈË£¬²»½ûÁ÷³ö¼¸µÎÏàË¼µÄÀáË®¡£\n");
  set("no_give","ÕâÃ´Õä¹óÖ®Îï£¬ÄÄÄÜËæ±ã×ªÔù¸øÈË£¿\n");
  set("no_drop","ÕâÃ´Õä¹óÖ®Îï£¬ÈÓÁË¶à¿ÉÏ§Ñ½£¡\n");
    set("no_sell","·²ÈËÄÄÀïÖªµÀ"+this_object()->query("name")+"µÄ¼ÛÖµ£¿»¹ÊÇ×Ô¼ºÁô×Å°É¡£\n");
  setup();
}
void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
    set_name (me->name(1)+ "µÄ[1;32m¡î¡î[2;37;0m", ({ "my star", "star" }));
  else
    set_name ("¡î¡î", ({ "my star", "star" }));

   add_action("help","help");
   add_action ("do_wakeup", "wakeup");
   add_action("full","full");
  this_player()->set_temp("heat",1);
}

int help(string str)
{

  if (str!="star") return 0;

write(@Help
    
    Äã¿ÉÒÔÊ¹ÓÃÒÔÏÂµÄÃüÁî:
       
       wakeup <Íæ¼Ò>                    <°Ñ»èÃÔ²»ĞÑµÄÍæ¼Ò½ĞĞÑ>
       full <Íæ¼Ò>                      <È«Ò½, Íæ¼ÒÈôÎŞÊäÈëÔòÄÚ¶¨Îª×Ô¼º>
       
          ×¢£ºÕâ¿ÅĞÇĞÇÖ»¿ÉÒÔÊ¹ÓÃÁù´Î£¬ÓÃÍêÁù´ÎºóËû½«Ê§È¥ËûÔ­ÓĞµÄÄ§Á¦¡£

Help

);

  return 1;
}


int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));
    if(me->query("id")!="gigi")
return notify_fail("ÕâÑù¶«Î÷ÄãÊÇ´ÓÄÄÍµÀ´µÄ£¿\n");
    if(query("used") >= 6)
          return notify_fail("ÕâÖ»[1;32mĞÇĞÇ[2;37;0mÒÑ¾­ÓÃ¹ıÁù±éÁË£¬±äµÃ÷öÈ»ÎŞÉ«¡£\n");

  if (!me) return notify_fail ("[star]: full error: ÕÒ²»µ½"+str+"\n");
max=me->query("max_sen");
me->set("eff_sen", max);
me->set("sen", max);
max=me->query("max_gin");
me->set("force", me->query("max_force"));
me->set("eff_gin", max);
me->set("mana", me->query("max_mana"));
me->set("atman", me->query("max_atman"));
me->set("gin", max);
max=me->query("max_kee");
me->set("eff_kee", max);
me->set("kee", max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();
  me->set("water",max);
  me->clear_condition();
  add("used", 1);

  message_vision( "$NµÎÏÂÁËÒ»¿Å¹öÌÌµÄ[1;36mÇéÈËÀá[2;37;0m,"+me->query("name")+"µÄÈ«²¿¾«Á¦Ñ¸ËÙ»Ö¸´ÁË¡£\n",this_player());

  return 1;
}

int do_wakeup (string str)
{
  object me,who;
  me=this_player();
  if (!str) return notify_fail ("[star]: wakeup error, wakeup <someone>\n");
  if(me->query("id")!="gigi")
return notify_fail("ÕâÑù¶«Î÷ÄãÊÇ´ÓÄÄÍµÀ´µÄ£¿\n");
  if(query("used") >= 6)
          return notify_fail("ÕâÖ»[1;32mĞÇĞÇ[2;37;0mÒÑ¾­ÓÃ¹ıÁù±éÁË£¬±äµÃ÷öÈ»ÎŞÉ«¡£¡£\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[cloak]: wakeup error, Ã»ÓĞ"+str+"\n");
   message_vision( "$N½«¸öÒ»¿Å[1;36mÏàË¼Ö®Àá[2;37;0mÇáÇáµÄµÎÂäÔÚÁË$nµÄÁ³ÅÓ¡£\n"+
   "$n½¥½¥»Ö¸´ÁËÖª¾õ¡£\n",me,who);
  who->remove_call_out("revive");
  who->revive();
  who->reincarnate();
  add("used", 1);

  return 1;
}
