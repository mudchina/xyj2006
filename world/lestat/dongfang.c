//niang.c/2001 by lestat
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
// int accept_object(object me, object ob);
void create()
{
       set_name(HIR"东方不败"NOR, ({"dongfang bubai", "dongfang", "bubai","master"}));
       set("long",
"他就是武功天下第一的日月神教教主。\n");
       set("title", HIR"日"HIC"月"HIW"神教教主"NOR);
       set("gender", "男性");
       set("age", 20);
       set("class", "swordsman");
       set("attitude", "friendly");
       set("rank_info/respect", "本座");
       set("per", 40);
       set("int", 30);
       set("max_kee", 10000);
       set("max_sen", 10000);
       set("force", 100000);
       set("max_force", 100000);
       set("force_factor", 1000);
       set("max_mana", 20000);
       set("mana", 20000);
       set("mana_factor", 1000);
       set("combat_exp", 50000000);
       set("daoxing", 50000000);
        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 500);
       set_skill("unarmed", 500);
       set_skill("dodge", 500);
       set_skill("force", 500);
       set_skill("parry", 500);
//       set_skill("qin", 200);
       set_skill("sword", 500);
       set_skill("spells", 500);
/*   set_skill("pansi-dafa", 500);
   set_skill("lanhua-shou", 500);
   set_skill("jiuyin-xinjing", 500);
   set_skill("chixin-jian", 500);
   set_skill("yueying-wubu", 500);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "chixin-jian");
   map_skill("parry", "chixin-jian");
   map_skill("dodge", "yueying-wubu");*/
   set("chat_chance",5);
   set("chat_msg", ({
        HIR"东方不败仰天长叹:葵花在手,江山有我！\n"NOR,

        }));


create_family("五庄观", 1, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/whip/jueqingwhip")->wield();
}

void attempt_apprentice(object ob)
{

        if (((int)ob->query("combat_exp") < 10000 )){
//      this_player()->set("mark/pansi_bai", 1);
        command("shake");
        command("say 凭你这点修为？");
        return;}

        else{
        command("curtain");
        command("say 好！" + RANK_D->query_respect(ob) + "投入我的门下，他日必有所成！\n");
        command("recruit " + ob->query("id") );
//         ob->set("title", BLINK+HIR"葵花在手江山有我"NOR);
        ob->set("name", BLINK+HIG"晓冬"NOR);
        ob->set("class", "swordsman");
        return ;}
}
