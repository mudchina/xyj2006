// created 4/5/1997 by snowcat
#include <ansi.h>
#define NAME "Î÷ÁºÅûËªÏÉºó"

inherit NPC;

void create()
{
  set_name(NAME, ({"xiliang xianhou", "queen"}));
  set("title", "³¿êØÅ®Éñ");
  set("gender", "Å®ĞÔ");
  set("age", 23);
  set("long", "Î÷ÁºÅûËªÏÉºó³¿êØÅ®Éñ¡£\n");
  set("combat_exp", 1000000);
  set("daoxing", 1000000);

  set_skill("snowsword", 100);
  set_skill("sword", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 120);
  set_skill("parry", 120);
  set_skill("dragonstep", 120);
  map_skill("dodge", "dragonstep");
  map_skill("sword", "snowsword");
  map_skill("parry", "snowsword");
  set("force", 900);
  set("max_force", 900);
  set("force_factor", 10);

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/obj/weapon/sword/feijian")->wield();
}

void init()
{
  ::init();
}

void announce_success(object who, string reason)
{//disabled announce and reward...
  int i;

  i = random(500);
if (who->query("obstacle/nuerguo") == "done")
return;
  who->add("obstacle/number",1);
  who->set("obstacle/nuerguo","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+reason+"£¬Ë³Àû´³¹ıÎ÷ĞĞÒ»¹Ø£¡");
  command("chat Î÷ÁºÉÏÏÂ±¼×ßÏà¸æ£¡");
tell_object(who,"ÄãÓ®µÃÁË"+chinese_number(3)+"Äê"+chinese_number(i/4)+"Ìì"+chinese_number((i-(i/4)*4)*3)+"Ê±³½µÄµÀĞĞ£¡");
  command("chat "+who->name()+"Ó®µÃÁË"+chinese_number(i)+"Ê±³½µÄµÀĞĞ£¡");
  who->save();
  message_vision (HIY NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void refuse_player(object who)
{
  string name;
  name = who->name();
  message_vision (HIY NAME+"Í»È»´Ó°×ÎíÖĞÉÁ³öÏò$NÒ¡Ò¡Í·£º"+
                  "ÄúÒÑ´³¹ıÎ÷ÁºÕâÒ»¹ØÁË¡£¿ìÈ¥Î÷ÌìÈ¡¾­°É¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ"+NAME+"ÔÚÒ»Õó°×ÎíÖĞĞìĞìÏûÊ§¡£\n" NOR,who);
}

void stop_access(object who)
{
  string name;
  name = who->name();

  message_vision (HIY NAME+"´ÓÒ»ÍÅ°×ÎíÖĞÏÔ³ö£¬¸æËß$N£º"+
                  "ÄúÉĞÎ´´³¹ıÎ÷ÁºÕâÒ»¹Ø£¬¶Ô²»Æğ¡£\n" NOR,who);
  message_vision (HIY "Ëµ°Õ°×ÎíÓµ×Å"+NAME+"ÔÚ¿ÕÖĞÂıÂıµØÏûÊ§¡£\n" NOR,who);
}
ÿ
