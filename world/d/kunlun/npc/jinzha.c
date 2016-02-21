inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name("金吒", ({"jin zha", "jin", "zha", "master"}));
       set("long",
"李敬的大儿子，玉虚宫三代燃灯的弟子。\n");
       set("title", "昆仑山玉虚洞第三代弟子");
       set("gender", "男性");
       set("age", 20);
       set("class", "shen");
       set("attitude", "friendly");
//       set("rank_info/respect", "仙客");
       set("per", 40);
       set("int", 40);
       set("max_kee", 3000);
      set("max_gin", 3000);
       set("max_sen", 1000);
       set("force", 1000);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 1000);
       set("mana_factor", 40);
       set("combat_exp", 1000000);
       set("daoxing", 800000);
       set("eff_dx", 800000);
       set("nkgain", 350);
       set_skill("literate", 100);
       set_skill("unarmed", 100);
       set_skill("dodge", 100);
       set_skill("force", 100);
       set_skill("parry", 100);
       set_skill("sword", 100);
       set_skill("spells", 100);
       set_skill("yuxu-spells", 100);
       set_skill("kaitian-zhang", 100);
       set_skill("xuanzong-force", 100);
       set_skill("wugou-jian", 100);
       set_skill("lingyunbu", 100);
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("force", "xuanzong-force");
       map_skill("sword", "wugou-jian");
       map_skill("parry", "wugou-jian");
       map_skill("dodge", "lingyunbu");
             
   set("chat_chance",5);
   set("chat_msg", ({
        HIM"金吒说道:有谁可愿意助我姜师叔一臂之力！\n"NOR,
        }));


create_family("昆仑山玉虚洞", 3, "弟子");
setup();

        carry_object("/d/obj/cloth/linen")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
/*        
         {*/
          command("curtain");
          command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n");
          command("recruit " + ob->query("id") );
          message("system", HIY"昆仑山玉虚洞又多了一个弟子  "+this_player()->name()+HIW"
                     昆仑山玉虚洞的势力加强了。\n"NOR,users());
          ob->set("class", "shen");

//     }

}
