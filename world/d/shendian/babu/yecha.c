#include <ansi.h>
inherit NPC;
 string ask_tianshen();

void create()
{
     set_name(HIR"夜叉"NOR, ({"ye cha","yecha"}));
       set("long", "八部天龙中的夜叉神\n");
       set("title", HIB"八部天龙"NOR);
       set("gender", "女性");
       set("age", 50);
        set("attitude", "heroism");
       set("per", 50);
       set("max_kee", 3100);
       set("max_gin", 3100);
       set("max_sen", 3100);
       set("force", 3150);
       set("max_force", 3000);
       set("force_factor", 160);
       set("max_mana", 3500);
       set("mana", 3500);
       set("mana_factor", 150);
       set("combat_exp", 4000000);
        set("daoxing", 4000000);

        set_skill("jinghun-zhang", 200);
        set_skill("tonsillit", 200);
        set_skill("gouhunshu", 200);
       set_skill("unarmed", 200);
        set_skill("whip", 200);
        set_skill("sword", 200);
        set_skill("hellfire-whip",200);
        set_skill("zhuihun-sword", 200);
       set_skill("dodge", 200);
        set_skill("ghost-steps", 200);
       set_skill("parry", 200);
        set_skill("spells", 200);
        set_skill("force", 200);
        map_skill("sword", "zhuihun-sword");
        map_skill("parry", "zhuihun-sword");
        map_skill("dodge", "ghost-steps");
        map_skill("unarmed", "jinghun-zhang");
        map_skill("force", "tonsillit");
        map_skill("whip", "hellfire-whip");
        map_skill("spells", "gouhunshu");

        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                ]) );


        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "whip.three" :),
                (: exert_function, "sheqi" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
                (: cast_spell, "gouhun" :)
        }) );
 create_family("阎罗地府", 2, "你好");
setup();
  carry_object("/d/obj/weapon/whip/longsuo")->wield();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}
void die()
{
   object me = query_temp("my_killer");
   me->set_temp("babu/yecha","done");
 message_vision (HIY"小子，我记住你了。\n"NOR);
  destruct (this_object());
  return ;
}
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/yecha") == "done")
                return "又来找我干吗？\n";
  command("say 你想知道众神之殿在哪里？\n");
   command("say 这容易，杀了我吧！\n");
   kill_ob(me);
  return "叫你知道本神的厉害！\n";
}
void kill_ob (object ob)
{
  object me = this_object();
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
