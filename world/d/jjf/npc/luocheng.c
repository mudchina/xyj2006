//created 8-5-97 pickle
//罗成 luocheng.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int handle_kill(object me);
int accept_fight(object me);
int attempt_apprentice(object me);
int recruit_apprentice(object me);
void check_fight (object npc, object me);
void player_win(object me);
void player_lose(object me);
void move_down(object ob);
void do_revive(object ob);

void create()
{
  set_name("罗成", ({"luo cheng", "luo", "cheng", "luocheng", "master", "shifu"}));
  set ("long", @LONG
罗成是秦琼的表弟，乃是隋唐第七条好汉。传说他早已
在保长安时被乱箭射死战死，但不知为何还在这里。听
说罗成年幼时曾受过异人传授，学得一身奇异的内功，
因此比武极少败过。
LONG);

  set("title", "开国元勋");
  set("gender", "男性");
  set("age", 34);
  set("str", 50);
  set("cor", 50);
  set("cps", 50);
  set("spi", 30);
  set("per", 30);
  set("con", 50);
  set("int", 30);
  set("kar", 15);
  set("combat_exp", 1800000);
  set_skill("literate", 80);
  set_skill("force", 180);
  set_skill("lengquan-force", 180);
  set_skill("parry", 180);
  set_skill("dodge", 150);
  set_skill("yanxing-steps", 120);
  set_skill("unarmed", 150);
  set_skill("changquan", 100);
  set_skill("mace", 100);
  set_skill("wusi-mace", 80);
  set_skill("spear", 180);
  set_skill("bawang-qiang", 150);
  map_skill("mace", "wusi-mace");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 3000);
  set("max_kee", 3500);
  set("force", 2000);
  set("max_force", 2000);
  set("force_factor", 100);
 
  create_family("将军府", 2, "蓝");
  setup();
 
  carry_object("/d/obj/weapon/spear/jinqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
void init()
{
	object ob;

	::init();
	if( interactive(ob = this_player()) && member_array(ob, query_enemy()) != -1)
	{
	    if (is_fighting())
	    {
		message_vision(CYN"罗成对$N喝道：“又是你！滚出去！”"NOR, ob);
		move_down(ob);
	    }
	    else do_revive(this_object());
	}
	add_action("do_kill", "kill");
        add_action("do_surrender", "surrender");
}
int do_surrender()
{
    this_player()->delete_temp("pending/jjf_apprentice_luocheng");
    return 0;
}
int do_kill(string arg)
{
    if(!id(arg)) return 0;
    handle_kill(this_player());
    return 0;
}
int handle_kill(object me)
{
    if(is_fighting())
    {
        message_vision(CYN"罗成抱拳道：众位，既然$N想要拼命，还请稍候片刻。\n"NOR, me);
        this_object()->remove_all_enemy();
    }
    do_revive(this_object());
    command("kill "+me->query("id"));
}
int accept_fight(object me)
{
  if(me->query_temp("pending/jjf_apprentice_luocheng"))
    {
      set("kee", query("max_kee"));
      set("force", query("max_force"));
      remove_call_out("check_fight");
      call_out("check_fight", 1, this_object(), me);
      return 1;
    }
  command("say 难道你来这里就是想打架？我看还是算了吧。\n");
  call_out("move_down", 1, me);
  return 0;
}
int attempt_apprentice(object me)
{
  string myname=RANK_D->query_respect(me);

  if(me->query("mark/jjf_defeated_luocheng")) 
  {
    command("say 不错，不错。"+myname+"果然是可教之才！");
    command("say "+myname+"武艺过人。你我不妨切磋一番。");
    command("recruit "+me->query("id"));
    return 1;
  }
  if (is_fighting())
  {
    command("say 现在在下正忙，"+myname+"请稍候。");
    return 1;
  }
  command("consider");
  command("say 在下从不收徒。");
  command("say 但阁下若能胜过我手中枪，你我不妨互相切磋功夫。");
  me->set_temp("pending/jjf_apprentice_luocheng", 1);
  return 1;
}
int chat()
{
    if(!is_fighting()) return 1;
    if(random(100)<30) do_revive(this_object());
}
void check_fight (object npc, object me)
{
  int npc_kee, my_kee, my_ratio, npc_ratio;
  int npc_max_kee, my_max_kee;
 
  my_kee = me->query("kee");
  npc_kee = npc->query("kee");
  my_max_kee = me->query("max_kee");
  npc_max_kee = npc->query("max_kee");
  my_ratio=my_kee*100/my_max_kee;
  npc_ratio=npc_kee*100/npc_max_kee;

  if (is_fighting())
  {
    call_out ("check_fight",2,npc,me);
    return;
  }
  if (query_temp("last_opponent")!=me) return;
  if (!present(me, environment(npc)))
    return;
  if(npc->query("kee")*100/npc->query("max_kee")
   < me->query("kee")*100/me->query("max_kee"))
    call_out("player_win", 1, me);
  else call_out("player_lose", 1, me);
  return;
}
void player_win(object me)
{
    this_object()->delete_temp("last_opponent");
    if (me->query_temp("pending/jjf_apprentice_luocheng"))
      {
	me->set("mark/jjf_defeated_luocheng", 1);
        me->delete_temp("pending/jjf_apprentice_luocheng");
	command("recruit "+me->query("id"));
      }
    return;
}
void player_lose(object me)
{
    this_object()->delete_temp("last_opponent");
    command("say "+RANK_D->query_respect(me) +"不必气馁，再接再厉！");
    return;
}
int recruit_apprentice(object me)
{
  if( ::recruit_apprentice(me))
  {
    me->delete_temp("pending/jjf_apprentice_luocheng");
    me->delete("mark/jjf_defeated_luocheng");
    me->set("class", "fighter");
  }
}
void do_revive(object ob)
{
    int kee=ob->query("kee"), max_kee=ob->query("max_kee"), eff_kee=ob->query("eff_kee");
    int force=ob->query("force"), max_force=ob->query("max_force");
    int diff_force=max_force-force, diff_kee=max_kee-kee;
    if(diff_force<0) diff_force=0;
    if(diff_kee<0) diff_kee=0;
    ob->receive_curing("kee", diff_kee*2/3);
    ob->set("force", force+diff_force*2/3);
}
void move_down(object me)
{
    if(environment(this_object())!=find_object("/d/jjf/guest_cabinet2"))
      return;
    me->move("/d/jjf/guest_cabinet");
    return;
}
