// pangu.c 盘古
//lestat
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string jiebai();
string unjiebai();

void create()
{
        set_name(HIR"盘古"NOR, ({ "pan gu","gu" }) );
        set("title", HIR"开天辟地"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
        set("per", 30);
        set("long",
                "上古正神,开天辟地!\n");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 120);
        set("combat_exp", 10000000);
        set("daoxing", 10000000);
        set("attitude", "friendly");
        set("max_kee", 1800);
        set("max_sen", 1800);
        set_skill("parry", 280);
        set_skill("dodge", 280);
        set_skill("force", 280);
        set_skill("archery", 300);
        set_skill("literate", 250);
        set_skill("mace", 300);
        set_skill("unarmed", 280);
        set_skill("changquan", 250);
        set_skill("yanxing-steps", 250);
        set_skill("lengquan-force", 300);
        set_skill("spear", 300);
        set_skill("axe", 300);
        set_skill("baguazhou", 300);
        set_skill("spells", 300);
        set_skill("sanban-axe", 300);
        set("max_mana", 10000);
        set("mana", 15000);
        set("mana_factor", 450);
        map_skill("force", "lengquan-force");
        map_skill("unarmed", "changquan");
        map_skill("spells", "baguazhou");
        map_skill("axe", "sanban-axe");
        map_skill("parry", "sanban-axe");
        map_skill("dodge", "yanxing-steps");
        
        set_temp("apply/attack",200);
        set_temp("apply/defense",200);
        set_skill("dodge", 250);
        set_skill("unarmed", 300);
        create_family("将军府", 1, "蓝");
        setup();
        carry_object("/d/obj/armor/jinjia")->wear();

        
}



int recruit_apprentice(object ob)
{
  if( ::recruit_apprentice(ob) )
    ob->set("class", "fighter");
    ob->set("title", HIR"盘古鬼斧传人"NOR);
}

void attempt_apprentice(object ob)
{
        ob=this_player();
  
  if (ob->query("obstacle/number") < 26) {
        command("say 这位" + RANK_D->query_respect(ob) + "你江湖阅历太浅了！\n");
        command("sigh");
        return;
        }
 if( (int)ob->query("pending/kick_out")) {
        command("say 这位" + RANK_D->query_respect(ob) + "老夫平生最恨不忠不义之人！\n");
        command("heng");
        return;
        }
  if (ob->query("combat_exp") < 1000000)
    {
       command("sigh");
       command("say 这位" + RANK_D->query_respect(ob) + "你武功根底太差了！\n");
       return ;
     }
    command("haha");
    command("recruit " + ob->query("id") );
    return 0;
}

