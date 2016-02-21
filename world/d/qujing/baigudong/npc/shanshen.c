// written by smile 12/09/1998

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("黑面山神", ({"heimian shanshen", "shanshen"}));
  set("gender", "男性");
  set("age", 70);
  set("attitude", "friendly");
  set("combat_exp", 730000);
  set("per", 20);
  set_skill("dodge", 100);
  set_skill("force", 100);
  set_skill("parry", 100);
  set_skill("spells",100);
  set_skill("dao", 100);
  set_skill("puti-zhi", 100);
  set_skill("jindouyun", 100);
  set_skill("wuxiangforce",100);
  map_skill("force","wuxiangforce");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("spells", "dao");
  set("max_sen",1800);
  set("max_gee",1800);
  set("max_gin",1800);
  set("force",800);
  set("max_force",800);
  set("max_mana",1280);
  set("force_factor",60);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}



void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 100000)
     {
        message_vision("黑面山神对你一拱手，道行不够强求亦枉然！\n",who);
    return;
     }
  if (who->query("obstacle/baigudong") == "done")
     {
       message_vision(HIY"黑面山神对$N一拱手，又慢慢消失于山壁中！\n" NOR,who);
    return;
     }
  if (! who->query_temp("obstacle/baigudong_nuzi_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_furen_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_gonggong_killed"))
    return;
  if (! who->query_temp("obstacle/baigudong_baigujing_killed"))
    return;
  i = random(600);
  who->add("obstacle/number",1);
     who->add("obstacle/potential",1);
  who->set("obstacle/baigudong","done");
  who->add("combat_exp",i+4000);
  command("chat "+who->query("name")+"白骨洞诛灭白骨精，为四方百姓造福！");
  command("chat "+who->query("name")+"顺利闯过西行又一关！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

