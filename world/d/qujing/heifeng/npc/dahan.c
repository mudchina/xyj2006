//Cracked by Roath
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/npc/dahan.c
 

inherit NPC;
#include <ansi.h>
string ask_jiasha();

void create()
{
   set_name("黑熊怪", ({ "hei xiong", "bear", "monster" }));
   set("long", "山间野兽，不知从哪里学到一身好本领。");
   set("gender", "男性");
   set("age", 30);
   set("attitude", "heroism");
   set("per", 9);
   set("rank_info/self", "黑熊");
   set("rank_info/rude", "熊怪");
   set("max_kee", 2000);
   set("max_sen", 2000);
   set("force", 1000);
   set("max_force", 1000);
   set("force_factor", 20);
   set("max_mana", 1000);
   set("mana", 1000);
   set("mana_factor", 20);
   set("combat_exp", 500000);
   set_skill("literate", 50);
   set_skill("spells", 60);
   set_skill("buddhism", 60);
   set_skill("unarmed", 100);
   set_skill("jienan-zhi", 95);
   set_skill("dodge", 80);
   set_skill("lotusmove", 80);
   set_skill("parry", 85);
   set_skill("force", 90);
   set_skill("lotusforce", 90);
   set_skill("staff", 60);
   set_skill("lunhui-zhang", 50);
   set_skill("spear", 100);
   set_skill("huoyun-qiang", 100);

   map_skill("spells", "buddhism");
   map_skill("unarmed", "jienan-zhi");
   map_skill("dodge", "lotusmove");
   map_skill("force", "lotusforce");
   map_skill("parry", "lunhui-zhang");
   map_skill("staff", "lunhui-zhang");
   map_skill("spear", "huoyun-qiang");

   set("chat_chance_combat", 60);
   set("chat_msg_combat", ({
     (: perform_action, "spear.lun" :),
   }) );
   set("inquiry",([
        "袈裟": (: ask_jiasha :),
        "jiasha":  (: ask_jiasha :),
        ]));

   setup();
   carry_object("/obj/cloth")->wear();
   carry_object("/d/obj/weapon/spear/jinqiang")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  object room = load_object("/d/qujing/heifeng/cave");
  if (! where ||
    where->query("short") == "正台")
    return;
  message_vision ("\n$N化作一阵风消失了！\n",me);
  me->move(room);
}

string ask_jiasha()
{
        object ob = this_player();
        object me = this_object();

        if( ob->query("obstacle/hf") )
        {
        command("shake");
        return("这又何从说起。\n");
        }

       if (! ob->query_temp("apply/name") ||
          ob->query_temp("apply/name")[0] != "金池长老")
        {
        kill_ob(ob);
        return("你是哪个鸟人，敢来参加本大仙的佛衣会。");
        }

        command("hehe");
        return("请稍等。");

}

void unconcious ()
{
  die ();
}
void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
    ob->set_temp("obstacle/heixiong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision(HIR"只见$N摔倒在地，现了本形。原来是只黑熊！\n"NOR,me);
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/heifeng/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}
void destruct_me (object me)
{
   destruct (me);
}

        
