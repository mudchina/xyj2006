#include <ansi.h>
inherit NPC;
string ask_tianshen();
 

void create()
{
        object ob;
         set_name(HIR"迦楼罗"NOR, ({ "jialou luo" }) );
        set("gender", "男性" );
        set("long",
        "八部天龙之一。\n"
        );
        set("age",50);
        set("title", HIB"八部天龙"NOR);
        set("attitude", "heroism");
        set("str",40);
        set("int",30);
        set("max_kee",3100);
        set("kee",3100);
        set("max_sen",3100);
        set("sen",3100);
         set("combat_exp",2500000);
         set("daoxing",4000000);
        set("force",2500);
        set("max_force",1500);
        set("mana",2500);
        set("max_mana",1600);
        set("force_factor", 120);
        set("mana_factor",120);

        set("eff_dx", 3500000);
        set("nkgain", 800);

        set_skill("unarmed",180);
        set_skill("yingzhaogong", 180);
        set_skill("parry",180);
        set_skill("dodge",180);
        set_skill("sword",180);
        set_skill("ningxie-force",180);
        set_skill("bainiao-jian",180);
        set_skill("force",180);
        set_skill("spells", 180);
        set_skill("moshenbu", 180);
        map_skill("dodge", "moshenbu");
        map_skill("force", "ningxie-force");
        map_skill("parry", "bainiao-jian");
        map_skill("sword","bainiao-jian");
        map_skill("unarmed", "yingzhaogong");
        set("inquiry", ([
                "众神殿" : (: ask_tianshen :),
                "shendian" : (: ask_tianshen :),
                ]) );
        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "sword", "chaofeng" :),
        }) );

        setup();

        ob=carry_object("/d/obj/weapon/sword/qingfeng");
        ob->wield();
        carry_object("/d/obj/armor/jinjia")->wear();
}
void die ()
{
   object me = query_temp("my_killer");
   me->set_temp("babu/jialouluo","done");
  message_vision (HIY"$N吓得撒腿就跑。\n"NOR,this_object());
  destruct (this_object());
  return ;
}
string ask_tianshen()
{
        object me = this_player();
        if ( (string)me->query_temp("babu/axiuluo") == "done")
                return "别杀我，别杀我！\n";

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
