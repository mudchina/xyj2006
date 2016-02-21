// created by wxb 12/24/1998
// room: /d/qujing/huangfeng/npc/shoumenyao.c

#include <ansi.h>
inherit NPC;

void create()
{
  set_name("守门妖", ({"shoumen yao", "yao", "shou men", "shoumen"}));
  set("long","一个虎头虎脑的小妖，看上去傻乎乎的。\n");
  set("gender", "男性");
  set("age", 20+random(15));
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 130000);
  set_skill("unarmed", 100);
  set_skill("parry", 100);
  set_skill("dodge", 100);
  set_skill("blade", 100);
  set_skill("bingpo-blade", 100);
  map_skill("blade", "bingpo-blade");
  map_skill("parry", "bingpo-blade");

  setup();
  carry_object("/d/obj/weapon/blade/blade")->wield();
  carry_object("/d/obj/armor/tenjia")->wear();
}
void init()
{
  object me;

  ::init();
  if( interactive(me = this_player()) && !is_fighting() ) {
    call_out("greeting", 1, me);
  }
}

void greeting(object me)
{
  int myspells, mykar, diff;
  string npcname=this_object()->query("name");

  if( !me || environment(me) != environment() ) return;

  myspells=me->query_skill("spells");
  mykar=me->query_kar(); 
  diff=40-mykar;

  if( member_array("hu xianfeng",me->parse_command_id_list())==-1)
    {
      command("say 什么东西？竟敢在我们黄风洞里乱闯！");
      kill_ob(me);
      return;
    }
  if( random(myspells+mykar) > diff) return;
  else
    {
      message_vision(CYN ""+npcname+"对$N大喝道：呔！什么东西！？休想从老子眼下溜过去！\n"NOR, me);
      message_vision(npcname+"大喊一声：现！$N顿时现出原形，原来是"+me->query("name")+"！\n", me);
      me->delete_temp("spellslevel");
      me->delete_temp("d_mana");
      me->delete_temp("apply/name");
      me->delete_temp("apply/id");
      me->delete_temp("apply/short");
      me->delete_temp("apply/long"); 
      kill_ob(me);
      return;
    }
}